#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 12); // RX, TX

int a;
int mode = 0;
long duration, distance;

void setup() {
  pinMode(8, INPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  while (mySerial.available()){
    a = mySerial.read();
    if (a == 'J')
    {
      mode = 1;
    }

    bool detect;
    int direct = 0;
    
    while (mode == 1){
      detect = digitalRead(A0);
      a = mySerial.read();
      if (a == 'H')
      {
        mode = 0;
      }
      
      if (detect)
      {
        digitalWrite(4, LOW);
        digitalWrite(7, LOW);
        analogWrite(5, 126);
        analogWrite(6, 130);
      }
      else
      {
          digitalWrite(4, LOW);
          digitalWrite(7, HIGH);
          analogWrite(5, 100);
          analogWrite(6, 0);
          delay(1);
      }
    }
    
    /*
    while (mode == 1){
      a = mySerial.read();
       if (a == 'H')
      {
        mode = 0;
      }
      digitalWrite(13, LOW);
      delayMicroseconds(2);

      Serial.print("working  ");

      digitalWrite(13, HIGH);
      delayMicroseconds(10);
      
      digitalWrite(13, LOW);
      duration = pulseIn(12, HIGH);
      
      distance = duration / 58.2;
      if (distance <= 50){
        digitalWrite(4, HIGH);
        digitalWrite(7, LOW);
        analogWrite(5, 130);
        analogWrite(6, 130);
      }else{
        digitalWrite(4, LOW);
        digitalWrite(7, LOW);
        analogWrite(5, 190);
        analogWrite(6, 190);
      }
    }
    */
    
    if (a=='F')
    {
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
      analogWrite(5, 255);
      analogWrite(6, 255);
    }
    else if (a=='R')
    {
      digitalWrite(4, LOW);
      digitalWrite(7, HIGH);
      analogWrite(5, 130);
      analogWrite(6, 130);
    }
    else if (a=='L')
    {
      digitalWrite(4, HIGH);
      digitalWrite(7, LOW);
      analogWrite(5, 130);
      analogWrite(6, 130);
    }   
    else if (a=='B')
    {
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH);
      analogWrite(5, 255);
      analogWrite(6, 255);
    }
    else if (a =='G')
    {
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
      analogWrite(5, 150);
      analogWrite(6, 255);
    }
    else if (a =='I')
    {
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
      analogWrite(5, 255);
      analogWrite(6, 150);
    }
    else
    {
      analogWrite(5, 0);
      analogWrite(6, 0);
    }
  }
}

