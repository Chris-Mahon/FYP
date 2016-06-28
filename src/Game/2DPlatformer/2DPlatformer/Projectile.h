#pragma once
#include "stdafx.h"
#include "Vector2.h"

class Projectile
{
	public:
		Projectile();
		Projectile(Vector2, int, char*);
		~Projectile();
		bool alive;
		char* source;
		char* spriteName;
		ALLEGRO_BITMAP *spriteBitmap;
		Vector2 pos;
		int moveDirection;
		int currFrame;
		int width, height;
		void Draw(int);
		void LoadSprite();
		void Move();
		int maxFrames = SPRITE5SIZE;
		int frameCounter = 3;
		int maxTimer;
		float currTime;
};

