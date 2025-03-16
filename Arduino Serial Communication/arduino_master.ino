// Master

#define LED 2

int buttonState = 0;

void setup(){
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
}

void loop(){
  if(Serial.available() > 0){
    buttonState = bitRead(Serial.read(), 0);
    Serial.println(buttonState);
  }
  
  digitalWrite(LED, buttonState);
  delay(500);
}