#include "Board.h"
#include <assert.h>

Board::Board( Graphics& gfx )
	:
	gfx( gfx )
{}

void Board::DrawCell(const Location& loc, Color c, bool isCircle, bool hasShading, bool hasShadow)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	const int off_x = x + borderWidth + borderPadding;
	const int off_y = y + borderWidth + borderPadding;

	float shadowDarkness = 0.1f;

	Color shadowColor = Color(int(float(c.GetR()) * shadowDarkness), int(float(c.GetG()) * shadowDarkness), int(float(c.GetB()) * shadowDarkness));


	if (isCircle)
	{
		if (hasShadow)
		{
			gfx.DrawCircle((loc.x * dimension + (off_x - 1) + (dimension / 2)) - 2, (loc.y * dimension + (off_y + 4) + (dimension / 2)) - 2, (dimension / 2) - 2, shadowColor);
		}
		gfx.DrawCircle((loc.x * dimension + off_x + (dimension / 2) + cellPadding) - 2, (loc.y * dimension + off_y + (dimension / 2) + cellPadding) - 2, (dimension / 2) - 2, c);
	}
	else 
	{
		if (hasShadow)
		{
			gfx.DrawRectDim(loc.x * dimension + (off_x - 1), loc.y * dimension + (off_y + 3), dimension, dimension, shadowColor, false);
		}
		gfx.DrawRectDim(loc.x * dimension + off_x + cellPadding, loc.y * dimension + off_y + cellPadding, dimension - cellPadding, dimension - cellPadding, c, hasShading);
	}
}

void Board::DrawCellPlain(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	const int off_x = x + borderWidth + borderPadding;
	const int off_y = y + borderWidth + borderPadding;

	gfx.DrawRectDim(loc.x * dimension + off_x, loc.y * dimension + off_y, dimension, dimension, c, false);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard( const Location & loc ) const
{
	return loc.x >= 0 && loc.x < width - 1 &&
		loc.y >= 0 && loc.y < height - 1;
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = top + (borderWidth + borderPadding) + height * dimension;
	const int right = left + (borderWidth + borderPadding) + width * dimension;

	// top
	gfx.DrawRect( left,top,right,top + borderWidth,borderColor );
	// left
	gfx.DrawRect( left,top + borderWidth,left + borderWidth,bottom - borderWidth,borderColor );
	// right
	gfx.DrawRect( right - borderWidth,top + borderWidth,right,bottom - borderWidth,borderColor );
	// bottom
	gfx.DrawRect( left,bottom - borderWidth,right,bottom,borderColor );
}

int Board::GetTotalCells() const
{
	return width * height;
}

void Board::SetBorderColor(Color c)
{
	borderColor = c;
}
