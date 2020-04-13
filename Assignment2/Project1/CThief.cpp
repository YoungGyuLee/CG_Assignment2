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

float CThief::getTheifPositionX()
{
	return positionX;
}

float CThief::getTheifPositionY()
{
	return positionY;
}

void CThief::setTheifPose(int pose)
{
	this->pose = pose;
	leftArm.setMotion(pose);
	rightArm.setMotion(pose);
}

int CThief::getTheifPose()
{
	return pose;
}

float CThief::getThiefSize()
{
	return thiefSize;
}

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
