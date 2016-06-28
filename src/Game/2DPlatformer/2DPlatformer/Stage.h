#pragma once
#include "stdafx.h"
#include "LevelSegment.h"

class Stage
{
public:
	LevelSegment segments[SEGMENTS_PER_STAGE];

	Stage();
	~Stage();
	void DrawAll();
	void LoadAll();
	void Update();
	void Update(Player*);

};