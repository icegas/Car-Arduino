
#include "Car.h"
#include "math.h"

Car::Car(){
	Yaw = 0;
}

void Car::setYaw(double _yaw){
	Yaw = _yaw;
}

double Car::getYaw(){
	gyro->read();
	double velZ = gyro->axisZ; // 1.05; /// 0.98;

	if(abs(velZ) < 0.25)
		velZ = 0;
  	Yaw += velZ * ((double)(micros() - timer) / 1000000);
	
	if(abs(Yaw) > 360)
		Yaw = 0;
	timer = micros();
	return Yaw;
}

double Car::check(double sp){
	if(sp > MAX_SPEED)
		sp = MAX_SPEED;
	if(sp < MIN_SPEED)
		sp = MIN_SPEED;
	return sp;
}
void Car::move(void){
	int engSp = 0;
	bool flag = false;
	double rSp = 0;
	double lSp = 0;
	double K1 = 5;
	Yaw  = 0;

	while(true){
		
		engSp = K1 * (-getYaw());
		if(flag)
			engSp = K1 * (90 - getYaw());
		rSp = SPEED + engSp;
		lSp = coff * SPEED - engSp;
	 	rSp = check(rSp);
		lSp = check(lSp);
		double curDist = sonar->distance(0);

		if(curDist > DISTANCE || !flag)
			goForward(lSp, rSp);

		if(curDist < DISTANCE || flag){
			flag = true;

			if(abs(getYaw()) < 90){
				goRight(lSp, rSp);
			}
			else{
				flag = false;
				Yaw = 0;
			}
		}
	}
}

void Car::goForward(uint8_t lSp, uint8_t rSp){
	analogWrite(L_F_B, FORWARD);
	analogWrite(R_F_B, FORWARD); 
	analogWrite(LEFT_WHEEL, lSp);
	analogWrite(RIGHT_WHEEL, rSp);
}

void Car::goBackward(uint8_t lSp, uint8_t rSp){
	analogWrite(L_F_B, BACKWARD);
	analogWrite(R_F_B, BACKWARD);
	analogWrite(RIGHT_WHEEL, rSp);
	analogWrite(LEFT_WHEEL, lSp);

}

void Car::goLeft(uint8_t rSpeed, uint8_t lSpeed){
	analogWrite(L_F_B, BACKWARD);
	analogWrite(R_F_B, FORWARD); 
	analogWrite(LEFT_WHEEL, lSpeed);
	analogWrite(RIGHT_WHEEL, rSpeed);

}

void Car::goRight(uint8_t rSpeed, uint8_t lSpeed){
	analogWrite(L_F_B, FORWARD);
	analogWrite(R_F_B, BACKWARD); 
	analogWrite(RIGHT_WHEEL, rSpeed);
	analogWrite(LEFT_WHEEL, lSpeed);
}

void Car::stop(void){
	analogWrite(RIGHT_WHEEL, STOP);
	analogWrite(LEFT_WHEEL, STOP);
}
