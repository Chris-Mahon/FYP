#include "stdafx.h"
#include "LevelSegment.h"


LevelSegment::LevelSegment()
{
}

LevelSegment::LevelSegment(int stageType)
{
	if (stageType == 0)
	{

		Enemy tempEnemies[NUMBEROFENEMIES] = {Enemy(Vector2(2 * GRIDSIZE, 7.5*GRIDSIZE)), Enemy(Vector2(3 * GRIDSIZE, 7.5*GRIDSIZE)), Enemy(Vector2(6*GRIDSIZE, 7.5*GRIDSIZE))};
		Obstacle tempObstacles[NUMBEROFOBSTACLES] = { Obstacle(Vector2(0 * GRIDSIZE, 6 * GRIDSIZE)), Obstacle(Vector2(0 * GRIDSIZE, 7 * GRIDSIZE)), Obstacle(Vector2(0 * GRIDSIZE, 8 * GRIDSIZE)),Obstacle(Vector2(0 * GRIDSIZE, 9 * GRIDSIZE)),
														Obstacle(Vector2(1 * GRIDSIZE, 9* GRIDSIZE)), Obstacle(Vector2(2 * GRIDSIZE, 9 * GRIDSIZE)), Obstacle(Vector2(3 * GRIDSIZE, 9 * GRIDSIZE)), Obstacle(Vector2(4 * GRIDSIZE, 9 * GRIDSIZE)), Obstacle(Vector2(5 * GRIDSIZE, 9 * GRIDSIZE)),Obstacle(Vector2(6 * GRIDSIZE, 9 * GRIDSIZE)),Obstacle(Vector2(7 * GRIDSIZE, 9 * GRIDSIZE)),Obstacle(Vector2(8 * GRIDSIZE, 9 * GRIDSIZE)),Obstacle(Vector2(9* GRIDSIZE, 9 * GRIDSIZE)),
														Obstacle(Vector2(10 * GRIDSIZE, 7 * GRIDSIZE))};
		for (int i = 0; i < ARRAY_SIZE(enemies); i++)
		{
			enemies[i] = tempEnemies[i];
		}
		for (int i = 0; i < ARRAY_SIZE(obstacles); i++)
		{
			obstacles[i] = tempObstacles[i];
		}
	}
	else if (stageType == 1)
	{

		Enemy tempEnemies[NUMBEROFENEMIES] = { Enemy(Vector2(2 * GRIDSIZE, 7.5 * GRIDSIZE)), Enemy(Vector2(3 * GRIDSIZE, 7.5 * GRIDSIZE)), Enemy(Vector2(6 * GRIDSIZE, 7.5 * GRIDSIZE)) };
		Obstacle tempObstacles[NUMBEROFOBSTACLES] = { Obstacle(Vector2(0 * GRIDSIZE, 7 * GRIDSIZE)),
			Obstacle(Vector2(1 * GRIDSIZE, 9 * GRIDSIZE)), Obstacle(Vector2(2 * GRIDSIZE, 9 * GRIDSIZE)), Obstacle(Vector2(3 * GRIDSIZE, 9 * GRIDSIZE)), Obstacle(Vector2(4 * GRIDSIZE, 9 * GRIDSIZE)), Obstacle(Vector2(5 * GRIDSIZE, 9 * GRIDSIZE)),Obstacle(Vector2(6 * GRIDSIZE, 9 * GRIDSIZE)),Obstacle(Vector2(7 * GRIDSIZE, 9 * GRIDSIZE)),Obstacle(Vector2(8 * GRIDSIZE, 9 * GRIDSIZE)),Obstacle(Vector2(9 * GRIDSIZE, 9 * GRIDSIZE)),
			Obstacle(Vector2(10 * GRIDSIZE, 6 * GRIDSIZE)), Obstacle(Vector2(10 * GRIDSIZE, 7 * GRIDSIZE)), Obstacle(Vector2(10 * GRIDSIZE, 8 * GRIDSIZE)),Obstacle(Vector2(10 * GRIDSIZE, 9 * GRIDSIZE)) };
		for (int i = 0; i < ARRAY_SIZE(enemies); i++)
		{
			enemies[i] = tempEnemies[i];
		}
		for (int i = 0; i < ARRAY_SIZE(obstacles); i++)
		{
			obstacles[i] = tempObstacles[i];
		}
	}
	else
	{
		Enemy tempEnemies[NUMBEROFENEMIES] = {Enemy(), Enemy(), Enemy()};
		for (int i = 0; i < ARRAY_SIZE(enemies); i++)
		{
			enemies[i] = tempEnemies[i];
		}
	}
}

LevelSegment::~LevelSegment()
{
}

void LevelSegment::DrawAssets(int offset)
{
	for (int i = 0; i < ARRAY_SIZE(enemies);i++)
	{
		enemies[i].Draw(offset);
	}
	for (int i = 0; i < ARRAY_SIZE(obstacles); i++)
	{
		obstacles[i].Draw(offset);
	}
}

void LevelSegment::LoadAssets()
{
	for (int i = 0; i < ARRAY_SIZE(enemies);i++)
	{
		enemies[i].LoadSprite();
	}
	for (int i = 0; i < ARRAY_SIZE(obstacles); i++)
	{
		obstacles[i].LoadSprite();
	}
}

void LevelSegment::Update()
{
	
}

