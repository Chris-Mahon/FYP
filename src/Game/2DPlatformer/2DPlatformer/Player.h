#pragma once
#include "Character.h"
#include "Controller.h"

class Player : public Character
{
	public:
		Player(char* Name, int health, Vector2 tPos);
		Player();
		~Player();
		Vector2 CalculateMovement();
		Controller controls;
		Vector2 Update();
};