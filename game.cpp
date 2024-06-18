#include "game.hpp"

Game::Game() 
{
	obstacles = CreateObstacles();
	aliens = CreateAliens();
}

Game::~Game()
{

}

void Game::Update()
{
	for (auto& laser : spaceship.lasers)
	{
		laser.Update();
	}

	DeleteInactiveLasers();
}

void Game::Draw()
{
	spaceship.Draw();

	for (auto& laser : spaceship.lasers) 
	{
		laser.Draw();
	}

	for (auto& obstacle : obstacles)
	{
		obstacle.Draw();
	}

	for (auto& alien : aliens)
	{
		alien.Draw();
	}
}

void Game::HandleInput()
{
	if (IsKeyDown(KEY_LEFT))
	{
		spaceship.MoveLeft();
	}
	else if (IsKeyDown(KEY_RIGHT))
	{
		spaceship.MoveRight();
	}
	else if (IsKeyDown(KEY_SPACE))
	{
		spaceship.FireLaser();
	}
}

void Game::DeleteInactiveLasers()
{
	// Go through each item "iterator" from the beginning of the lasers vector to the end
	for (auto iterator = spaceship.lasers.begin(); iterator != spaceship.lasers.end();)
	{
		if (!iterator->active)
		{
			iterator = spaceship.lasers.erase(iterator); // remove the laser from the vector if it's inactive
		}
		else {
			++iterator;
		}
	}
}

std::vector<Obstacle> Game::CreateObstacles()
{
	int obstacleWidth = Obstacle::grid[0].size() * 3;
	float gap = (GetScreenWidth() - (4 * obstacleWidth)) / 5;

	for (int i = 0; i < 4; i++)
	{
		float offsetX = (i + 1) * gap + i * obstacleWidth;
		obstacles.push_back(Obstacle({ offsetX, float(GetScreenHeight() - 100) }));
	}
	return obstacles;
}

std::vector<Alien> Game::CreateAliens()
{
	int cellSize = 55;

	std::vector<Alien> aliens;
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			// Determine alien
			int alienType;
			if (row == 0)
			{
				alienType = 3;
			}
			else if (row == 1 || row == 2)
			{
				alienType = 2;
			}
			else {
				alienType = 1;
			}

			float x = 75 + col * cellSize;
			float y = 110 + row * cellSize;
			aliens.push_back(Alien(alienType, {x, y}));
		}
	}
	return aliens;
}