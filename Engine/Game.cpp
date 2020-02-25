#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng( std::random_device()() ),
	snek( {2,2} ),
	goal( rng,brd,snek )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if( gameIsStarted )
	{
		if( !gameIsOver )
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				if (delta_loc.y != 1) 
				{
					delta_loc = { 0,-1 };
				}
			}
			else if( wnd.kbd.KeyIsPressed( VK_DOWN ) )
			{
				if (delta_loc.y != -1)
				{
					delta_loc = { 0,1 };
				}
			}
			else if( wnd.kbd.KeyIsPressed( VK_LEFT ) )
			{
				if (delta_loc.x != 1)
				{
					delta_loc = { -1,0 };
				}
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				if (delta_loc.x != -1)
				{
					delta_loc = { 1,0 };
				}
			}

			++snekMoveCounter;
			if( snekMoveCounter >= snekMovePeriod )
			{
				snekMoveCounter = 0;
				const Location next = snek.GetNextHeadLocation( delta_loc );
				if( !brd.IsInsideBoard( next ) ||
					snek.IsInTileExceptEnd( next ) )
				{
					gameIsOver = true;
				}
				else
				{
					const bool eating = next == goal.GetLocation();
					if( eating )
					{
						if (snekMovePeriod >= 4) 
						{
							--snekMovePeriod;
						}
						snek.Grow();
					}
					snek.MoveBy( delta_loc );
					if( eating )
					{
						goal.Respawn( rng,brd,snek );
					}
				}
			}
		}
	}
	else
	{
		gameIsStarted = wnd.kbd.KeyIsPressed( VK_RETURN );
	}
}

void Game::ComposeFrame()
{
	if( gameIsStarted )
	{
		snek.Draw( brd );
		goal.Draw( brd );
		if( gameIsOver )
		{
			SpriteCodex::DrawGameOver((gfx.ScreenWidth / 2) - 42,(gfx.ScreenHeight / 2) - 32,gfx);
		}
		brd.DrawBorder();
	}
	else
	{
		SpriteCodex::DrawTitle((gfx.ScreenWidth / 2) - 110, (gfx.ScreenHeight / 2) - 64,gfx );
	}
}
