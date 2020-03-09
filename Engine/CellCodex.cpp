#include "CellCodex.h"

CellCodex::CellCodex(Board& brdCls)
	:
	brd(brdCls)
{
}

void CellCodex::DrawGameOver()
{
	brd.DrawCellPlain(Location({ 22, 11 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 23, 11 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 24, 11 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 21, 12 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 38, 12 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 39, 12 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 21, 13 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 27, 13 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 28, 13 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 31, 13 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 32, 13 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 34, 13 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 37, 13 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 40, 13 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 21, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 23, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 24, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 26, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 29, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 31, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 33, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 35, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 37, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 38, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 39, 14 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 21, 15 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 24, 15 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 26, 15 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 29, 15 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 31, 15 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 33, 15 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 35, 15 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 37, 15 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 22, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 23, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 24, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 27, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 28, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 29, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 31, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 33, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 35, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 38, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 39, 16 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 22, 19 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 23, 19 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 24, 19 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 34, 19 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 35, 19 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 21, 20 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 25, 20 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 27, 20 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 31, 20 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 33, 20 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 36, 20 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 39, 20 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 40, 20 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 21, 21 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 25, 21 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 27, 21 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 31, 21 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 33, 21 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 34, 21 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 35, 21 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 38, 21 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 21, 22 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 25, 22 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 28, 22 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 30, 22 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 33, 22 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 38, 22 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 22, 23 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 23, 23 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 24, 23 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 29, 23 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 34, 23 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 35, 23 }), gameOverTextColor);
	brd.DrawCellPlain(Location({ 38, 23 }), gameOverTextColor);
}

void CellCodex::DrawReady()
{
	brd.DrawCellPlain(Location({ 19, 13 }), readyTextColor);
	brd.DrawCellPlain(Location({ 19, 14 }), readyTextColor);
	brd.DrawCellPlain(Location({ 19, 15 }), readyTextColor);
	brd.DrawCellPlain(Location({ 19, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 19, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 19, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 19, 19 }), readyTextColor);
	brd.DrawCellPlain(Location({ 20, 13 }), readyTextColor);
	brd.DrawCellPlain(Location({ 20, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 21, 13 }), readyTextColor);
	brd.DrawCellPlain(Location({ 21, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 21, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 22, 14 }), readyTextColor);
	brd.DrawCellPlain(Location({ 22, 15 }), readyTextColor);
	brd.DrawCellPlain(Location({ 22, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 22, 19 }), readyTextColor);
	brd.DrawCellPlain(Location({ 24, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 24, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 24, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 25, 15 }), readyTextColor);
	brd.DrawCellPlain(Location({ 25, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 25, 19 }), readyTextColor);
	brd.DrawCellPlain(Location({ 26, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 26, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 26, 19 }), readyTextColor);
	brd.DrawCellPlain(Location({ 28, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 28, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 29, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 29, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 30, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 30, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 30, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 30, 19 }), readyTextColor);
	brd.DrawCellPlain(Location({ 32, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 32, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 33, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 33, 19 }), readyTextColor);
	brd.DrawCellPlain(Location({ 34, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 34, 19 }), readyTextColor);
	brd.DrawCellPlain(Location({ 35, 13 }), readyTextColor);
	brd.DrawCellPlain(Location({ 35, 14 }), readyTextColor);
	brd.DrawCellPlain(Location({ 35, 15 }), readyTextColor);
	brd.DrawCellPlain(Location({ 35, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 35, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 35, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 35, 19 }), readyTextColor);
	brd.DrawCellPlain(Location({ 37, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 37, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 37, 21 }), readyTextColor);
	brd.DrawCellPlain(Location({ 38, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 38, 22 }), readyTextColor);
	brd.DrawCellPlain(Location({ 39, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 39, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 39, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 39, 19 }), readyTextColor);
	brd.DrawCellPlain(Location({ 39, 20 }), readyTextColor);
	brd.DrawCellPlain(Location({ 39, 21 }), readyTextColor);
	brd.DrawCellPlain(Location({ 41, 14 }), readyTextColor);
	brd.DrawCellPlain(Location({ 42, 13 }), readyTextColor);
	brd.DrawCellPlain(Location({ 42, 17 }), readyTextColor);
	brd.DrawCellPlain(Location({ 42, 18 }), readyTextColor);
	brd.DrawCellPlain(Location({ 42, 20 }), readyTextColor);
	brd.DrawCellPlain(Location({ 43, 13 }), readyTextColor);
	brd.DrawCellPlain(Location({ 43, 16 }), readyTextColor);
	brd.DrawCellPlain(Location({ 44, 14 }), readyTextColor);
	brd.DrawCellPlain(Location({ 44, 15 }), readyTextColor);
}

