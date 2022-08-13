#include "header.h"


void spawngoblins(int n) {
	
	goblins[n]->alive = 1;
	
}

void drawgoblins(int n) {

	
	int dir = goblins[n]->dir;
	int x = goblins[n]->x - 15;
	int y = goblins[n]->y - 15;

	if (!goblins[n]->alive) return;
	
	if (inside(x, y, scrollx, scrolly, scrollx + SCROLLW - goblins_bmp->w, scrolly + SCROLLH - goblins_bmp->h))
	{
		draw_sprite(buffer, goblins_bmp, startx + x - scrollx, starty + y - scrolly);
	}
}

void movegoblins(int n) {

	int x, y;
	
	x = goblins[n]->x;
	y = goblins[n]->y;

	//is the bullet active?
	if (!goblins[n]->alive) return;

	//move bullet
	goblins[n]->x += goblins[n]->xspeed;
	goblins[n]->y += goblins[n]->yspeed;
	x = goblins[n]->x;
	y = goblins[n]->y;

	int tempxspeed = rand() % 5;
	int tempyspeed = rand() % 5;
	
	
	if (x < 1500) {
		goblins[n]->xspeed = tempxspeed;
	}
	else if (x > 3000) {
		goblins[n]->xspeed = -tempxspeed;
	}

	if (y > 900) {
		goblins[n]->yspeed = -tempyspeed;
	}
	else if (y < 300) {
		goblins[n]->yspeed = tempyspeed;
	}

	//stay within the virtual screen
	//3200
	if (x < 0 || x > MAPW - 140 || y < 50 || y > MAPH - 6)
	{
		goblins[n]->xspeed = -tempxspeed;
		goblins[n]->yspeed = tempyspeed;
		
		return;
	}
}




void spawndemons(int n) {

	demons[n]->alive = 1;

}


void drawdemons(int n) {


	int dir = demons[n]->dir;
	int x = demons[n]->x - 15;
	int y = demons[n]->y - 15;

	if (!demons[n]->alive) return;

	if (inside(x, y, scrollx, scrolly, scrollx + SCROLLW - demons_bmp->w, scrolly + SCROLLH - demons_bmp->h))
	{
		draw_sprite(buffer, demons_bmp, startx + x - scrollx, starty + y - scrolly);
	}
}

void movedemons(int n) {

	int x, y;

	x = demons[n]->x;
	y = demons[n]->y;

	//is the bullet active?
	if (!demons[n]->alive) return;

	//move bullet
	demons[n]->x += demons[n]->xspeed;
	demons[n]->y += demons[n]->yspeed;
	x = demons[n]->x;
	y = demons[n]->y;

	int tempxspeed = rand() % 5;
	int tempyspeed = rand() % 5;


	if (x < 1000) {
		demons[n]->xspeed = tempxspeed;
	}
	else if (x > 3000) {
		demons[n]->xspeed = -tempxspeed;
	}

	if (y < 2000) {
		demons[n]->yspeed = tempyspeed;
	}
	else if (y > 1000) {
		demons[n]->yspeed = -tempyspeed;
	}

	//stay within the virtual screen
	//3200
	if (x < 0 || x > MAPW - 140 || y < 50 || y > MAPH - 6)
	{
		demons[n]->xspeed = -tempxspeed;
		demons[n]->yspeed = tempyspeed;

		return;
	}

}

void spawnslime(int n) {

	slime[n]->alive = 1;

}


void drawslime(int n) {


	int dir = slime[n]->dir;
	int x = slime[n]->x - 15;
	int y = slime[n]->y - 15;

	if (!slime[n]->alive) return;

	if (inside(x, y, scrollx, scrolly, scrollx + SCROLLW - slime_bmp->w, scrolly + SCROLLH - slime_bmp->h))
	{
		draw_sprite(buffer, slime_bmp, startx + x - scrollx, starty + y - scrolly);
	}
}

void moveslime(int n) {

	int x, y;

	x = slime[n]->x;
	y = slime[n]->y;

	//is the bullet active?
	if (!slime[n]->alive) return;

	//move bullet
	slime[n]->x += slime[n]->xspeed;
	slime[n]->y += slime[n]->yspeed;
	x = slime[n]->x;
	y = slime[n]->y;

	int tempxspeed = rand() % 5;
	int tempyspeed = rand() % 5;

	
	//stay within the virtual screen
	//3200
	if (x < 0 || x > MAPW - 140 || y < 50 || y > MAPH - 6)
	{
		if (slime[n]->xspeed > 0) {
			slime[n]->xspeed = -tempxspeed;
		}
		else {
			slime[n]->xspeed = tempxspeed;
		}
	
		//slime[n]->yspeed = tempyspeed;

		return;
	}

}