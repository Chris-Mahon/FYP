// 2DPlatformer.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Vector2.h"
#include "Stage.h"
#include "Projectile.h"
#include "2DPlatformer.h"

Player player = Player("Gizmo", 8, Vector2(40, 8*32));
Stage currStage = Stage();
Vector2 healthPlaces[9] = {Vector2(10, 51), Vector2(10, 46), Vector2(10, 41), Vector2(10, 36), Vector2(10, 31), Vector2(10, 26), Vector2(10, 21), Vector2(10, 16), Vector2(10, 11)};
ALLEGRO_BITMAP *healthBar; 
ALLEGRO_BITMAP *healthBit;

int main()
{
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY *display = al_create_display(480, 320);
	healthBar  = al_load_bitmap("Assets/HealthBar.png");
	healthBit = al_load_bitmap("Assets/HealthBit.png");
	
	player.LoadSprite();
	currStage.LoadAll();

	while (true)//for (int i = 0; i < 250; i++)
	{	
		if (rungameFlag == false)
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(healthBar, 0, 0, 0);
			for (int i = 0; i < std::fmin(ARRAY_SIZE(healthPlaces), player.Health); i++)//, player.Health); i++)
			{
				al_draw_bitmap(healthBit, healthPlaces[i].x, healthPlaces[i].y, 0);
			}

			al_flip_display();
		}
		else
		{
			if (pauseFlag == false)
			{
				player.controls.Update();
				currStage.Update(&player);
			}
			else
			{

			}
			DrawAssets();
		}
	}

	al_destroy_display(display);

    return 0;
}

void DrawAssets()
{
	al_clear_to_color(al_map_rgb(30, 30, 230));
	player.Draw(0);
	al_draw_bitmap(healthBar, 3, 3, 0);
	for (int i = 0; i < std::fmin(ARRAY_SIZE(healthPlaces), player.Health); i++)
	{
		al_draw_bitmap(healthBit, healthPlaces[i].x, healthPlaces[i].y, 0);
	}
	currStage.DrawAll();
	al_flip_display();
}
