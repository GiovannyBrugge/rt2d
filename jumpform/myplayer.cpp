#include <fstream>
#include <sstream>
#include "myplayer.h"


MyPlayer::MyPlayer() : Entity()
{
	playerVelocity =  Vector2(0.0f,0.0f);
	playerAcceleration = Vector2(0.0f, 0.0f);
	playerGravity =  Vector2(0.0f, 0.0001f);
	playerJumpForce = Vector2(0.0f, -1000.0f);
	isGrounded = true;
	isJumping = false;
	this->addSprite("assets/square.tga");
	this->sprite()->color = BLUE;
}

MyPlayer::~MyPlayer()
{
	
}

void MyPlayer::update(float deltaTime)
{
	//applies gravity to the acceleration
	applyForce(playerGravity);

	//applies acceleration to the player velocity
	this->playerVelocity += this->playerAcceleration;

	//applies velocity to the player movement
	this->position += this->playerVelocity;


	// D moves myplayer to the right
	if (input()->getKey(KeyCode::D)) {
		this->playerVelocity.x = 600.0f * deltaTime;
	}
	if (input()->getKeyUp(KeyCode::D)) {
		this->playerVelocity.x = 0.0f * deltaTime;
	}

	// A moves myplayer to the left
	if (input()->getKey(KeyCode::A)) {
		this->playerVelocity.x = -600.0f * deltaTime;
	}
	if (input()->getKeyUp(KeyCode::A)) {
		this->playerVelocity.x = 0.0f * deltaTime;
	}
	
	// Spacebar jumps the myplayer up
	if (input()->getKeyDown(KeyCode::Space) && isGrounded && !isJumping) {
		this->applyForce(playerJumpForce);
		this->isJumping = true;
		this->isGrounded = false;
	}

	// checks if player touches the ground
	if (this->position.y >= 650) {
		this->position.y -= this->playerGravity.y;
		this->isGrounded = true;
		this->isJumping = false;
	}
	playerAcceleration = Vector2(0, 0);
}

void MyPlayer::applyForce(Vector2 force) {
	playerAcceleration += force;
}

