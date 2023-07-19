//This code is to use with L298n Dual H-bridge motor driver
//It just turns on a DC motor for a certain time with a low speed and turn it off then turn on with high speed
//refer to surtrtech.com for more information

int in1 = 9; //Declaring the pins where in1 in2 from the driver are wired 
int in2 = 8; //here they are wired with D9 and D8 from Arduino
int ConA = 10; //And we add the pin to control the speed after we remove its jumper 
               //Make sure it's connected to a pin that can deliver a PWM signal

void setup() {
  pinMode(in1, OUTPUT); //Declaring the pin modes, obviously they're outputs
  pinMode(in2, OUTPUT);
  pinMode(ConA, OUTPUT);
}

//Before starting the loop you should create functions type "void" to control the driver's pins
//here I created three functions, the first one is to turn the motor to a direction with speed(100)
//The second one to turn it off
//And the last one to turn it in the same direction as the first but higher speed(250)
//Speed range (0-255)

void TurnMotorA(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ConA,80);
}

void TurnOFFA(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(ConA,0);
}
void TurnMotorA2(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ConA,80);
}

void loop() {
  TurnMotorA();  //Sequence: turning on low speed, stop, turning again in high speed and stop
  delay(160);

  TurnOFFA();
  delay(3500);

  TurnMotorA2();
  delay(160);

  TurnOFFA();
  delay(3500);
}