#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(char* Name, char* sprite, int health, Vector2 tPos):Character(Name, sprite, health, tPos)
{
}

Enemy::Enemy(Vector2 tPos)
{
	objName = "Default Enemy";
	Health = 1;
	pos = tPos;
	spriteName = SPRITE4;
	width = 32;
	height = 32;
	maxFrames = SPRITE4SIZE;
	isAlive = true;
	direction = -1;
}

Enemy::Enemy()
{
	objName = "Default Enemy";
	Health = 5;
	pos = Vector2(0, 0);
	spriteName = SPRITE4;
	isAlive = false;
	width = 32;
	height = 32;
}

Enemy::~Enemy()
{
}


Vector2 Enemy::CalculateMovement()
{
	Vector2 force = Vector2(0, 0) * direction;
	return force;
}

Vector2 Enemy::Update()
{
	if (Health < 1)
	{
		isAlive = false;
	}
	pos += Vector2(0, -5 / GRAVITY);
	Character::Update();
	return Vector2(0, 0);
}