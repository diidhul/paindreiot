//Tech Trends Shameer

#define BLYNK_TEMPLATE_ID "TMPLM7mrE9kW"
#define BLYNK_DEVICE_NAME "DHT11"
#define BLYNK_AUTH_TOKEN "wKJ1k_wO2HQ4dGPtyoqgzEDXgVsxZ9XU"

#define BLYNK_PRINT Serial
#include <WiFi.h>
//#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp32.h>

#include <DHT.h>


char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "lektopfadhil";
char pass[] = "12345678";

BlynkTimer timer;


#define DHTPIN 27 //Connect Out pin to D2 in NODE MCU
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);


void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Serial.print("Temperature : ");
    Serial.print(t);
    Serial.print("    Humidity : ");
    Serial.println(h);
}
void setup()
{   

  Serial.begin(115200);


  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(500L, sendSensor);
  }

void loop()
{
  Blynk.run();
  timer.run();
 }