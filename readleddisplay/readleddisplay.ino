int trans1 = 21;
int trans2 = 22;
int trans3 = 23;
int read1 = 30;
int read2 = 31;
int read3 = 32;
int read4 = 33; 
int read5 = 34;
int read6 = 35;
int read7 = 36;
int read8 = 37;

int listening(int transpin){
  int state = digitalRead(transpin);
  return state;
}

void readDigits(int transpin) {
  if(transpin == trans1){ 
    int reading1 = digitalRead(read1);
    int reading2 = digitalRead(read2);
    int reading3 = digitalRead(read3);
    int reading4 = digitalRead(read4);
    int reading5 = digitalRead(read5);
    int reading6 = digitalRead(read6);
    int reading7 = digitalRead(read7);
    int reading8 = digitalRead(read8);
    Serial.print("lastDigit: ");
    Serial.print(reading1);
    Serial.print(" ");
    Serial.print(reading2);
    Serial.print(" ");
    Serial.print(reading3);
    Serial.print(" ");
    Serial.print(reading4);
    Serial.print(" ");
    Serial.print(reading5);
    Serial.print(" ");
    Serial.print(reading6);
    Serial.print(" ");
    Serial.print(reading7);
    Serial.print(" ");
    Serial.print(reading8);
    Serial.print("\n");
    delayMicroseconds(1);
  }
  else if(transpin == trans2){
    int reading1 = digitalRead(read1);
    int reading2 = digitalRead(read2);
    int reading3 = digitalRead(read3);
    int reading4 = digitalRead(read4);
    int reading5 = digitalRead(read5);
    int reading6 = digitalRead(read6);
    int reading7 = digitalRead(read7);
    int reading8 = digitalRead(read8);
    Serial.print("midDigit: ");
    Serial.print(reading1);
    Serial.print(" ");
    Serial.print(reading2);
    Serial.print(" ");
    Serial.print(reading3);
    Serial.print(" ");
    Serial.print(reading4);
    Serial.print(" ");
    Serial.print(reading5);
    Serial.print(" ");
    Serial.print(reading6);
    Serial.print(" ");
    Serial.print(reading7);
    Serial.print(" ");
    Serial.print(reading8);
    Serial.print("\n");
    delayMicroseconds(1);
  }
  else if(transpin == trans3){
    int reading1 = digitalRead(read1);
    int reading2 = digitalRead(read2);
    int reading3 = digitalRead(read3);
    int reading4 = digitalRead(read4);
    int reading5 = digitalRead(read5);
    int reading6 = digitalRead(read6);
    int reading7 = digitalRead(read7);
    int reading8 = digitalRead(read8);
    Serial.print("firstDigit: ");
    Serial.print(reading1);
    Serial.print(" ");
    Serial.print(reading2);
    Serial.print(" ");
    Serial.print(reading3);
    Serial.print(" ");
    Serial.print(reading4);
    Serial.print(" ");
    Serial.print(reading5);
    Serial.print(" ");
    Serial.print(reading6);
    Serial.print(" ");
    Serial.print(reading7);
    Serial.print(" ");
    Serial.print(reading8);
    Serial.print("\n");
    delayMicroseconds(1);
  }
}

void setup(){
  Serial.begin(9600);
  pinMode(trans1, INPUT);
  pinMode(trans2, INPUT);
  pinMode(trans3, INPUT);
  pinMode(read1, INPUT);
  pinMode(read2, INPUT);
  pinMode(read3, INPUT);
  pinMode(read4, INPUT);
  pinMode(read5, INPUT);
  pinMode(read6, INPUT);
  pinMode(read7, INPUT);
  pinMode(read8, INPUT);
}

void loop(){
  while (digitalRead(trans1) == LOW){
    listening(trans1);
  }
  readDigits(trans1);
  while (digitalRead(trans2) == LOW){ //gets stuck here!!!
    listening(trans2);
  }
  readDigits(trans2);
  while (digitalRead(trans3) == LOW){
    listening(trans3);
  }
  readDigits(trans3);
}
