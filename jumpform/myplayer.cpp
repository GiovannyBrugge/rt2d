#include <fstream>
#include <sstream>

#include "myplayer.h"


	MyPlayer::MyPlayer() : Entity()
	{
		
		playerVelocity = new Vector2(0.0f,0.0f);
		playerAcceleration = new Vector2(0.0f, 0.0f);
		playerGravity = new Vector2(0.0f, 1.0f);
		isGrounded = true;
		this->addSprite("assets/square.tga");
		this->sprite()->color = BLUE;
	}

	MyPlayer::~MyPlayer()
	{
		delete playerVelocity;
		delete playerAcceleration;
		delete playerGravity;
	}

void MyPlayer::update(float deltaTime)
{
	//applies gravity to the player
	this->position.y += this->playerGravity->y;


	// ###############################################################
	// D moves myplayer to the right
	// ###############################################################
	if (input()->getKey(KeyCode::D)) {
		this->position.x += this->playerVelocity->x = 1.0f;
	}
	if (input()->getKeyUp(KeyCode::D)) {
		this->position.x += this->playerVelocity->x = 0.0f;
	}

	// ###############################################################
	// A moves myplayer to the left
	// ###############################################################
	if (input()->getKey(KeyCode::A)) {
		this->position.x += this->playerVelocity->x = -1.0f;
	}
	if (input()->getKeyUp(KeyCode::A)) {
		this->position.x += this->playerVelocity->x = 0.0f;
	}
	// ###############################################################
	// Spacebar jumps the myplayer up
	// ###############################################################
	if (this->isGrounded == true) {

		if (input()->getKeyDown(KeyCode::Space)) {
			this->position.y -= 200;
			this->isGrounded = false;
		}
	}
	// checks if player touches the ground
	if (this->position.y >= 650) {
		this->position.y -= this->playerGravity->y;
		this->isGrounded = true;
	}
	//this->position.x += playerVelocity->x = 1.0f;
	//this->position.y += playerVelocity->y;
	
}


