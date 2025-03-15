// library lcd i2c
#include <LiquidCrystal_I2C.h>

// deklarasi lcd i2c
LiquidCrystal_I2C lcd(0x20,16,2);

// deklarasi pin
#define LDR_PIN A0
#define RELAY 3
#define PIR_PIN 2

int light_value, light, motion;

void setup(){
  Serial.begin(9600);
  
  pinMode(LDR_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY, OUTPUT);
  
  // inisialisasi lcd i2c
  lcd.init();
  lcd.clear();         
  lcd.backlight();
}

void loop(){
  light_value = analogRead(LDR_PIN);
  light = map(light_value, 0, 1023, 0, 100);
  Serial.print("Light Level: ");
  Serial.print(light);
  
  motion = digitalRead(PIR_PIN);
  
  if (light < 30 || motion == HIGH){
    Serial.println(" -> Lamp Status: ON");
    // relay on
  	digitalWrite(RELAY, HIGH);
    // tampilkan status di lcd i2c
    lcd.setCursor(0,0);
    lcd.print("Lamp Status: ON ");
  }
  else{
    Serial.println(" - > Lamp Status: OFF");
    // relay on
  	digitalWrite(RELAY, LOW);
    // tampilkan status di lcd i2c
    lcd.setCursor(0,0);
    lcd.print("Lamp Status: OFF");
  }
  
  delay(100);
}