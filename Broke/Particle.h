#pragma once
#include "Pulse.h"
namespace Law
{

	class Particle : public Law::GameObject
	{
	public:
		Particle(int Rotation, double LastingTime, Pulse *pulse, float width, float height, sf::Vector2f aceleration, sf::Vector2f force, sf::VertexArray m_vertices,
			  sf::Texture *m_texture) :GameObject(width, height, aceleration, force, m_vertices, m_texture){
			this->lastingTime = LastingTime;
			this->pulse = pulse;
			this->Rotation = Rotation;
		};
		~Particle();


		bool update(float delta, double time);


	private:
		int Rotation;
		double lastingTime;
		Law::Pulse *pulse;
	};
}
