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
	// player nog weghalen
	Vector2 playerVelocity;
	Vector2 playerAcceleration;
	Vector2 playerGravity;
	Vector2 playerJumpForce;
	bool isGrounded;
	bool isJumping;
	void applyForce(Vector2 force);

private:
	

	/* add your private declarations */
};

#endif /* MYPLAYER_H */
