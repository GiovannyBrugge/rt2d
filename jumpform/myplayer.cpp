#include <fstream>
#include <sstream>

#include "myplayer.h"


	MyPlayer::MyPlayer() : Entity()
	{
		
		playerVelocity = new Vector2(30,30);
		this->addSprite("assets/square.tga");
		this->sprite()->color = BLUE;
	}

	MyPlayer::~MyPlayer()
	{
		delete playerVelocity;
	}

void MyPlayer::update(float deltaTime)
{
	
	
}


