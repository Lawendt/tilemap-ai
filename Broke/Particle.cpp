#include "Particle.h"

namespace Law
{

	Particle::~Particle()
	{
		delete pulse;
		pulse = 0;
	}

	bool Particle::update(float delta, double time)
	{
		rotate(Rotation);
		move(aceleration * delta);
		lastingTime -= time;
		if (lastingTime < 0)
			return false;
		else
			return true;
	}

}