/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>


#include "myscene.h"
#include "collider.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myplayer = new MyPlayer();
	
	
	myplatform = new MyPlatform();
	

	myplayer->position = Point2(100,300);
	myplatform->position = Point2(500, 550);
	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myplayer);
	this->addChild(myplatform);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myplayer);
	this->removeChild(myplatform);
	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myplayer;
	delete myplatform;
}

void MyScene::update(float deltaTime)
{
	

	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// create shapes ('colliders')
	Rectangle rect1 = Rectangle(myplayer->position.x, myplayer->position.y, 125, 125);
	Rectangle rect2 = Rectangle(myplatform->position.x, myplatform->position.y, 125, 125);

	// reset colors
	myplayer->sprite()->color = GREEN;
	myplatform->sprite()->color = GREEN;

	if (Collider::rectangle2rectangle(rect1, rect2)) {
		myplayer->sprite()->color = RED;
		myplatform->sprite()->color = RED;
		
		if (Collider::rectangle2rectangle(rect1, rect2)) {
			myplayer->position.y = myplatform->position.y - 125;
			myplayer->velocity.y *= -0;
			myplayer->isGrounded = true;
			myplayer->isJumping = false;
		}
	}
}
