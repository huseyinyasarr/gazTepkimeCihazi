  int sensor1Read = A1;
  int sensor2Read = A2;
  float sensor1Deger = 0;
  float sensor2Deger = 0;
  float gerilim1, gerilim2;
  float sensor1Write = 10;
  float sensor2Write = 11;
  int gps = 12;
  int speed;
  
  void setup(){
  
  Serial.begin(9600);
  pinMode(gps, INPUT);
  
  }

  float sensor1 (float giris1) {
    
  analogWrite(sensor1Write, giris1);
  //return (giris1);
  }

  float sensor2 (float giris2) {
    
  analogWrite(sensor2Write, giris2);
    
  }
  
  void loop (){

  
  float firstVoltaj, secondVoltaj;
  gps = 1; //gps = 1, viraj olarak kabul edilir.
  speed = 80;

  sensor1Deger = analogRead(sensor1Read);
  gerilim1 = (sensor1Deger*5.00)/1023.0;
  
  sensor2Deger = analogRead(sensor2Read);
  gerilim2 = (sensor2Deger*5.00)/1023.0;

  
  
  Serial.print("Gerilim 1: ");
  Serial.println(gerilim1);
  delay(300);
  //Serial.print("Gerilim 2: ");
  //Serial.println(gerilim2);
  //delay(300);
  

  //pwm çıkış 0-255
  //analog okuma 0-1023
  
  if (gps ==1 && speed > 60) {
    firstVoltaj = gerilim1*51 - 51.00;
    sensor1(firstVoltaj);
    secondVoltaj = gerilim2*51 - 51.00;
    sensor2(secondVoltaj);
   // sensor2(sensor1(firstVoltaj)/2.00);
  }
// voltaj*51 = potDeğeri

  else if (gps == 1 && speed <= 60) {
    firstVoltaj = gerilim1*51;
    sensor1(firstVoltaj);
    secondVoltaj = gerilim2*51;
    sensor2(secondVoltaj);
   // sensor2(sensor1(firstVoltaj)/2.00);
  }

  else if (gps==0) {
    firstVoltaj = gerilim1*51;
    sensor1(firstVoltaj);
    secondVoltaj = gerilim2*51;
    sensor2(secondVoltaj);
   // sensor2(sensor1(firstVoltaj)/2.00);
  }
  
  }
