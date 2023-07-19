#include <Servo.h>

// #define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
// #define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
Servo mainServo1;
Servo mainServo2;
int position1 = 0;
int previousPosition1;
int position2 = 0;
int previousPosition2;
// defines variables
// long duration; // variable for the duration of sound wave travel
// int distance; // variable for the distance measurement

void setup() {
      mainServo1.attach(8);
      mainServo2.attach(9);

  // pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  // pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  // // Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  // Serial.println("with Arduino UNO R3");

}
void loop() {
  // Clears the trigPin condition
  mainServo2.write(90);
  delay(1000);
  position2 = 90;
  Serial.println(position2);

  mainServo2.write(0);
  delay(1000);
  position2 = 0;
  Serial.println(position2);

  if (position2 == 90){
  mainServo1.write(90);
  delay(1000);
  }
  if (position2 == 0){
    mainServo1.write(0);
  delay(1000);
  }
}
  