#include "stdafx.h"
#include "Stage.h"


Stage::Stage()
{
	for (int i = 0; i < ARRAY_SIZE(segments); i++)
	{
		segments[i] = LevelSegment(i);
	}
}

Stage::~Stage()
{
}

void Stage::DrawAll()
{
	for (int i = 0; i < ARRAY_SIZE(segments); i++)
	{
		segments[i].DrawAssets(i*(10*GRIDSIZE));
	}
}

void Stage::LoadAll()
{
	for (int i = 0; i < ARRAY_SIZE(segments); i++)
	{
		segments[i].LoadAssets();
	}
}

/*void Stage::Update()
{
	for (int i = 0; i < ARRAY_SIZE(segments); i++)
	{
		segments[i].Update();
	}
}*/

void Stage::Update(Player *player)
{
	for (int i = 0; i < ARRAY_SIZE(segments); i++)
	{
		segments[i].Update(player, i*(10*GRIDSIZE));
	}
}