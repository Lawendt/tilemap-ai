#pragma once
#include "Animation.h"
#include <cmath>
namespace Law
{

	class GameObject : public sf::Drawable, public sf::Transformable
	{
	public:
		GameObject();
		GameObject(float width, float height, sf::Vector2f aceleration, sf::Vector2f force, sf::VertexArray m_vertices, sf::Texture *m_texture);
		~GameObject();

		void update(float delta);

		float getSpeed();

		sf::Vector2f& getAceleration();

		void setAceleration(sf::Vector2f);
		void addAceleration(sf::Vector2f);
		void multiplyAceleration(sf::Vector2f);

		void setAceleration(int x, int y);
		void addAceleration(int x, int y);
		void multiplyAceleration(int x, int y);

		/*sf::Vector2f& getForce();

		void setForce(sf::Vector2f);
		void addForce(sf::Vector2f);
		void multiplyForce(sf::Vector2f);

		void setForce(int x, int y);
		void addForce(int x, int y);
		void multiplyForce(int x, int y);*/

		void setWidht(float w);
		void setHeight(float h);
		void setDimensions(float w, float h);

		sf::Vector2f getDimensions();
		float getWidth();
		float getHeight();

		sf::Texture*getTexture();
		void setTexture(sf::Texture &texture);

		bool getActive();
		void setActive(bool a);

		sf::VertexArray* getVertices();
		void setVertices(sf::VertexArray vertex);

		sf::Vector2f getMovement();

	/*	void Move()
		{
			movement+
		}*/

		void setColorAll(int r, int g, int b, int a);
		void setColorOne(int n, int r, int g, int b, int a);


	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		bool active;
		float width, height;
		sf::Vector2f aceleration, force;
		sf::VertexArray m_vertices;
		sf::Texture *m_texture;
	};

}