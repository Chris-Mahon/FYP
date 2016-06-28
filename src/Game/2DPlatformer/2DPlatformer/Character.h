#pragma once
#include "stdafx.h"
#include "Vector2.h"
#include "Projectile.h"

class Character
{
	public:
		char* objName;
		char* spriteName;
		ALLEGRO_BITMAP *spriteBitmap;
		Projectile assocProjectiles[10];
		int Health;
		int collisionCount = 0;
		int direction;
		int currFrame = 0;
		int maxFrames = 1;
		int frameCounter = 3;
		bool isEffectedByGravity;
		bool isGrounded;
		Vector2 pos;
		Vector2 force;
		bool isAlive;
		int maxTimer;
		int dirMove;
		float currTime;


		float width, height;

		void Shoot();
		//void Draw();
		void Draw(int);
		void LoadSprite();
		void Update();
		Vector2 CalculateMovement();
		Vector2 Gravity();
		Vector2 Jump();
		Character(char* Name, char* sprite, int health, Vector2 tPos);
		Character();
		~Character();
};