#include <Car.h>

Car car1(2,3,4,5,6,7,150,A0,A1); //this is new Car - car1 with paramethor (ENA,in1,in2,in3,in4,ENB,speed,Sensor1,Sensor2)
void setup() {
  car1.init(); //init the car1 (pins)

}

void loop() {
  car1.DriveOnLine(); //run the function drive on line for car1
}
