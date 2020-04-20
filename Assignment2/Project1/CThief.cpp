#include "CThief.h"
#include <math.h>
CThief::CThief()
{
	positionX = 7;
	positionY = 1.9;

	thiefSize = 0.5;
	
	thiefWidth = 0.5;
	thiefHeight = 1;
	pose = BLUE;
}

CThief::~CThief()
{
}

float CThief::getThiefPositionX()
{
	return positionX;
}

float CThief::getThiefPositionY()
{
	return positionY;
}

void CThief::setThiefPositionX(float positionX)
{
	this->positionX = positionX;
}

void CThief::setThiefPositionY(float positionY)
{
	this->positionY = positionY;
}


void CThief::setThiefPose(int pose)
{
	this->pose = pose;
	leftArm.setMotion(pose);
	rightArm.setMotion(pose);
}

int CThief::getThiefPose()
{
	return pose;
}

float CThief::getThiefSize()
{
	return thiefSize;
}
 
//void CThief::jumpThief(float velocity, int state)
//{
//	switch (state)
//	{
//	case UP:
//		this->positionX -= velocity;
//		this->positionY += velocity * 10;
//		break;
//
//	case STAY:
//		break;
//
//	case DOWN:
//		this->positionX -= velocity;
//		this->positionY -= velocity * 10;
//		break;
//	}
//
//}


void CThief::drawThief()
{

	leftArm.drawArm(positionX + thiefWidth * 0.5, positionY + thiefHeight * 0.9, LEFT);
	leftThigh.drawThigh(positionX + thiefWidth * 0.5, positionY + thiefHeight * 0.1, LEFT);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
		glVertex2f(this->positionX, this->positionY);
		glVertex2f(this->positionX, this->positionY + this->thiefHeight);
		glVertex2f(this->positionX + this->thiefWidth, this->positionY + this->thiefHeight);
		glVertex2f(this->positionX + this->thiefWidth, this->positionY);
	glEnd();
	thiefFace.drawFace(positionX + thiefWidth * 0.5, positionY + thiefHeight);

	rightArm.drawArm(positionX + thiefWidth * 0.5, positionY + thiefHeight * 0.9, RIGHT);
	rightThigh.drawThigh(positionX + thiefWidth * 0.5, positionY + thiefHeight * 0.1, RIGHT);

}

void CThief::setPassCount(int passCount)
{
	this->passCount = passCount;
	leftThigh.setPassCount(passCount);
	rightThigh.setPassCount(passCount);
}
