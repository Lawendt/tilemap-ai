#include "Peripherals.h"

// --- Key
namespace Law
{
	Key::Key()
	{
		state = 0;
		released = 0;
	}
	Key::~Key()
	{
		state = 0;
		released = 0;
	}
	void Key::update(bool pressed)
	{
		if (pressed)
		{
			if (state)
				state = 2;
			else
				state = 1;
		}
		else if (state)
		{
			state = 0;
			released = true;
		}
		else
		{
			released = false;
		}

	}

	// Keyboard
	Keyboard::Keyboard()
	{
	}
	Keyboard::~Keyboard()
	{
	}
	int Keyboard::getStateKey(int which) const
	{
		if (which >= 0 && which < 101)
			return keys[which].state;
		else
			std::cout << "Trying to acess Unexistent Key\n";
		return 0;
	}
	bool Keyboard::getReleasedKey(int which) const
	{
		if (which >= 0 && which < 101)
			return keys[which].released;
		else
			std::cout << "Trying to acess Unexistent Key\n";
		return 0;
	}
	Key Keyboard::getKey(int which) const
	{
		if (which >= 0 && which < 101)
			return keys[which];
		else
			std::cout << "Trying to acess Unexistent Key\n";
		return keys[0];
	}
	void Keyboard::updateKey(int which, bool pressed)
	{
		keys[which].update(pressed);
	}
	void Keyboard::update()
	{
		updateKey(sf::Keyboard().A, sf::Keyboard().isKeyPressed(sf::Keyboard().A));
		updateKey(sf::Keyboard().B, sf::Keyboard().isKeyPressed(sf::Keyboard().B));
		updateKey(sf::Keyboard().C, sf::Keyboard().isKeyPressed(sf::Keyboard().C));
		updateKey(sf::Keyboard().D, sf::Keyboard().isKeyPressed(sf::Keyboard().D));
		updateKey(sf::Keyboard().E, sf::Keyboard().isKeyPressed(sf::Keyboard().E));
		updateKey(sf::Keyboard().F, sf::Keyboard().isKeyPressed(sf::Keyboard().F));
		updateKey(sf::Keyboard().G, sf::Keyboard().isKeyPressed(sf::Keyboard().G));
		updateKey(sf::Keyboard().H, sf::Keyboard().isKeyPressed(sf::Keyboard().H));
		updateKey(sf::Keyboard().I, sf::Keyboard().isKeyPressed(sf::Keyboard().I));
		updateKey(sf::Keyboard().J, sf::Keyboard().isKeyPressed(sf::Keyboard().J));
		updateKey(sf::Keyboard().K, sf::Keyboard().isKeyPressed(sf::Keyboard().K));
		updateKey(sf::Keyboard().L, sf::Keyboard().isKeyPressed(sf::Keyboard().L));
		updateKey(sf::Keyboard().M, sf::Keyboard().isKeyPressed(sf::Keyboard().M));
		updateKey(sf::Keyboard().N, sf::Keyboard().isKeyPressed(sf::Keyboard().N));
		updateKey(sf::Keyboard().O, sf::Keyboard().isKeyPressed(sf::Keyboard().O));
		updateKey(sf::Keyboard().P, sf::Keyboard().isKeyPressed(sf::Keyboard().P));
		updateKey(sf::Keyboard().Q, sf::Keyboard().isKeyPressed(sf::Keyboard().Q));
		updateKey(sf::Keyboard().R, sf::Keyboard().isKeyPressed(sf::Keyboard().R));
		updateKey(sf::Keyboard().S, sf::Keyboard().isKeyPressed(sf::Keyboard().S));
		updateKey(sf::Keyboard().T, sf::Keyboard().isKeyPressed(sf::Keyboard().T));
		updateKey(sf::Keyboard().U, sf::Keyboard().isKeyPressed(sf::Keyboard().U));
		updateKey(sf::Keyboard().V, sf::Keyboard().isKeyPressed(sf::Keyboard().V));
		updateKey(sf::Keyboard().W, sf::Keyboard().isKeyPressed(sf::Keyboard().W));
		updateKey(sf::Keyboard().X, sf::Keyboard().isKeyPressed(sf::Keyboard().X));
		updateKey(sf::Keyboard().Y, sf::Keyboard().isKeyPressed(sf::Keyboard().Y));
		updateKey(sf::Keyboard().Z, sf::Keyboard().isKeyPressed(sf::Keyboard().Z));
		updateKey(sf::Keyboard().LAlt, sf::Keyboard().isKeyPressed(sf::Keyboard().LAlt));
		updateKey(sf::Keyboard().LShift, sf::Keyboard().isKeyPressed(sf::Keyboard().LShift));
		updateKey(sf::Keyboard().LControl, sf::Keyboard().isKeyPressed(sf::Keyboard().LControl));
		updateKey(sf::Keyboard().Escape, sf::Keyboard().isKeyPressed(sf::Keyboard().Escape));
		updateKey(sf::Keyboard().Num9, sf::Keyboard().isKeyPressed(sf::Keyboard().Num9));
		updateKey(sf::Keyboard().Num8, sf::Keyboard().isKeyPressed(sf::Keyboard().Num8));
		updateKey(sf::Keyboard().Num7, sf::Keyboard().isKeyPressed(sf::Keyboard().Num7));
		updateKey(sf::Keyboard().Num6, sf::Keyboard().isKeyPressed(sf::Keyboard().Num6));
		updateKey(sf::Keyboard().Num5, sf::Keyboard().isKeyPressed(sf::Keyboard().Num5));
		updateKey(sf::Keyboard().Num4, sf::Keyboard().isKeyPressed(sf::Keyboard().Num4));
		updateKey(sf::Keyboard().Num3, sf::Keyboard().isKeyPressed(sf::Keyboard().Num3));
		updateKey(sf::Keyboard().Num2, sf::Keyboard().isKeyPressed(sf::Keyboard().Num2));
		updateKey(sf::Keyboard().Num1, sf::Keyboard().isKeyPressed(sf::Keyboard().Num1));
		updateKey(sf::Keyboard().Num0, sf::Keyboard().isKeyPressed(sf::Keyboard().Num0));
		updateKey(sf::Keyboard().Tilde, sf::Keyboard().isKeyPressed(sf::Keyboard().Tilde));
		updateKey(sf::Keyboard().BackSlash, sf::Keyboard().isKeyPressed(sf::Keyboard().BackSlash));
		updateKey(sf::Keyboard().Slash, sf::Keyboard().isKeyPressed(sf::Keyboard().Slash));
		updateKey(sf::Keyboard().Quote, sf::Keyboard().isKeyPressed(sf::Keyboard().Quote));
		updateKey(sf::Keyboard().Period, sf::Keyboard().isKeyPressed(sf::Keyboard().Period));
		updateKey(sf::Keyboard().Comma, sf::Keyboard().isKeyPressed(sf::Keyboard().Comma));
		updateKey(sf::Keyboard().SemiColon, sf::Keyboard().isKeyPressed(sf::Keyboard().SemiColon));
		updateKey(sf::Keyboard().RBracket, sf::Keyboard().isKeyPressed(sf::Keyboard().RBracket));
		updateKey(sf::Keyboard().LBracket, sf::Keyboard().isKeyPressed(sf::Keyboard().LBracket));
		updateKey(sf::Keyboard().Menu, sf::Keyboard().isKeyPressed(sf::Keyboard().Menu));
		updateKey(sf::Keyboard().RSystem, sf::Keyboard().isKeyPressed(sf::Keyboard().RSystem));
		updateKey(sf::Keyboard().RAlt, sf::Keyboard().isKeyPressed(sf::Keyboard().RAlt));
		updateKey(sf::Keyboard().RShift, sf::Keyboard().isKeyPressed(sf::Keyboard().RShift));
		updateKey(sf::Keyboard().RControl, sf::Keyboard().isKeyPressed(sf::Keyboard().RControl));
		updateKey(sf::Keyboard().LSystem, sf::Keyboard().isKeyPressed(sf::Keyboard().LSystem));
		updateKey(sf::Keyboard().Multiply, sf::Keyboard().isKeyPressed(sf::Keyboard().Multiply));
		updateKey(sf::Keyboard().Subtract, sf::Keyboard().isKeyPressed(sf::Keyboard().Subtract));
		updateKey(sf::Keyboard().Add, sf::Keyboard().isKeyPressed(sf::Keyboard().Add));
		updateKey(sf::Keyboard().Delete, sf::Keyboard().isKeyPressed(sf::Keyboard().Delete));
		updateKey(sf::Keyboard().Insert, sf::Keyboard().isKeyPressed(sf::Keyboard().Insert));
		updateKey(sf::Keyboard().Home, sf::Keyboard().isKeyPressed(sf::Keyboard().Home));
		updateKey(sf::Keyboard().End, sf::Keyboard().isKeyPressed(sf::Keyboard().End));
		updateKey(sf::Keyboard().PageDown, sf::Keyboard().isKeyPressed(sf::Keyboard().PageDown));
		updateKey(sf::Keyboard().PageUp, sf::Keyboard().isKeyPressed(sf::Keyboard().PageUp));
		updateKey(sf::Keyboard().Tab, sf::Keyboard().isKeyPressed(sf::Keyboard().Tab));
		updateKey(sf::Keyboard().BackSpace, sf::Keyboard().isKeyPressed(sf::Keyboard().BackSpace));
		updateKey(sf::Keyboard().Return, sf::Keyboard().isKeyPressed(sf::Keyboard().Return));
		updateKey(sf::Keyboard().Space, sf::Keyboard().isKeyPressed(sf::Keyboard().Space));
		updateKey(sf::Keyboard().Dash, sf::Keyboard().isKeyPressed(sf::Keyboard().Dash));
		updateKey(sf::Keyboard().Equal, sf::Keyboard().isKeyPressed(sf::Keyboard().Equal));
		updateKey(sf::Keyboard().Numpad9, sf::Keyboard().isKeyPressed(sf::Keyboard().Numpad9));
		updateKey(sf::Keyboard().Numpad8, sf::Keyboard().isKeyPressed(sf::Keyboard().Numpad8));
		updateKey(sf::Keyboard().Numpad7, sf::Keyboard().isKeyPressed(sf::Keyboard().Numpad7));
		updateKey(sf::Keyboard().Numpad6, sf::Keyboard().isKeyPressed(sf::Keyboard().Numpad6));
		updateKey(sf::Keyboard().Numpad5, sf::Keyboard().isKeyPressed(sf::Keyboard().Numpad5));
		updateKey(sf::Keyboard().Numpad4, sf::Keyboard().isKeyPressed(sf::Keyboard().Numpad4));
		updateKey(sf::Keyboard().Numpad3, sf::Keyboard().isKeyPressed(sf::Keyboard().Numpad3));
		updateKey(sf::Keyboard().Numpad2, sf::Keyboard().isKeyPressed(sf::Keyboard().Numpad2));
		updateKey(sf::Keyboard().Numpad1, sf::Keyboard().isKeyPressed(sf::Keyboard().Numpad1));
		updateKey(sf::Keyboard().Numpad0, sf::Keyboard().isKeyPressed(sf::Keyboard().Numpad0));
		updateKey(sf::Keyboard().Down, sf::Keyboard().isKeyPressed(sf::Keyboard().Down));
		updateKey(sf::Keyboard().Up, sf::Keyboard().isKeyPressed(sf::Keyboard().Up));
		updateKey(sf::Keyboard().Right, sf::Keyboard().isKeyPressed(sf::Keyboard().Right));
		updateKey(sf::Keyboard().Left, sf::Keyboard().isKeyPressed(sf::Keyboard().Left));
		updateKey(sf::Keyboard().Divide, sf::Keyboard().isKeyPressed(sf::Keyboard().Divide));
		updateKey(sf::Keyboard().F15, sf::Keyboard().isKeyPressed(sf::Keyboard().F15));
		updateKey(sf::Keyboard().F14, sf::Keyboard().isKeyPressed(sf::Keyboard().F14));
		updateKey(sf::Keyboard().F13, sf::Keyboard().isKeyPressed(sf::Keyboard().F13));
		updateKey(sf::Keyboard().F12, sf::Keyboard().isKeyPressed(sf::Keyboard().F12));
		updateKey(sf::Keyboard().F11, sf::Keyboard().isKeyPressed(sf::Keyboard().F11));
		updateKey(sf::Keyboard().F10, sf::Keyboard().isKeyPressed(sf::Keyboard().F10));
		updateKey(sf::Keyboard().F9, sf::Keyboard().isKeyPressed(sf::Keyboard().F9));
		updateKey(sf::Keyboard().F8, sf::Keyboard().isKeyPressed(sf::Keyboard().F8));
		updateKey(sf::Keyboard().F7, sf::Keyboard().isKeyPressed(sf::Keyboard().F7));
		updateKey(sf::Keyboard().F6, sf::Keyboard().isKeyPressed(sf::Keyboard().F6));
		updateKey(sf::Keyboard().F5, sf::Keyboard().isKeyPressed(sf::Keyboard().F5));
		updateKey(sf::Keyboard().F4, sf::Keyboard().isKeyPressed(sf::Keyboard().F4));
		updateKey(sf::Keyboard().F3, sf::Keyboard().isKeyPressed(sf::Keyboard().F3));
		updateKey(sf::Keyboard().F2, sf::Keyboard().isKeyPressed(sf::Keyboard().F2));
		updateKey(sf::Keyboard().F1, sf::Keyboard().isKeyPressed(sf::Keyboard().F1));
		updateKey(sf::Keyboard().Pause, sf::Keyboard().isKeyPressed(sf::Keyboard().Pause));


	}

	Mouse::Mouse()
	{

	}
	Mouse::~Mouse()
	{

	}

	int Mouse::getStateKey(int which) const
	{
		if (which < ButtonCount_)
			return buttons[which].state;
		
	}
	bool Mouse::getReleasedKey(int which) const
	{
		if (which < ButtonCount_)
			return buttons[which].released;
		
	}
	Key Mouse::getKey(int which) const
	{
		if (which < ButtonCount_)
			return buttons[which];
	}

	void Mouse::update(int which, bool pressed)
	{
		if (which < ButtonCount_)
			buttons[which].update(pressed);
	}

	void Mouse::update(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void Mouse::update(sf::Vector2i pos)
	{
		x = pos.x;
		y = pos.y;
	}
	void Mouse::update()
	{
		for (int i = 0; i < 5; i++)
		{
			if (buttons[i].state == Key_Pressed)
				buttons[i].state++;
		}
	}
	sf::Vector2i Mouse::getPosition()
	{
		return sf::Vector2i(x,y);
	}
	float Mouse::getX()
	{
		return x;
	}
	float Mouse::getY()
	{
		return y;
	}
}