#include "HX711.h"  //You must have this library in your arduino library folder
 
#define DOUT  16
#define CLK  4
 
HX711 scale(DOUT, CLK);
 
//Change this calibration factor as per your load cell once it is found you many need to vary it in thousands
float calibration_factor = -109525; //-106600 worked for my 40Kg max scale setup 
 
//=============================================================================================
//                         SETUP
//=============================================================================================
void setup() {
  Serial.begin(9600);
  Serial.println("HX711 Calibration");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press a,s,d,f to increase calibration factor by 10,100,1000,10000 respectively");
  Serial.println("Press z,x,c,v to decrease calibration factor by 10,100,1000,10000 respectively");
  Serial.println("Press t for tare");
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
 
  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
}
  void loop() {

  scale.set_scale(calibration_factor); //Adjust to this calibration factor
 
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 3);
  Serial.print(" kg"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();
  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
    else if(temp == 's')
      calibration_factor += 100;  
    else if(temp == 'x')
      calibration_factor -= 100;  
    else if(temp == 'd')
      calibration_factor += 1000;  
    else if(temp == 'c')
      calibration_factor -= 1000;
    else if(temp == 'f')
      calibration_factor += 10000;  
    else if(temp == 'v')
      calibration_factor -= 10000;  
    else if(temp == 't')
      scale.tare();  //Reset the scale to zero
  }
}
// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <BlynkSimpleEsp32.h>
// #include "HX711.h"

// #define BLYNK_PRINT Serial
// #include <Blynk.h>

// #define BLYNK_PRINT Serial
// #define BLYNK_TEMPLATE_ID "TMPLDKJmUQR2"
// #define BLYNK_DEVICE_NAME "loadcellblynk"
// #define BLYNK_AUTH_TOKEN "clUKc8YrxjO3RzVA3jHvcOOm_OhjtZIW"
 
// const char *ssid = "lektopfadhil"; // replace with your wifi ssid and wpa2 key
// const char *pass = "12345678";
// char auth[] = "clUKc8YrxjO3RzVA3jHvcOOm_OhjtZIW";    // You should get Auth Token in the Blynk App.
//  int weight;
// WiFiClient client;
 
// HX711 scale(4, 16);
 
// void setup() 
// {
//   Serial.begin(115200);
//   scale.set_scale();
//   scale.tare(); //Reset the scale to 0
//   long zero_factor = scale.read_average(); //Get a baseline reading
//   Blynk.begin(auth, ssid, pass);
  
//   WiFi.begin(ssid, pass);
//   {
//   delay(1000);
//   Serial.print(".");
//   }
//   Serial.println("");
//   Serial.println("WiFi connected");
  
//   delay(2000);
// }
 
// void loop() 
 
// {
 
//   Blynk.run();
   
//   weight = scale.get_units(5); 
 
//   Blynk.virtualWrite(V3, weight);
//   delay(2000);
  
//   Serial.print("Weight: ");
//   Serial.print(weight);
//   Serial.println(" KG");
//   Serial.println();
  
 
// }