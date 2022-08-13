#include "header.h"


void drawspells(int num)
{
	int x, y;
	
	int tempdir;
	int spelltype;

	tempdir = wizard->dir;

	if(dark == 1){
		if (tempdir == 0){spelltype = 10;}
		else if (tempdir == 2) { spelltype = 8; }
		else if (tempdir == 4) { spelltype = 9; }
		else {spelltype = 11;}
	}
	else if(ice == 1){
		if (tempdir == 0){spelltype = 7;}
		else if (tempdir == 2) { spelltype = 4; }
		else if (tempdir == 4) { spelltype = 5; }
		else {spelltype = 6;}
	}
	else {
		if (tempdir == 0){spelltype = 3;}
		else if (tempdir == 2) { spelltype = 0; }
		else if (tempdir == 4) { spelltype = 1; }
		else {	spelltype = 2;}
	}
	
	x = spells[num]->x;
	y = spells[num]->y;

	if (!spells[num]->alive) { return; }

	if (inside(x, y, scrollx, scrolly, scrollx + SCROLLW - spells_bmp[num]->w, scrolly + SCROLLH - spells_bmp[num]->h))

		draw_sprite(buffer, spells_bmp[spelltype], startx + x - scrollx, starty + y - scrolly);

}

void movespells(int num)
{
	int x, y, tx, ty;

	x = spells[0]->x;
	y = spells[0]->y;

	//is the bullet active?
	if (!spells[0]->alive) return;

	//move bullet
	spells[0]->x += spells[0]->xspeed;
	spells[0]->y += spells[0]->yspeed;
	x = spells[0]->x;
	y = spells[0]->y;


	//stay within the virtual screen
	if (x < 0 || x > MAPW - 6 || y < 0 || y > MAPH - 6)
	{
		spells[num]->alive = 0;
		return;
	}
	
	//collisions
	for (int i = 0; i < 5; i++) {
		tx = goblins[i]->x;
		ty = goblins[i]->y;

		const int frame = 20;
		if (inside(x, y, tx - frame, ty - frame, tx + frame, ty + frame)) {
			spells[i]->alive = 0;
			goblins[i]->alive = 0;
			goblincounter++;
		}
	}

	if(ice ==1){
		//collisions
		for (int i = 0; i < 3; i++) {
			tx = demons[i]->x;
			ty = demons[i]->y;

			const int frame = 20;
			if (inside(x, y, tx - frame, ty - frame, tx + frame, ty + frame)) {
				demons[i]->health--;
				spells[i]->alive = 0;
				if (demons[i]->health == 0) {
					spells[i]->alive = 0;
					demons[i]->alive = 0;
					demoncounter++;
				}
			}
		}
	}
	if (dark == 1) {
		//collisions

			tx = slime[0]->x;
			ty = slime[0]->y;

			const int frame = 20;
			if (inside(x, y, tx - frame, ty - frame, tx + frame, ty + frame)) {
				slime[0]->health--;
				
				if(slime[0]->health == 0){
					spells[0]->alive = 0;
					slime[0]->alive = 0;
					slimecounter++;
				}
			}
		
	}


}

//This method is not was from the Tankwars/Bullet for reference.
void firespell(int num)
{
	int x = scrollx + -50 +SCROLLW / 4;
	int y = scrolly + + SCROLLH / 4;

	if (!spells[num]->alive)
	{	
	//fires the first spell if alive
		spells[num]->alive = 1;

		switch (wizard->dir)
		{
			//north
		case 0:
			spells[num]->x = x - 4;
			spells[num]->y = y-20;
			spells[num]->xspeed = 0;
			spells[num]->yspeed = -SPELLSPEED;
			//spells[num]->yspeed = 0;
			break;
		
		case 2:
			spells[num]->x = x + 22;
			spells[num]->y = y - 2;
			spells[num]->xspeed = SPELLSPEED;
			spells[num]->yspeed = 0;
			break;
			//SE
		
		case 4:
			spells[num]->x = x - 2;
			spells[num]->y = y + 22;
			spells[num]->xspeed = 0;
			spells[num]->yspeed = SPELLSPEED;
			break;
	
		case 6:
			spells[num]->x = x - 22;
			spells[num]->y = y - 2;
			spells[num]->xspeed = -SPELLSPEED;
			spells[num]->yspeed = 0;
			break;
	
		}
	}
}
