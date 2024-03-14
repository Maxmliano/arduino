#include <Servo.h>
Servo servo1;

int pin = 9;
int pulsoMinimo = 580;
int pulsoMaximo = 2500;
int angulo = 45;

void setup() {
  // put your setup code here, to run once:
servo1.attach(pin, pulsoMinimo, pulsoMaximo);

}

void loop() {
  for (angulo = 0; angulo <= 180; angulo ++)
  {
    servo1.write(angulo);
    delay (10);
  }
  for (angulo = 180; angulo >= 0; angulo --)
  {
    servo1.write(angulo);
    delay (10);
  }
  // put your main code here, to run repeatedly
}
