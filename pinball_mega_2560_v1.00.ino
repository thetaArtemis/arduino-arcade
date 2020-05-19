//(c) 2020, Oliver Marsh

int input1 = 2;
int input2 = 3;
int input3 = 4;
int input4 = 5;

int led1 = 10;
int led2 = 11;
int led3 = 12;
int led4 = 13;

int writeLED1;
int writeLED2;
int writeLED3;
int writeLED4;

unsigned long startMillis1;
unsigned long startMillis2;
unsigned long startMillis3;
unsigned long startMillis4;
unsigned long currentMillis;
const unsigned long period = 1000;

void setup() {
  // put your setup code here, to run once:
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(input1, INPUT_PULLUP);
    pinMode(input2, INPUT_PULLUP);
    pinMode(input3, INPUT_PULLUP);
    pinMode(input4, INPUT_PULLUP);

    // tests all leds
    digitalWrite(led1, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    delay(100);
    digitalWrite(led2, HIGH);
    delay(250);
    digitalWrite(led2, LOW);
    delay(100);
    digitalWrite(led3, HIGH);
    delay(250);
    digitalWrite(led3, LOW);
    delay(100);
    digitalWrite(led4, HIGH);
    delay(500);
    for (int i = 0; i <= 3; i++) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(250);      
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      delay(250);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis = millis();
  writeLED1 = writeLEDsByState1();
  writeLED2 = writeLEDsByState2();
  writeLED3 = writeLEDsByState3();
  writeLED4 = writeLEDsByState4();
  digitalWrite(led1, writeLED1);
  digitalWrite(led2, writeLED2);
  digitalWrite(led3, writeLED3);
  digitalWrite(led4, writeLED4);
}
int writeLEDsByState1() {
  int stateInput1 = !digitalRead(input1);
  if(stateInput1 == 1) {
    startMillis1 = currentMillis;
  }
  if (currentMillis - startMillis1 <= period) {
    return 1;
   }
   else {
     return 0;
   }
 }

int writeLEDsByState2() {
  int stateInput2 = !digitalRead(input2);
  if(stateInput2 == 1) {
  startMillis2 = currentMillis;
  }
  if (currentMillis - startMillis2 <= period) {
    return 1;
    }
    else {
      return 0;
   }
}

int writeLEDsByState3() {
  int stateInput3 = !digitalRead(input3);
  if(stateInput3 == 1) {
    startMillis3 = currentMillis;
  }
  if (currentMillis - startMillis3 <= period) {
    return 1;
  }
  else {
    return 0;
  }
}

int writeLEDsByState4() {
  int stateInput4 = !digitalRead(input4);
  if(stateInput4 == 1) {
    startMillis4 = currentMillis;
  }
  if (currentMillis - startMillis4 <= period) {
    return 1;
  }
  else {
   return 0;
  }
}
