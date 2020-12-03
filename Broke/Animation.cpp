#include "Animation.h"

namespace Law
{
	Animation::Animation()
	{
		velAnimation = 1;
		clock.restart();
		numAnimation = 0;
		numFrames = 0;
		currentFrame = 0;
		currentAnimation = 0;
		m_vertices = sf::VertexArray(sf::Quads, 4);



	}
	Animation::Animation(sf::Texture *texture, int numAnimation, int numFrames)
	{
		velAnimation = 1;
		clock.restart();
		m_texture = texture;
		this->numAnimation = numAnimation;
		this->numFrames = numFrames;
		m_vertices = sf::VertexArray(sf::Quads, 4);
		currentFrame = 0;
		currentAnimation = 0;

		m_vertices[0].position = sf::Vector2f(0, 0);
		m_vertices[1].position = sf::Vector2f(m_texture->getSize().x / numAnimation, 0);
		m_vertices[2].position = sf::Vector2f(m_texture->getSize().x / numAnimation, m_texture->getSize().y / numFrames);
		m_vertices[3].position = sf::Vector2f(0, m_texture->getSize().y / numFrames);

		m_vertices[0].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
		m_vertices[1].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
		m_vertices[2].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, (currentFrame + 1) *  m_texture->getSize().y / numFrames);
		m_vertices[3].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, (currentFrame + 1) * m_texture->getSize().y / numFrames);
	}
	Animation::~Animation()
	{
	}
	void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = m_texture;

		target.draw(m_vertices, states);

	}
	void Animation::NextAnimation()
	{
		currentAnimation++;
		if (currentAnimation >= numAnimation)
			currentAnimation = 0;

		m_vertices[0].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
		m_vertices[1].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
		m_vertices[2].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, (currentFrame + 1) *  m_texture->getSize().y / numFrames);
		m_vertices[3].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, (currentFrame + 1) * m_texture->getSize().y / numFrames);

	}
	void Animation::update()
	{

		if ((50 * 1 / velAnimation) < (clock.getElapsedTime()).asMilliseconds())
		{
			NextAnimation();
			clock.restart();
		}
	}
	void Animation::setTexture(sf::Texture *texture, int numAnimation, int numFrames, bool modify)
	{
		this->numAnimation = numAnimation;
		this->numFrames = numFrames;
		m_texture = texture;
		if (modify)
		{

			m_vertices[0].position = sf::Vector2f(0, 0);
			m_vertices[1].position = sf::Vector2f(m_texture->getSize().x / numAnimation, 0);
			m_vertices[2].position = sf::Vector2f(m_texture->getSize().x / numAnimation, m_texture->getSize().y / numFrames);
			m_vertices[3].position = sf::Vector2f(0, m_texture->getSize().y / numFrames);

			m_vertices[0].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
			m_vertices[1].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
			m_vertices[2].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, (currentFrame + 1) *  m_texture->getSize().y / numFrames);
			m_vertices[3].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, (currentFrame + 1) * m_texture->getSize().y / numFrames);
		}
	}
	sf::Texture* Animation::getTexture()
	{
		return m_texture;
	}
	void Animation::setNumAnimation(int n, bool modify)
	{
		numAnimation = n;
		if (modify)
		{
			m_vertices[0].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
			m_vertices[1].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
			m_vertices[2].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, (currentFrame + 1) *  m_texture->getSize().y / numFrames);
			m_vertices[3].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, (currentFrame + 1) * m_texture->getSize().y / numFrames);
		}
	}
	int Animation::getNumAnimation()
	{
		return numAnimation;
	}
	void Animation::setNumFrames(int n, bool modify)
	{
		numFrames = n;
		if (modify)
		{
			m_vertices[0].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
			m_vertices[1].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
			m_vertices[2].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, (currentFrame + 1) *  m_texture->getSize().y / numFrames);
			m_vertices[3].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, (currentFrame + 1) * m_texture->getSize().y / numFrames);
		}
	}
	int Animation::getNumFrames()
	{
		return numFrames;
	}
	void Animation::setCurrentAnimation(int n, bool modify)
	{
		currentAnimation = n;
		if (modify)
		{
			m_vertices[0].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
			m_vertices[1].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
			m_vertices[2].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, (currentFrame + 1) *  m_texture->getSize().y / numFrames);
			m_vertices[3].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, (currentFrame + 1) * m_texture->getSize().y / numFrames);
		}
	}
	int Animation::getCurrentAnimation()
	{
		return currentAnimation;
	}
	void Animation::setCurrentFrame(int n, bool modify)
	{
		currentFrame = n;
		if (modify)
		{
			m_vertices[0].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
			m_vertices[1].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, currentFrame *  m_texture->getSize().y / numFrames);
			m_vertices[2].texCoords = sf::Vector2f((currentAnimation + 1) * m_texture->getSize().x / numAnimation, (currentFrame + 1) *  m_texture->getSize().y / numFrames);
			m_vertices[3].texCoords = sf::Vector2f(currentAnimation * m_texture->getSize().x / numAnimation, (currentFrame + 1) * m_texture->getSize().y / numFrames);
		}
	}
	int Animation::getCurrentFrame()
	{
		return currentFrame;
	}
	void Animation::setVelAnimation(float n)
	{
		velAnimation = n;
	}
	float Animation::getVelAnimation()
	{
		return velAnimation;
	}
	sf::VertexArray* Animation::getVertices()
	{
		return &m_vertices;
	}
	void Animation::setVertices(sf::VertexArray vertex)
	{
		m_vertices = vertex;
	}
}