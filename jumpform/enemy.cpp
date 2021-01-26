#include <fstream>
#include <sstream>
#include "enemy.h"


Enemy::Enemy() : Entity()
{
	velocity = Vector2(0.0f, 0.0f);
	acceleration = Vector2(0.0f, 0.0f);
	gravity = Vector2(0.0f, 0.1f);
	jumpForce = Vector2(0.0f, -1200.0f);
	moveForce = Vector2(0.0f, 0.0f);
	movementSpeed = 0.1f;
	StopSpeed = 0.0f;
	this->addSprite("assets/square.tga");
	this->sprite()->color = BLUE;
	/*
	c = 0.01f;
	friction = getCopy(velocity);
	friction * -1;
	friction.normalize();
	friction* c;
	normal = 0.0f;
	*/
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{


	// checks if player touches the ground
	if (position.y > SHEIGHT - 65) {
		position.y = SHEIGHT - 65;
		velocity.y *= -0;
		isGrounded = true;
		isJumping = false;
	}
	// checks if player touches the ceiling
	if (position.y < 0 + 65) {
		position.y = 0 + 65;
		velocity.y *= -0;
	}
	// checks if player touches the right wall
	if (position.x > SWIDTH - 65) {
		position.x = SWIDTH - 65;
		velocity.x *= -0;

	}
	// checks if player touches the left wall
	if (position.x < 0 + 65) {
		position.x = 0 + 65;
		velocity.x *= -0;

	}
	
	

	//applies friction to acceleration
	//applyForce(friction);

	//applies gravity to the acceleration
	applyForce(gravity);

	//applies force to the leff/right movement
	applyForce(moveForce);

	//applies acceleration to the player velocity
	velocity += acceleration;

	//applies velocity to the player movement
	position += velocity;

	acceleration = Vector2(0, 0);

}

void Enemy::applyForce(Vector2 force) {
	acceleration += force;

}

Vector2 Enemy::getCopy(Vector2 copy) {
	return Vector2(copy.x, copy.y);

}


