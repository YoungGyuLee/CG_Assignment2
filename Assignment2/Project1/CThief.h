#pragma once
#include "global.h"
#include <math.h>
#include "CThiefArm.h"
#include "CThiefThigh.h"
#include "CThiefFace.h"

class CThief
{
private:
	float positionX;
	float positionY;
	float thiefSize;


	int pose;

	float thiefWidth;
	float thiefHeight;

	int passCount;

	CThiefArm rightArm;
	CThiefArm leftArm;

	CThiefThigh rightThigh;
	CThiefThigh leftThigh;

	CThiefFace thiefFace;

public:
	CThief();
	~CThief();

	void setThiefPositionX(float positionX);
	void setThiefPositionY(float positionY);
	float getThiefPositionX();
	float getThiefPositionY();

	void setThiefPose(int pose);
	int getThiefPose();

	float getThiefSize();

	void drawThief();
	void jumpThief(float velocity, int state);

	void setPassCount(int passCount);

};

