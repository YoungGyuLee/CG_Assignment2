#pragma once
#include "global.h"
#include "CThiefForeArm.h"
class CThiefArm
{
private:
	float jointX;
	float jointY;
	float length;
	float width;

	float leftAngle;
	float rightAngle;

	float leftPreviousAngle;
	float rightPreviousAngle;

	float leftRotateAngle;
	float rightRotateAngle;

	CThiefForeArm leftForeArm;
	CThiefForeArm rightForeArm;

public:
	CThiefArm();

	void setJoint(float jointX, float jointY);

	void setAngle(float angle);
	float getAngle();

	void drawArm(float positionX, float positionY, int type);

	void setMotion(int pose);

};

