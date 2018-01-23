#include "CarBuilder.h"

iarduino_Position_BMX055* CarBuilder::getINS(){
	iarduino_Position_BMX055* ins = new iarduino_Position_BMX055(BMG);
	return ins;
}

iarduino_HC_SR04* CarBuilder::getSonar(volatile uint8_t port0, volatile uint8_t port1){
	iarduino_HC_SR04* sonar = new iarduino_HC_SR04(port0, port1);
	return sonar;
}
