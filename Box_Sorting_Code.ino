#include <Servo.h>

int cm = 0;
int distancia = 0;
int posicion_1 = 90;
int posicion_2 = -90;

Servo myServo;

long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);  
  digitalWrite(pin, LOW);
  delayMicroseconds(10);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  return pulseIn(pin, HIGH);
}

void setup()
{
  pinMode(7, INPUT);
  myServo.attach(12);
  Serial.begin(9600);

}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(7);
  Serial.print(cm);
  Serial.println("cm");
  delay(100); 
  distancia = cm;
  
  if (distancia < 100) {
    myServo.write(posicion_1);
  }else{
    myServo.write(posicion_2);
    }
}