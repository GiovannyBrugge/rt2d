#include <fstream>
#include <sstream>
#include "myplayer.h"


MyPlayer::MyPlayer() : Entity()
{
	playerVelocity = new Vector2(0.0f,0.0f);
	playerAcceleration = new Vector2(0.0f, 0.0f);
	playerGravity = new Vector2(0.0f, 1.0f);
	isGrounded = true;
	isJumping = false;
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
	//applies velocity to the player left/right movement
	this->position.x += this->playerVelocity->x;

	//applies acceleration to the player velocity
	this->playerVelocity->x += this->playerAcceleration->x;

	//applies gravity to the player
	this->position.y += this->playerGravity->y;
	
	// D moves myplayer to the right
	if (input()->getKey(KeyCode::D)) {
		this->playerVelocity->x = 600.0f * deltaTime;
	}
	if (input()->getKeyUp(KeyCode::D)) {
		this->playerVelocity->x = 0.0f * deltaTime;
	}

	// A moves myplayer to the left
	if (input()->getKey(KeyCode::A)) {
		this->playerVelocity->x = -600.0f * deltaTime;
	}
	if (input()->getKeyUp(KeyCode::A)) {
		this->playerVelocity->x = 0.0f * deltaTime;
	}
	
	// Spacebar jumps the myplayer up
	if (input()->getKeyDown(KeyCode::Space) && isGrounded && !isJumping) {
		this->isJumping = true;
		this->isGrounded = false;
	}

	// checks if player touches the ground
	if (this->position.y >= 650) {
		this->position.y -= this->playerGravity->y;
		this->isGrounded = true;
		this->isJumping = false;
	}
	
}


