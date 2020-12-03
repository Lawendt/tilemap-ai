#include "Game.h"
#include "Resource.h"
#include <cmath>
#include <fstream>


Game::Game()
{
	loops = 0;
	fps = 60;
	delta = 1 / (float)fps;
	//delta = 0;

	int n = rand() % 10;
	start = false;
	keep = true;
}
Game::~Game()
{
}
void Game::OpenWindow(int widht, int height, string title, bool fullscreen)
{
	Window.create(sf::VideoMode(widht, height), title);
	Window.setFramerateLimit(60);

}
void Game::StartFrame()
{
	mouse.update();
	Window.clear();
	PickTileWindow.clear();
	Event event;
	while (Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			End();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			keyboard.updateKey(event.key.code, true);
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			keyboard.updateKey(event.key.code, false);
		}
		if (event.type == sf::Event::MouseWheelScrolled)
		{
			DeltaMouseWheel = event.mouseWheelScroll.delta;
		}
		else
		{
			DeltaMouseWheel = 0;
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			mouse.update(event.mouseButton.button, true);
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			mouse.update(event.mouseButton.button, false);
		}
		if (event.type == sf::Event::MouseMoved)
		{
			mouse.update(event.mouseMove.x, (int)event.mouseMove.y);
		}
	}
	while (PickTileWindow.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			mousetile.update(event.mouseButton.button, true);
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			mousetile.update(event.mouseButton.button, false);
		}
		if (event.type == sf::Event::MouseMoved)
		{
			mousetile.update(event.mouseMove.x, (int)event.mouseMove.y);
		}
	}
	PreciseKeyboard.update();
}
void Game::PlayLoop()
{
	while (Window.isOpen())
	{	/*
		static Clock c;
		delta = c.getElapsedTime().asMilliseconds*/;
	StartFrame();
	Play();



	Window.display(); //Don't delete
	PickTileWindow.display();
	loops++;
	if (seconds.getElapsedTime().asMilliseconds() >= 1000)
	{
		cout << loops << " fps\n";
		//delta = 1 / (float)loops;
		loops = 0;
		seconds.restart();
		//cout << ball.getPosition().x << endl;
	}
	}
}
void Game::Load()
{
	seconds.restart();

	//Matrix mading
	//dimensionsPattern.x = 15;
	//dimensionsPattern.y = 15;
	//matrixV.x = Window.getSize().x / dimensionsPattern.x;
	//matrixV.y = Window.getSize().y / dimensionsPattern.y;

	matrixV.x = 7;
	matrixV.y = 7;
	dimensionsPattern.x = Window.getSize().x / 2 / matrixV.x;
	dimensionsPattern.y = Window.getSize().y / 2 / matrixV.y;

	matrix.setDimensions(matrixV.x, matrixV.y);
	outmatrix.setDimensions(matrixV.x, matrixV.y);

	//Patterns

	gResource->loadTexture("tileset.png", "tileset");
	Texture *texture = gResource->getTexture("tileset");
sf:Sprite *object = new sf::Sprite;
	object->setScale(dimensionsPattern.x / 8.0f, dimensionsPattern.y / 8.0f);
	object->setTexture(*texture, true);
	IntRect rect;
	rect.height = 8;
	rect.width = 8;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			rect.left = x * 8;
			rect.top = y * 8;
			object->setTextureRect(rect);
			pattern.push_back(*object);
		}
	}

	delete object;


	//Testing
	for (int y = 0; y < matrixV.y; y++)
	{
		for (int x = 0; x < matrixV.x; x++)
		{
			matrix.setElement(x, y, rand() % pattern.size());
			outmatrix.setElement(x, y, rand() % pattern.size());
		}
	}

	PickTileWindow.create(sf::VideoMode(dimensionsPattern.x * pattern.size() / 4, dimensionsPattern.x * pattern.size() / 4), "Pick Tile Window");
	PickTileWindow.setFramerateLimit(60);

	cout << "Train NN\n";
	net.trainWithData("testeAll.data");

	cout << "Finished\n";

}



void Game::Reset()
{
	for (int y = 0; y < matrixV.y; y++)
	{

		for (int x = 0; x < matrixV.x; x++)
		{
			//matrix[x][y] = 0;
		}

	}
}

void Game::generateDataToTrain()
{
	cout << "Write the name of the test file: \n";
	string name;
	getline(cin, name);
	if (name == 'n')
		return;
	ofstream file(name);
	float divisor = pattern.size() / 2;
	if (file.is_open()) {
		file << (matrixV.y * matrixV.x) << " " << 8 << " " << pattern.size() << endl;
		int rx, ry;
		for (int y = 0; y < matrixV.y; y++)
		{
			for (int x = 0; x < matrixV.x; x++)
			{
				for (int yi = -1; yi <= 1; yi++)
				{
					for (int xi = -1; xi <= 1; xi++)
					{
						if (xi == 0 && yi == 0) {
							file << -2;
							continue;
						}
						rx = x + xi;
						ry = y + yi;
						if (rx < 0 || ry < 0) {
							file << -2;
							continue;
						}
						if (rx >= matrixV.x || ry >= matrixV.y) {
							file << -2;
							continue;
						}

						file << matrix.getElement(rx, ry) / divisor - 1 << " ";

					}
				}
				file << endl;
				int element = matrix.getElement(x, y);
				for (int i = 0; i < pattern.size(); i++) {
					if (i == element)
						file << 1 << " ";
					else
						file << 0 << " ";
				}
				file << endl;
			}
		}

		cout << "End of save train data\n";
	}
	else {
		cout << "could't open the file\n";
	}
}

