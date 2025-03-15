#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

#define FRS A0
#define PIR 4
#define LED 3
#define BUZZER 2

float forceValue, pirState;

void setup(){
  Serial.begin(9600);
  
  pinMode(FRS, INPUT);
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop(){
  pirState = digitalRead(PIR);
  forceValue = analogRead(FRS);
  
  Serial.print("Force Sensor: ");
  Serial.print(forceValue);
  Serial.print(" | PIR Sensor: ");
  Serial.println(pirState);

  if (forceValue > 200 && pirState == HIGH){  
    lcd.setCursor(0,0);
    lcd.print("ALARM TRIGGERED");
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(1000);
    digitalWrite(BUZZER, LOW);
  }
  else if(forceValue > 200){
    lcd.setCursor(0,0);
    lcd.print("Step Detected   ");
  }
  else if(pirState == HIGH){
    lcd.setCursor(0,0);
    lcd.print("Motion Detected ");
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("No Activity    ");
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }
  
  delay(100);
}