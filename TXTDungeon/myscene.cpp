/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"



MyScene::MyScene() : Scene()
{
	
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.

	

	grid = new GameGrid();
	grid -> position = Point2(0, 0);
	//button = new Buttonclass();
	//button ->position = Point2(SWIDTH / 1, SHEIGHT / 4);
	// create the scene 'tree'

	//this->addChild(button);
	this->addChild(grid);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree

	//this->removeChild(button);

	// delete myentity from the heap (there was a 'new' in the constructor)
	

	//delete button;
	delete grid;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	mx = input()->getMouseX();
	my = input()->getMouseY();
	grid->mx = mx;
	grid->my = my;
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Mouseclick 
	// ###############################################################


	// ###############################################################
	// Rotate color
	// ###############################################################

	t.start();
}