#include "Obstacle.h"

Obstacle::Obstacle(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng, brd, snake);
	
}

void Obstacle::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(2, brd.GetGridWidth() - 2);
	std::uniform_int_distribution<int> yDist(2, brd.GetGridHeight() - 2);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc));

	loc = newLoc;
}

void Obstacle::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

void Obstacle::Update()
{
	loc.Add(delta_loc);

	if (loc.x >= 61 || loc.x <= 0)
	{
		delta_loc.x *= -1;
	}

	if (loc.y >= 33 || loc.y <= 0)
	{
		delta_loc.y *= -1;
	}
}

const Location& Obstacle::GetLocation() const
{
	return loc;
}

