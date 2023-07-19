/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
int position1 = 0;
int previousPosition1;

void setup() {
    Serial.begin(9600);  // attaches the servo on pin 9 to the servo object
    myservo1.attach(8);
  }

void loop() {
    myservo1.write(0);
    delay(1000);
    myservo1.write(50);
    delay(1000);      
    myservo1.write(125);
    delay(1000);   
    }
