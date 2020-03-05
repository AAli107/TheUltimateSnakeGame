#pragma once

#include "Graphics.h"

class SpriteCodex
{
public:
	void DrawTitle( int x,int y,Graphics& gfx );
public:
	Color titleTextColor = Colors::MakeRGB(255, 255, 255);
};