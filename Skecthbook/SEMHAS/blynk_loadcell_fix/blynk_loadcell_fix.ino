#define BLYNK_TEMPLATE_ID "TMPL5VfLNnpA"
#define BLYNK_DEVICE_NAME "loadcell"
#define BLYNK_AUTH_TOKEN "9h_AEua0xnTXdIjsPGSzVu-NaXHQ3SXt"
#include <HX711_ADC.h>
#include <BlynkSimpleEsp32.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif
#include <Servo.h>
Servo mainServo1;


//pins:
const int HX711_dout = 16; //mcu > HX711 dout pin
const int HX711_sck = 5; //mcu > HX711 sck pin
char auth[] = BLYNK_AUTH_TOKEN;
int pos = 0; 

char ssid[] = "lektopfadhil";
char pass[] = "12345678";

BlynkTimer timer;
//HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);

const int calVal_eepromAdress = 0;
unsigned long t = 0;

// void sendSensor(){
// float i = 
// Blynk.virtualWrite(V2, i);
// }

void setup() {
  mainServo1.attach(19);
  Serial.begin(115200); delay(10);
  Serial.println();
  Serial.println("Starting...");
  Blynk.begin(auth, ssid, pass);

  LoadCell.begin();
  // LoadCell.setReverseOutput(); //uncomment to turn a negative output value to positive
  float calibrationValue; // calibration value (see example file "Calibration.ino")
  calibrationValue = -450.05; // uncomment this if you want to set the calibration value in the sketch
#if defined(ESP8266)|| defined(ESP32)
  //EEPROM.begin(512); // uncomment this if you use ESP8266/ESP32 and want to fetch the calibration value from eeprom
#endif
  //EEPROM.get(calVal_eepromAdress, calibrationValue); // uncomment this if you want to fetch the calibration value from eeprom

  unsigned long stabilizingtime = 2000; // preciscion right after power-up can be improved by adding a few seconds of stabilizing time
  boolean _tare = true; //set this to false if you don't want tare to be performed in the next step
  LoadCell.start(stabilizingtime, _tare);
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else {
    LoadCell.setCalFactor(calibrationValue); // set calibration value (float)
    Serial.println("Startup is complete");
  }
}

void loop() {
  static boolean newDataReady = 0;
  const int serialPrintInterval = 0; //increase value to slow down serial print activity

  // check for new data/start next conversion:
  if (LoadCell.update()) newDataReady = true;

  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell.getData();
      Serial.print("Load_cell output val: ");
      Serial.println(i);
      Blynk.virtualWrite(V2, i);
      newDataReady = 0;
      t = millis();

    }
  }

  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
  }
Blynk.run();
timer.run();
 for (pos = 0; pos <= 0; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    mainServo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    mainServo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15 ms for the servo to reach the position
  }

}
