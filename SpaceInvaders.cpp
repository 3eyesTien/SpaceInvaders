// SpaceInvaders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <raylib.h>
#include "spaceship.hpp"

int main()
{
	Color gray = { 29, 29, 27, 255 };
	int windowWidth = 750;
	int windowHeight = 700;

	InitWindow(windowWidth, windowHeight, "Space Invaders");
	SetTargetFPS(60);

	Spaceship spaceship = Spaceship();

	while (WindowShouldClose() == false) //  WindowShouldClose checks if esc key is pressed or close button on window is clicked
	{
		BeginDrawing();
		ClearBackground(gray);
		spaceship.Draw();

		EndDrawing();
	}

	CloseWindow();
}