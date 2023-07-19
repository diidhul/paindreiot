void setup() {
  Serial.begin(9600);
  Serial.println("Mean, media, modus dengan Arduino");
  Serial.println("http://www.semesin.com/project/");
  Serial.println();
}
 
void loop() {
  float Sampel[] = {75.2, 82.0, 83.7, 74.4, 80.1, 85.5, 82.0, 80.1};
 
  byte jumlahSampel = sizeof(Sampel) / sizeof(Sampel[0]);
  float jumlah = 0;
  for (int i = 0; i < jumlahSampel; i++)
  {
    jumlah += Sampel[i];
  }
  float mean = jumlah / jumlahSampel;
  Serial.print("mean = ");
  Serial.println(mean);
 
  urutkanSampel(Sampel, jumlahSampel);
  float median = Sampel[(byte)(jumlahSampel / 2)];
  if (!(jumlahSampel % 2))
  {
    median += Sampel[(byte)(jumlahSampel / 2) - 1];
    median /= 2;
  }
  Serial.print("median = ");
  Serial.println(median);
 
  float modus;
  Serial.print("modus = ");
  if(cariModus(Sampel, jumlahSampel, &modus))
  {
    Serial.println(modus);
  }
  else
  {
    Serial.println("tidak ada");
  }
   
  while (1);
}
 
void urutkanSampel(float *dataArray, byte jumlahData)
{
  byte i = 0;
  for (byte i = 0; i < jumlahData; i++)
  {
    byte k;
    for (byte j = 1; j < jumlahData; j++)
    {
      if (dataArray[j - 1] > dataArray[j])
      {
        float temp = dataArray[j - 1];
        dataArray[j - 1] = dataArray[j];
        dataArray[j] = temp;
      }
    }
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
  if(!frekuensiMaxCount)
  {
    return true;
  }
  return false;
}