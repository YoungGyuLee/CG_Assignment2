#pragma once
#pragma comment(lib, "winmm")

#define STB_IMAGE_IMPLEMENTATION
#include "CPlayer.h"
#include "CThief.h"
#include "CThief.h"
#include "CWall.h"
#include "CSound.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <vector>
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <math.h>
#include <ctime>
#include <mmsystem.h>
#include "stb_image.h"
CONST TCHAR* lpszClass = _T("Message Box!\n");

//Game objects
CPlayer player;
CThief thief;
vector<CWall> walls;
CSound sound;

//Wall indices
int total = 0;		//Number of walls
int front = 0;		//Index of the leftmost wall
int previous = 0;	//Index of the wall just to the right of player
int now = 0;		//Index of the wall just to the left of theif

//System varables
int passCount = 0;
int failCount = 0;		//Number of fail
int interval = 3000;	//Wall creation interval
float velocity = 0.01;	//Wall velocity

//Timer variables
int startTickCount = 0;
int currentTickCount = 0;
int allPassTimer = 0;

//Player animation variables
bool pass = false;
float playerDistance = 0.1;
float previousPlayerPosition = 0.0;

//Cheatcode variables
enum CheatMode
{
	NO,
	ALL_PASS,
	ALL_FAIL
};
CheatMode cheatMode;

//Window variables
int width;
int height;

//Functions
void init();					// Initialize game states
void setObjectColor(int color);	// Set theif or wall pose(color)
void cameraZoomIn();			// Camera zoom-in
void message(bool success);		// End the game and show the message if pass or fail
void playSound();				// Play background or effect sound
void registerCallbackFunctions(char** argv); // Register input callback functions

//Input callback functions
void display();		// Display game objects (player, theif, wall, & ground)
void reshape(int w, int h); // reshape callback
void moveWall();	// Change the wall position
void selectPose(int key, int x, int y);	// Select player pose using keyboard input
void selectCheatMode(unsigned char Key, int x, int y); // Selec cheat mode using keyboard input
