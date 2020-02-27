#pragma once

#include "Snake.h"
#include "Board.h"
#include <random>

class Obstacle
{
public:
	Obstacle(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Draw(Board& brd) const;
	void Update();
	const Location& GetLocation() const;
private:
	static constexpr Color c = Colors::MakeRGB(64, 64, 64);
	Location loc;
	Location delta_loc = {1, 1};
};