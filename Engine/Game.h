#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include "Obstacle.h"
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
	bool gameIsOver = false;
	bool gameIsStarted = false;
	bool canChangeDirection = true;
	bool InhibitEnter = false;
	std::mt19937 rng;
	FrameTimer ft;
	Board brd;
	Snake snek;
	Obstacle obstacle[nObstacle];
	Location delta_loc = { 1,0 };
	Goal goal;
	/********************************/
};