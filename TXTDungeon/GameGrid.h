/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef GAMEGRID_H
#define GAMEGRID_H

#include <rt2d/entity.h>
#include "Buttonclass.h"

/// @brief The MyEntity class is the Entity implementation.
class GameGrid : public Entity
{
public:
	/// @brief Constructor
	GameGrid();
	/// @brief Destructor
	virtual ~GameGrid();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	/// 
	float mx;
	float my;
	virtual void update(float deltaTime);

private:
	Buttonclass* button1;

	/* add your private declarations */
	//MyScene* myscne;
};

#endif /* MYENTITY_H */
