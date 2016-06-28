#include "stdafx.h"
#include "Projectile.h"

Projectile::Projectile()
{
	pos = Vector2(-10, -10);
	spriteName = SPRITE5;
	width = 0;
	height = 0;
	alive = false;
	moveDirection = -1;
	currFrame = 0; 
	maxTimer = 1;
	currTime = 0;
}

Projectile::Projectile(Vector2 tPos, int direction, char* sauce)
{
	pos = tPos;
	spriteName = SPRITE5;
	width = 16;
	height = 16;
	alive = true;
	moveDirection = direction;
	currFrame = 0;
	maxTimer = 130;
	currTime = 0;
	source = sauce;
}

Projectile::~Projectile()
{
	
}

void Projectile::Draw(int offset)
{
	if (alive == true)
	{
		if (moveDirection == -1)
		{
			al_draw_bitmap_region(spriteBitmap, currFrame * width, 0, width, height, pos.x+offset, pos.y, ALLEGRO_FLIP_HORIZONTAL);
		}
		else
		{
			al_draw_bitmap_region(spriteBitmap, currFrame * width, 0, width, height, pos.x+offset, pos.y, 0);
		}
		currFrame++;
		currFrame = currFrame %SPRITE5SIZE;
		if (frameCounter == 0)
		{
			currFrame++;
			currFrame = currFrame % (maxFrames);
		}
		frameCounter++;
		frameCounter = frameCounter % (20);
	}
}

void Projectile::LoadSprite()
{
	spriteBitmap = al_load_bitmap(spriteName);

	if (spriteBitmap == NULL)
	{
		cout << "Failed to load sprite";
	}
}

void Projectile::Move()
{
	if (currTime > maxTimer)
	{
		alive = false;
	}
	else
	{
		currTime = (currTime + (1.0 / GRAVITY));
	}
	Vector2 force = Vector2((4.0*moveDirection)/GRAVITY, 0*moveDirection);
	pos += force;
}
