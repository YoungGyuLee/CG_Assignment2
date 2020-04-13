#include "CWall.h"

CWall::CWall()
{
	positionX = 10;
	positionY = 1;
	color = BLACK;
	width = 0.5;
	height = 6;
	front = 0;
}

CWall::~CWall()
{

}

void CWall::setWallPositionX(float positionX)
{
	this->positionX = positionX;
}

float CWall::getWallPositionX()
{
	return positionX;
}

void CWall::setWallPositionY(float positionY)
{
	this->positionY = positionY;
}

float CWall::getWallPositionY()
{
	return positionY;
}

void CWall::setWallColor(int color)
{
	this->color = color;
}

int CWall::getWallColor()
{
	return color;
}

float CWall::getWallWidth()
{
	return width;
}

float CWall::getWallHeight()
{
	return height;
}

void CWall::setFront(int front)
{
	this->front = front;
}

int CWall::getFront()
{
	return front;
}
