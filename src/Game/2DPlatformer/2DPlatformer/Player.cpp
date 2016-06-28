#include "stdafx.h"
#include "Player.h"

Player::Player(char* Name,  int health, Vector2 tPos):Character(Name, SPRITE1, health, tPos)
{
	width = 30;
	height = 34;
	controls = Controller();
	direction = 1;
	isGrounded = false;
}

Player::Player():Character()
{
}

Player::~Player()
{
	
}

Vector2 Player::CalculateMovement()
{
	Vector2 moveF = Vector2(0, 0);
	double dir, move, modifier;
	dir = direction;
	move = dirMove;
	modifier = GRAVITY;
	if (isGrounded)
	{
		moveF.x += (double)((2* move * dir)/GRAVITY);
	}
	return moveF;
}

Vector2 Player::Update()
{
	if (Health < 1)
	{
		pos = Vector2(35, 8 * 32);
		Health = 10;
	}

	if (controls.Left != 0)
	{
		dirMove = 1;
		direction = -1;

	}
	else if (controls.Right != 0)
	{
		dirMove = 1;
		direction = 1;
	}
	else
	{
		dirMove = 0;
	}
		
	if (isAlive)
	{
		for (int i = 0; i < ARRAY_SIZE(assocProjectiles); i++)
		{
			if (assocProjectiles[i].alive == true)
			{
				assocProjectiles[i].Move();
			}
		}
		currTime = (currTime + (1.0));
		if (currTime > maxTimer)
		{
			if (controls.B != 0)
			{
				Shoot();
			}
			currTime = 0;
		}
	}
	pos += force;
	force = Vector2(0, 0);
	return Vector2(0, 0);
}