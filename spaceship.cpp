#include "spaceship.hpp"

Spaceship::Spaceship()
{
	image = LoadTexture("Graphics/spaceship.png");
	position.x = ((GetScreenWidth() - image.width) / 2);
	position.y = (GetScreenHeight() - image.height);
}

Spaceship::~Spaceship()
{
	UnloadTexture(image);
}

void Spaceship::Draw()
{
	DrawTextureV(image, position, WHITE);
}

void Spaceship::MoveLeft()
{
	position.x -= moveVelocity;

	// Keep player within the game window boundaries
	if (position.x < 0)
	{
		position.x = 0;
	}
}

void Spaceship::MoveRight()
{
	position.x += moveVelocity;
	// Subtrack by image.width so spaceship sprite doesn't go offscreen
	if (position.x > GetScreenWidth() - image.width)
	{
		position.x = GetScreenWidth() - image.width;
	}

}