int crossTime = 5000; // time to cross for pedestrians
unsigned long changeTime; // time after push button is pressed

void setup(){
    // set input and output pin
    pinMode(2, INPUT); // push button
    pinMode(12, OUTPUT); // green-vehicle
    pinMode(11, OUTPUT); // yellow-vehicle
    pinMode(10, OUTPUT); // red-vehicle
    pinMode(9, OUTPUT); // red-pedestrian
    pinMode(8, OUTPUT); // green-pedestrian
  
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
}

void loop(){
  int state = digitalRead(2);
  if(state == HIGH && (millis() - changeTime) > 5000){
    changeLights();
  }
}

void changeLights(){
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(2000);
  
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(1000);
  
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  
  delay(crossTime);
  
  for(int i=0; i<10; i++){
    digitalWrite(8, HIGH);
    delay(250);
    digitalWrite(8, LOW);
    delay(250);
  }
  
  digitalWrite(9, HIGH);
  delay(500);
  
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  
  changeTime = millis();
}