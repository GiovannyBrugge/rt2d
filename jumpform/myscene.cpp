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
	myplayer = new MyPlayer();
	myplatform = new MyPlatform();
	
	myplayer->position = Point2(100,300);
	myplatform->position = Point2(500, 650);
	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myplayer);
	this->addChild(myplatform);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myplayer);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myplayer;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

}
