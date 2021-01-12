/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include "Buttonclass.h"
#include "myscene.h"




Buttonclass::Buttonclass() : Entity()
{
	//this->sprite()->color = RED;
	sellected = false;
	frame = 0;
	this->addGrid("assets/dungeonwalls.tga", 2, 2, gridwidth, gridheight, cellwidth, cellheight);
	this->spritebatch()[0]->frame(frame);
	this->spritebatch()[0]->spriteposition = Point3(0.0f, 0.0f, 0.0f);
	this->spritebatch()[0]->spriterotation = Point3(0.0f, 0.0f, 0.0f);
	this->spritebatch()[0]->spritescale = Point3(1.0f, 1.0f, 1.0f);
}


Buttonclass::~Buttonclass()
{

}

void Buttonclass::update(float deltaTime)
{

	//std::cout << mx << std::endl;
	// ###############################################################
	// Rotate
	// ###############################################################
	//MOUSE WITHIN BOUNDS
	if (click == true) {
		std::cout << "click = true";

	}
	if (sellected == false) {
		if (mx >= this->position.x - cellwidth / 2 && mx <= this->position.x + cellwidth / 2 && my >= this->position.y - cellheight / 2 && my <= this->position.y + cellheight / 2) {

			
			if (input()->getMouse(0)) {
				frame = 1;
				hover = false;
				click = false;
			}
			else if(input()->getMouseUp(0)){
				
				click = true;
				
			}
			else {
				frame = 2;
				click = false;
				hover = true;
			}
		}
		else {

			frame = 0;
			hover = false;
			click = false;
		}



		if (input()->getMouse(0)) {


		}
		else {


		}
		// 90 deg/sec
		this->spritebatch()[0]->frame(frame);
	}
	else {
		frame = 3;
		this->spritebatch()[0]->frame(frame);
	}
}
