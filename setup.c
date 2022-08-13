#include "header.h"


void setupwizard() {
	BITMAP *temp;
	BITMAP *temp1;

	wizard = &mywizard;
	wizard->x = 30;
	wizard->y = 40;
	wizard->xspeed = 0;
	wizard->yspeed = 0;
	wizard->dir = 2;
	
	if (redwiz == 1) {
		temp = load_bitmap("resources/sprites/red.bmp", NULL);
	}
	else if (purplewiz == 1) {
		temp = load_bitmap("resources/sprites/purple.bmp", NULL);
	}
	else {
		temp = load_bitmap("resources/sprites/green.bmp", NULL);
	}
	
	if (redwiz == 1) {
		temp1 = load_bitmap("resources/sprites/redright.bmp", NULL);
	}
	else if (purplewiz == 1) {
		temp1 = load_bitmap("resources/sprites/purpleright.bmp", NULL);
	}
	else {
		temp1 = load_bitmap("resources/sprites/greenright.bmp", NULL);
	}


	wizard_bmp[1] = temp;
	wizard_bmp[0] = temp1;

	wizard_bmp[2] = create_bitmap(35, 35);
	clear_to_color(wizard_bmp[2], makecol(255, 0, 255));
	rotate_sprite(wizard_bmp[2], wizard_bmp[1],0,0,itofix(0));

	wizard_bmp[3] = create_bitmap(35, 35);
	clear_to_color(wizard_bmp[3], makecol(255, 0, 255));
	rotate_sprite(wizard_bmp[3], wizard_bmp[0], 0, 0, itofix(0));

	destroy_bitmap(temp);
	destroy_bitmap(temp1);


	if (spells_bmp[0] == NULL) {
		spells_bmp[0] = load_bitmap("resources/sprites/fireright.bmp", NULL);
		spells_bmp[1] = load_bitmap("resources/sprites/firedown.bmp", NULL);
		spells_bmp[2] = load_bitmap("resources/sprites/fireleft.bmp", NULL);
		spells_bmp[3] = load_bitmap("resources/sprites/fireup.bmp", NULL);
		spells_bmp[4] = load_bitmap("resources/sprites/iceright.bmp", NULL);
		spells_bmp[5] = load_bitmap("resources/sprites/icedown.bmp", NULL);
		spells_bmp[6] = load_bitmap("resources/sprites/iceleft.bmp", NULL);
		spells_bmp[7] = load_bitmap("resources/sprites/iceup.bmp", NULL);
		spells_bmp[8] = load_bitmap("resources/sprites/darkright.bmp", NULL);
		spells_bmp[9] = load_bitmap("resources/sprites/darkdown.bmp", NULL);
		spells_bmp[10] = load_bitmap("resources/sprites/darkup.bmp", NULL);
		spells_bmp[11] = load_bitmap("resources/sprites/darkleft.bmp", NULL);
		
	}
	for(int i=0; i <12;i++){
	spells[i] = &myspells[i];
	spells[i]->x = 0;
	spells[i]->y = 0;
	spells[i]->width = spells_bmp[i]->w;
	spells[i]->height = spells_bmp[i]->h;
	spells[i]->alive = 0;
	}
	wizard->x = 5 + SCROLLW / 4;
	wizard->y = 30 + SCROLLH / 2;
}

void setupscreen()
{
	int ret;

	//set video mode    
	set_color_depth(16);
	ret = set_gfx_mode(MODE, WIDTH, HEIGHT, 0, 0);
	if (ret != 0) {
		allegro_message(allegro_error);
		return;
	}

	//load screen background
	back = load_bitmap("resources/maps/background1.bmp", NULL);
	if (back == NULL)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("Error loading background.bmp file");
		return;
	}

	//create the double buffer
	buffer = create_bitmap(WIDTH, HEIGHT);
	if (buffer == NULL)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("Error creating double buffer");
		return;
	}

	magic_bmp[0] = load_bitmap("resources/sprites/fire.bmp",NULL);
	magic_bmp[1] = load_bitmap("resources/sprites/ice.bmp", NULL);
	magic_bmp[2] = load_bitmap("resources/sprites/darkright.bmp", NULL);


	scrollx = 100;
	scrolly = 100;

	startx = 50;
	starty = 100;
}


void setupgoblins(int n) {

	BITMAP *temp;

	int spawnx = (rand() % 1500) +1500;
	int spawny = (rand() % 600) +300;

	int tempxspeed = rand() % 5;
	int tempyspeed = rand() % 5;


	goblins[n] = &mygoblins[n];
	goblins[n]->x = spawnx;
	goblins[n]->y = spawny;
	goblins[n]->xspeed = tempxspeed;
	goblins[n]->yspeed = tempyspeed;
	goblins[n]->dir = 0;

	temp = load_bitmap("resources/sprites/goblin.bmp", NULL);

	goblins_bmp = temp;
}

void setupdemons(int n) {

	BITMAP *temp;

	int spawnx = (rand() % 1000) + 1000;
	int spawny = (rand() % 1000) + 1000;

	int tempxspeed = rand() % 10;
	int tempyspeed = rand() % 10;

	
	demons[n] = &mydemons[n];
	demons[n]->x = spawnx;
	demons[n]->y = spawny;
	demons[n]->xspeed = tempxspeed;
	demons[n]->yspeed = tempyspeed;
	demons[n]->dir = 0;
	demons[n]->health = 5;

	temp = load_bitmap("resources/sprites/demon.bmp", NULL);

	demons_bmp = temp;
}

void setupslime(int n) {

	BITMAP *temp;

	int tempxspeed = rand() % 10;
	int tempyspeed = rand() % 10;

	slime[n] = &myslime[n];
	slime[n]->x = 2800;
	slime[n]->y = 2900;
	slime[n]->xspeed =-10;
	slime[n]->yspeed = 0;
	slime[n]->health = 10;
	slime[n]->dir = 0;

	temp = load_bitmap("resources/sprites/slime.bmp", NULL);

	slime_bmp = temp;
}