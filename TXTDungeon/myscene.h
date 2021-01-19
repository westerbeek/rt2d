/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H
#include <sstream>
#include <rt2d/scene.h>
#include <string>  
#include "myentity.h"
#include "Buttonclass.h"
#include "GameGrid.h"
#include <rt2d/text.h>
/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();
	float mx;
	float my;
	int turn;
	int gold;
	std::string turnstr;
	std::string goldstr;
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	MyEntity* currency;
	Text* currencytext;
	MyEntity* turntimer;
	Text* turntext;

	Buttonclass* nextturnbutton;
	Text* nextturntext;
	GameGrid* grid;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
