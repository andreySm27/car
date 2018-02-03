#include "Arduino.h"

#ifndef Car_h
#define Car_h
 
class Car{
  public :
  Car(int ENA1,int in11,int in21,int in31,int in41,int ENB1,byte Sp1,int S11,int S21);
  void init();
  void DriveOnLine();
  int ENA,in1, in2, in3, in4, ENB, S1, S2 ;byte Sp;
  uint8_t valSensor;
  bool flgTurn = false;
  bool edit = true;
  bool lr;
  bool flgStop = false;
  private:
    void Car_move(byte a );
};
 
#endif
