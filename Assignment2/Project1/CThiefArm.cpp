#include "CThiefArm.h"

CThiefArm::CThiefArm()
{
	jointX = 0;
	jointY = 0;

	length = 0.4;
	width = 0.1;

	leftAngle = 0;
	rightAngle = 0;

	leftPreviousAngle = 0;
	rightPreviousAngle = 0;

	leftRotateAngle = 0;
	rightRotateAngle = 0;
}

void CThiefArm::drawArm(float positionX, float positionY, int type)
{
	if (leftRotateAngle != leftAngle)
		leftRotateAngle = leftPreviousAngle += (leftAngle - leftPreviousAngle) * 0.1;

	if (rightRotateAngle != rightAngle)
		rightRotateAngle = rightPreviousAngle += (rightAngle - rightPreviousAngle) * 0.1;

	jointX = positionX;
	jointY = positionY;
	switch (type)
	{
	case LEFT:
		//model-frame
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(jointX, jointY, 0);
		glRotatef(leftRotateAngle, 0, 0, 1);

		glBegin(GL_POLYGON);
		glColor3f(0.3, 0.7, 0.3);
			glVertex2f(0, 0);
			glVertex2f(width, -width);
			glVertex2f(width, -length + width);
			glVertex2f(0, -length);
			glVertex2f(-width, -length + width);
			glVertex2f(-width, -width);
		glEnd();

		leftForeArm.drawForeArm(length, LEFT);
		glLoadIdentity();
		glPopMatrix();
		break;
	case RIGHT:
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(jointX, jointY, 0);

		glRotatef(rightRotateAngle, 0, 0, 1);
		glBegin(GL_POLYGON);
		glColor3f(0.7, 1.0, 0.3);
			glVertex2f(0, 0);
			glVertex2f(width, -width);
			glVertex2f(width, -length + width);
			glVertex2f(0, -length);
			glVertex2f(-width, -length + width);
			glVertex2f(-width, -width);
		glEnd();

		rightForeArm.drawForeArm(length, RIGHT);
		glLoadIdentity();
		glPopMatrix();
		break;
	default:
		break;
	}
}

void CThiefArm::setMotion(int pose)
{
	leftPreviousAngle = leftAngle;
	rightPreviousAngle = rightAngle;
	switch (pose) {
	case RED:
		//哭率 0, 坷弗率 0
		leftAngle = 0;
		rightAngle = 0;
		break;
	case BLUE:
		//哭率 180, 坷弗率 90
		leftAngle = 180;
		rightAngle = 90;
		break;
	case GREEN:
		//哭率 180, 坷弗率 180
		leftAngle = 180;
		rightAngle = 180;
		break;
	case YELLOW:
		//哭率 90, 坷弗率 -90
		leftAngle = 90;
		rightAngle = -90;
		break;
	case BLACK:
		leftAngle = 0;
		rightAngle = 0;
		break;
	}

	leftForeArm.setMotion(pose);
	rightForeArm.setMotion(pose);
}
