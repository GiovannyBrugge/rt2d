#include <fstream>
#include <sstream>

#include "myplayer.h"


MyPlayer::MyPlayer() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = BLUE;
}

MyPlayer::~MyPlayer()
{

}

void MyPlayer::update(float deltaTime)
{

}


