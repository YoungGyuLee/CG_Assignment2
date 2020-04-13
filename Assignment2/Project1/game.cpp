#include "game.h"

using namespace std;


MCI_OPEN_PARMS openParams;
MCI_PLAY_PARMS playParams;
DWORD deviceID;
MCI_OPEN_PARMS openParams2;
MCI_PLAY_PARMS playParams2;

int dwID;
wchar_t text1[20] = L"";
size_t length;
//LPCWSTR text1;
unsigned int TBO;
MCIDEVICEID mID;


void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
	cheatMode = NO;
	startTickCount = GetTickCount64();
	srand((unsigned int)time(NULL));
	thief.setTheifPose(rand()%4);
	walls.push_back(CWall());
	sound.playsound(BGM);
}

void setObjectColor(int color) {
	switch (color)
	{
	case RED:
		glColor3f(1.0, 0.0, 0.0);
		break;
	case GREEN:
		glColor3f(0.0, 1.0, 0.0);
		break;
	case BLUE:
		glColor3f(0.0, 0.0, 1.0);
		break;
	case YELLOW:
		glColor3f(1.0, 1.0, 0.0);
		break;
	case BLACK:
		glColor3f(0.0, 0.0, 0.0);
		break;
	default:
		glColor3f(0.0, 0.0, 0.0);
		break;
	}
}


