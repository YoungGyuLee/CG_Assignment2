#pragma once
#include "global.h"
class CThiefForeArm
{
private:
	float jointX;
	float jointY;

	float width;
	float length;

	float leftAngle;
	float rightAngle;

	float leftPreviousAngle;
	float rightPreviousAngle;

	float leftRotateAngle;
	float rightRotateAngle;

public:
	CThiefForeArm();
	void setJoint(float jointX, float jointY);

	void setAngle(float angle);
	float getAngle();

	void drawForeArm(float armLength, int type);

	void setMotion(int pose);
};