void CellCodex::DrawMainMenu()
{
	brd.DrawCellPlain(Location({ 8, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 9, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 9, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 9, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 9, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 9, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 10, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 11, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 11, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 11, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 11, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 11, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 11, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 12, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 13, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 13, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 13, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 13, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 13, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 13, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 14, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 14, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 14, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 14, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 14, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 14, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 14, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 15, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 16, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 16, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 16, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 16, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 16, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 17, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 17, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 17, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 17, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 17, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 17, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 17, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 18, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 18, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 18, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 18, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 18, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 18, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 18, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 18, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 18, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 18, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 19, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 20, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 20, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 20, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 20, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 21, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 21, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 21, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 21, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 21, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 22, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 22, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 22, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 22, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 22, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 22, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 22, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 23, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 24, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 24, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 24, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 24, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 24, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 24, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 25, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 25, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 25, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 25, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 25, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 25, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 25, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 26, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 27, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 27, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 27, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 27, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 27, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 27, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 28, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 29, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 29, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 30, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 30, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 30, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 30, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 30, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 30, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 30, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 31, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 31, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 31, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 31, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 31, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 31, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 31, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 31, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 31, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 32, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 32, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 32, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 32, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 32, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 33, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 33, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 33, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 33, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 33, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 33, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 34, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 34, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 34, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 34, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 34, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 34, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 35, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 35, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 35, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 35, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 35, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 35, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 35, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 35, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 35, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 36, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 36, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 36, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 36, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 36, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 36, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 36, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 36, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 37, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 37, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 37, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 37, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 37, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 37, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 37, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 37, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 38, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 38, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 38, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 38, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 38, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 38, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 38, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 38, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 39, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 39, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 39, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 39, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 39, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 39, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 39, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 39, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 40, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 40, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 40, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 40, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 40, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 41, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 42, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 42, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 42, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 42, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 42, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 42, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 43, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 43, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 43, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 43, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 43, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 43, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 44, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 44, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 44, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 44, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 44, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 44, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 44, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 44, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 44, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 44, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 45, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 45, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 45, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 45, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 45, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 45, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 45, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 46, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 46, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 46, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 46, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 46, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 46, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 46, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 47, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 47, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 47, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 47, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 47, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 47, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 47, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 47, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 47, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 48, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 48, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 48, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 48, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 48, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 48, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 48, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 49, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 50, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 50, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 12 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 14 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 51, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 5 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 7 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 24 }), menuTextColor);
	brd.DrawCellPlain(Location({ 52, 26 }), menuTextColor);
	brd.DrawCellPlain(Location({ 53, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 53, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 53, 8 }), menuTextColor);
	brd.DrawCellPlain(Location({ 53, 11 }), menuTextColor);
	brd.DrawCellPlain(Location({ 53, 13 }), menuTextColor);
	brd.DrawCellPlain(Location({ 53, 15 }), menuTextColor);
	brd.DrawCellPlain(Location({ 53, 19 }), menuTextColor);
	brd.DrawCellPlain(Location({ 53, 25 }), menuTextColor);
	brd.DrawCellPlain(Location({ 53, 27 }), menuTextColor);
	brd.DrawCellPlain(Location({ 53, 28 }), menuTextColor);
	brd.DrawCellPlain(Location({ 54, 4 }), menuTextColor);
	brd.DrawCellPlain(Location({ 54, 6 }), menuTextColor);
	brd.DrawCellPlain(Location({ 54, 8 }), menuTextColor);
}
