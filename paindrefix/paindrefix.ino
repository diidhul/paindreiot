#include "BluetoothSerial.h" 
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
#include <IRremote.h>
#include <ESP32Servo.h>
String message = "";
char incomingChar;
Servo myservo;
const int SENSOR_PIN = 17; //sensor sentuh
#define IR_RECEIVE_PIN 22 // receiver
#define IR_BUTTON_0 22
#define IR_BUTTON_1 12
#define IR_BUTTON_2 24
#define IR_BUTTON_3 94
#define IR_BUTTON_4 8
#define IR_BUTTON_5 28
#define IR_BUTTON_6 90
#define IR_BUTTON_7 66
#define IR_BUTTON_8 82
#define IR_BUTTON_9 74
#define IR_BUTTON_10 25
int levelnyeri = 0;
void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(16, OUTPUT); //hijau
  digitalWrite(16, LOW);
  myservo.attach(5);
  SerialBT.begin("ESP32");
  Serial.println("Start pairing!");
  Serial.begin(9600); 
}
void loop() {
  if(digitalRead(SENSOR_PIN) == HIGH){
    digitalWrite(16, HIGH);  
//    while(digitalRead(SENSOR_PIN) == HIGH){}
//  Serial.println("HIGH");
  }
  else{
//      Serial.println("low");
//          while(digitalRead(SENSOR_PIN) == LOW){}
    digitalWrite(16, LOW); 
  }
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      case IR_BUTTON_0: {
        myservo.write(0);
        SerialBT.println(levelnyeri);
        break;
      }
      case IR_BUTTON_1: {
        myservo.write(20);
        levelnyeri = 1;
        Serial.print(levelnyeri);
        SerialBT.println(levelnyeri);
        break;
      }
      case IR_BUTTON_2: {
        myservo.write(40);
        levelnyeri = 2;
        Serial.print(levelnyeri);
        SerialBT.println(levelnyeri);        
        break;
      }
      case IR_BUTTON_3: {
        myservo.write(60);    
        levelnyeri = 3;
        Serial.print(levelnyeri);
        SerialBT.println(levelnyeri);
        break;
      }
        case IR_BUTTON_4: {
        myservo.write(80);
        levelnyeri = 4;
        Serial.print(levelnyeri);
        SerialBT.println(levelnyeri);
        break;
      }
        case IR_BUTTON_5: {
        myservo.write(100);     
        levelnyeri = 5;
        Serial.print(levelnyeri);
        SerialBT.println(levelnyeri);
        break;
        }
        case IR_BUTTON_6: {
        myservo.write(120);   
        levelnyeri = 6;
        Serial.print(levelnyeri);
        SerialBT.println(levelnyeri);
        break;
        }
        case IR_BUTTON_7: {
        myservo.write(140);   
        levelnyeri = 7;
        Serial.print(levelnyeri);
        SerialBT.println(levelnyeri);
        break;
        }
        case IR_BUTTON_8: {
        myservo.write(160);   
        levelnyeri = 8;
        Serial.print(levelnyeri);
        SerialBT.println(levelnyeri);
        break;
        }
        case IR_BUTTON_9: {
        myservo.write(170);   
        levelnyeri = 9;
        Serial.print(levelnyeri);
        SerialBT.println(levelnyeri);
        break;
        }
        case IR_BUTTON_10: {
        myservo.write(180);   
        levelnyeri = 10;
        Serial.print(levelnyeri);
        SerialBT.println(levelnyeri);
        break;
        }
      default: {
      }
      }
    }
    if (SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
    delay(20);
  }
