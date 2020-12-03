#include "Game.h"
#include <ctime>

int main(int argc, char ** argv)
{
	srand(time(0));
	Game game;
	game.OpenWindow(800, 600);
	game.Load();
	game.PlayLoop();
	return 0;
}