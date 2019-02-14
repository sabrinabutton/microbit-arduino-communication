#ifndef MotorController_h
#define MotorController_h


#include "Arduino.h"


class MotorController
{
protected:
    int _pwmA, _dirA, _pwmB, _dirB;
    int _currentSpeed;
	int _ADir, _BDir, _Dir;
    double _motorAConst, _motorBConst;
	int _minAPosSpeed;
	int _minANegSpeed;
	int _minBPosSpeed;
	int _minBNegSpeed;
	int _minNegSpeed, _minPosSpeed;
public:
    MotorController(int dirA, int pwmA, int dirB, int pwmB, double motorAConst, double motorBConst);
    void move(int ASpeed, int BSpeed);
    void move(int speed);
    void stopMoving();
};


#endif