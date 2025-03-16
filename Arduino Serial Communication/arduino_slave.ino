// Slave

#define BUTTON_PIN 2

int buttonState = 0;

void setup(){
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}

void loop(){
  buttonState = digitalRead(BUTTON_PIN);
  Serial.print(buttonState);
  delay(500);
}