#pragma once
#include <SFML\System\Clock.hpp>
#include "GameObject.h"

using sf::Vector2f;
namespace Law
{

	class Pulse
	{
	public:
		Pulse(GameObject &object, int inX, int inY, float seconds =1, bool beginexpanding = false);
		~Pulse();
		void Update(float delta);

	private:
		bool pulse;
		bool first;
		bool beginExpanding;
		sf::Clock clock;
		Law::GameObject *object;
		int inX, inY;
		float seconds;
		Vector2f scalefirst;
		

	};
}

