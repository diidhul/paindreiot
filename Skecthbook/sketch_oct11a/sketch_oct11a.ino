//inisiasi library
#include <HTTPClient.h>
#include <WiFi.h>

//inisiasi pin 
    const int buttonPin1 = 4;
    int buttonState1 = 0;
    const int buttonPin2 = 14;
    int buttonState2 = 0;
    const int buttonPin3 = 2;
    int buttonState3 = 0; 
    long instance1=0, timer;
    double hrv = 0, BPM = 72, interval = 0;
    int value = 0, count = 0;  
    bool flag = 0;
    #define threshold 100 // to identify R peak
    #define timer_value 10000 // 10 seconds timer to calculate hr
    const int buzzer = 23;
    char msg[300];
//wifi setup
    const char* ssid = "..."; // isi nama SSID wifinya
    const char* password = "12345678"; // isi password wifinya
    
//Bacokeh kend credentialx` s
    const char* serverName = "https://api-detakjantung.herokuapp.com/api/data";
    const char* serverName2 = "https://api-detakjantung.herokuapp.com/api/alert";
    const char* EVENT_TOPIC = "api/data";
    
//connect wi-fi    
    WiFiClient espClient;
    void setup_wifi() {
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
  delay(1000);
  WiFi.disconnect();
  delay(1000);
  WiFi.begin(ssid, password);
  delay(1000);
  
    randomSeed(micros());
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}
//inisiasi tombol
byte lastbuttonstate1;
byte lastbuttonstate2;
int number;

//membaca detak jantung
 void readbpm(){
  int is_button;
  pinMode(1, INPUT); // Setup for leads off detection LO +
  pinMode(3, INPUT); // Setup for leads off detection LO -
      String kirim;
      String kirim2;
      if((digitalRead(1) == 1)||(digitalRead(3) == 1)){
      Serial.println("leads off!");
        instance1 = micros(); 
        timer = millis();
      }
      else {
        value = analogRead(A0);
        value = map(value, 250, 400, 0, 100); //to flatten the ecg values a bit
        if((value > threshold) && (!flag)) {
          count++;  
//          Serial.println("in");
          flag = 1;
          interval = micros() - instance1; //RR interval
          instance1 = micros(); 
        }
        else if((value < threshold)) {
          flag = 0;
        }
        if ((millis() - timer) > 10000) {
          BPM = count*6;
          timer = millis();
          count = 0; 
        }
        hrv = BPM/60 - interval/1000000;
        delay(1);
      }
      
      // mengirim bacaan sensor detak jantung dan input tombol
      kirim += "{\"bpm\":\"";
      kirim += BPM;
      kirim += "\",\"v55\":\"01\"}";
      char*msg = (char*)kirim.c_str();
      kirim2 += "{\"bpm\":\"";
      kirim2 += BPM;
      kirim2 += "\",\"v55\":\"01\", \"is_alert\": 1}";
      char*msg1 = (char*)kirim2.c_str();
      Serial.println(BPM);
      
      // kode alarm
      pinMode(buzzer, OUTPUT);
      if (BPM < 60 && BPM > 110) {
        digitalWrite(buzzer, HIGH);
        delay(50);
        digitalWrite(buzzer, LOW);
        delay(10);
        digitalWrite(buzzer, HIGH);
        delay(50);
      }
    // jika wifi terhubung, kirim data
    if(WiFi.status()== WL_CONNECTED){
     
      HTTPClient http;
      // jika tombol satu ditekan, memulai pengukuran
      if (lastbuttonstate1 == 1){
        http.begin(serverName);
        http.addHeader("Content-Type", "application/json");
        int httpResponseCode = http.POST(kirim);
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
      // jika tombol dua ditekan, mengirim lokasi
      } else if (lastbuttonstate2 == 1) {
        http.begin(serverName2);
        http.addHeader("Content-Type", "application/json");
        int httpResponseCode = http.POST(kirim2);
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        Serial.println("Link2");

        //jika tombol tiga ditekan, berhenti mengirim data
      } else {
        Serial.println("No data response");
      }
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }

void setup() {
    pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT);
    pinMode(buttonPin3, INPUT);

  Serial.begin(115200);
  setup_wifi();
  pinMode(23, OUTPUT);
  


}
void loop() {
    byte buttonState1 = digitalRead(buttonPin1);
    byte buttonState2 = digitalRead(buttonPin2);
    byte buttonState3 = digitalRead(buttonPin3);

    if (buttonState1 == HIGH) {
      Serial.print("button state 1 = ");
      Serial.println(buttonState1);
      lastbuttonstate1 = 1;
      lastbuttonstate2 = LOW;
      number = 1;
      Serial.print("NUMBER = ");
      Serial.println(number);
    } else if (buttonState2 == HIGH && lastbuttonstate1 == 1) {
      Serial.print("button state 2 = ");
      Serial.println(buttonState2);
      lastbuttonstate2 = 1;
      lastbuttonstate1 = LOW;
      number = 2;
      Serial.print("NUMBER = ");
      Serial.println(number);
      
    } else if (buttonState3 == HIGH){
      lastbuttonstate2 = LOW;
      lastbuttonstate1 = LOW;
      Serial.println("stop");
    } else {
      number = 0;
    }

    readbpm();
}
