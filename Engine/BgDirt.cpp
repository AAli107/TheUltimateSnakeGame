#include "BgDirt.h"

BgDirt::BgDirt(std::mt19937& rng, const Board& brd, int x, int y)
{
	Respawn(rng, brd);
	SetLocation(x, y);
}

void BgDirt::Init(std::mt19937& rng, const Board& brd)
{
	Respawn(rng, brd);
}

void BgDirt::Respawn(std::mt19937& rng, const Board& brd)
{
	RandomColor(rng);
}

void BgDirt::Draw(Board& brd) const
{
	brd.DrawCellPlain(loc, c);
}

void BgDirt::SetLocation(int x, int y)
{
	loc.x = x;
	loc.y = y;
}

void BgDirt::RandomColor(std::mt19937& rng)
{
	std::uniform_int_distribution<int> ColorRange(-5, 5);
	int cOffset = ColorRange(rng);
	c = Colors::MakeRGB(87 + cOffset, 46 + cOffset, 0);
}

Location BgDirt::GetLocation() const
{
	return loc;
}
