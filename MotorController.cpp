#include "MotorController.h"
#include "Arduino.h"


MotorController::MotorController(int dirA, int pwmA, int dirB, int pwmB, double motorAConst, double motorBConst)
{
    _motorAConst = motorAConst;
    _motorBConst = motorBConst;
    _minAPosSpeed = 50;
	_minANegSpeed = -50;
	_minBPosSpeed = 50;
	_minBNegSpeed = -50;
	_minNegSpeed = -50;
	_minPosSpeed = 50;
	_dirA = dirA;
	_pwmA = pwmA;
	_dirB = dirB;
	_pwmB = pwmB;
	
	pinMode(_dirA, OUTPUT);
	pinMode(_pwmA, OUTPUT);
    
	pinMode(_dirB, OUTPUT);
	pinMode(_pwmB, OUTPUT);
}


void MotorController::move(int ASpeed, int BSpeed)
{

    
	if (ASpeed < 0) // Motor A - right from front - slow one
    { // fastest speed is -255 which is 0
		_ADir = 1;
		ASpeed = min(ASpeed, 0); //-60
        ASpeed = max(ASpeed, -255);
		if(ASpeed > -6) {ASpeed = 0; _ADir = 0;}
		else { 
		  ASpeed = map(ASpeed,-6,-255,_minANegSpeed,-255);
		  ASpeed = 255 + ASpeed;
		}
    }
    else // speed >= 0
    { // fastest speed is 255 which is 255
		_ADir = 0;
        ASpeed = max(ASpeed, 0); // 60
        ASpeed = min(ASpeed, 255);
		if(ASpeed < 6) {ASpeed = 0; _ADir = 0;}
		else {
		  ASpeed = map(ASpeed,6,255,_minAPosSpeed,255);
		}
    }
    
    if (BSpeed < 0) // Motor B - left from front - fast one
    {
	    //Serial.print(F("S"));
        //Serial.print(BSpeed);
		_BDir = 1;
        BSpeed = min(BSpeed, 0);
        BSpeed = max(BSpeed, -255);
		if(BSpeed > -6) {BSpeed = 0; _BDir = 0;}
		else {
		  BSpeed = map(BSpeed,-6,-255,_minBNegSpeed,-255);
		  BSpeed = 255 + BSpeed;
		}
    }
    else // speed >= 0
    {
		//Serial.print(F("S"));
        //Serial.print(BSpeed);
		_BDir = 0;
        BSpeed = max(BSpeed, 0);
        BSpeed = min(BSpeed, 255);
		
		if(BSpeed < 6) {BSpeed = 0; _BDir = 0;}
		else {
		  BSpeed = map(BSpeed,6,255,_minBPosSpeed,255);
		}
    }
	    //Serial.print(F(" S"));
        //Serial.println(BSpeed);
        digitalWrite(_dirA, _ADir );
        digitalWrite(_dirB, _BDir);
		
        analogWrite(_pwmA, ASpeed);
        analogWrite(_pwmB, BSpeed);
}


void MotorController::move(int speed)
{
   if(speed != _currentSpeed) {
       _currentSpeed = speed;
	   //move(speed, speed);
	   if (speed < 0){ // fastest speed is -255 which is 0
		   _Dir = 1;
            speed = min(speed, 0); //-70
            speed = max(speed, -255);
			//speed = map(speed,0,-255,_minNegSpeed,-255);
			if(speed > -6) {speed = 0; _Dir = 0;}
		    else {speed = 255 + speed;}
        }
        else // speed >= 0
        { // fastest speed is 255 which is 255
		    _Dir = 0;
            speed = max(speed, 0); //70
            speed = min(speed, 255);
			//speed = map(speed,0,255,_minPosSpeed,255);
			if(speed < 6) {speed = 0; _Dir = 0;}
        }
	    digitalWrite(_dirA, _Dir );
        digitalWrite(_dirB, _Dir);
        analogWrite(_pwmA, speed);
        analogWrite(_pwmB, speed);
		
	}
}



void MotorController::stopMoving()
{
    digitalWrite(_dirA, LOW);
    digitalWrite(_dirB, LOW);
    digitalWrite(_pwmA, LOW);
    digitalWrite(_pwmB, LOW);
    
    _currentSpeed = 0;
}