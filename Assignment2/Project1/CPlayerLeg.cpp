#include "CPlayerLeg.h"

CPlayerLeg::CPlayerLeg()
{
	jointX = 0;
	jointY = 0;

	width = 0.1;
	length = 0.5;

	rightAngle = -45;
	leftAngle = -45;

	startTick = GetTickCount64();

	rightDirection = 0;
	leftDirection = 0;

	rightCircuit = false;
}

void CPlayerLeg::drawLeg(float tightLength, int type, 
	float thighJointX, float thighJointY, int thighAngle, bool thighDirection)
{

	jointY = tightLength;
	switch (type)
	{
	case LEFT:
		setLeftAngle(thighDirection, thighAngle);
		//model-frame
		glPushMatrix();
		glTranslatef(jointX, -jointY, 0);
		glRotatef(leftAngle, 0, 0, 1);
		glBegin(GL_POLYGON);
			glColor3f(0.0, 0.7, 0.7);
			glVertex2f(0, 0);
			glVertex2f(width, -width);
			glVertex2f(width, -length + width);
			glVertex2f(0, -length);
			glVertex2f(-width, -length + width);
			glVertex2f(-width, -width);
		glEnd();
		glPopMatrix();
		break;
	case RIGHT:
		setRightAngle(thighDirection, thighAngle);
		//이전까지의 좌표 저장(여기서는 오른쪽 Arm의 joint
		glPushMatrix();
		//오른쪽 joint를 기준으로 얼마만큼 translation할 건지.
		glTranslatef(jointX, -jointY, 0);
		glRotatef(rightAngle, 0, 0, 1);
		glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 1.0);
			glVertex2f(0, 0);
			glVertex2f(width, -width);
			glVertex2f(width, -length + width);
			glVertex2f(0, -length);
			glVertex2f(-width, -length + width);
			glVertex2f(-width, -width);
		glEnd();
		glPopMatrix();
		break;
	default:
		break;
	}
}

void CPlayerLeg::setLeftAngle(bool thighDirection, float thighAngle)
{
	//함수 통해서 들어온 thighDirection은 right 기준이라 바꿔서 생각
	thighDirection = !thighDirection;
	thighAngle = -thighAngle;

	if (thighDirection && thighAngle < 0) {
		//중간에서 뒤로 접히는 구간
		//최대로 펴져서 이제 접히기 시작하는 부분
		leftDirection = 1;
	}

	if (thighDirection && thighAngle > 0) {
		//앞에서 중간으로 펴지는 구간
		//중간정도 펴진 상태
		leftDirection = 2;
	}

	if (!thighDirection && thighAngle < 0) {
		//뒤에서 중간으로 접히는 구간
		//중간정도 접힌 상태
		leftDirection = 3;
	}

	if (!thighDirection && thighAngle > 0) {
		//중간에서 앞으로 펴지는 구간
		//최대로 접혀서 이제 펴지기 시작하는 부분.
		leftDirection = 4;
	}


	switch (leftDirection) {
	case 1:
		startTick = GetTickCount64();
		leftAngle = -((startTick - currentTick) / (VELORATE - ADJUST * passCount));
		leftCircuit = true;
		break;
	case 2:
		currentTick = GetTickCount64();
		leftAngle = -45 + ((currentTick - startTick) / (VELORATE - ADJUST * passCount));

		break;
	case 3:
		currentTick = GetTickCount64();
		//startTick = GetTickCount64();
		leftAngle = -45 -((currentTick - startTick) / (VELORATE - ADJUST * passCount));
		break;
	case 4:
		startTick = GetTickCount64();
		leftAngle = -90 + ((startTick - currentTick) / (VELORATE - ADJUST * passCount));
		//leftCircuit = true;
		break;
	default:
		break;
	}
	//cout << leftDirection << " " << leftAngle << endl;

}

void CPlayerLeg::setRightAngle(bool thighDirection, float thighAngle)
{
	if (thighDirection && thighAngle < 0) {
		//중간에서 뒤로 접히는 구간
		//최대로 펴져서 이제 접히기 시작하는 부분
		rightDirection = 1;
	}

	if (thighDirection && thighAngle > 0) {
		//앞에서 중간으로 펴지는 구간
		//중간정도 펴진 상태
		rightDirection = 2;
	}

	if (!thighDirection && thighAngle < 0) {
		//뒤에서 중간으로 접히는 구간
		//중간정도 접힌 상태
		rightDirection = 3;
	}

	if (!thighDirection && thighAngle > 0) {
		//중간에서 앞으로 펴지는 구간
		//최대로 접혀서 이제 펴지기 시작하는 부분.
		rightDirection = 4;
	}

	//cout << direction << endl;


	switch (rightDirection) {
	case 1:
		startTick = GetTickCount64();
		rightAngle = -((startTick - currentTick) / (VELORATE - ADJUST * passCount));
		break;
	case 2:
		currentTick = GetTickCount64();
		rightAngle = -45 + ((currentTick - startTick) / (VELORATE - ADJUST * passCount)) - 45 * rightCircuit;
		//cout << rightAngle << endl;

		break;
	case 3:
		startTick = GetTickCount64();
		rightAngle = -((startTick - currentTick) / (VELORATE - ADJUST * passCount));
		break;
	case 4:
		currentTick = GetTickCount64();
		rightAngle = -90 + ((currentTick - startTick) / (VELORATE - ADJUST * passCount));
		rightCircuit = true;
		break;
	default:
		break;
	}
}

void CPlayerLeg::setPassCount(int passCount)
{
	this->passCount = passCount;
}


