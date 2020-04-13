#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <vector>

//player, thief pose and wall color
#define RED 0
#define GREEN 1
#define BLUE 2
#define YELLOW 3
#define BLACK 4

//sound track
#define BGM 5
#define THIEFPASS 6
#define PLAYERPASS 7
#define PLAYERNONPASS 8
#define WIN 9
#define LOSE 10
#define CHANGE 11

//left, right
#define LEFT 12
#define RIGHT 13

//leg, thigh velocity rate
//velocity is faster if it is smaller
#define VELORATE 20
#define ADJUST 1