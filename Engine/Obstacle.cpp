#include "Obstacle.h"

void Obstacle::Init(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng, brd, snake);
}

void Obstacle::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(6, brd.GetGridWidth() - 6);
	std::uniform_int_distribution<int> yDist(6, brd.GetGridHeight() - 6);
	std::uniform_int_distribution<int> ColorRange(100, 150);
	std::uniform_int_distribution<int> deltalocOffset(-1, 1);
	std::uniform_int_distribution<int> RandomBool(0, 1);

	//if (RandomBool(rng) == 1)
	//{
	//	isCircle = true;
	//}
	//else 
	//{
	//	isCircle = false;
	//}

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc));

	loc = newLoc;
	c = Colors::MakeRGB(ColorRange(rng), ColorRange(rng), ColorRange(rng));
	delta_loc.x = deltalocOffset(rng);
	delta_loc.y = deltalocOffset(rng);

	if (delta_loc.x == 0 || delta_loc.y == 0 || (loc.x >= 26 && loc.x <= 36 && loc.y >= 12 && loc.y <= 22))
	{
		Respawn(rng, brd, snake);
	}
}

void Obstacle::Draw(Board& brd) const
{
	if (isVisible)
	{
		brd.DrawCell(loc, c, false, true, true);
	}
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

void Obstacle::SetVisibility(bool visible)
{
	isVisible = visible;
}

