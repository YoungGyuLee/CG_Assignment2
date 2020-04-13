#include "CPlayerFace.h"


CPlayerFace::CPlayerFace()
{
	jointX = 0;
	jointY = 0;
	faceSize = 0.2;
}

void CPlayerFace::drawFace(float positionX, float positionY)
{
	jointX = positionX;
	jointY = positionY;
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(jointX, jointY, 0);
		glBegin(GL_POLYGON);
		glColor3f(0.8, 0.8, 0.8);
		glVertex2f(0, 0);
		glVertex2f(faceSize/2, faceSize/2);
		glVertex2f(faceSize/2, faceSize/2 + faceSize);
		glVertex2f(-faceSize/2, faceSize / 2 + faceSize);
		glVertex2f(-faceSize / 2, faceSize / 2);
		glEnd();
	glLoadIdentity();
	glPopMatrix();
}
