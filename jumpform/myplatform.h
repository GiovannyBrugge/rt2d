#ifndef MYPLATFORM_H
#define MYPLATFORM_H

#include <rt2d/entity.h>
class MyPlatform : public Entity
{
public:


	/// @brief Constructor
	MyPlatform();
	/// @brief Destructor
	virtual ~MyPlatform();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	
private:


	/* add your private declarations */
};

#endif /* MYPLATFORM_H */