void cameraZoomIn() {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(velocity*50, 10, 0, (10 - velocity*50) / 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void message(bool success) {
	HWND hwnd;
	HINSTANCE hInstance = GetModuleHandle(NULL);
	hwnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	if (success) {
		sound.playsound(WIN);
		cout << "Win" << endl;
		MessageBoxA(hwnd, "Win", "Win", MB_OK);
	}
	else {
		sound.playsound(LOSE);
		cout << "Lose" << endl;
		MessageBoxA(hwnd, "Lose", "Lose", MB_OK);
	}

	exit(0);
}

void playSound() {

	wchar_t path[100] = _T(" ");

	MCI_OPEN_PARMS mOpen;
	mOpen.lpstrElementName = _T("bgm.mp3");
	mOpen.lpstrDeviceType = _T("mpegvideo");

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mOpen);

	mID = mOpen.wDeviceID;

	MCI_PLAY_PARMS mPlay;
	mciSendCommand(mID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mPlay);

}

void registerCallbackFunctions(char** argv) {

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(moveWall);
	glutSpecialFunc(selectPose);
	glutKeyboardFunc(selectCheatMode);
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	//Ground - initialize position and color
	glBegin(GL_QUADS);
		setObjectColor(BLACK);
		glVertex2f(0,0);
		glVertex2f(0, 1);
		glVertex2f(10, 1);
		glVertex2f(10, 0);
	glEnd();
	
	//Player - initialize position and size
	player.drawPlayer();
	/*glBegin(GL_QUADS);
		setObjectColor(player.getPlayerPose());
		glVertex2f(player.getPlayerPositionX(), player.getPlayerPositionY());
		glVertex2f(player.getPlayerPositionX(), player.getPlayerPositionY() + player.getPlayerSize());
		glVertex2f(player.getPlayerPositionX() + player.getPlayerSize(), player.getPlayerPositionY() + player.getPlayerSize());
		glVertex2f(player.getPlayerPositionX() + player.getPlayerSize(), player.getPlayerPositionY());
	glEnd();
	*/
	//Thief - Initialize position and size

	thief.drawThief();
	/*
	glBegin(GL_QUADS);
		setObjectColor(thief.getTheifPose());
		glVertex2f(thief.getTheifPositionX(), thief.getTheifPositionY());
		glVertex2f(thief.getTheifPositionX(), thief.getTheifPositionY() + thief.getThiefSize());
		glVertex2f(thief.getTheifPositionX() + thief.getThiefSize(), thief.getTheifPositionY() + thief.getThiefSize());
		glVertex2f(thief.getTheifPositionX() + thief.getThiefSize(), thief.getTheifPositionY());
	glEnd();
	*/
	
	glBegin(GL_QUADS);
		//Wall - create a wall every "interval" time
		currentTickCount = GetTickCount64();
		if (currentTickCount - startTickCount >= interval) {
			walls.push_back(CWall());
			walls[total].setWallPositionX(walls[total].getWallPositionX() + interval/1000.0 * total);
			startTickCount = currentTickCount;
			total++;
		}

		//Wall - initialize position and color
		for (int i = front; i < total; i++) {
			setObjectColor(walls[i].getWallColor());
			glVertex2f(walls[i].getWallPositionX(), walls[i].getWallPositionY());
			glVertex2f(walls[i].getWallPositionX(), walls[i].getWallPositionY() + walls[i].getWallHeight());
			glVertex2f(walls[i].getWallPositionX() + walls[i].getWallWidth(), walls[i].getWallPositionY() + walls[i].getWallHeight());
			glVertex2f(walls[i].getWallPositionX() + walls[i].getWallWidth(), walls[i].getWallPositionY());
		}
	glEnd();
	
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h) {
	width = w;
	height = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(velocity * 50, 10, 0, (10 - velocity * 50) / 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void moveWall() {

	//Wall - move wall in "velocity"
	for (int i = 0; i < total; i++) {
		walls[i].setWallPositionX(walls[i].getWallPositionX() - velocity);
		if (walls[i].getWallPositionX() + walls[i].getWallWidth() < 0) {
			walls[i].setWallPositionX(-10);
			front = i;
		}
	}

	//Thief - change color
	if (walls[now].getWallPositionX() <= (thief.getTheifPositionX() + thief.getThiefSize())) {
		walls[now].setWallColor(thief.getTheifPose());
		thief.setTheifPose(rand() % 4);
		now++;
		sound.playsound(THIEFPASS);
	}

	//System - check if pass or fail
	if (walls[previous].getWallPositionX() <= (player.getPlayerPositionX() + player.getPlayerSize())) {

		switch (cheatMode)
		{
		case NO:
			if (player.getPlayerPose() == walls[previous].getWallColor()) {
				sound.playsound(PLAYERPASS);
				cout << "Pass" << endl;
				velocity += 0.01;
				interval -= 300;
				previousPlayerPosition = player.getPlayerPositionX();
				player.setPassCount(passCount++);
				thief.setPassCount(passCount++);
				pass = true;
			}
			else {
				sound.playsound(PLAYERNONPASS);
				cout << "Fail" << endl;
				failCount++;
				if (failCount >= 3)
					message(false);
				pass = false;
			}
			previous++;
			break;

		case ALL_PASS:
			sound.playsound(PLAYERPASS);
			cout << "Pass" << endl;
			velocity += 0.01;
			interval -= 300;
			previousPlayerPosition = player.getPlayerPositionX();
			pass = true;
			player.setPassCount(passCount++);
			thief.setPassCount(passCount++);
			previous++;
			break;

		case ALL_FAIL:
			sound.playsound(PLAYERNONPASS);
			cout << "Fail" << endl;
			failCount++;
			if (failCount >= 3)
				message(false);
			pass = false;
			previous++;
			break;
		}
	}

	//Player - move toward thief with moving animation
	if (pass) {
		player.setPlayerPositionX(player.getPlayerPositionX() + playerDistance);
		if ((player.getPlayerPositionX() - previousPlayerPosition) >= 1.0) {
			previousPlayerPosition = 0.0;
			pass = false;
			cameraZoomIn();
		}
	}

	//System - WIN if the distance between player and thief is less than a "threshold"
	//"threshold" == player.getPlayerSize()
	if (thief.getTheifPositionX() <= player.getPlayerPositionX() + player.getPlayerSize())
		message(true);

	//System - LOSE after 3 minutes in all pass mode
	if ((cheatMode == ALL_PASS) && (GetTickCount64() - allPassTimer > 1000 * 60 * 3))
		message(false);

	glutPostRedisplay();
}

void selectPose(int key, int x, int y) {
	sound.playsound(CHANGE);
	switch (key) {
	case GLUT_KEY_LEFT: //RED
		player.setPlayerPose(RED);
		break;
	case GLUT_KEY_RIGHT: //GREEN
		player.setPlayerPose(GREEN);
		break;
	case GLUT_KEY_UP: //BLUE
		player.setPlayerPose(BLUE);
		break;
	case GLUT_KEY_DOWN: //YELLOW
		player.setPlayerPose(YELLOW);
		break;
	}

	glutPostRedisplay();
}

void selectCheatMode(unsigned char key, int x, int y) {

	switch (key) {
	case 'c':
		if (cheatMode == ALL_PASS)
			cheatMode = NO;
		else
			cheatMode = ALL_PASS;
		break;
	case 'f':
		if (cheatMode == ALL_FAIL)
			cheatMode = NO;
		else
			cheatMode = ALL_FAIL;
		break;
	}

	if (cheatMode == ALL_PASS) {
		cout << "All Pass Mode" << endl;
		allPassTimer = GetTickCount64();
	}
	else if (cheatMode == ALL_FAIL)
		cout << "All Fail Mode" << endl;
	else
		cout << "No Cheat" << endl;

	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	//Initialize and open window
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();

	registerCallbackFunctions(argv);

	//Enter event processing loop
	glutMainLoop();
}

