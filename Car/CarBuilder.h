#ifndef CarBuilder_h
#define CarBuilder_h

#include "Arduino.h"
#include "Director.h"

class CarBuilder : public Builder{
	
public:
	iarduino_Position_BMX055* getINS();
	iarduino_HC_SR04* getSonar(volatile uint8_t port0, volatile uint8_t port1);	
};

#endif //CarBuilder_h
