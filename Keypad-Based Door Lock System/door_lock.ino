// library lcd i2c
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// deklarasi lcd i2c
LiquidCrystal_I2C lcd(0x20,16,2);

// deklarasi keypad
#define ROW_NUM    4 // jumlah baris keypad
#define COLUMN_NUM 4 // jumlah kolom keypad

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM] = {13, 12, 11, 10};
byte pin_column[COLUMN_NUM] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

// deklarasi servo
Servo door;

// deklarasi pin
#define servo 5
#define buzzer 4
#define led_green 3
#define led_red 2
  
// deklarasi variabel
String setPin = "";
String inputPin = "";
bool isPinSet = false;

void setup(){
  Serial.begin(9600);
  
  // set input output pin
  pinMode(buzzer, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);

  door.attach(servo);
  
  // inisialisasi lcd i2c
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  
  // set door locked
  door.write(0);
  
  lcd.setCursor(0, 0);
  lcd.print("Set Door PIN:");
}

void loop(){
  char key = keypad.getKey();
  if (key){
    if (!isPinSet){
      set_pin(key);
    }
    else{
      cek_pin(key);
    }
  }
}


void set_pin(char key){
  if (key == '*'){
    setPin = "";
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Set Door PIN:");
  }
  else if (key == '#'){
    if (setPin.length() >= 4){
      isPinSet = true;
      lcd.clear();
      lcd.print("PIN Saved!");
      delay(2000);
      lcd.clear();
      lcd.print("Enter PIN:");
    }
    else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Min. 4 digit!");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Set Door PIN:");
    }
  }
  else{
    if (setPin.length() < 16){
      setPin += key;
      lcd.setCursor(setPin.length(), 1);
      lcd.print(key);
  	}
  }
}
  
void cek_pin(char key) {
  if (key == '*') {
    inputPin = "";
    lcd.clear();
    lcd.print("Enter PIN:");
  } else if (key == '#') {
    if (inputPin == setPin) {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_red, LOW);
      digitalWrite(buzzer, LOW);
      lcd.clear();
      lcd.print("Correct Pin!");
      door.write(90);
      delay(5000);
      door.write(0);
      digitalWrite(led_green, LOW);
      lcd.clear();
      lcd.print("Enter PIN:");
    } else {
      digitalWrite(led_red, HIGH);
      digitalWrite(led_green, LOW);
      digitalWrite(buzzer, HIGH);
      lcd.clear();
      lcd.print("Incorrent PIN!");
      delay(2000);
      digitalWrite(led_red, LOW);
      digitalWrite(buzzer, LOW);
      inputPin = "";
      lcd.clear();
      lcd.print("Enter PIN:");
    }
  } else {
    inputPin += key;
    lcd.setCursor(inputPin.length(), 1);
    lcd.print("*");
  }
}