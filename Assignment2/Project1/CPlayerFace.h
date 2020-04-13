#pragma once
#include "global.h"
class CPlayerFace
{
private:
	float jointX;
	float jointY;

	float faceSize;
public:
	CPlayerFace();
	void drawFace(float positionX, float positionY);
};

