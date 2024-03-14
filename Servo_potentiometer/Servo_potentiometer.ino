#include <Servo.h>
Servo servo1;

int pin = 9;
int pulsoMinimo = 580;
int pulsoMaximo = 2500;
int angulo = 45;
int lectura;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(pin, pulsoMinimo, pulsoMaximo);
  pinMode(A0, INPUT);

}

void loop() {
  lectura = analogRead(A0);
  angulo = map(lectura, 0, 1023, 0, 180);
  servo1.write(angulo);
  delay(10);
  // put your main code here, to run repeatedly
}
