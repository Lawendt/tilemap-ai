#pragma once
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>
#include <iostream>

#define ButtonCount_ 5

//Idea by Demetrius
#ifndef Key_Pressed 
#define Key_Pressed 1
#endif
#ifndef Key_Hold 
#define Key_Hold 2
#endif
#ifndef Key_NotPressed
#define Key_NotPressed 0
#endif
//End of the Idea
enum enum_Key_
{
	Key_Unknown = -1, ///< Unhandled key
	Key_A = 0,        ///< The A key
	Key_B,            ///< The B key
	Key_C,            ///< The C key
	Key_D,            ///< The D key
	Key_E,            ///< The E key
	Key_F,            ///< The F key
	Key_G,            ///< The G key
	Key_H,            ///< The H key
	Key_I,            ///< The I key
	Key_J,            ///< The J key
	Key_K,            ///< The K key
	Key_L,            ///< The L key
	Key_M,            ///< The M key
	Key_N,            ///< The N key
	Key_O,            ///< The O key
	Key_P,            ///< The P key
	Key_Q,            ///< The Q key
	Key_R,            ///< The R key
	Key_S,            ///< The S key
	Key_T,            ///< The T key
	Key_U,            ///< The U key
	Key_V,            ///< The V key
	Key_W,            ///< The W key
	Key_X,            ///< The X key
	Key_Y,            ///< The Y key
	Key_Z,            ///< The Z key
	Key_Num0,         ///< The 0 key
	Key_Num1,         ///< The 1 key
	Key_Num2,         ///< The 2 key
	Key_Num3,         ///< The 3 key
	Key_Num4,         ///< The 4 key
	Key_Num5,         ///< The 5 key
	Key_Num6,         ///< The 6 key
	Key_Num7,         ///< The 7 key
	Key_Num8,         ///< The 8 key
	Key_Num9,         ///< The 9 key
	Key_Escape,       ///< The Escape key
	Key_LControl,     ///< The left Control key
	Key_LShift,       ///< The left Shift key
	Key_LAlt,         ///< The left Alt key
	Key_LSystem,      ///< The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
	Key_RControl,     ///< The right Control key
	Key_RShift,       ///< The right Shift key
	Key_RAlt,         ///< The right Alt key
	Key_RSystem,      ///< The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
	Key_Menu,         ///< The Menu key
	Key_LBracket,     ///< The [ key
	Key_RBracket,     ///< The ] key
	Key_SemiColon,    ///< The ; key
	Key_Comma,        ///< The , key
	Key_Period,       ///< The . key
	Key_Quote,        ///< The ' key
	Key_Slash,        ///< The / key
	Key_BackSlash,    ///< The \ key
	Key_Tilde,        ///< The ~ key
	Key_Equal,        ///< The = key
	Key_Dash,         ///< The - key
	Key_Space,        ///< The Space key
	Key_Return,       ///< The Return key
	Key_BackSpace,    ///< The Backspace key
	Key_Tab,          ///< The Tabulation key
	Key_PageUp,       ///< The Page up key
	Key_PageDown,     ///< The Page down key
	Key_End,          ///< The End key
	Key_Home,         ///< The Home key
	Key_Insert,       ///< The Insert key
	Key_Delete,       ///< The Delete key
	Key_Add,          ///< The + key
	Key_Subtract,     ///< The - key
	Key_Multiply,     ///< The * key
	Key_Divide,       ///< The / key
	Key_Left,         ///< Left arrow
	Key_Right,        ///< Right arrow
	Key_Up,           ///< Up arrow
	Key_Down,         ///< Down arrow
	Key_Numpad0,      ///< The numpad 0 key
	Key_Numpad1,      ///< The numpad 1 key
	Key_Numpad2,      ///< The numpad 2 key
	Key_Numpad3,      ///< The numpad 3 key
	Key_Numpad4,      ///< The numpad 4 key
	Key_Numpad5,      ///< The numpad 5 key
	Key_Numpad6,      ///< The numpad 6 key
	Key_Numpad7,      ///< The numpad 7 key
	Key_Numpad8,      ///< The numpad 8 key
	Key_Numpad9,      ///< The numpad 9 key
	Key_F1,           ///< The F1 key
	Key_F2,           ///< The F2 key
	Key_F3,           ///< The F3 key
	Key_F4,           ///< The F4 key
	Key_F5,           ///< The F5 key
	Key_F6,           ///< The F6 key
	Key_F7,           ///< The F7 key
	Key_F8,           ///< The F8 key
	Key_F9,           ///< The F9 key
	Key_F10,          ///< The F10 key
	Key_F11,          ///< The F11 key
	Key_F12,          ///< The F12 key
	Key_F13,          ///< The F13 key
	Key_F14,          ///< The F14 key
	Key_F15,          ///< The F15 key
	Key_Pause,        ///< The Pause key

	Key_KeyCount      ///< Keep last -- the total number of keyboard keys
};
enum enum_Button
{
	Button_Left,       ///< The left mouse button
	Button_Right,      ///< The right mouse button
	Button_Middle,     ///< The middle (wheel) mouse button
	Button_XButton1,   ///< The first extra mouse button
	Button_XButton2,   ///< The second extra mouse button

	Button_ButtonCount ///< Keep last -- the total number of mouse buttons
};
namespace Law
{
	class Key
	{
	public:
		int state;
		bool released;

		Key();
		~Key();

		void update(bool pressed);
	};
	class Keyboard
	{
	public:
		Key keys[101];

		Keyboard();
		~Keyboard();

		int getStateKey(int which) const;
		bool getReleasedKey(int which) const;
		Key getKey(int which) const;

		void updateKey(int which, bool pressed);
		void update();


	};
	class Mouse
	{
	public:
		Mouse();
		~Mouse();

		int getStateKey(int which) const;
		bool getReleasedKey(int which) const;
		Key getKey(int which) const;

		void update(int which, bool pressed);

		void update(int x, int y);
		void update(sf::Vector2i pos);
		void update();
		sf::Vector2i getPosition();
		float getX();
		float getY();

		int x,  y;
	private:
		Key buttons[ButtonCount_];
		
	};

}

