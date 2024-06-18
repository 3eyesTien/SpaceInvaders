#pragma once
#include <vector>
#include "block.hpp"

class Obstacle
{
public:
	Obstacle(Vector2 position);
	void Draw();

	Vector2 position;
	std::vector<Block> blocks;
	// grid for the individual blocks in the obstacle. 2D array
	static std::vector<std::vector<int>> grid; // "static" allows for access even if it's not instantiated. Being access by game class

private:

};
