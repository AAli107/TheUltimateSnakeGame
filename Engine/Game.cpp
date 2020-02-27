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
			if (wnd.kbd.KeyIsPressed('P')) // Pause Game
			{
				gameIsStarted = false;
			}

			// Controls the direction of the snake
			if (wnd.kbd.KeyIsPressed(VK_UP) && canChangeDirection)
			{
				if (delta_loc.y != 1) 
				{
					canChangeDirection = false;
					delta_loc = { 0,-1 };
				}
			}
			if( wnd.kbd.KeyIsPressed(VK_DOWN) && canChangeDirection)
			{
				if (delta_loc.y != -1)
				{
					canChangeDirection = false;
					delta_loc = { 0,1 };
				}
			}
			if( wnd.kbd.KeyIsPressed(VK_LEFT) && canChangeDirection)
			{
				if (delta_loc.x != 1)
				{
					canChangeDirection = false;
					delta_loc = { -1,0 };
				}
			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT) && canChangeDirection)
			{
				if (delta_loc.x != -1)
				{
					canChangeDirection = false;
					delta_loc = { 1,0 };
				}
			}

			// Sets game over to true if snake collides with an obstacle
			for (int i = 0; i < nObstacle; i++)
			{
				if (snek.GetHeadLocation() == obstacle[i].GetLocation())
				{
					gameIsOver = true;
				}
			}

			// Sets game over to true if snake collides with itself or the edge
			const Location next = snek.GetNextHeadLocation(delta_loc);
			if (!brd.IsInsideBoard(next) ||
				snek.IsInTileExceptEnd(next))
			{
				gameIsOver = true;
			}

			snekMoveCounter += (gameSpeedMultiplyer * 60.0f) * dt; // Controls Game Speed
			if( snekMoveCounter >= snekMovePeriod )
			{
				canChangeDirection = true;
				snekMoveCounter = 0.0f;
				
				// Updates all the obstacles
				for (int i = 0; i < nObstacle; i++)
				{
					obstacle[i].Update();
				}

				// Grows the snake when it eats the food and switches the location of the food
				const bool eating = next == goal.GetLocation();
				if( eating )
				{
					if (gameSpeedMultiplyer <= 8.0f)
					{
						gameSpeedMultiplyer += 0.1f;
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
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) // Start game
		{
			gameIsStarted = true;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE)) // Leaves game
	{
		exit(0);
	}

	if(gameIsOver)
	{
		if (wnd.kbd.KeyIsPressed('R'))
		{
			snek.nSegments = 2;
			snek.Init({ 31, 17 });
			gameSpeedMultiplyer = 1.0f;
			delta_loc = { 1, 0 };
			gameIsOver = false;
			gameIsStarted = false;
			for (int i = 0; i < nObstacle; i++)
			{
				obstacle[i].Init(rng, brd, snek);
			}
		}
	}
}

void Game::ComposeFrame()
{
	if( gameIsStarted )
	{
		goal.Draw(brd); // Draws food
		snek.Draw(brd); // Draws Snake and it's segments
		brd.DrawBorder(); // Draws the Border

		// Draws the obstacles
		for (int i = 0; i < nObstacle; i++)
		{
			obstacle[i].Draw(brd);
		}

		if( gameIsOver ) // Draws game over message if game ends
		{
			SpriteCodex::DrawGameOver((gfx.ScreenWidth / 2) - 42,(gfx.ScreenHeight / 2) - 32,gfx);
		}
	}
	else // Draws Main menu message
	{
		SpriteCodex::DrawTitle((gfx.ScreenWidth / 2) - 110, (gfx.ScreenHeight / 2) - 64,gfx );
	}
}