// SpaceInvaders.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <raylib.h>
#include "game.hpp"

int main()
{
	Color gray = { 29, 29, 27, 255 };
	int windowWidth = 750;
	int windowHeight = 700;

	InitWindow(windowWidth, windowHeight, "Space Invaders");
	SetTargetFPS(60);

	Game game;

	while (WindowShouldClose() == false) //  WindowShouldClose checks if esc key is pressed or close button on window is clicked
	{
		game.HandleInput();
		game.Update();

		BeginDrawing();
		ClearBackground(gray);
		game.Draw();
		
		EndDrawing();
	}
	CloseWindow();
}

// To Do Checklist
/*
* 1. Setup Game Loop - Done
* 2. Create Spaceship - Done
* 3. Lasers (for Spaceship and Aliens) - Done
* 4. Create Obstacles - Work in progress
* 5. Create Aliens
* 6. Create Mystery Ship
* 7. Check for collisions
* 8. Game Over
* 9. Add Score
* 10.Add High-Score
* 11.Add Sounds
*/