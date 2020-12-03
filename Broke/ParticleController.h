#pragma once
#include <list>
#include "Particle.h"

using namespace std;
typedef list<Law::Particle>::iterator ItP;

namespace Law
{
	

	class ParticleController
	{
	public:
		ParticleController();
		~ParticleController();

	private:
		list<Law::Particle> particles;
	};
}

