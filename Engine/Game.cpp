#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd ) // Initilizes the game
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng( std::random_device()() ),
	snek({31, 17}),
	goal(rng, brd, snek),
	cellCodex(brd)
{
	InitializeGame();
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
				gameSpeedMultiplyer = 3.1f;
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
					Select.Play();
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

						goal.Respawn(rng, brd, snek);
					}
					snek.MoveBy(delta_loc); // Moves Snake around
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
	else if (wnd.kbd.KeyIsPressed(VK_RETURN)) // Starts game when pressing enter
	{
		gameIsStarted = true;
		Select.Play();
	}

	if (wnd.kbd.KeyIsPressed(VK_ESCAPE)) // Leaves game when pressing escape button
	{
		exit(0);
		Select.Play();
	}

	if (gameIsStarted && isReady && wnd.kbd.KeyIsPressed('R')) // Restarts game when pressing 'R'
	{
		InitializeGame();
		Select.Play();
	}
}

void Game::InitializeGame()
{
	brd.SetBorderColor(MenuBgColor);
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
	{
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
			cellCodex.DrawGameOver();
		}
		
		if (!isReady)
		{
			cellCodex.DrawReady(); // Draws "Ready?" text before game starts
		}
	}
	else // Draws Main menu image if game is not started
	{
		gfx.DrawRectDim(0, 0, gfx.ScreenWidth, gfx.ScreenHeight, MenuBgColor, false); // Set Background Color of main menu
		cellCodex.DrawMainMenu(); // Menu Title
	}
}