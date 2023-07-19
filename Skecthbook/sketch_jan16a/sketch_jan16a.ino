//inisiasi library
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;
Servo mainServo1;
int position1 = 0;
int previousPosition1;
const long eventTime_1_motor = 100; //in ms
const long eventTime_2_temp = 100; //in ms
unsigned long previousTime_1 = 0;
unsigned long previousTime_2 = 0;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
int in1 = 9; //Declaring the pins where in1 in2 from the driver are wired 
int in2 = 8; //here they are wired with D9 and D8 from Arduino
int ConA = 10; //And we add the pin to control the speed after we remove its jumper 
               //Make sure it's connected to a pin that can deliver a PWM signal

void setup() {
    Serial.begin(9600);
    mainServo1.attach(13);
    Serial.println(F("AMG88xx pixels"));

    bool status;
    
    // default settings
    status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }
    
    Serial.println("-- Pixels Test --");

    Serial.println();

    delay(100); // let sensor boot up
  
    
}
void TurnMotorA(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ConA,100);
}

void TurnOFFA(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(ConA,0);
}
void TurnMotorA2(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ConA,250);
}
void loop() { 
    //read all the pixels
    amg.readPixels(pixels);
    Serial.print("[");
    for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
      Serial.print(pixels[i-1]);
      Serial.print(", ");
      if( i%8 == 0 ) Serial.println();
    }
    Serial.println("]");
    Serial.println();
    delay(50);
    
  float sampel_1 = pixels[0];
  float sampel_2 = pixels[1];
  float sampel_3 = pixels[2];
  float sampel_4 = pixels[3];
  float sampel_5 = pixels[4];
  float sampel_6 = pixels[5];
  float sampel_7 = pixels[6];
  float sampel_8 = pixels[7];
  float sampel_9 = pixels[8];
  float sampel_10 = pixels[9];
  float sampel_11 = pixels[10];
  float sampel_12 = pixels[11];
  float sampel_13 = pixels[12];
  float sampel_14 = pixels[13];
  float sampel_15 = pixels[14];
  float sampel_16 = pixels[15];
  float sampel_17 = pixels[16];
  float sampel_18 = pixels[17];
  float sampel_19 = pixels[18];
  float sampel_20 = pixels[19];
  float sampel_21 = pixels[20];
  float sampel_22 = pixels[21];
  float sampel_23 = pixels[22];
  float sampel_24 = pixels[23];
  float sampel_25 = pixels[24];
  float sampel_26 = pixels[25];
  float sampel_27 = pixels[26];
  float sampel_28 = pixels[27];
  float sampel_29 = pixels[28];
  float sampel_30 = pixels[29];
  float sampel_31 = pixels[30];
  float sampel_32 = pixels[31];
  float sampel_33 = pixels[32];
  float sampel_34 = pixels[33];
  float sampel_35 = pixels[34];
  float sampel_36 = pixels[35];
  float sampel_37 = pixels[36];
  float sampel_38 = pixels[37];
  float sampel_39 = pixels[38];
  float sampel_40 = pixels[39];
  float sampel_41 = pixels[40];
  float sampel_42 = pixels[41];
  float sampel_43 = pixels[42];
  float sampel_44 = pixels[43];
  float sampel_45 = pixels[44];
  float sampel_46 = pixels[45];
  float sampel_47 = pixels[46];
  float sampel_48 = pixels[47];
  float sampel_49 = pixels[47];
  float sampel_50 = pixels[49];
  float sampel_51 = pixels[50];
  float sampel_52 = pixels[51];
  float sampel_53 = pixels[52];
  float sampel_54 = pixels[53];
  float sampel_55 = pixels[54];
  float sampel_56 = pixels[55];
  float sampel_57 = pixels[56];
  float sampel_58 = pixels[57];
  float sampel_59 = pixels[58];
  float sampel_60 = pixels[59];
  float sampel_61 = pixels[60];
  float sampel_62 = pixels[61];
  float sampel_63 = pixels[62];
  float sampel_64 = pixels[63];
  float totalsampel[] = {sampel_1, sampel_2, sampel_3, sampel_4, sampel_5, sampel_6, sampel_7, sampel_8, sampel_9, sampel_10, sampel_11, sampel_12, sampel_13, sampel_14, sampel_15, 
                          sampel_16, sampel_17, sampel_18, sampel_19, sampel_20, sampel_21, sampel_22, sampel_23, sampel_24, sampel_25, sampel_26, sampel_27, sampel_28, sampel_29, sampel_30, 
                          sampel_31, sampel_32, sampel_33, sampel_34, sampel_35, sampel_36, sampel_37, sampel_38, sampel_39, sampel_40,sampel_41, sampel_42, sampel_43, sampel_44, sampel_45, 
                          sampel_46, sampel_47, sampel_48, sampel_49, sampel_50, sampel_51, sampel_52, sampel_53, sampel_54, sampel_55, sampel_56, sampel_57, sampel_58, sampel_59, sampel_60,
                          sampel_61, sampel_62, sampel_63, sampel_64};
  byte jumlahSampel = sizeof(totalsampel) / sizeof(totalsampel[0]);
  
  float modus;
  cariModus(totalsampel, jumlahSampel, &modus);
  unsigned long currentTime = millis();
  if ( currentTime - previousTime_2 >= eventTime_2_temp) {
    Serial.print("modus: ");
    Serial.println(modus);
    
    /* Update the timing for the next event*/
    previousTime_2 = currentTime;
  }
  if(modus > 27){
    mainServo1.write(20);
    delay(100);
  }
  else {
    mainServo1.write(0);
    delay(100);
  } 

}
  

bool cariModus(float *dataArray, byte jumlahData, float *modus)
{
  byte frekuensi;
  float frekuensiData;
  byte frekuensiMax = 0;
  byte frekuensiMaxCount = 0;
  *modus = 0;
  for (byte i = 0; i < jumlahData; ++i)
  {
    frekuensi = 0;
    for (byte j = 0; j < jumlahData; j++)
    {
      if (dataArray[i] == dataArray[j])
      {
        frekuensi++;
      }
    }
    if(frekuensiMax < frekuensi)
    {
      frekuensiMax = frekuensi;
      frekuensiData = dataArray[i];
      *modus = dataArray[i];
      frekuensiMaxCount = 0;
    }
    else if((frekuensiMax == frekuensi) && (frekuensiData != dataArray[i]))
    {
      frekuensiMaxCount++;
    }
  }
  if(!frekuensiMaxCount){
    return true;
    delay(50);
  }
}