void Game::runNeural()
{
	float divisor = pattern.size() / 2;
	float *input = new float[8];
	float *result;
	int rx, ry;
	for (int y = 0; y < matrixV.y; y++)
	{
		for (int x = 0; x < matrixV.x; x++)
		{
#pragma region get Inputs
			for (int yi = -1; yi <= 1; yi++)
			{
				for (int xi = -1; xi <= 1; xi++)
				{
					if (xi == 0 && yi == 0) {
						continue;
					}
					rx = x + xi;
					ry = y + yi;
					if (rx < 0 || ry < 0) {
						input[xi + yi * 3] = -2;
						continue;
					}
					if (rx >= matrixV.x || ry >= matrixV.y) {
						input[xi + yi * 3] = -2;
						continue;
					}
					input[xi + yi * 3] = matrix.getElement(rx, ry) / divisor - 1;
				}
			}
#pragma endregion
			result = net.run(input);
			float highest = result[0];
			int best = 0;
			for (int i = 1; i < net.num_output; i++) {
				if (highest < result[i]) {
					best = i;
					highest = result[i];
				}
			}
			cout << "Choosed " << best << " with " << highest;
			outmatrix.setElement(x, y, best);
		}
	}
}

void Game::Play()
{
	if (keyboard.getStateKey(Key_R) == Key_Pressed)
		runNeural();

	if (keyboard.getStateKey(Key_E) == Key_Pressed)
		Reset();

	if (keyboard.getStateKey(Key_S) == Key_Pressed)
	{
		cout << "Save input? ";
		char n;
		cin >> n;

		cout << "Write the name of the file to save: \n";
		string name;
		getline(cin, name);
		if (name == 'n')
			return;
		ofstream file(name);
		if (file.is_open()) {
			if (n == 'n')
			{
				file << outmatrix;
			}
			else
			{
				file << matrix;
			}
			cout << "End of save\n";
		}
		else {

			cout << "could't open the file\n";
		}
	}

	if (keyboard.getStateKey(Key_L) == Key_Pressed)
	{
		cout << "Write the name of the file to load: \n";
		string name;
		getline(cin, name);
		if (name == 'n')
			return;
		ifstream file(name);
		if (file.is_open()) {
			file >> matrix;
			cout << "End of Load\n";
		}
		else {
			cout << "could't open the file\n";
		}
	}

	if (keyboard.getStateKey(Key_T) == Key_Pressed)
	{
		generateDataToTrain();
	}

	if (keyboard.getStateKey(Key_Space) == Key_Pressed)
		start = !start;
	Draw();

	static int mode = 0;
	if (mouse.getStateKey(Button_Right) == Key_Pressed)
	{
		mode++;
		if (mode == pattern.size())
			mode = 0;
	}

	if (mouse.getStateKey(Button_Left) == Key_Hold)
	{
		if (mouse.x > 0 && mouse.x < Window.getSize().x && mouse.y > 0 && mouse.y < Window.getSize().y)
			matrix.setElement(mouse.x / dimensionsPattern.x, mouse.y / dimensionsPattern.y, mode);
	}

	if (mousetile.getStateKey(Button_Left) == Key_Pressed)
	{
		if (mousetile.x > 0 && mousetile.x < PickTileWindow.getSize().x && mousetile.y > 0 && mousetile.y < PickTileWindow.getSize().y)
			mode = mousetile.x / dimensionsPattern.x + mousetile.y / dimensionsPattern.y * pattern.size() / 4;
	}

	if (mode == pattern.size())
		mode = 0;



	static Clock c;
	if (start && c.getElapsedTime().asMilliseconds() > 1) // tava 10
	{
		c.restart();

	}


}
void Game::End()
{
	Window.close();
	PickTileWindow.close();
}


void Game::Draw()
{
	float dy = 0;
	for (int y = 0; y < matrixV.y; y++)
	{
		float dx = 0;
		for (int x = 0; x < matrixV.x; x++)
		{
			Sprite *object = &pattern[matrix.getElement(x, y)];
			object->setPosition(dx, dy);
			Window.draw(*object);
			dx += dimensionsPattern.x;
		}
		dy += dimensionsPattern.y;
	}

	dy = Window.getSize().y / 2;
	for (int y = 0; y < matrixV.y; y++)
	{
		float dx = Window.getSize().x / 2;
		for (int x = 0; x < matrixV.x; x++)
		{
			Sprite *object = &pattern[outmatrix.getElement(x, y)];
			object->setPosition(dx, dy);
			Window.draw(*object);
			dx += dimensionsPattern.x;
		}
		dy += dimensionsPattern.y;
	}

	for (int y = 0; y < (pattern.size() / 4); y++)
	{
		for (int x = 0; x < (pattern.size() / 4); x++)
		{
			Sprite *object = &pattern[x + y * (pattern.size() / 4)];
			object->setPosition(dimensionsPattern.x * x, dimensionsPattern.y * y);
			PickTileWindow.draw(*object);
		}
	}
}
