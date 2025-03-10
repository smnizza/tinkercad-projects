int cntUp = 99;
int cntDown = 00;

int digit[10] =
{0b1000000, 
 0b1111001, 
 0b0100100, 
 0b0110000, 
 0b0011001, 
 0b0010010, 
 0b0000010, 
 0b1111000, 
 0b0000000, 
 0b0010000};

int b1state0 = 1;
int b2state0 = 1;
int b1state1, b2state1;
int b1 = 12;
int b2 = 11;

int countstate;
int ones, tens;
int spd = 25;
int rep = spd;

int countDirection = 0;

void setup(){
    for (int i = 2; i < 11; i++){
    pinMode(i, OUTPUT);
    }
    pinMode(11, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
}

void count(int num){
    for (int i = 2; i <= 8; i++){
    	digitalWrite(i, bitRead(digit[num], i - 2));
    }
}

void loop(){
  b1state1 = digitalRead(b1);
  b2state1 = digitalRead(b2);

  switch (countDirection){
    case 1:
      cntUp = (cntUp + 1) % 100;
      break;

    case -1:
      cntDown = (cntDown - 1 + 100) % 100;
      break;
  }

  tens = (countDirection == 1) ? cntUp / 10 : cntDown / 10;
  ones = (countDirection == 1) ? cntUp % 10 : cntDown % 10;

  digitalWrite(9, 0);
  digitalWrite(10, 1);
  count(ones);
  delay(100);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  count(tens);
  delay(100);

  if (b1state1 == 1 && b1state0 == 0){
    b1state0 = b1state1;
    countDirection = (countDirection == 1) ? 0 : 1;
  }

  if (b2state1 == 1 && b2state0 == 0){
    b2state0 = b2state1;
    countDirection = (countDirection == -1) ? 0 : -1;
  }

  b1state0 = b1state1;
  b2state0 = b2state1;
}