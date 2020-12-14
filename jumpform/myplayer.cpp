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
	
	//this->position.x += playerVelocity->x = 1.0f;
	//this->position.y += playerVelocity->y;
	
}


