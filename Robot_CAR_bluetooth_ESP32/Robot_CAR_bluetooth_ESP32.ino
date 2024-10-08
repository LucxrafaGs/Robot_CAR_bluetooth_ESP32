#include <ESP32Servo.h>
Servo esc;

int escPin = 2;

#include "BluetoothSerial.h"
#define pin1 13
#define pin2 27
#define pin3 26
#define pin4 25

BluetoothSerial SerialBT;



char comando;

void setup() {
 esc.attach(escPin, 1000, 2000);

 esc.writeMicroseconds(1000);
delay(2000);

 Serial.begin(9600);
 //btSerial.begin(9600);
 SerialBT.begin("Patrickbot");
 pinMode(pin1, OUTPUT);
 pinMode(pin2, OUTPUT);
 pinMode(pin3, OUTPUT);
 pinMode(pin4, OUTPUT);
 Serial.println("Fim Setup");
 delay(2000); }


void loop() {
 if (SerialBT.available()) {
 comando = SerialBT.read();
 }
 switch (comando) {
 case 'F': { //move frente
 digitalWrite(pin1, HIGH);
 digitalWrite(pin2, LOW);
 digitalWrite(pin3, HIGH);
 digitalWrite(pin4, LOW);
 break;
 }
 case 'G': {//frente direita
 digitalWrite(pin1, HIGH);
 digitalWrite(pin2, LOW);
 digitalWrite(pin3, LOW);
 digitalWrite(pin4, HIGH);
 break;
 }
 case 'I': {//frente esquerda
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, HIGH);
 digitalWrite(pin3, HIGH);
 digitalWrite(pin4, LOW);
 break;
 }
 case 'R': {//direita
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, HIGH);
 digitalWrite(pin3, HIGH);
 digitalWrite(pin4, LOW);
 break;
 }
 case 'L': {//esquerda
 digitalWrite(pin1, HIGH);
 digitalWrite(pin2, LOW);
 digitalWrite(pin3, LOW);
 digitalWrite(pin4, HIGH);
 break;
 }
 case 'B': {// ré
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, HIGH);
 digitalWrite(pin3, LOW);
 digitalWrite(pin4, HIGH);
 break;
 }
 case 'H': {// ré esquerda
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, LOW);
 digitalWrite(pin3, LOW);
 digitalWrite(pin4, HIGH);
 break;
 }
 case 'J': {//ré direita
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, HIGH);
 digitalWrite(pin3, LOW);
 digitalWrite(pin4, LOW);
 break;
 }
 case 'W': {
 esc.writeMicroseconds(1200);  // Velocidade baixa
  delay(2000);
    break;
}
case 'w': {

esc.writeMicroseconds(0000);  // Velocidade baixa
  delay(2000);
    break;
}
 default: {
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, LOW);
 digitalWrite(pin3, LOW);
 digitalWrite(pin4, LOW);
 break;
 }
 }
}
