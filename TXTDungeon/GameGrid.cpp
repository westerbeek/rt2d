/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include "GameGrid.h"

int gridsize = 9;
int startposition = 100;
GameGrid::GameGrid() : Entity()
{
	//this->sprite()->color = RED;

	for (int x = 0; x < gridsize; x++) {
		for (int y = 0; y < gridsize; y++) {
		
			Buttonclass* button = new Buttonclass();

			buttons.push_back(button);

			this->addChild(button);

			button->position.x = x * 64+ startposition;
			button->position.y = y * 64+ startposition;
			
		}
	}
}


GameGrid::~GameGrid()
{
	//this->removeChild(button1);
	//delete(button1);
}

void GameGrid::update(float deltaTime)
{
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->mx = mx;
		buttons[i]->my = my;
		if (buttons[i]->click == true) {

			for (int a = 0; a < buttons.size(); a++) {
				if (buttons[a]->sellected == true) {
					buttons[a]->sellected = false;

				}
			}
			
			buttons[i]->sellected = true;
			buttons[i]->click = false;
		}
		
	}
	
	//button1->mx = mx;
	//button1->my = my;
}