#pragma once
#include "global.h"
#include "CPlayerForearm.h"

//¿©±â´Â ÆÈ²ÞÄ¡~¾î±ú±îÁöÀÇ ÆÈ
class CPlayerArm
{
private : 
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

	CPlayerForearm leftForeArm;
	CPlayerForearm rightForeArm;

public:
	CPlayerArm();

	void setJoint(float jointX, float jointY);
	
	void setAngle(float angle);
	float getAngle();

	void drawArm(float positionX, float positionY, int type);

	void setMotion(int pose);

	//void drawArm(float positionX, float positionY, int type);
	//void drawArm(float positionX, float positionY, int type);

};

