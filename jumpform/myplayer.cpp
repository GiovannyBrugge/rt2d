#include <fstream>
#include <sstream>

#include "myplayer.h"


	MyPlayer::MyPlayer() : Entity()
	{
		playerVelocity = new Vector2(0.0f,0.0f);
		playerAcceleration = new Vector2(0.0f, 0.0f);
		this->addSprite("assets/square.tga");
		this->sprite()->color = BLUE;
	}

	MyPlayer::~MyPlayer()
	{
		delete playerVelocity;
	}

void MyPlayer::update(float deltaTime)
{
	//this->position.x += playerVelocity->x = 1.0f;
	this->position.y += playerVelocity->y;
}


