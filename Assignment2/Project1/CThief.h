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

	float getTheifPositionX();
	float getTheifPositionY();

	void setTheifPose(int pose);
	int getTheifPose();

	float getThiefSize();

	void drawThief();

	void setPassCount(int passCount);

};

