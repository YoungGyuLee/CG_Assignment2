#pragma once
//무릎부터 발까지. 즉 종아리 부분
#include "global.h"
#include <iostream>
using namespace std;
class CPlayerLeg
{
private:
	float jointX;
	float jointY;

	float width;
	float length;

	float rightAngle;
	float leftAngle;

	long startTick;
	long currentTick;

	bool rightCircuit;
	bool leftCircuit;

	int rightDirection;
	int leftDirection;

	int passCount;

public:
	CPlayerLeg();
	void setJoint(float jointX, float jointY);

	void setAngle(float angle);
	float getAngle();

	void drawLeg(float tightLength, int type, 
		float thighJointX, float thighJointY, int thighAngle, bool thighDirection);

	void setLeftAngle(bool thighDirection, float thighAngle);
	void setRightAngle(bool thighDirection, float thighAngle);

	void setPassCount(int passCount);
};

