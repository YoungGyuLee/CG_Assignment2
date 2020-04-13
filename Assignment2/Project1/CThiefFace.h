#pragma once
#include "global.h"
class CThiefFace
{
private:
	float jointX;
	float jointY;

	float faceSize;
public:
	CThiefFace();
	void drawFace(float positionX, float positionY);
};

