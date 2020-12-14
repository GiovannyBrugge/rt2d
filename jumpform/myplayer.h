#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <rt2d/entity.h>
class MyPlayer: public Entity
{
public:
	/// @brief Constructor
	MyPlayer();
	/// @brief Destructor
	virtual ~MyPlayer();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Vector2* playerVelocity;

	/* add your private declarations */
};

#endif /* MYPLAYER_H */
