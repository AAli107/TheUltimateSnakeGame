#include "Goal.h"

Goal::Goal( std::mt19937 & rng,const Board & brd,const Snake & snake )
{
	Respawn( rng,brd,snake );
}

void Goal::Respawn( std::mt19937 & rng,const Board & brd,const Snake & snake )
{
	std::uniform_int_distribution<int> xDist( 2, brd.GetGridWidth() - 2 );
	std::uniform_int_distribution<int> yDist( 2, brd.GetGridHeight() - 2 );
	std::uniform_int_distribution<int> ColorRange(150, 200);

	Location newLoc;
	do
	{
		newLoc.x = xDist( rng );
		newLoc.y = yDist( rng );
	} while( snake.IsInTile( newLoc ) );

	loc = newLoc;
	c = Colors::MakeRGB(ColorRange(rng), 0, 0);
}

void Goal::Draw( Board & brd ) const
{
	brd.DrawCell( loc,c );
}

const Location& Goal::GetLocation() const
{
	return loc;
}
