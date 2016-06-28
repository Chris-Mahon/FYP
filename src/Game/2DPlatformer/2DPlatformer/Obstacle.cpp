#include "stdafx.h"
#include "Obstacle.h"


Obstacle::Obstacle()
{
	objName = "Block";
	spriteName = SPRITE2;
	isEffectedByGravity = false;
	width = GRIDSIZE;
	height = GRIDSIZE;
	pos = Vector2(-50, -150);
	isAlive = true;
}

Obstacle::Obstacle(Vector2 vect)
{
	objName = "Block";
	spriteName = SPRITE2;
	isEffectedByGravity = false;
	pos = vect;
	width = GRIDSIZE;
	height = GRIDSIZE;
	isAlive = true;
}

Obstacle::~Obstacle()
{
}
