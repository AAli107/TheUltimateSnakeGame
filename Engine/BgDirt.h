#pragma once

#include "Snake.h"
#include "Board.h"
#include <random>

class BgDirt
{
public:
	void Init(std::mt19937& rng, const Board& brd);
	void Respawn(std::mt19937& rng, const Board& brd);
	void Draw(Board& brd) const;
	void SetLocation(int x, int y);
	void RandomColor(std::mt19937& rng);
	Location GetLocation() const;
private:
	Color c = Colors::MakeRGB(87, 46, 0);
	Location loc;
	Location delta_loc = { 1, 1 };
};