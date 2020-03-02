#include "BgDirt.h"

void BgDirt::Init(std::mt19937& rng, const Board& brd)
{
	Respawn(rng, brd);
}

void BgDirt::Respawn(std::mt19937& rng, const Board& brd)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 2);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 2);
	std::uniform_int_distribution<int> ColorRange(-5, 5);
	std::uniform_int_distribution<int> RandomBool(0, 1);

	int cOffset = ColorRange(rng);

	c = Colors::MakeRGB(87 + cOffset, 46 + cOffset, 0);

	loc.x = xDist(rng);
	loc.y = yDist(rng);
}

void BgDirt::Draw(Board& brd) const
{
	brd.DrawCell(loc, c, false);
}

void BgDirt::SetLocation(int x, int y)
{
	loc.x = x;
	loc.y = y;
}
