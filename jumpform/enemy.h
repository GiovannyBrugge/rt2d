#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
class Enemy : public Entity
{
public:


	/// @brief Constructor
	Enemy();
	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	float movementSpeed;
	float StopSpeed;
	float c;
	float normal;
	float frictionMag;
	bool isGrounded;
	bool isJumping;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 gravity;
	Vector2 jumpForce;
	Vector2 moveForce;
	Vector2 friction;
	void applyForce(Vector2 force);
	void walkLeft(float deltaTime);
	void walkRight(float deltaTime);
	void stopMovement(float deltaTime);
	Vector2 getCopy(Vector2 copy);

private:


	/* add your private declarations */
};

#endif /* ENEMY */