#include <Servo.h>

Servo trashBin;

#define trigPin 13
#define echoPin 12
#define buzzer 11
#define led 10
#define servo 9

float distance;

void setup(){
  Serial.begin(9600);
  
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  
  trashBin.attach(servo);
  
  trashBin.write(0);
}

void loop(){
  // sensor ultrasonik data
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // konversi jarak ke cm
  distance = pulseIn(echoPin,HIGH);      
  distance = distance/58; 
  Serial.print(distance);
  
  if (distance < 20){
    Serial.println(" cm -> Trash Bin Open!");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    trashBin.write(90);
  }
  else{
    Serial.println(" cm -> Trash Bin Close!");
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    trashBin.write(0);
  }
  
  delay(1000);
}