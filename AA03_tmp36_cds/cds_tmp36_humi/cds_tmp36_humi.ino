//  lux
#define TEMP_INPUT 0
#define CDS_INPUT 1

int humi = 0;
int tempC = 0;
int lux = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // TMP36
  int temp_value = analogRead(TEMP_INPUT);
  float voltage = temp_value * 5.0 * 1000;
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10;
  humi = random(40,90);
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));
  
  Serial.print(lux);
  Serial.print(",");
  Serial.print(humi);
  Serial.print(",");
  Serial.println(tempC);
  
  delay(1000);
}

//Voltage to Lux
  double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023.0;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}