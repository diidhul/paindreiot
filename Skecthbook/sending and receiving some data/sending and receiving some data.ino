/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPL0CLLp6u8"
#define BLYNK_DEVICE_NAME "LED BUTTON"
#define BLYNK_AUTH_TOKEN  "KHeutYrRn7kxoPpn3iCuxkd2-NWidH-F"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

int ledhijau = 22;
char auth[] = "KHeutYrRn7kxoPpn3iCuxkd2-NWidH-F";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "lektopfadhil";
char pass[] = "12345678";

// This function is called every time the Virtual Pin 0 state changes


// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}


void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode (ledhijau, OUTPUT);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int tmblLED = param.asInt();

 if (tmblLED == HIGH){
 digitalWrite(ledhijau, HIGH);
 }

 if (tmblLED == LOW){
 digitalWrite(ledhijau, LOW);
  }
}

void loop()
{
  
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
