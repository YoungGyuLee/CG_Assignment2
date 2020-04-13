#pragma once
#include "global.h"
class CWall
{
private:
	float positionX;
	float positionY;
	int color;
	float width;
	float height;
	int front;

public:
	CWall();
	~CWall();
	
	void setWallPositionX(float positionX);
	float getWallPositionX();
	
	void setWallPositionY(float positionY);
	float getWallPositionY();
	
	void setWallColor(int color);
	int getWallColor();

	float getWallWidth();
	float getWallHeight();

	void setFront(int front);
	int getFront();
};

