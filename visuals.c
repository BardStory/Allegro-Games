#include "header.h"

void mainmenu() {

	const char *filename2 = "resources/maps/hello.bmp";
	BITMAP *background1;
	background1 = load_bitmap(filename2, NULL);
	blit(background1, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	int hold1 = 1;
	while (hold1) {
		if (key[KEY_SPACE]) {
			hold1 = 0;
		}
	}

	//const char *filename = "resources/maps/help.bmp";
	const char *filename = "resources/images/ForestWizards.bmp";
	BITMAP *background;
	background = load_bitmap(filename, NULL);
	blit(background, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

	int hold = 1;
	while (hold){

		
		if (key[KEY_W]) {
			greenwiz = 0;
			purplewiz = 0;
			redwiz = 1;
			hold = 0;
		}
		if (key[KEY_A]) {
			greenwiz = 0;
			purplewiz = 1;
			redwiz = 0;
			hold = 0;
		}
		if (key[KEY_D]) {
			greenwiz = 1;
			purplewiz = 0;
			redwiz = 0;
			hold = 0;
		}
		
		if (key[KEY_H] && key[KEY_LCONTROL]) { help(); }
		if (key[KEY_H] && key[KEY_RCONTROL]) { help(); }

		if (key[KEY_ESC]) {
			hold = 0;
		}
	}
	rectfill(screen, 0, 0, SCREEN_W, SCREEN_H, makecol(0, 0, 0));
	destroy_bitmap(background);
	destroy_bitmap(background1);
}


void reset() {
	//const char *filename = "resources/maps/help.bmp";
	const char *filename = "resources/maps/gameover.bmp";
	BITMAP *background;
	background = load_bitmap(filename, NULL);
	blit(background, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);


	goblincounter, demoncounter, slimecounter =0;
	fire, ice, dark =0;

	redwiz, purplewiz, greenwiz =0;
	gameover =0;

	characterSelector=0;

	scrollx, scrolly=0;
	startx, starty=0;

	int questcomplete;

}

void playsong() {

	
	if (playmusic == 1) {
		play_sample(sounds[0], VOLUME, PAN, PITCH, TRUE);
		//allegro_message("hello");
		playmusic = 0;
	}
	else {
		stop_sample(sounds[0]);
		playmusic = 1;
	}
}


void help() {
	const char *filename = "resources/maps/help.bmp";
	BITMAP *background;
	background = load_bitmap(filename, NULL);
	blit(background, screen, 0, 0, 50,80, 500, 400);

	int hold = 1;
	while (hold) {

		rest(50);
		if (key[KEY_H] && key[KEY_LCONTROL]) {
			hold = 0;
		}

		if (key[KEY_H] && key[KEY_RCONTROL]) {
			hold = 0;
		}
		if (key[KEY_ESC])   gameover = 1;
	}
	destroy_bitmap(background);
}

void quest() {
	
	const char *filename = "resources/maps/Quest1.bmp";

	if (questcomplete == 1) {
		filename = "resources/maps/Quest1complete.bmp";
	}
	if (questcomplete == 2) {
		filename = "resources/maps/Quest2complete.bmp";
	}
	if (questcomplete == 3) {
		filename = "resources/maps/Quest3complete.bmp";
	}

	BITMAP *background;
	background = load_bitmap(filename, NULL);
	blit(background, screen, 0, 0, 50, 80, 500, 400);

	
	int hold = 1;
	while (hold) {

		rest(50);
		if (key[KEY_Q] && key[KEY_LCONTROL]) {
			hold = 0;
		}

		if (key[KEY_Q] && key[KEY_RCONTROL]) {
			hold = 0;
		}
		if (key[KEY_ESC])  hold =0;
	}
	destroy_bitmap(background);
}