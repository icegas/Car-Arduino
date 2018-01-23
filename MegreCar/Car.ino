#include <CarBuilder.h>

Car* car; //final product
Director director;
CarBuilder carBuilder; 

void setup() {
  Serial.begin(9600); //PD1
  while(!Serial){}
  DDRD = OUTD; //Setting Ports for engines
  
  director.setBuilder(&carBuilder);
  car = director.getCar(SONAR_TRIG, SONAR_ECHO);
  car->gyro->begin();
  car->timer = micros();

}

void loop() { 
   car->move();   
}

    


      
     


    

  

  
  
   
   
    


