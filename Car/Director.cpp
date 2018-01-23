#include "Director.h"

void Director::setBuilder(Builder* newBuilder){
	
	builder = newBuilder;
}

Car* Director::getCar(volatile uint8_t sonarPort0, volatile uint8_t sonarPort1){
	Car* car = new Car();
	car->gyro = builder->getINS();
	car->sonar = builder->getSonar(sonarPort0, sonarPort1);
	
	return car;
}
