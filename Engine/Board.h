#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board( Graphics& gfx );
	void DrawCell(const Location& loc,Color c, bool isCircle, bool hasShading, bool hasShadow);
	void DrawCellPlain(const Location& loc, Color c);
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard( const Location& loc ) const;
	void DrawBorder();
	int GetTotalCells() const;
public:
	static constexpr Color borderColor = Colors::MakeRGB(89, 89, 89);
	static constexpr int dimension = 30;
	static constexpr int cellPadding = 2;
	static constexpr int width = 63;
	static constexpr int height = 35;
	static constexpr int borderWidth = 30;
	static constexpr int borderPadding = 0;
	static constexpr int x = 0;
	static constexpr int y = 0;
	Graphics& gfx;
};