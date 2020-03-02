#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd ) // Initilizes the game
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
	for (int i = 0; i < nDirt; i++)
	{
		dirt[i].Init(rng, brd);
	}
}

void Game::Go() // Single Frame sequence
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
		if (gameIsOver)
		{
			gameSpeedMultiplyer = 3.0f;
			snekMoveCounter += (gameSpeedMultiplyer * 60.0f) * dt;
			if (snekMoveCounter >= snekMovePeriod)
			{
				snekMoveCounter = 0.0f;
				snek.nSegments--;
			}
		}
		if( !gameIsOver )
		{
			if (wnd.kbd.KeyIsPressed('P')) // Pause Game
			{
				gameIsStarted = false;
			}

			// Controls the direction of the snake
			if (wnd.kbd.KeyIsPressed(VK_UP) && canChangeDirection) // Move snake Up
			{
				if (delta_loc.y != 1) 
				{
					canChangeDirection = false;
					delta_loc = { 0,-1 };
				}
			}
			if( wnd.kbd.KeyIsPressed(VK_DOWN) && canChangeDirection) // Move snake Down
			{
				if (delta_loc.y != -1)
				{
					canChangeDirection = false;
					delta_loc = { 0,1 };
				}
			}
			if( wnd.kbd.KeyIsPressed(VK_LEFT) && canChangeDirection) // Move snake Left
			{
				if (delta_loc.x != 1)
				{
					canChangeDirection = false;
					delta_loc = { -1,0 };
				}
			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT) && canChangeDirection) // Move snake Right
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
				std::uniform_int_distribution<int> BoolRand(0, 1);
				std::uniform_int_distribution<int> BoolRandLow(0, 3);
				std::uniform_real_distribution<float> DistP(0.5f, 1.5f);
				canChangeDirection = true;
				snekMoveCounter = 0.0f;

				for (int i = 0; i < nDirt; i++)
				{
					if (snek.IsInTile(dirt[i].GetLocation()))
					{
						dirt[i].RandomColor(rng);
					}
					for (int i2 = 0; i2 < nObstacle; i2++)
					{
						if (obstacle[i2].GetLocation() == dirt[i].GetLocation())
						{
							dirt[i].RandomColor(rng);
						}
					}
				}

				if (BoolRand(rng) == 1)
				{
					PlayBeep = true;
				}
				else
				{
					PlayBeep = false;
				}

				if (BoolRandLow(rng) == 1)
				{
					PlayNoise = true;
				}
				else
				{
					PlayNoise = false;
				}

				if (PlayBeep) 
				{
					Beep.Play(DistP(rng), 0.75f);
				}
				if (PlayNoise)
				{
					Noise.Play(DistP(rng), 0.75f);
				}

				// Updates all the obstacles in game
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
					Collect.Play();
				}
				snek.MoveBy( delta_loc );
				if( eating )
				{
					goal.Respawn( rng,brd,snek ); // Changes food location when snake eats it
				}
			}
		}
		else
		{
			if (gameOverPlay)
			{
				Death.Play();
				gameOverPlay = false;
			}
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) // Starts game when pressing enter
		{
			gameIsStarted = true;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE)) // Leaves game when pressing escape button
	{
		exit(0);
	}

	if(gameIsOver)
	{
		if (wnd.kbd.KeyIsPressed('R')) // Restarts game when pressing 'R' if game is over
		{
			snek.nSegments = 2;
			snek.Init({ 31, 17 });
			gameSpeedMultiplyer = 1.0f;
			delta_loc = { 1, 0 };
			gameIsOver = false;
			gameIsStarted = false;
			gameOverPlay = true;
			goal.Respawn(rng, brd, snek);
			for (int i = 0; i < nDirt; i++)
			{
				dirt[i].Init(rng, brd);
			}
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
		gfx.DrawRectDim(0, 0, gfx.ScreenWidth, gfx.ScreenHeight, bgColor); // Set Background Color

		for (int i = 0; i < nDirt; i++) // Draws Dirt on Background
		{
			dirt[i].Draw(brd);
		}

		goal.Draw(brd); // Draws food/goal
		snek.Draw(brd); // Draws Snake and it's segments
		brd.DrawBorder(); // Draws the game Border

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
	else // Draws Main menu image if game is not started
	{
		SpriteCodex::DrawTitle((gfx.ScreenWidth / 2) - 110, (gfx.ScreenHeight / 2) - 64,gfx );
	}
}