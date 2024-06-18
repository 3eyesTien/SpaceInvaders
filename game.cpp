#include "game.hpp"

Game::Game() 
{

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