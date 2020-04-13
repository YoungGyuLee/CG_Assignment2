#include "CSound.h"


CSound::CSound()
{
	bgmId = 0;
	winId = 0;
	loseId = 0;
	thiefPassId = 0;
	playerPassId = 0;
	playerNonPassId = 0;
	playerPoseChangeId = 0;
}

void CSound::setSoundType(int type)
{
	this->type = type;
}

int CSound::getSoundType()
{
	return this->type;
}

void CSound::playsound(int type)
{
	MCI_PLAY_PARMS mPlay;

	switch (type) {
	case BGM:
		bgmOpen.lpstrElementName = _T("bgm.mp3");
		bgmOpen.lpstrDeviceType = _T("mpegvideo");
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&bgmOpen);
		bgmId = bgmOpen.wDeviceID;
		mciSendCommand(bgmId, MCI_PLAY, MCI_NOTIFY, (DWORD)&mPlay);
		break;
	case THIEFPASS:
		mciSendCommand(thiefPassId, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
		thiefPassOpen.lpstrElementName = _T("thief_pass.mp3");
		thiefPassOpen.lpstrDeviceType = _T("mpegvideo");
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&thiefPassOpen);
		thiefPassId = thiefPassOpen.wDeviceID;
		mciSendCommand(thiefPassId, MCI_PLAY, MCI_NOTIFY, (DWORD)&mPlay);
		break;
	case PLAYERPASS:
		mciSendCommand(playerPassId, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
		playerPassOpen.lpstrElementName = _T("player_pass.mp3");
		playerPassOpen.lpstrDeviceType = _T("mpegvideo");
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&playerPassOpen);
		playerPassId = playerPassOpen.wDeviceID;
		mciSendCommand(playerPassId, MCI_PLAY, MCI_NOTIFY, (DWORD)&mPlay);
		break;
	case PLAYERNONPASS:
		mciSendCommand(playerNonPassId, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
		playerNonPassOpen.lpstrElementName = _T("player_non_pass.mp3");
		playerNonPassOpen.lpstrDeviceType = _T("mpegvideo");
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&playerNonPassOpen);
		playerNonPassId = playerNonPassOpen.wDeviceID;
		mciSendCommand(playerNonPassId, MCI_PLAY, MCI_NOTIFY, (DWORD)&mPlay);
		break;
	case WIN:
		mciSendCommand(bgmId, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
		winOpen.lpstrElementName = _T("win.mp3");
		winOpen.lpstrDeviceType = _T("mpegvideo");
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&winOpen);
		winId = winOpen.wDeviceID;
		mciSendCommand(winId, MCI_PLAY, MCI_NOTIFY, (DWORD)&mPlay);
		break;
	case LOSE:
		mciSendCommand(bgmId, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
		loseOpen.lpstrElementName = _T("lose.mp3");
		loseOpen.lpstrDeviceType = _T("mpegvideo");
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&loseOpen);
		loseId = loseOpen.wDeviceID;
		mciSendCommand(loseId, MCI_PLAY, MCI_NOTIFY, (DWORD)&mPlay);
		break;
	case CHANGE:
		mciSendCommand(playerPoseChangeId, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
		playerPoseChangeOpen.lpstrElementName = _T("change.mp3");
		playerPoseChangeOpen.lpstrDeviceType = _T("mpegvideo");
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
			(DWORD)(LPVOID)&playerPoseChangeOpen);
		playerPoseChangeId = playerPoseChangeOpen.wDeviceID;
		mciSendCommand(playerPoseChangeId, MCI_PLAY, MCI_NOTIFY, (DWORD)&mPlay);
		break;
	default:
		break;
	}
}
