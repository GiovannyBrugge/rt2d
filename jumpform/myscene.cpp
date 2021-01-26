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
	enemy->position = Point2(100,300);
	myplatform->position = Point2(500, 250);
	enemy->position = Point2(800, 550);
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
		enemy->position = Point2(800, 550);
		enemy->acceleration = Point2(0, 0);
		enemy->velocity = Point2(0, 0);
		enemy->moveForce = Point2(0, 0);
		
	}
	
	// create shapes ('colliders')
	Rectangle rect1 = Rectangle(myplayer->position.x, myplayer->position.y, 125, 125);
	Rectangle rect2 = Rectangle(myplatform->position.x, myplatform->position.y, 125, 125);
	Rectangle rect3 = Rectangle(enemy->position.x, enemy->position.y, 125, 125);
	// reset colors
	myplayer->sprite()->color = GREEN;
	myplatform->sprite()->color = GREEN;
	enemy->sprite()->color = GREEN;

	if (Collider::rectangle2rectangle(rect1, rect2)) {
		myplayer->sprite()->color = RED;
		myplatform->sprite()->color = RED;
		myplayer->position.y = myplatform->position.y - 125;
		myplayer->velocity.y *= -0;
		myplayer->isGrounded = true;
		myplayer->isJumping = false;
	}
	if (Collider::rectangle2rectangle(rect1, rect3)) {
		myplayer->sprite()->color = RED;
		enemy->sprite()->color = RED;
		myplayer->isDead = true;
		myplayer->position = Point2(100, 300);

	}

	if (myplayer->isDead == true) {
		removeChild(myplayer);
	}
}
