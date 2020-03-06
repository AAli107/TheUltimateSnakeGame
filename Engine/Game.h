#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Sound.h"
#include "Board.h"
#include "SpriteCodex.h"
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
	void DrawGameOver();
	void DrawReady();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	float snekMovePeriod = 15.0f;
	float snekMoveCounter = 0.0f;
	float gameSpeedMultiplyer = 1.0f;
	float gameStartDelay = 2.1f;

	static const int nObstacle = 5;
	static const int nDirt = 2205;

	bool gameIsOver = false;
	bool gameIsStarted = false;
	bool canChangeDirection = true;
	bool InhibitEnter = false;
	bool gameOverPlay = true;
	bool readyPlay = true;
	bool PlayBeep = false;
	bool PlayNoise = false;
	bool isReady = false;

	SpriteCodex spriteCodex;
	std::mt19937 rng;
	FrameTimer ft;
	Board brd;

	Snake snek;
	Goal goal;
	Obstacle obstacle[nObstacle];
	BgDirt dirt[nDirt];

	Location delta_loc = {1, 0};

	Color textColor = Colors::MakeRGB(150, 200, 0);
	Color MenuBgColor = Colors::MakeRGB(89, 89, 89);

	Sound Collect = L"Sounds\\SnakeEat.wav";
	Sound Death = L"Sounds\\LoseGame.wav";
	Sound Beep = L"Sounds\\Beep.wav";
	Sound Noise = L"Sounds\\Noise.wav";
	Sound Start = L"Sounds\\StartMusic.wav";
	/********************************/
};