#include "stdafx.h"
#include "Character.h"

Character::Character(char* Name, char* sprite, int health, Vector2 tPos)
{
	objName = Name;
	Health = health;
	pos = tPos;
	spriteName = sprite;
	isEffectedByGravity = true;
	isAlive = true;
	width = 32;
	height = 32;
	maxTimer = 400;
	currTime = 1;
	dirMove = 0;
}

Character::Character()
{
	objName = "Null and Void";
	Health = 69;
	pos = Vector2(0, 0);
	spriteName = SPRITE3;
	isEffectedByGravity = true;
	isAlive = false;
	width = 32;
	height = 32;
	collisionCount = 0;
	maxTimer = 250;
	currTime = 1;
	dirMove = 0;
}

Character::~Character()
{

}

void Character::Draw(int offset)
{
	if (isAlive == true)
	{
		if (spriteBitmap != NULL)
		{
			if (direction == -1)
			{

				al_draw_bitmap_region(spriteBitmap, currFrame * width, 0, width, height, pos.x + offset, pos.y, ALLEGRO_FLIP_HORIZONTAL);
			}
			else
			{
				al_draw_bitmap_region(spriteBitmap, currFrame * width, 0, width, height, pos.x + offset, pos.y, 0);
			}
			if (frameCounter == 0)
			{
				currFrame++;
				currFrame = currFrame % (maxFrames);
			}
			frameCounter++;
			frameCounter = frameCounter % (9);
		}
		for (int i = 0; i < ARRAY_SIZE(assocProjectiles); i++)
		{
			if (assocProjectiles[i].alive == true)
			{
				assocProjectiles[i].Draw(offset);
			}
		}
	}
}

void Character::LoadSprite()
{
	spriteBitmap = al_load_bitmap(spriteName);

	if (spriteBitmap == NULL)
	{
		cout << "Failed to load Sprite";
	}
}

Vector2 Character::Gravity()
{
	Vector2 pForce = Vector2(0, 0);
	if (isEffectedByGravity)
	{
		pForce += Vector2(0, (6) / GRAVITY);
	}
	return pForce;
}

Vector2 Character::CalculateMovement()
{
	Vector2 force = Vector2(10, 0) * direction;

	return force;
}

void Character::Shoot()
{
	for (int i = 0; i < ARRAY_SIZE(assocProjectiles); i++)
	{
		if (assocProjectiles[i].alive != true)
		{
			assocProjectiles[i] = Projectile(pos, direction, objName);
			assocProjectiles[i].LoadSprite();
			return;
		}
	}
}

void Character::Update()
{
	if (isAlive)
	{
		for (int i = 0; i < ARRAY_SIZE(assocProjectiles); i++)
		{
			if (assocProjectiles[i].alive == true)
			{
				assocProjectiles[i].Move();
			}
		}
		currTime = (currTime + (1.0 / GRAVITY));
		if (currTime > maxTimer)
		{
			Shoot();
			currTime = 0;
		}
		pos += force;
		force = Vector2(0, 0);
		
	}
	
}
Vector2 Character::Jump()
{
	return Vector2(0, (float)-10.0);
}