#include <fstream>
#include <sstream>

#include "myplayer.h"


	MyPlayer::MyPlayer() : Entity()
	{
		playerVelocity = new Vector2(1.0f,0.0f);
		this->addSprite("assets/square.tga");
		this->sprite()->color = BLUE;
	}

	MyPlayer::~MyPlayer()
	{
		delete playerVelocity;
	}

void MyPlayer::update(float deltaTime)
{
	this->position.x += playerVelocity->x;
	this->position.y += playerVelocity->y;
}


