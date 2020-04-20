#include "CPlayer.h"

CPlayer::CPlayer()
{
	positionX = 1;
	positionY = 1.9;
	playerWidth = 0.5;
	playerHeight = 1;
	pose = RED;
	passCount = 0;
}

CPlayer::~CPlayer()
{
}

void CPlayer::setPlayerPositionX(float positionX)
{
	this->positionX = positionX;
}

float CPlayer::getPlayerPositionX()
{
	return positionX;
}

float CPlayer::getPlayerPositionY()
{
	return positionY;
}

void CPlayer::setPlayerPose(int pose) {
	this->pose = pose;
	leftArm.setMotion(pose);
	rightArm.setMotion(pose);
}

int CPlayer::getPlayerPose()
{
	return pose;
}

float CPlayer::getPlayerSize()
{
	return playerWidth;
}

void CPlayer::drawPlayer()
{

	leftArm.drawArm(positionX + playerWidth * 0.5, positionY + playerHeight*0.9, LEFT);
	leftThigh.drawThigh(positionX + playerWidth * 0.5, positionY + playerHeight * 0.1, LEFT);
	
	//Draw player body
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
		glVertex2f(this->positionX, this->positionY);
		glVertex2f(this->positionX, this->positionY + this->playerHeight);
		glVertex2f(this->positionX + this->playerWidth, this->positionY + this->playerHeight);
		glVertex2f(this->positionX + this->playerWidth, this->positionY);
	glEnd();
	
	playerFace.drawFace(positionX + playerWidth * 0.5, positionY + playerHeight);
	rightArm.drawArm(positionX + playerWidth * 0.5, positionY + playerHeight*0.9, RIGHT);
	rightThigh.drawThigh(positionX + playerWidth * 0.5, positionY + playerHeight * 0.1, RIGHT);

}

void CPlayer::setPassCount(int passCount)
{
	this->passCount = passCount;
	leftThigh.setPassCount(passCount);
	rightThigh.setPassCount(passCount);
}

