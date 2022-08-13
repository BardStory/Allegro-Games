#pragma once
#ifndef _HEADER_H
#define _HEADER_H

#include <stdlib.h>

#include "allegro.h"
#include "mappyal.h"

//defines constants
#define MODE GFX_AUTODETECT_WINDOWED
#define WIDTH 640
#define HEIGHT 480
#define MAXSPEED 10
#define MINSPEED -10

#define TILEW 32
#define TILEH 32

#define MAP_ACROSS 100
#define MAP_DOWN 100

#define MAPW MAP_ACROSS * TILEW 
#define MAPH MAP_DOWN * TILEH

#define SCROLLW 540
#define SCROLLH 330

#define SPELLSPEED 30

#define PAN 128
#define PITCH 1000
#define VOLUME 128

typedef struct SPRITE
{
	int x, y;
	
	int dir, alive;
	
	int width, height;
	int xspeed, yspeed;
	int health;

}SPRITE;

SPRITE mywizard;
SPRITE *wizard;

SPRITE myspells[15];
SPRITE *spells[15];

SPRITE mygoblins[7];
SPRITE *goblins[7];
SPRITE mydemons[5];
SPRITE *demons[5];
SPRITE myslime[2];
SPRITE *slime[2];

BITMAP *goblins_bmp;
BITMAP *demons_bmp;
BITMAP *slime_bmp;

BITMAP *wizard_bmp[4];
BITMAP *spells_bmp[15];

BITMAP *back;
BITMAP *buffer;

BITMAP *magic_bmp[3];

SAMPLE *sounds[4];

int goblincounter, demoncounter, slimecounter;
int fire, ice, dark;

int redwiz, purplewiz, greenwiz;
int gameover;

int characterSelector;

int scrollx, scrolly;
int startx, starty;

int questcomplete;

int playmusic;

//visuals.c
void mainmenu();
void help();
void quest();
void reset();



//setup.c
void setupscreen();
void setupwizard();
void setupgoblins(int n);
void setupdemons(int n);
void setupslime(int n);

//wizard.c
void drawwizard();
void movewizard();

//getinput.c
void getinput();
void escape();
void moveleft();
void moveright();
void moveup();
void movedown();

//spells
void drawspells(int num);
void movespells(int num);
void firespell(int num);

//mobs.c
void drawgoblins(int n);
void movegoblins(int n);
void spawngoblins(int n);

void spawndemons(int n);
void drawdemons(int n);
void movedemons(int n);

void spawnslime(int n);
void drawslime(int n);
void moveslime(int n);

int inside(int, int, int, int, int, int);



#endif