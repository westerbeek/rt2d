/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef BUTTONCLASS_H
#define BUTTONCLASS_H

#include <rt2d/entity.h>


/// @brief The MyEntity class is the Entity implementation.
class Buttonclass : public Entity
{
public:
	/// @brief Constructor
	Buttonclass();
	/// @brief Destructor
	virtual ~Buttonclass();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	/// 
	float mx;
	float my;
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	//MyScene* myscne;
};

#endif /* MYENTITY_H */
