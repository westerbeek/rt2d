/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include "GameGrid.h"

int gridsize;

GameGrid::GameGrid() : Entity()
{
	//this->sprite()->color = RED;
	button1 = new Buttonclass();
	
	button1->position = Point2(SWIDTH / 8, SHEIGHT / 4);

	this->addChild(button1);
}


GameGrid::~GameGrid()
{
	this->removeChild(button1);
	delete(button1);
}

void GameGrid::update(float deltaTime)
{
	button1->mx = mx;
	button1->my = my;
}
