#pragma once
#include "System.h"
#include "Peripherals.h"
#include "Animation.h"
#include "Collision.h"
#include <list>
#include <vector>
#include "Matrix.h"
#include "NNInterface.h"



using namespace Law;
using namespace sf;

using Law::Animation;
//typedef list<Law::Block>::iterator itBlock;
class Game
{
public:
	Game();
	~Game();

	void OpenWindow(int widht, int height, string name = "window", bool fullscreen = false);
	
	void Load();

	void End();

	void Play();
	void PlayLoop();
	void StartFrame();

	void Draw();

	void Reset();

	void generateDataToTrain();

	void runNeural();


	//Inputs
	
	Law::Keyboard PreciseKeyboard;
	Law::Keyboard keyboard;
	Law::Mouse mouse;
	Law::Mouse mousetile;

	RenderWindow Window;
	RenderWindow PickTileWindow;

	float DeltaMouseWheel;
	Clock seconds;
	int loops;
	float delta;
	int fps;
	//End of Inputs
	bool start;
	bool keep;
	

	vector<sf::Sprite> pattern;
	Matrix<int> matrix;
	Matrix<int> outmatrix;
	sf::Vector2i matrixV, dimensionsPattern;
	NNInterface net;
	
};