void LevelSegment::Update(Player *player, int offset)
{
	
	for (int j = 0; j < GRAVITY; j++)
	{
		Vector2 gravity = player->Gravity();
		Vector2 moveForce = player->CalculateMovement();
		player->isGrounded = false;
		Vector2 force = DetectCollision(offset, player, obstacles, gravity, moveForce);
		for (int i = 0; i < ARRAY_SIZE(enemies); i++)
		{
			force += DetectCollision(offset, player, enemies[i].assocProjectiles);
			if (enemies[i].isAlive == true)
			{
				force += DetectCollision(offset, player, &enemies[i]);
				for (int j = 0; j < GRAVITY; j++)
				{
					Vector2 gravity = enemies[i].Gravity();
					Vector2 moveForce = enemies[i].CalculateMovement();
					Vector2 force = DetectCollision(offset, enemies + i, obstacles, gravity, moveForce);
					force += DetectCollision(offset, &enemies[i], player->assocProjectiles);
					enemies[i].force = gravity + moveForce + force;
					enemies[i].Update();
				}
			}
		}
		player->force = gravity + force + moveForce;
		player->Update();
	}
	for (int i = 0; i < ARRAY_SIZE(enemies); i++)
	{
		if (enemies[i].isAlive == true)
		{
			
		}
	}
}

Vector2 LevelSegment::DetectCollision(int off, Character *target, Character listOfAll[], Vector2 force, Vector2 secondForce)
{
	Vector2 tPos = target->pos;
	if (target->objName != "Gizmo")
	{
		tPos.x += off;
	}
	Vector2 altForce = Vector2(0, 0);
	for (int i = 0; i < NUMBEROFOBSTACLES; i++)
	{
		double distFX, distFY, minDistX, minDistY, distSX, distSY;
		distFX = tPos.DiffX(listOfAll[i].pos - force);
		distFY = tPos.DiffY(listOfAll[i].pos - force);
		
		minDistX = (target->width / 2) + (listOfAll[i].width / 2);
		minDistY = (target->height / 2) + (listOfAll[i].height / 2);

		double height = listOfAll[i].pos.y + (listOfAll[i].height / 2);
		double width = listOfAll[i].pos.x + (listOfAll[i].width / 2);
		if ((distFX > -minDistX && distFX < minDistX)|| tPos.x == listOfAll[i].pos.x+off)
		{
			if ((-distFY > -minDistY && -distFY < minDistY)|| tPos.y == listOfAll[i].pos.y)
			{
				if (tPos.y + target->height / 2 < height)
				{
					altForce += force*-1;
					target->isGrounded = true;
				}

				else if ((tPos.x + (target->width / 2) <= width) || (tPos.x - (target->width / 2) >= width))
				{
					altForce += force*-1;
				}
			}
		}
		distSX = tPos.DiffX(listOfAll[i].pos - secondForce);
		distSY = tPos.DiffY(listOfAll[i].pos - secondForce);
		if ((distSX > -minDistX && distSX < minDistX) || tPos.x == listOfAll[i].pos.x + off)
		{
			if ((-distSY > -minDistY && -distSY < minDistY) || tPos.y == listOfAll[i].pos.y)
			{
				if (tPos.y + target->height / 2 < height)
				{
					altForce += secondForce*-1;
				}

				else if ((tPos.x + (target->width / 2) <= width) || (tPos.x - (target->width / 2) >= width))
				{
					altForce += secondForce*-1;
				}
			}
		}
	}
	if (target->objName == "Gizmo")
	{
		return altForce;
	}
	return altForce;
}

Vector2 LevelSegment::DetectCollision(int off, Character *target, Projectile *projs)
{
	Vector2 tPos = target->pos;
	if (target->objName != "Gizmo")
	{
		tPos.x+=off;
	}
	if (projs->source== "Gizmo")
	{
		off=0;
	}
	for (int i = 0; i < 10; i++)
	{
		if ((projs + i)->alive)
		{
			double distX, distY, minDistX, minDistY;
			distX = tPos.DiffX((projs + i)->pos+off);
			distY = tPos.DiffY((projs + i)->pos);
			minDistX = (target->width / 2) + ((projs + i)->width / 2);
			minDistY = (target->height / 2) + ((projs + i)->height / 2);
			if ((distX > -minDistX && distX < minDistX) || tPos.x == (projs + i)->pos.x+off)
			{
				if ((-distY > -minDistY && -distY < minDistY) || tPos.y == (projs + i)->pos.y)
				{
					(projs + i)->alive = false;
					target->Health--;
				}
			}
		}
	}
	return Vector2(0, 0);
}

Vector2 LevelSegment::DetectCollision(int off, Player *target, Character *enemy)
{
	double distX, distY, minDistX, minDistY;
	distX = target->pos.DiffX(((enemy)->pos+off));
	distY = target->pos.DiffY(((enemy)->pos));
	minDistX = (target->width / 2) + ((enemy)->width / 2);
	minDistY = (target->height / 2) + ((enemy)->height / 2);
	if ((distX > -minDistX && distX < minDistX) || target->pos.x == enemy->pos.x+off)
	{
		if ((-distY > -minDistY && -distY < minDistY) || target->pos.y == enemy->pos.y)
		{
			enemy->isAlive = false;
			target->Health--;
		}
	
	}
	return Vector2(0, 0);
}