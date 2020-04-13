#pragma once
#include "global.h"
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <mmsystem.h>
#include "stb_image.h"

class CSound
{
private:
	int type;
	//background sound
	MCIDEVICEID bgmId;
	MCI_OPEN_PARMS bgmOpen;

	MCIDEVICEID winId;
	MCI_OPEN_PARMS winOpen;

	MCIDEVICEID loseId;
	MCI_OPEN_PARMS loseOpen;

	//effect sound
	MCIDEVICEID thiefPassId = 0;
	MCI_OPEN_PARMS thiefPassOpen;

	MCIDEVICEID playerPassId = 0;
	MCI_OPEN_PARMS playerPassOpen;

	MCIDEVICEID playerNonPassId = 0;
	MCI_OPEN_PARMS playerNonPassOpen;

	MCIDEVICEID playerPoseChangeId = 0;
	MCI_OPEN_PARMS playerPoseChangeOpen;

public:
	CSound();
	void setSoundType(int type);
	int getSoundType();
	void playsound(int type);
};
