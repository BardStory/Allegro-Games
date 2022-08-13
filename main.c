//include the header file
#include "header.h"

/*
Author: Joshua Bard
COMP 369 Assignment 3
*/


//perform basic collision detection
int inside(int x, int y, int left, int top, int right, int bottom)
{
	if (x > left && x < right && y > top && y < bottom)
		return 1;
	else
		return 0;
}

int main(void)
{
	allegro_init();
	install_keyboard();
	install_timer();
	srand(time(NULL));

	if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0) {
		return 1;
	}

	sounds[0] = load_sample("resources/sounds/music.wav");
	sounds[1] = load_sample("resources/sounds/fireball.wav");


	setupscreen();
	mainmenu();
	setupwizard();
	
	for (int i = 0; i < 5; i++) {
		setupgoblins(i);
		spawngoblins(i);
	}
	for (int i = 0; i < 3; i++) {
		setupdemons(i);
		spawndemons(i);
	}

	setupslime(0);
	spawnslime(0);

	//load the Mappy file
	if (MapLoad("resources/maps/map1.fmp") != 0)
	{
		allegro_message("Can't find map1.fmp");
		return 1;
	}
	int silence = 1;



	while (!gameover) {

		if (key[KEY_LCONTROL] && key[KEY_M]) {
			
			if (silence == 1) {
				play_sample(sounds[0], VOLUME, PAN, PITCH, TRUE);
				silence = 0;
				rest(20);

			}
			else {
				stop_sample(sounds[0]);
				silence = 1;
				rest(20);
			}
		}
		
		if (goblincounter == 5) {
			questcomplete = 1;
			ice = 1;
		}
		else if (demoncounter == 3) {
			questcomplete = 2;
			dark = 1;
		}
		else if (slimecounter ==1) {
			questcomplete = 3;
			reset();
		}
		
		movewizard();
		movespells(0);

		for (int i = 0; i < 5; i++) {
			movegoblins(i);
		}
		for (int i = 0; i < 3; i++) {
			movedemons(i);
		}
		moveslime(0);
		blit(back, buffer, 0, 0, 0, 0, back->w, back->h);
		escape();

		//Draw the map
		MapDrawBG(buffer, scrollx, scrolly, startx, starty, SCROLLW, SCROLLH);
		
		//tells the player what magic they are on
		if (dark == 1) {
			blit(magic_bmp[2], buffer, 0, 0, 590, 60, WIDTH, HEIGHT);
		}
		else if (ice ==1){
			blit(magic_bmp[1], buffer, 0, 0, 590, 60, WIDTH, HEIGHT);
		}
		else {
			blit(magic_bmp[0], buffer, 0, 0, 590, 60, WIDTH, HEIGHT);
		
		}
	
		drawspells(0);
		drawwizard();
		for (int i = 0; i < 5; i++) {
			drawgoblins(i);
		}
		for (int i = 0; i < 3; i++) {
			drawdemons(i);
		}
		drawslime(0);
	
		
		acquire_screen();
		blit(buffer, screen, 0, 0, 0, 0, WIDTH - 1, HEIGHT - 1);
		release_screen();

		getinput();

		rest(30);
	}

	destroy_bitmap(back);
	destroy_bitmap(buffer);

	MapFreeMem();
	allegro_exit();
	return 0;
}END_OF_MAIN()