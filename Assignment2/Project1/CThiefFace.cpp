#include "CThiefFace.h"

CThiefFace::CThiefFace()
{
	jointX = 0;
	jointY = 0;
	faceSize = 0.2;
}

void CThiefFace::drawFace(float positionX, float positionY)
{
	jointX = positionX;
	jointY = positionY;
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(jointX, jointY, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(0, 0);
	glVertex2f(faceSize / 2, faceSize / 2);
	glVertex2f(faceSize / 2, faceSize / 2 + faceSize);
	glVertex2f(-faceSize / 2, faceSize / 2 + faceSize);
	glVertex2f(-faceSize / 2, faceSize / 2);
	glEnd();
	glLoadIdentity();
	glPopMatrix();
}
