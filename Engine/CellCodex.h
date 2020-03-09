#pragma once

#include "Board.h"

class CellCodex
{
public:
	CellCodex(Board& brdCls);
	void DrawGameOver();
	void DrawReady();
	void DrawMainMenu();
private:
	Board& brd;
	Color textColor = Colors::MakeRGB(150, 200, 0);
	Color menuTextColor = Colors::MakeRGB(255, 255, 255);
};