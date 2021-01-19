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
	gold = 100;
	turn = 0;
	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.

	turntimer = new MyEntity();
	turntext = new Text();
	currency = new MyEntity();
	currencytext = new Text();

	turntimer->addSprite("assets/turntimer.tga");
	currency->addSprite("assets/currency.tga");
	turntimer->position = Point2(SWIDTH / 50, SHEIGHT / 25);
	currency->position = Point2(SWIDTH / 5, SHEIGHT / 25);
	currency->scale = Vector2(0.4, 0.4);
	turntimer->scale = Vector2(1,-1);

	turntext->position = Point2(SWIDTH / 20, SHEIGHT / 25);
	currencytext->position = Point2(SWIDTH / 4.5, SHEIGHT / 25);
	turntext->scale = Vector2(0.3,0.5);
	turntext->rotation + 180;

	currencytext->scale = Vector2(0.3, 0.5);


	nextturnbutton = new Buttonclass();
	nextturntext = new Text();
	nextturntext->scale = Vector2(0.4,0.7);
	
	//button = new Buttonclass();
	nextturnbutton->buttontype = 1;
	nextturnbutton->frame = 0;
	nextturnbutton->cellheight = 64;
	nextturnbutton->cellwidth = 128;

	nextturntext->message("Next Turn");
	//nextturntext->sprite()->color = RED;
	nextturnbutton->position = Point2(SWIDTH / 1.08, SHEIGHT / 20);
	nextturntext->position = Point2(SWIDTH / 1.128, SHEIGHT / 20);

	grid = new GameGrid();
	grid -> position = Point2(0, 0);

	// create the scene 'tree'
	this->addChild(nextturnbutton);

	this->addChild(nextturntext);
	this->addChild(grid);

	this->addChild(turntimer);
	this->addChild(currency);
	this->addChild(turntext);
	this->addChild(currencytext);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(nextturntext);

	this->removeChild(nextturnbutton);

	this->removeChild(grid);

	this->removeChild(turntext);
	this->removeChild(currencytext);
	this->removeChild(turntimer);
	this->removeChild(currency);
	// delete myentity from the heap (there was a 'new' in the constructor)
	
	delete nextturntext;

	delete nextturnbutton;
	delete grid;

	delete turntimer;
	delete turntext;
	delete currency;
	delete currencytext;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	mx = input()->getMouseX();
	my = input()->getMouseY();
	grid->mx = mx;
	grid->my = my;
	nextturnbutton->mx = mx;
	nextturnbutton->my = my;

	
	turnstr = ": ";
	goldstr= ": ";
	turnstr += std::to_string(turn);
	goldstr += std::to_string(gold);
	turntext->message(turnstr);
	currencytext->message(goldstr);
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	if (nextturnbutton->click == true) {
		turn++;
		nextturnbutton->click = false;
	}
	// ###############################################################
	// Mouseclick 
	// ###############################################################


	// ###############################################################
	// Rotate color
	// ###############################################################

	t.start();
}