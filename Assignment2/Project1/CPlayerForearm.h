#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <vector>
#include "global.h"
class CPlayerForearm
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
	CPlayerForearm();
	void setJoint(float jointX, float jointY);

	void setAngle(float angle);
	float getAngle();

	void drawForeArm(float armLength, int type);

	void setMotion(int pose);

};

