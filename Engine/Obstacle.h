#pragma once

#include "Snake.h"
#include "Board.h"
#include <random>

class Obstacle
{
public:
	void Init(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Draw(Board& brd) const;
	void Update();
	const Location& GetLocation() const;
	void SetVisibility(bool visible);
	bool HittingWall() const;
private:
	Color c = Colors::MakeRGB(64, 64, 64);
	Location loc;
	Location delta_loc = {1, 1};
	bool isCircle = false;
	bool isVisible = true;
	bool hittingWall = false;
};