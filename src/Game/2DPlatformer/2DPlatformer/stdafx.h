// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <algorithm>
#define GRAVITY 10.0

#define SPRITE1 "Assets/Player.png"
#define SPRITE2 "Assets/Block.png"
#define SPRITE3 "Assets/Girder"
#define SPRITE4 "Assets/SlimeScaled.png"
#define SPRITE5 "Assets/Projectile.png"

#define SPRITE4SIZE 5
#define SPRITE5SIZE 4
#define SEGMENTS_PER_STAGE 2
#define GRIDSIZE 32

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;





// TODO: reference additional headers your program requires here
