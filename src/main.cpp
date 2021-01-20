#include <Arduino.h>

int Button8 = 8;
int Button9 = 9;
int Button7 = 7;
int CodePass[5];
int xx = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Button9, INPUT);
  pinMode(Button8, INPUT);
  pinMode(Button7, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  int buttonState7 = digitalRead(Button7);
  if (buttonState7 == 0) {
    // Serial.println(xx);
    delay(100);
    CodePass[xx] = 7;
    xx = xx + 1;
    for (byte i = 0; i < 5; i = i + 1) {
      Serial.println(CodePass[i]);
    }
    delay(300);

  } 
  int buttonState8 = digitalRead(Button8);
  if (buttonState8 == 0) {
    // Serial.println(xx);
    CodePass[xx] = 8;
    xx = xx + 1;
    for (byte i = 0; i < 5; i = i + 1) {
      Serial.println(CodePass[i]);
    }
    delay(300);
  }
  int buttonState9 = digitalRead(Button9);
  if (buttonState9 == 0) {
    // Serial.println(xx);
    CodePass[xx] = 9;
    xx = xx + 1;
    for (byte i = 0; i < 5; i = i + 1) {
      Serial.println(CodePass[i]);
    }
    delay(300);
  }
  if (xx == 5) {
    // int CodePass[6] = {0, 0, 0, 0, 0, 0};
    Serial.println("klar");
    if (CodePass[0] == 8 && CodePass[1] == 7 && CodePass[2] == 7 && CodePass[3] == 8 && CodePass[4] == 9) {
        Serial.println("win");
        xx = 0;
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN, LOW);
        CodePass[0] = 0;
        CodePass[1] = 0;
        CodePass[2] = 0;
        CodePass[3] = 0;
        CodePass[4] = 0;
        
    }
    else {
      
      Serial.println("Lose");
      CodePass[0] = 0;
      CodePass[1] = 0;
      CodePass[2] = 0;
      CodePass[3] = 0;
      CodePass[4] = 0;
      xx = 0;
      digitalWrite(12, HIGH);
      delay(1000);
      digitalWrite(12, LOW);
    }
       
  } 


}
      