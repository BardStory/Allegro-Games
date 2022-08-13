#include "header.h"

void drawwizard() {

	int dir = wizard->dir;
	int x = wizard->x - 15;
	int y = wizard->y - 15;
	
	int tempx = wizard->xspeed;
	
	if (tempx > -1) {
		draw_sprite(buffer, wizard_bmp[3], x, y);
	}
	else {
		draw_sprite(buffer, wizard_bmp[2], x, y);
	}
	//allegro_message("we drawing wiz");
}

void movewizard() {

	int speedx = wizard->xspeed;
	int speedy = wizard->yspeed;

	if (speedx == 0) {
		scrollx += speedx;
	}
	if (speedx > 0) {
		scrollx += speedx;
	}
	if (speedx < 0) {
		scrollx += speedx;
	}
	
	if (speedy == 0) {
		scrolly += speedy;
	}
	if (speedy > 0) {
		scrolly += speedy;
	}
	if (speedy < 0) {
		scrolly += speedy;
	}

	if (scrollx < 0) {
		scrollx = 0;
		wizard->xspeed = 0;
	}
	else if (scrollx > mapwidth*mapblockwidth - SCROLLW) {
		scrollx = mapwidth * mapblockwidth - SCROLLW;
		wizard->xspeed = 0;
	}
	
	if (scrolly < 0) {
		scrolly = 0;
		wizard->yspeed = 0;
	}
	else if (scrolly > mapwidth*mapblockwidth - SCROLLH) {
		scrolly = mapwidth * mapblockwidth - SCROLLH;
		wizard->yspeed = 0;
	}
}
	