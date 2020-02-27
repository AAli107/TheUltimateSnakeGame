#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng( std::random_device()() ),
	snek({31, 17}),
	goal(rng, brd, snek)
{
	for (int i = 0; i < nObstacle; i++)
	{
		obstacle[i].Init(rng, brd, snek);
	}
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
	const float dt = ft.Mark();

	if( gameIsStarted )
	{
		if( !gameIsOver )
		{
			if (wnd.kbd.KeyIsPressed(VK_SHIFT))
			{
				gameIsStarted = false;
			}

			if (wnd.kbd.KeyIsPressed(VK_UP) && canChangeOrientation)
			{
				if (delta_loc.y != 1) 
				{
					canChangeOrientation = false;
					delta_loc = { 0,-1 };
				}
			}
			else if( wnd.kbd.KeyIsPressed( VK_DOWN ) && canChangeOrientation)
			{
				if (delta_loc.y != -1)
				{
					canChangeOrientation = false;
					delta_loc = { 0,1 };
				}
			}
			else if( wnd.kbd.KeyIsPressed( VK_LEFT ) && canChangeOrientation)
			{
				if (delta_loc.x != 1)
				{
					canChangeOrientation = false;
					delta_loc = { -1,0 };
				}
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT) && canChangeOrientation)
			{
				if (delta_loc.x != -1)
				{
					canChangeOrientation = false;
					delta_loc = { 1,0 };
				}
			}

			for (int i = 0; i < nObstacle; i++)
			{
				if (snek.GetHeadLocation() == obstacle[i].GetLocation())
				{
					gameIsOver = true;
				}
			}

			const Location next = snek.GetNextHeadLocation(delta_loc);
			if (!brd.IsInsideBoard(next) ||
				snek.IsInTileExceptEnd(next))
			{
				gameIsOver = true;
			}

			snekMoveCounter += 60.0f * dt;
			if( snekMoveCounter >= snekMovePeriod )
			{
				canChangeOrientation = true;
				snekMoveCounter = 0.0f;
				for (int i = 0; i < nObstacle; i++)
				{
					obstacle[i].Update();
				}
				const Location next = snek.GetNextHeadLocation( delta_loc );
				if( !brd.IsInsideBoard( next ) ||
					snek.IsInTileExceptEnd( next ) )
				{
					gameIsOver = true;
				}
				const bool eating = next == goal.GetLocation();
				if( eating )
				{
					if (snekMovePeriod >= 4.0f)
					{
						snekMovePeriod -= 2.0f;
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
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			gameIsStarted = true;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE))
	{
		exit(0);
	}
}

void Game::ComposeFrame()
{
	if( gameIsStarted )
	{
		goal.Draw(brd);
		snek.Draw(brd);
		for (int i = 0; i < nObstacle; i++)
		{
			obstacle[i].Draw(brd);
		}
		brd.DrawBorder();
		if( gameIsOver )
		{
			SpriteCodex::DrawGameOver((gfx.ScreenWidth / 2) - 42,(gfx.ScreenHeight / 2) - 32,gfx);
		}
	}
	else
	{
		SpriteCodex::DrawTitle((gfx.ScreenWidth / 2) - 110, (gfx.ScreenHeight / 2) - 64,gfx );
	}
}