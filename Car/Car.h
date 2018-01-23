#ifndef Car_h
#define Car_h

#include <Arduino.h>
#include <iarduino_Position_BMX055.h> 
#include <avr/io.h>
#include <util/delay.h>
#include "const.h"
#include <iarduino_HC_SR04.h>

class Car{

public:
	iarduino_Position_BMX055* gyro;
	iarduino_HC_SR04* sonar;
	Car();
	void goForward(uint8_t lSp, uint8_t rSp);
	void goBackward(uint8_t lSp, uint8_t rSp);
	void goRight(uint8_t rSpeed, uint8_t lSpeed);
	void goLeft(uint8_t rSpeed, uint8_t lSpeed);
	void stop(void);
 	void move(void);
	double getYaw();
	uint32_t timer;
	void setYaw(double _yaw);
protected:
	double Yaw;
	double check(double sp);

};

#endif //Car_h
