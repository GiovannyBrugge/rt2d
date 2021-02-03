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
	enemy = new Enemy();
	myplayer->position = Point2(100,300);
	myplatform->position = Point2(500, 550);
	enemy->position = Point2(1000, 550);
	// create the scene 'tree'
	// add myentity to this Scene as a child.

	this->addChild(myplayer);
	this->addChild(enemy);
	this->addChild(myplatform);


}

MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myplayer);
	this->removeChild(enemy);
	this->removeChild(myplatform);
	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myplayer;
	delete enemy;
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
	// R resets the scene
	if (input()->getKeyDown(KeyCode::R) && myplayer->isDead == true) {
		// deconstruct and delete the Tree
		this->removeChild(myplayer);
		this->removeChild(enemy);
		this->removeChild(myplatform);
		// construct and add the Tree
		this->addChild(myplayer);
		this->addChild(enemy);
		this->addChild(myplatform);
		//reset values 
		//Player
		myplayer->acceleration = Point2(0, 0);
		myplayer->velocity = Point2(0, 0);
		myplayer->moveForce = Point2(0, 0);
		myplayer->isDead = false;
		//Enemy
		enemy->position = Point2(1000, 550);
		enemy->acceleration = Point2(0, 0);
		enemy->velocity = Point2(0, 0);
		enemy->moveForce = Point2(0, 0);	
	}
	// create shapes ('colliders')
	Rectangle rect1 = Rectangle(myplayer->position.x, myplayer->position.y, 125, 100);
	Rectangle rect2 = Rectangle(myplatform->position.x, myplatform->position.y, 150, 62.5);
	Rectangle rect3 = Rectangle(enemy->position.x, enemy->position.y, 62.5, 62.5);
	// reset colors
	
	myplatform->sprite()->color = BLACK;
	enemy->sprite()->color = RED;
	if (Collider::rectangle2rectangle(rect1, rect2)) {
		
		myplayer->position.y = myplatform->position.y - 100;
		myplayer->velocity.y *= -0;
		myplayer->isGrounded = true;
		myplayer->isJumping = false;
		
	}
	if (Collider::rectangle2rectangle(rect1, rect3)) {
		
		enemy->sprite()->color = RED;
		myplayer->isDead = true;
		myplayer->position = Point2(200, 300);
	}

	if (myplayer->isDead == true) {
		removeChild(myplayer);
	}
}
