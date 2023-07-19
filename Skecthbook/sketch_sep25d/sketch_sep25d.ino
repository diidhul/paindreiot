#define QUEUE_LEN 64

// Possibly still useful https://www.tutorialspoint.com/cplusplus-program-to-implement-queue-using-array
int queue[QUEUE_LEN];
int sortedArray[QUEUE_LEN];


void setup() {
  // put your setup code here, to run once:
  //Serial.begin(115200);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  // untuk 64 pixel
  for (int i = 1; i <= 64; ++i)
  {
    
    int value = random(20, 30); // contoh data suhu
 
    //
    int numItems = Push(queue, value); // push antrian
    copy(queue,sortedArray,numItems);
    isort(sortedArray, numItems); // urutkan
    printArray(sortedArray,numItems); // cetak isi array
    calculateMode(sortedArray,numItems); // hitung
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(100);
}


int Push(int* myQ, int val) {
  static int currIndex = 0;
  static int numItems = 0;
   if (currIndex == QUEUE_LEN - 1)
     currIndex = 0;
   else {
      myQ[currIndex] = val;
      currIndex++;
      numItems = max(currIndex,numItems);
   }
   return numItems;
}

void copy(int* src, int* dst, int len) {
    // Serial.print(" copy complete ");
    memcpy(dst, src, sizeof(src[0])*len);
}

void isort(int *a, int n)
{
  for (int i = 1; i < n; ++i)
  {
    int j = a[i];
    int k;
    for (k = i - 1; (k >= 0) && (j < a[k]); k--)
    {
      a[k + 1] = a[k];
    }
    a[k + 1] = j;
  }
  // Serial.println(" sort complete ");
}

void printArray(int *a, int n)
{
  for (int i = 0; i < n; i++)
  {
    Serial.print(a[i], DEC);
    Serial.print(' ');
  }
  Serial.println();
}


void calculateMode(int *sortedQ, int numItems) {
  int modeCt = 0;
  int modeV = -1;

  int ct = 0;
  int v = -1;

  for(int i = 0; i< numItems; i++) {
    if(sortedQ[i] != v) {
      v = sortedQ[i];
      ct = 0;
    }

    ct ++;

    if(ct > modeCt) {
      modeCt = ct;
      modeV = v;
    }
  }
  Serial.print("   ");
  Serial.print("mode: ");
  Serial.print(modeV);
  Serial.print(" count: ");
  Serial.println(modeCt);
}
