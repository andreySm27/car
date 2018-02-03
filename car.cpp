#include "Arduino.h"
#include "Car.h"
Car::Car(int ENA1,int in11,int in21,int in31,int in41,int ENB1,byte Sp1,int S11,int S21){
   ENA = ENA1;
   in1 = in11;
   in2 = in21;
   in3 = in31;
   in4 = in41;
   ENB = ENB1;
   Sp = Sp1;
   S1 = S11;
   S2 = S21;
}
void Car::Car_move(byte a ){
   switch(a){
    case 0:
    digitalWrite(in1,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in4,HIGH);
    break;
    case 1:
    digitalWrite(in1,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in2,HIGH);
    break;
    case 2:
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in1,HIGH);
    digitalWrite(in4,HIGH);
    break;
    case 3:   
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in1,LOW);
    digitalWrite(in4,LOW);
    break;
   }
   analogWrite(ENA,Sp);
   analogWrite(ENB,Sp);
}
void Car::DriveOnLine(){
  long mTime;
   valSensor = 0;
   valSensor |= analogRead(S1)<<0;
   valSensor |= analogRead(S2)<<1;

  switch(valSensor){
    case 0b00 : edit =  flgTurn; flgTurn = false;  break;
    case 0b10 : edit = !flgTurn; flgTurn = true; lr = false;  mTime = millis();break;
    case 0b01 : edit = !flgTurn; flgTurn = true; lr = true;   mTime = millis(); break;
    case 0b11 : edit = !flgTurn; flgStop = !flgTurn; flgTurn = false; (flgTurn)?mTime = millis():mTime=mTime; break;
  }
  if(millis()-mTime > 2000){
    edit = true;
    flgStop = true;
  }
  if(edit){
    if(flgTurn){
      Car_move((lr)?1:2);
    }else if(flgStop){
      Car_move(3);
    }else{
      Car_move(0);
    }
  }
   
}
void Car::init(){
  pinMode(ENA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENB,OUTPUT);
}
