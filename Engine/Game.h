#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Sound.h"
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include "Obstacle.h"
#include "BgDirt.h"
#include "FrameTimer.h"
#include <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	float snekMovePeriod = 15.0f;
	float snekMoveCounter = 0.0f;
	float gameSpeedMultiplyer = 1.0f;
	static const int nObstacle = 5;
	static const int nDirt = 2205;
	bool gameIsOver = false;
	bool gameIsStarted = false;
	bool canChangeDirection = true;
	bool InhibitEnter = false;
	bool gameOverPlay = true;
	bool PlayBeep = false;
	bool PlayNoise = false;
	std::mt19937 rng;
	FrameTimer ft;
	Board brd;
	Snake snek;
	Obstacle obstacle[nObstacle];
	BgDirt dirt[nDirt];
	Location delta_loc = {1, 0};
	Goal goal;
	Color bgColor = Colors::MakeRGB(87, 46, 0);
	Sound Collect = L"Sounds\\SnakeEat.wav";
	Sound Death = L"Sounds\\LoseGame.wav";
	Sound Beep = L"Sounds\\Beep.wav";
	Sound Noise = L"Sounds\\Noise.wav";
	/********************************/
};