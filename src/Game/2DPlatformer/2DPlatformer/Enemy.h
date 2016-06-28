#pragma once
#include "Character.h"

class Enemy : public Character
{
	public:
		Enemy(char*, char*, int, Vector2);
		Enemy(Vector2);
		Enemy();
		~Enemy();
		Vector2 CalculateMovement();
		Vector2 Update();
};

