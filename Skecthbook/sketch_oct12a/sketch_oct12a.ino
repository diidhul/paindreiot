long instance1=0, timer;

double hrv =0, hr = 72, interval = 0;

int value = 0, count = 0;  

bool flag = 0;



#define threshold 100 // to identify R peak

#define timer_value 10000 // 10 seconds timer to calculate hr


void setup() {

  Serial.begin(115200);

  pinMode(1, INPUT); // Setup for leads off detection LO +

  pinMode(3, INPUT); // Setup for leads off detection LO -

}

void loop() { 

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

      Serial.println("in");

      flag = 1;

      interval = micros() - instance1; //RR interval

      instance1 = micros(); 

    }

    else if((value < threshold)) {

      flag = 0;

    }

    if ((millis() - timer) > 10000) {

      hr = count*6;

      timer = millis();

      count = 0; 

    }

    hrv = hr/60 - interval/1000000;

    Serial.println(hr);

    

    delay(1);

  }

}
