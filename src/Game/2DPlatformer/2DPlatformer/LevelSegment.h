#pragma once

#define NUMBEROFENEMIES 3
#define NUMBEROFOBSTACLES 20

#include "Obstacle.h"
#include "Enemy.h"
#include "Player.h"

class LevelSegment
{
public:
	LevelSegment();
	LevelSegment(int);
	~LevelSegment();
	int segmentOffset = 0;
	Enemy enemies[NUMBEROFENEMIES];
	Obstacle obstacles[NUMBEROFOBSTACLES];
	//void DrawAssets();
	void DrawAssets(int);
	void LoadAssets();
	void Update();
	void Update(Player*, int);
	Vector2 DetectCollision(int, Character*, Character[], Vector2, Vector2);
	Vector2 DetectCollision(int, Character*, Projectile*);
	Vector2 DetectCollision(int, Player*, Character*);
};

