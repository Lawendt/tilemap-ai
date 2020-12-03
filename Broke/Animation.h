#pragma once
#include <SFML\System\Time.hpp>
#include <SFML\Graphics.hpp>

namespace Law
{

	class Animation : public sf::Drawable, public sf::Transformable
	{
	public:
		Animation();
		Animation(sf::Texture *texture, int numAnimation, int numFrames);
		~Animation();

		void update();
		void NextAnimation();

		void setTexture(sf::Texture *texture, int numAnimation, int numFrames, bool modify = true);
		sf::Texture* getTexture();

		void setNumAnimation(int n, bool modify = true);
		int getNumAnimation();

		void setNumFrames(int n, bool modify = true);
		int getNumFrames();

		void setCurrentAnimation(int n, bool modify = true);
		int getCurrentAnimation();

		void setCurrentFrame(int n, bool modify = true);
		int getCurrentFrame();

		void setVelAnimation(float n);
		float getVelAnimation();

		sf::VertexArray* getVertices();
		void setVertices(sf::VertexArray vertex);

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;


		int numAnimation, numFrames;
		int currentAnimation, currentFrame;
		float velAnimation;
		sf::Clock clock;
		sf::VertexArray m_vertices;
		sf::Texture *m_texture;
	};
}

