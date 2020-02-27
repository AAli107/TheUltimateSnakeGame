#pragma once

#include "Board.h"
#include <random>


class Snake
{
private:	
	class Segment
	{
	public:
		void InitHead( const Location& loc );
		void InitBody( Color c );
		void Follow( const Segment& next );
		void MoveBy( const Location& delta_loc );
		void Draw( Board& brd ) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake( const Location& loc);
	void MoveBy( const Location& delta_loc );
	Location GetNextHeadLocation( const Location& delta_loc ) const;
	Location GetHeadLocation() const;
	void Grow();
	void Draw( Board& brd ) const;
	bool IsInTileExceptEnd( const Location& target ) const;
	bool IsInTile( const Location& target ) const;
	std::random_device rng;

private:
	static constexpr Color headColor = Colors::MakeRGB(128, 200, 0);
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};