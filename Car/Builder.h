#ifndef Builder_h
#define Builder_h

#include <iarduino_Position_BMX055.h>
#include "Car.h"

class Builder{
	
public:
	virtual iarduino_Position_BMX055* getINS() = 0;
	virtual iarduino_HC_SR04* getSonar(volatile uint8_t port0, volatile uint8_t port1) = 0;
};

#endif //Builder_h
