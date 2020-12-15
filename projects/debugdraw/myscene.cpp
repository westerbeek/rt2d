/**
 * This class describes MyScene behavior.
 *
 * Copyright 2019 Rik Teerling <rik@onandoffables.com>
 */

#include "myscene.h"


MyScene::MyScene() : Scene()
{

}

MyScene::~MyScene()
{

}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}



	// clears previous Debug Draw calls
	ddClear();

	// Debug Draw a single line
	// x0, y0, x1, y1, color
	
}
