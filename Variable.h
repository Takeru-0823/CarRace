#pragma once
#include "DxLib.h"
#include <stdlib.h>

const int WIDTH = 720, HEIGHT = 640;
const int CAR_MAX = 4;
const int CAR_W[CAR_MAX] = { 32, 26, 26, 40 };
const int CAR_H[CAR_MAX] = { 48, 48, 48, 100 };
const int COM_MAX = 8;
const int FUELSIZE = 12;

struct VECTOR2
{
	int x;
	int y;
};

struct CAR
{
	VECTOR2 pos;
	int type;
};

struct COM_CAR
{
	CAR car;
	bool flag;
};

struct FUEL
{
	VECTOR2 pos;
	int fuelAmount;
	int imgFuel;
};

struct INFO
{
	int timer;
	int bgY;
	int score;
	int highScore;
};


struct SOUND
{
	int bgm;
	int jin;
	int seFuel;
	int seCrash;
};


enum
{
	RED_CAR,
	YELLOW_CAR,
	BLUE_CAR,
	TRUCK
};

enum Scene
{
	TITLE,
	PLAY,
	OVER
};

