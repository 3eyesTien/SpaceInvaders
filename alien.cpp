#include "alien.hpp"

Texture2D Alien::alienImages[3] = {};

Alien::Alien(int type, Vector2 position)
{
	this->type = type;
	this->position = position;

	if(alienImages[type -1].id == 0) // if true, alienImages array hasn't been initialized yet
	{
		switch (type) {
		case 1:
			alienImages[0] = LoadTexture("Graphics/alien_1.png");
			break;
		case 2:
			alienImages[1] = LoadTexture("Graphics/alien_2.png");
			break;
		case 3:
			alienImages[2] = LoadTexture("Graphics/alien_3.png");
			break;
		default:
			alienImages[0] = LoadTexture("Graphics/alien_1.png");
			break;
		}
	}
}

void Alien::Draw()
{
	DrawTextureV(alienImages[type - 1], position, WHITE);
}

void Alien::Update(int direction)
{
	position.x += direction;
}

int Alien::GetType()
{
	return type;
}

void Alien::UnloadImages() 
{
	for (int i = 0; i < 4; i++)
	{
		UnloadTexture(alienImages[i]);
	}
}