#include "Game.hpp"

using namespace std;

Game* game = nullptr;

int main(int argc, char* argv[])
{
	srand(time(0));

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("RunRunRun v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1152, 576, false);

	while(game->running())
	{

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	game->clean();

	return 0;
}