#include "GameObject.h"

namespace Law
{
	GameObject::GameObject()
	{
		setPosition(0, 0);
		aceleration= sf::Vector2f(0, 0);
		width = 5;
		height = 5;
		m_vertices = sf::VertexArray(sf::Quads, 4);
		m_vertices[0].position = sf::Vector2f(0, 0);
		m_vertices[1].position = sf::Vector2f(width, 0);
		m_vertices[2].position = sf::Vector2f(width, height);
		m_vertices[3].position = sf::Vector2f(0, height);

		m_texture = 0;

	}
	GameObject::GameObject(float w, float h, sf::Vector2f a, sf::Vector2f f, sf::VertexArray v, sf::Texture *t)
	{
		setPosition(0, 0);
		aceleration = a;
		width = w;
		height = h;
		m_vertices = v;
		m_texture = t;
	}

	GameObject::~GameObject()
	{
		m_texture = 0;
	}
	void GameObject::update(float delta)
	{
		move(aceleration * delta);

	}

	float GameObject::getSpeed()
	{
		return sqrtf(aceleration.x * aceleration.x + aceleration.y + aceleration.y);
	}
	sf::Vector2f& GameObject::getAceleration()
	{
		return aceleration;
	}
	void GameObject::setAceleration(sf::Vector2f v)
	{
		aceleration = v;
	}
	void GameObject::addAceleration(sf::Vector2f v)
	{
		aceleration += v;
	}
	void  GameObject::multiplyAceleration(sf::Vector2f v)
	{
		aceleration.x *= v.x;
		aceleration.y *= v.y;
	}
	void GameObject::setAceleration(int x, int y)
	{
		aceleration.x = x;
		aceleration.y = y;
	}
	void GameObject::addAceleration(int x, int y)
	{
		aceleration.x += x;
		aceleration.y += y;
	}
	void GameObject::multiplyAceleration(int x, int y)
	{
		aceleration.x *= x;
		aceleration.y *= y;
	}

	/*sf::vector2f& gameobject::getforce()
	{
		return force;
	}
	void gameobject::setforce(sf::vector2f v)
	{
		force = v;
	}
	void gameobject::addforce(sf::vector2f v)
	{
		force += v;
	}
	void  gameobject::multiplyforce(sf::vector2f v)
	{
		force.x *= v.x;
		force.y *= v.y;
	}
	void gameobject::setforce(int x, int y)
	{
		force.x = x;
		force.y = y;
	}
	void gameobject::addforce(int x, int y)
	{
		force.x += x;
		force.y += y;
	}
	void gameobject::multiplyforce(int x, int y)
	{
		force.x *= x;
		force.y *= y;
	}*/

	void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = m_texture;

		target.draw(m_vertices, states);

	}

	void GameObject::setWidht(float w)
	{
		width = w;

		m_vertices[1].position = sf::Vector2f(width, 0);
		m_vertices[2].position = sf::Vector2f(width, height);

	}
	void GameObject::setHeight(float h)
	{
		height = h;
	

		m_vertices[2].position = sf::Vector2f(width, height);
		m_vertices[3].position = sf::Vector2f(0, height);
	}
	void GameObject::setDimensions(float w, float h)
	{
		width = w;
		height = h;
		m_vertices[0].position = sf::Vector2f(0, 0);
		m_vertices[1].position = sf::Vector2f(width, 0);
		m_vertices[2].position = sf::Vector2f(width, height);
		m_vertices[3].position = sf::Vector2f(0, height);
		
	}
	sf::Vector2f GameObject::getDimensions()
	{
		return sf::Vector2f(width, height);
	}
	float GameObject::getWidth()
	{
		return width;
	}
	float GameObject::getHeight()
	{
		return height;
	}

	sf::Texture*GameObject::getTexture()
	{
		return m_texture;
	}
	void GameObject::setTexture(sf::Texture &texture)
	{
		m_texture = &texture;
		
		m_vertices[0].texCoords = sf::Vector2f(0, 0);
		m_vertices[1].texCoords = sf::Vector2f(texture.getSize().x, 0);
		m_vertices[2].texCoords = sf::Vector2f(texture.getSize().x, texture.getSize().y);
		m_vertices[3].texCoords = sf::Vector2f(0, texture.getSize().y);
	}
	bool GameObject::getActive()
	{
		return active;
	}
	void GameObject::setActive(bool a)
	{
		active = a;
	}
	sf::VertexArray* GameObject::getVertices()
	{
		return &m_vertices;
	}
	void GameObject::setVertices(sf::VertexArray vertex)
	{
		m_vertices = vertex;
	}

	void GameObject::setColorAll(int r, int g, int b, int a)
	{
		for (int i = 0; i < m_vertices.getVertexCount(); i++)
		{
			m_vertices[i].color = sf::Color(r, g, b, a);
		}
	}
	void GameObject::setColorOne(int n, int r, int g, int b, int a)
	{
		if (n < m_vertices.getVertexCount())
		{
			m_vertices[n].color = sf::Color(r, g, b, a);
		}
	}

}