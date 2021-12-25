#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570),
	goal(xDist(rng), yDist(rng)),
	meter(20,20)
{
	std::uniform_int_distribution<int>vDist(-2,2);//it was (-1,1)
	for (int i = 0; i < nPoo; ++i)
	{
		poos[i].Init(xDist (rng), yDist (rng), vDist(rng), vDist(rng));
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
	goal.UpdateColor();
	if( isStarted && !isGameOver)
	{
		//goal.UpdateColor(); stop the colors from updating if its gameover
		dude.Update(wnd.kbd);
		dude.ClampToScreen();

		for (int i = 0; i < nPoo; ++i)
		{
			poos[i].Update();
			if (poos[i].TestCollision(dude))
			{
				isGameOver = true;
			}
		}
		if (goal.TestCollision(dude))
		{
			goal.Respawn(xDist(rng), yDist(rng));
			meter.IncreaseLevel();
		}
	}
	else
	{
		if( wnd.kbd.KeyIsPressed( VK_RETURN ) )
		{
			isStarted = true;
		}
	}
}

int Game::GameOver()
{
	return 0;
}

void Game::DrawTitleScreen( int x,int y) 
{
	gfx.PutPixel(400, 300, 255, 255, 255);
}

void Game::ComposeFrame()
{
	if( !isStarted )
	{
		DrawTitleScreen( 325,211 );
	}
	else
	{
		goal.Draw(gfx);
		for (int i = 0; i < nPoo; ++i)
		{
				poos[i].Draw(gfx);
		}
		dude.Draw(gfx);
		if (isGameOver)
		{
			GameOver();
		}
		meter.Draw(gfx);
	}
}
