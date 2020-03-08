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

	if (gameIsStarted)
	{
		if (isReady)
		{
			if (gameIsOver)
			{
				gameSpeedMultiplyer = 3.5f;
				snekMoveCounter += (gameSpeedMultiplyer * 60.0f) * dt; // Game over timer
				if (snekMoveCounter >= snekMovePeriod)
				{
					snekMoveCounter = 0.0f;
					snek.nSegments--;
				}
			}
			if (!gameIsOver)
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
				if (wnd.kbd.KeyIsPressed(VK_DOWN) && canChangeDirection) // Move snake Down
				{
					if (delta_loc.y != -1)
					{
						canChangeDirection = false;
						delta_loc = { 0,1 };
					}
				}
				if (wnd.kbd.KeyIsPressed(VK_LEFT) && canChangeDirection) // Move snake Left
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

				snekMoveCounter += (gameSpeedMultiplyer * 60.0f) * dt; // Controls Game Speed
				if (snekMoveCounter >= snekMovePeriod)
				{
					std::uniform_int_distribution<int> BoolRand(0, 1);
					std::uniform_int_distribution<int> BoolRandLow(0, 3);
					std::uniform_real_distribution<float> DistP(0.5f, 1.5f);
					canChangeDirection = true;
					snekMoveCounter = 0.0f;

					// Sets game over to true if snake collides with itself or the edge
					const Location next = snek.GetNextHeadLocation(delta_loc);
					if (!brd.IsInsideBoard(next) ||
						snek.IsInTileExceptEnd(next))
					{
						gameIsOver = true;
					}

					// Randomizes Dirt color
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

					// Beep Random Bool
					if (BoolRand(rng) == 1)
					{
						PlayBeep = true;
					}
					else
					{
						PlayBeep = false;
					}

					// Noise Random Bool
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
						Beep.Play(DistP(rng), 0.75f); // Beep sound
					}
					if (PlayNoise)
					{
						Noise.Play(DistP(rng), 0.75f); // Noise sound
					}

					BgBeat.Play(DistP(rng), 0.75f); // Snake Moving sound

					// Updates all the obstacles in game
					for (int i = 0; i < nObstacle; i++)
					{
						obstacle[i].Update();
						if(obstacle[i].HittingWall())
						{
							Hit.Play(1.0f, 2.0f);
						}
					}

					// Grows the snake when it eats the food and switches the location of the food
					const bool eating = next == goal.GetLocation();
					if (eating)
					{
						if (gameSpeedMultiplyer <= 8.0f)
						{
							gameSpeedMultiplyer += 0.1f;
						}
						snek.Grow();
						Collect.Play();
					}

					snek.MoveBy(delta_loc); // Moves Snake around

					if (eating)
					{
						goal.Respawn(rng, brd, snek); // Changes food location when snake eats it
					}
				}
			}
			else
			{
				if (gameOverPlay) // Plays death sound once
				{
					Death.Play();
					gameOverPlay = false;
				}
			}
		}
		else
		{
			if (readyPlay)
			{
				Start.Play();
				readyPlay = false;
			}

			if (gameStartDelay > 0.0f)
			{
				gameStartDelay -= 1.0f * dt;
			}

			if (gameStartDelay <= 0.0f)
			{
				isReady = true;
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

	if (gameIsStarted && isReady)
	{
		if (wnd.kbd.KeyIsPressed('R')) // Restarts game when pressing 'R'
		{
			snek.nSegments = 2;
			snek.Init({ 31, 17 });
			gameSpeedMultiplyer = 1.0f;
			gameStartDelay = 2.1f;
			delta_loc = { 1, 0 };
			isReady = false;
			gameIsOver = false;
			gameIsStarted = false;
			gameOverPlay = true;
			readyPlay = true;
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
		
		if (isReady)
		{
			snek.Draw(brd); // Draws Snake and it's segments
		}

		// Draws the obstacles
		for (int i = 0; i < nObstacle; i++)
		{
			obstacle[i].Draw(brd);
		}

		brd.DrawBorder(); // Draws the game Border

		if( gameIsOver ) // Draws game over message if game ends
		{
			DrawGameOver();
		}
		
		if (!isReady)
		{
			DrawReady(); // Draws "Ready?" text before game starts
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
	brd.DrawCellPlain(Location({22, 11}), textColor);
	brd.DrawCellPlain(Location({23, 11}), textColor);
	brd.DrawCellPlain(Location({24, 11}), textColor);
	brd.DrawCellPlain(Location({21, 12}), textColor);
	brd.DrawCellPlain(Location({38, 12}), textColor);
	brd.DrawCellPlain(Location({39, 12}), textColor);
	brd.DrawCellPlain(Location({21, 13}), textColor);
	brd.DrawCellPlain(Location({27, 13}), textColor);
	brd.DrawCellPlain(Location({28, 13}), textColor);
	brd.DrawCellPlain(Location({31, 13}), textColor);
	brd.DrawCellPlain(Location({32, 13}), textColor);
	brd.DrawCellPlain(Location({34, 13}), textColor);
	brd.DrawCellPlain(Location({37, 13}), textColor);
	brd.DrawCellPlain(Location({40, 13}), textColor);
	brd.DrawCellPlain(Location({21, 14}), textColor);
	brd.DrawCellPlain(Location({23, 14}), textColor);
	brd.DrawCellPlain(Location({24, 14}), textColor);
	brd.DrawCellPlain(Location({26, 14}), textColor);
	brd.DrawCellPlain(Location({29, 14}), textColor);
	brd.DrawCellPlain(Location({31, 14}), textColor);
	brd.DrawCellPlain(Location({33, 14}), textColor);
	brd.DrawCellPlain(Location({35, 14}), textColor);
	brd.DrawCellPlain(Location({37, 14}), textColor);
	brd.DrawCellPlain(Location({38, 14}), textColor);
	brd.DrawCellPlain(Location({39, 14}), textColor);
	brd.DrawCellPlain(Location({21, 15}), textColor);
	brd.DrawCellPlain(Location({24, 15}), textColor);
	brd.DrawCellPlain(Location({26, 15}), textColor);
	brd.DrawCellPlain(Location({29, 15}), textColor);
	brd.DrawCellPlain(Location({31, 15}), textColor);
	brd.DrawCellPlain(Location({33, 15}), textColor);
	brd.DrawCellPlain(Location({35, 15}), textColor);
	brd.DrawCellPlain(Location({37, 15}), textColor);
	brd.DrawCellPlain(Location({22, 16}), textColor);
	brd.DrawCellPlain(Location({23, 16}), textColor);
	brd.DrawCellPlain(Location({24, 16}), textColor);
	brd.DrawCellPlain(Location({27, 16}), textColor);
	brd.DrawCellPlain(Location({28, 16}), textColor);
	brd.DrawCellPlain(Location({29, 16}), textColor);
	brd.DrawCellPlain(Location({31, 16}), textColor);
	brd.DrawCellPlain(Location({33, 16}), textColor);
	brd.DrawCellPlain(Location({35, 16}), textColor);
	brd.DrawCellPlain(Location({38, 16}), textColor);
	brd.DrawCellPlain(Location({39, 16}), textColor);
	brd.DrawCellPlain(Location({22, 19}), textColor);
	brd.DrawCellPlain(Location({23, 19}), textColor);
	brd.DrawCellPlain(Location({24, 19}), textColor);
	brd.DrawCellPlain(Location({34, 19}), textColor);
	brd.DrawCellPlain(Location({35, 19}), textColor);
	brd.DrawCellPlain(Location({21, 20}), textColor);
	brd.DrawCellPlain(Location({25, 20}), textColor);
	brd.DrawCellPlain(Location({27, 20}), textColor);
	brd.DrawCellPlain(Location({31, 20}), textColor);
	brd.DrawCellPlain(Location({33, 20}), textColor);
	brd.DrawCellPlain(Location({36, 20}), textColor);
	brd.DrawCellPlain(Location({39, 20}), textColor);
	brd.DrawCellPlain(Location({40, 20}), textColor);
	brd.DrawCellPlain(Location({21, 21}), textColor);
	brd.DrawCellPlain(Location({25, 21}), textColor);
	brd.DrawCellPlain(Location({27, 21}), textColor);
	brd.DrawCellPlain(Location({31, 21}), textColor);
	brd.DrawCellPlain(Location({33, 21}), textColor);
	brd.DrawCellPlain(Location({34, 21}), textColor);
	brd.DrawCellPlain(Location({35, 21}), textColor);
	brd.DrawCellPlain(Location({38, 21}), textColor);
	brd.DrawCellPlain(Location({21, 22}), textColor);
	brd.DrawCellPlain(Location({25, 22}), textColor);
	brd.DrawCellPlain(Location({28, 22}), textColor);
	brd.DrawCellPlain(Location({30, 22}), textColor);
	brd.DrawCellPlain(Location({33, 22}), textColor);
	brd.DrawCellPlain(Location({38, 22}), textColor);
	brd.DrawCellPlain(Location({22, 23}), textColor);
	brd.DrawCellPlain(Location({23, 23}), textColor);
	brd.DrawCellPlain(Location({24, 23}), textColor);
	brd.DrawCellPlain(Location({29, 23}), textColor);
	brd.DrawCellPlain(Location({34, 23}), textColor);
	brd.DrawCellPlain(Location({35, 23}), textColor);
	brd.DrawCellPlain(Location({38, 23}), textColor);
}

void Game::DrawReady()
{
	brd.DrawCellPlain(Location({19, 13}), textColor);
	brd.DrawCellPlain(Location({19, 14}), textColor);
	brd.DrawCellPlain(Location({19, 15}), textColor);
	brd.DrawCellPlain(Location({19, 16}), textColor);
	brd.DrawCellPlain(Location({19, 17}), textColor);
	brd.DrawCellPlain(Location({19, 18}), textColor);
	brd.DrawCellPlain(Location({19, 19}), textColor);
	brd.DrawCellPlain(Location({20, 13}), textColor);
	brd.DrawCellPlain(Location({20, 16}), textColor);
	brd.DrawCellPlain(Location({21, 13}), textColor);
	brd.DrawCellPlain(Location({21, 16}), textColor);
	brd.DrawCellPlain(Location({21, 17}), textColor);
	brd.DrawCellPlain(Location({22, 14}), textColor);
	brd.DrawCellPlain(Location({22, 15}), textColor);
	brd.DrawCellPlain(Location({22, 18}), textColor);
	brd.DrawCellPlain(Location({22, 19}), textColor);
	brd.DrawCellPlain(Location({24, 16}), textColor);
	brd.DrawCellPlain(Location({24, 17}), textColor);
	brd.DrawCellPlain(Location({24, 18}), textColor);
	brd.DrawCellPlain(Location({25, 15}), textColor);
	brd.DrawCellPlain(Location({25, 17}), textColor);
	brd.DrawCellPlain(Location({25, 19}), textColor);
	brd.DrawCellPlain(Location({26, 16}), textColor);
	brd.DrawCellPlain(Location({26, 17}), textColor);
	brd.DrawCellPlain(Location({26, 19}), textColor);
	brd.DrawCellPlain(Location({28, 17}), textColor);
	brd.DrawCellPlain(Location({28, 18}), textColor);
	brd.DrawCellPlain(Location({29, 16}), textColor);
	brd.DrawCellPlain(Location({29, 18}), textColor);
	brd.DrawCellPlain(Location({30, 16}), textColor);
	brd.DrawCellPlain(Location({30, 17}), textColor);
	brd.DrawCellPlain(Location({30, 18}), textColor);
	brd.DrawCellPlain(Location({30, 19}), textColor);
	brd.DrawCellPlain(Location({32, 17}), textColor);
	brd.DrawCellPlain(Location({32, 18}), textColor);
	brd.DrawCellPlain(Location({33, 16}), textColor);
	brd.DrawCellPlain(Location({33, 19}), textColor);
	brd.DrawCellPlain(Location({34, 16}), textColor);
	brd.DrawCellPlain(Location({34, 19}), textColor);
	brd.DrawCellPlain(Location({35, 13}), textColor);
	brd.DrawCellPlain(Location({35, 14}), textColor);
	brd.DrawCellPlain(Location({35, 15}), textColor);
	brd.DrawCellPlain(Location({35, 16}), textColor);
	brd.DrawCellPlain(Location({35, 17}), textColor);
	brd.DrawCellPlain(Location({35, 18}), textColor);
	brd.DrawCellPlain(Location({35, 19}), textColor);
	brd.DrawCellPlain(Location({37, 16}), textColor);
	brd.DrawCellPlain(Location({37, 17}), textColor);
	brd.DrawCellPlain(Location({37, 21}), textColor);
	brd.DrawCellPlain(Location({38, 18}), textColor);
	brd.DrawCellPlain(Location({38, 22}), textColor);
	brd.DrawCellPlain(Location({39, 16}), textColor);
	brd.DrawCellPlain(Location({39, 17}), textColor);
	brd.DrawCellPlain(Location({39, 18}), textColor);
	brd.DrawCellPlain(Location({39, 19}), textColor);
	brd.DrawCellPlain(Location({39, 20}), textColor);
	brd.DrawCellPlain(Location({39, 21}), textColor);
	brd.DrawCellPlain(Location({41, 14}), textColor);
	brd.DrawCellPlain(Location({42, 13}), textColor);
	brd.DrawCellPlain(Location({42, 17}), textColor);
	brd.DrawCellPlain(Location({42, 18}), textColor);
	brd.DrawCellPlain(Location({42, 20}), textColor);
	brd.DrawCellPlain(Location({43, 13}), textColor);
	brd.DrawCellPlain(Location({43, 16}), textColor);
	brd.DrawCellPlain(Location({44, 14}), textColor);
	brd.DrawCellPlain(Location({44, 15}), textColor);
}