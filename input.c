#include "header.h"


void moveleft() {
	int tempx = wizard->xspeed;

	if (wizard->xspeed <= MINSPEED) {
		wizard->xspeed = MINSPEED;
	}
	else {
		wizard->xspeed--;
	}
}

void moveright() {
	int tempx = wizard->xspeed;

	if (tempx >= MAXSPEED) {
		wizard->xspeed = MAXSPEED;
	}
	else {
		wizard->xspeed++;
	}
}

void movedown() {
	int tempy = wizard->yspeed;

	if (tempy >= MAXSPEED) {
		wizard->yspeed = MAXSPEED;
	}
	else {
		wizard->yspeed++;
	}
}

void moveup() {
	int tempy = wizard->yspeed;

	if (tempy <= MINSPEED) {
		wizard->yspeed = MINSPEED;
	}
	else {
		wizard->yspeed--;
	}
}

void getinput()
{
	//hit ESC to quit
	if (key[KEY_ESC])   gameover = 1;

	//WASD - SPACE keys control tank 1
	if (key[KEY_W]) { moveup(); }
	if (key[KEY_D]) { moveright(); }
	if (key[KEY_A]) { moveleft(); }
	if (key[KEY_S]){ movedown(); }
	
	if (key[KEY_SPACE]) firespell(0);
	//arrow - ENTER keys control tank 2
	
	//if (key[KEY_UP] && key[KEY_RIGHT]) { wizard->dir = 1; }
	if (key[KEY_UP]) { wizard->dir = 0; }
	//if (key[KEY_RIGHT] && key[KEY_DOWN]) { wizard->dir = 3; }
	if (key[KEY_RIGHT]){ wizard->dir = 2; }
	//if (key[KEY_DOWN] && key[KEY_LEFT]) { wizard->dir = 5; }
	if (key[KEY_DOWN]){ wizard->dir = 4; }
	//if (key[KEY_LEFT] && key[KEY_UP]) { wizard->dir = 7; }
	if (key[KEY_LEFT]){ wizard->dir = 6; }


	if (key[KEY_H] && key[KEY_LCONTROL]) { help(); }
	if (key[KEY_Q] && key[KEY_LCONTROL]) { quest(); }

	
	if (key[KEY_H] && key[KEY_RCONTROL]) { help(); }
	if (key[KEY_Q] && key[KEY_RCONTROL]) { quest(); }


	//if (key[KEY_E] && key[KEY_LCONTROL]) { ice=1; }
	//if (key[KEY_R] && key[KEY_LCONTROL]) { dark = 1; }


	//short delay after keypress
	rest(20);

}

void escape()
{
	if (key[KEY_ESC]) {
		gameover = 1;
	}
}
