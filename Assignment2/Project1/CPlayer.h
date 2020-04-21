#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <vector>
#include "global.h"
#include "CPlayerArm.h"
#include "CPlayerThigh.h"
#include "CPlayerFace.h"
using namespace std;

class CPlayer
{
private:
	float positionX;
	float positionY;

	float playerWidth;
	float playerHeight;

	int pose;

	//속도 조절
	int passCount;

	CPlayerArm rightArm;
	CPlayerArm leftArm;

	CPlayerThigh rightThigh;
	CPlayerThigh leftThigh;

	CPlayerFace playerFace;
public:
	CPlayer();
	~CPlayer();

	void setPlayerPositionX(float positionX);
	void setPlayerPositionY(float positionY);

	float getPlayerPositionX();
	float getPlayerPositionY();

	void setPlayerPose(int pose);
	int getPlayerPose();

	float getPlayerSize();

	void drawPlayer();

	void setPassCount(int passCount);
};

