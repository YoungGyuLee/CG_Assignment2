#include "CThiefThigh.h"

CThiefThigh::CThiefThigh()
{
	jointX = 0;
	jointY = 0;
	length = 0.5;
	width = 0.1;
	angle = 0;
	startTick = GetTickCount64();

	//true면 오른쪽이 앞으로 향함.
	direction = true;
}

void CThiefThigh::drawThigh(float positionX, float positionY, int type)
{
	if (angle > 45) {
		direction = true;
	}
	if (angle < -45) {
		direction = false;
	}

	if (direction) {
		currentTick = GetTickCount64();
		angle = 45 - ((currentTick - startTick) / (VELORATE - ADJUST * passCount));
	}
	else {
		startTick = GetTickCount64();
		angle = -45 - ((currentTick - startTick) / (VELORATE - ADJUST * passCount));
	}


	jointX = positionX;
	jointY = positionY;
	switch (type)
	{
	case LEFT:
		//model-frame
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(jointX, jointY, 0);
		glRotatef(-angle, 0, 0, 1);
		glBegin(GL_POLYGON);
		glColor3f(0.7, 0.0, 0.7);
		glVertex2f(0, 0);
		glVertex2f(width, -width);
		glVertex2f(width, -length + width);
		glVertex2f(0, -length);
		glVertex2f(-width, -length + width);
		glVertex2f(-width, -width);
		glEnd();
		leftLeg.drawLeg(length, LEFT, 0, 0, angle, direction);
		glLoadIdentity();
		glPopMatrix();
		break;
	case RIGHT:
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(jointX, jointY, 0);
		glRotatef(angle, 0, 0, 1);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 1.0);
		glVertex2f(0, 0);
		glVertex2f(width, -width);
		glVertex2f(width, -length + width);
		glVertex2f(0, -length);
		glVertex2f(-width, -length + width);
		glVertex2f(-width, -width);
		glEnd();
		rightLeg.drawLeg(length, RIGHT, currentTick, startTick, angle, direction);
		glLoadIdentity();
		glPopMatrix();
		break;
	default:
		break;
	}
}

void CThiefThigh::setPassCount(int passCount)
{
	this->passCount = passCount;
	leftLeg.setPassCount(passCount);
	rightLeg.setPassCount(passCount);
}
