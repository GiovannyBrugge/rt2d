#include <fstream>
#include <sstream>

#include "myplatform.h"


MyPlatform::MyPlatform() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = GREEN;
}

MyPlatform::~MyPlatform()
{
	
}

void MyPlatform::update(float deltaTime)
{
	
}


