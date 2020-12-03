#include "Pulse.h"

namespace Law
{

	Pulse::Pulse(GameObject &object, int inX, int inY, float sec, bool beginexpanding)
	{
		pulse = true;
		first = true;
		this->object = &object;
		this->inX = inX;
		this->inY = inY;
		seconds = sec;
		scalefirst = object.getScale();
		beginExpanding = beginexpanding;
	}


	Pulse::~Pulse()
	{
		object = 0;
		object->setScale(scalefirst);

	}

	void Pulse::Update(float delta)
	{
		if (!first)
		{

			if (pulse)
			{
				object->setScale(Vector2f(object->getScale().x + (inX * delta), object->getScale().y + (inY * delta)));
				if (clock.getElapsedTime().asSeconds() > seconds)
				{

					clock.restart();
					pulse = false;
				}
			}
			else
			{

				object->setScale(Vector2f(object->getScale().x - (inX * delta), object->getScale().y - (inY * delta)));
				if (clock.getElapsedTime().asSeconds() > seconds)
				{

					clock.restart();
					pulse = true;
				}
			}
		}
		else
		{
			if (beginExpanding)
				object->setScale(Vector2f(object->getScale().x + (inX / 2 * delta), object->getScale().y + (inY / 2 * delta)));
			else
				object->setScale(Vector2f(object->getScale().x - (inX / 2 * delta), object->getScale().y - (inY / 2 * delta)));
			if (clock.getElapsedTime().asSeconds() > seconds)
			{

				clock.restart();
				if (beginExpanding)
					pulse = false;
				else
					pulse = true;
				first = false;
			}

		}
	}
}