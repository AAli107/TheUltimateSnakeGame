#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd ) // Initilizes the game
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng( std::random_device()() ),
	snek({31, 17}),
	goal(rng, brd, snek)
{
	brd.SetBorderColor(MenuBgColor);

	for (int i = 0; i < nObstacle; i++)
	{
		obstacle[i].Init(rng, brd, snek);
	}

	int i = 0;
	for (int y = 0; y < brd.GetGridHeight(); y++)
	{
		for (int x = 0; x < brd.GetGridWidth(); x++)
		{
			dirt[i] = BgDirt(rng, brd, x, y);
			i++;
		}
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
		for (int i = 0; i < nDirt; i++) // Draws Dirt Background
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
			DrawGameOver();
		}
	}
	else // Draws Main menu image if game is not started
	{
		gfx.DrawRectDim(0, 0, gfx.ScreenWidth, gfx.ScreenHeight, MenuBgColor, true); // Set Background Color of main menu
		spriteCodex.DrawTitle((gfx.ScreenWidth / 2) - 320, (gfx.ScreenHeight / 2) - 240,gfx ); // Menu Title
	}
}

void Game::DrawGameOver()
{
	brd.DrawCellPlain(Location({ 22,11 }), gameOverColor);
	brd.DrawCellPlain(Location({ 23,11 }), gameOverColor);
	brd.DrawCellPlain(Location({ 24,11 }), gameOverColor);
	brd.DrawCellPlain(Location({ 21,12 }), gameOverColor);
	brd.DrawCellPlain(Location({ 38,12 }), gameOverColor);
	brd.DrawCellPlain(Location({ 39,12 }), gameOverColor);
	brd.DrawCellPlain(Location({ 21,13 }), gameOverColor);
	brd.DrawCellPlain(Location({ 27,13 }), gameOverColor);
	brd.DrawCellPlain(Location({ 28,13 }), gameOverColor);
	brd.DrawCellPlain(Location({ 31,13 }), gameOverColor);
	brd.DrawCellPlain(Location({ 32,13 }), gameOverColor);
	brd.DrawCellPlain(Location({ 34,13 }), gameOverColor);
	brd.DrawCellPlain(Location({ 37,13 }), gameOverColor);
	brd.DrawCellPlain(Location({ 40,13 }), gameOverColor);
	brd.DrawCellPlain(Location({ 21,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 23,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 24,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 26,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 29,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 31,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 33,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 35,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 37,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 38,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 39,14 }), gameOverColor);
	brd.DrawCellPlain(Location({ 21,15 }), gameOverColor);
	brd.DrawCellPlain(Location({ 24,15 }), gameOverColor);
	brd.DrawCellPlain(Location({ 26,15 }), gameOverColor);
	brd.DrawCellPlain(Location({ 29,15 }), gameOverColor);
	brd.DrawCellPlain(Location({ 31,15 }), gameOverColor);
	brd.DrawCellPlain(Location({ 33,15 }), gameOverColor);
	brd.DrawCellPlain(Location({ 35,15 }), gameOverColor);
	brd.DrawCellPlain(Location({ 37,15 }), gameOverColor);
	brd.DrawCellPlain(Location({ 22,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 23,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 24,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 27,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 28,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 29,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 31,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 33,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 35,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 38,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 39,16 }), gameOverColor);
	brd.DrawCellPlain(Location({ 22,19 }), gameOverColor);
	brd.DrawCellPlain(Location({ 23,19 }), gameOverColor);
	brd.DrawCellPlain(Location({ 24,19 }), gameOverColor);
	brd.DrawCellPlain(Location({ 34,19 }), gameOverColor);
	brd.DrawCellPlain(Location({ 35,19 }), gameOverColor);
	brd.DrawCellPlain(Location({ 21,20 }), gameOverColor);
	brd.DrawCellPlain(Location({ 25,20 }), gameOverColor);
	brd.DrawCellPlain(Location({ 27,20 }), gameOverColor);
	brd.DrawCellPlain(Location({ 31,20 }), gameOverColor);
	brd.DrawCellPlain(Location({ 33,20 }), gameOverColor);
	brd.DrawCellPlain(Location({ 36,20 }), gameOverColor);
	brd.DrawCellPlain(Location({ 39,20 }), gameOverColor);
	brd.DrawCellPlain(Location({ 40,20 }), gameOverColor);
	brd.DrawCellPlain(Location({ 21,21 }), gameOverColor);
	brd.DrawCellPlain(Location({ 25,21 }), gameOverColor);
	brd.DrawCellPlain(Location({ 27,21 }), gameOverColor);
	brd.DrawCellPlain(Location({ 31,21 }), gameOverColor);
	brd.DrawCellPlain(Location({ 33,21 }), gameOverColor);
	brd.DrawCellPlain(Location({ 34,21 }), gameOverColor);
	brd.DrawCellPlain(Location({ 35,21 }), gameOverColor);
	brd.DrawCellPlain(Location({ 38,21 }), gameOverColor);
	brd.DrawCellPlain(Location({ 21,22 }), gameOverColor);
	brd.DrawCellPlain(Location({ 25,22 }), gameOverColor);
	brd.DrawCellPlain(Location({ 28,22 }), gameOverColor);
	brd.DrawCellPlain(Location({ 30,22 }), gameOverColor);
	brd.DrawCellPlain(Location({ 33,22 }), gameOverColor);
	brd.DrawCellPlain(Location({ 38,22 }), gameOverColor);
	brd.DrawCellPlain(Location({ 22,23 }), gameOverColor);
	brd.DrawCellPlain(Location({ 23,23 }), gameOverColor);
	brd.DrawCellPlain(Location({ 24,23 }), gameOverColor);
	brd.DrawCellPlain(Location({ 29,23 }), gameOverColor);
	brd.DrawCellPlain(Location({ 34,23 }), gameOverColor);
	brd.DrawCellPlain(Location({ 35,23 }), gameOverColor);
	brd.DrawCellPlain(Location({ 38,23 }), gameOverColor);
}