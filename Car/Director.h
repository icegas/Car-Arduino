#ifndef Director_h
#define Director_h

#include "Builder.h"


class Director{
	
protected:
	Builder* builder;

public:
	void setBuilder(Builder* newBuilder);
	Car* getCar(volatile uint8_t sonarPort0, volatile uint8_t sonarPort1);
};


#endif //Director_h
