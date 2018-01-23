#ifndef CONST_H
#define CONST_H

#define RIGHT_WHEEL 	    PD6
#define LEFT_WHEEL  	    PD5
#define R_F_B		    PD7
#define L_F_B		    PD4
#define RIGHT_WHEEL_FLAG    _BV(7)
#define LEFT_WHEEL_FLAG     _BV(4)

#define R_WHEEL_PORT   _BV(6)
#define L_WHEEL_PORT   _BV(5)

#define OUTD (R_WHEEL_PORT  | L_WHEEL_PORT | RIGHT_WHEEL | LEFT_WHEEL )

#define SONAR_ECHO 10
#define SONAR_TRIG 8

#define STOP 0
#define FORWARD 255
#define BACKWARD 0
#define SPEED 150
#define coff 0.72
#define MAX_SPEED 255
#define MIN_SPEED 90

#define DEG 360
#define ANGLE 30
#define DISTANCE 10
#define ERR 1.5
#define TRUTH 1

#endif //CONST_H
