#pragma once
#include "global.h"
#include "CThiefLeg.h"
class CThiefThigh
{
private:
	float jointX;
	float jointY;
	float length;
	float width;
	float angle;
	long startTick;
	long currentTick;
	bool direction;

	int passCount;

	CThiefLeg leftLeg;
	CThiefLeg rightLeg;
public:
	CThiefThigh();

	void setJoint(float jointX, float jointY);

	void setAngle(float angle);
	float getAngle();

	void drawThigh(float positionX, float positionY, int type);
	void setPassCount(int passCount);
};

