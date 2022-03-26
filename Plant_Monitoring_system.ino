#include <SoftwareSerial.h>



#include <BoltIoT-Arduino-Helper.h>

SoftwareSerial mySerial(1,0);
float temp;
float sen;
float lightValue;
float ms;

void setup() {
  // put your setup code here, to run once:

pinMode(A0,INPUT);//Moisture value
pinMode(A1,INPUT);//Temperature value
pinMode(A2,INPUT);//Light Value
boltiot.Begin(Serial);
mySerial.begin(9600);
Serial.begin(9600);
delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:
  boltiot.handleCommand();
  ms=analogRead(A0);
  ms=map(ms,550,0,0,100);
  Serial.print("Moisture: ");
  Serial.print(ms);
  mySerial.print(ms);
  Serial.println("%");
  sen=analogRead(A1);
  temp=(sen/1024)*100;
  Serial.print("Temperature: ");
  Serial.print(temp);
  mySerial.print(temp);
  Serial.print(" \xC2\xB0");
  Serial.println("C");
  lightValue=analogRead(A2);
  Serial.print("Light intensity: ");
  Serial.println(lightValue);
  mySerial.print(lightValue);
  delay(5000);
}
