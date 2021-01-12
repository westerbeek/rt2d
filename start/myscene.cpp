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
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/2);
	

	button = new Buttonclass();
	button ->position = Point2(SWIDTH / 3, SHEIGHT / 3);
	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);
	this->addChild(button);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);
	this->removeChild(button);
	// delete myentity from the heap (there was a 'new' in the constructor)
	
	delete myentity;
	delete button;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	mx = input()->getMouseX();
	my = input()->getMouseY();
	button->mx = mx;
	button->my = my;
	myentity->position = Point(mx, my);
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Mouseclick scales myentity
	// ###############################################################
	if (input()->getMouseDown(0)) {
		myentity->scale = Point(0.1f, 0.1f);
		
		
	}
	if (input()->getMouseUp(0)) {
		myentity->scale = Point(0.01f, 0.01f);
		
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity->sprite()->color;
		if (input()->getMouse(0)) {
			myentity->sprite()->color = Color::rotate(color, 0.4f);


		}
		else {
			myentity->sprite()->color = Color::rotate(color, 0.1f);
		}
		t.start();
	}
}
