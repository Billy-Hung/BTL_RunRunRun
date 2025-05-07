#include "Game.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include "Collision.hpp"
#include "Heart.hpp"

using namespace std;

Player* player;

Entity* obs1;
Entity* obs2;

Map* map;

Heart* hp;

SDL_Event Game::event;

Game::Game() {}
Game::~Game() {}

SDL_Renderer* Game::renderer = nullptr;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL Initialised!" << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(window)
		{
			cout << "Window is created!" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if(renderer)
		{
			cout << "Renderer is created!" << endl;
		}

		isRunning = true;
	}else{
		isRunning = false;
	}

	map = new Map("res/background/bg1.png", "res/background/bg2.png");

	player = new Player("res/player/player_sprite.png");
	player->movement();

	obs1 = new Entity("res/envi/obs.png", 544, 250);
	obs2 = new Entity("res/envi/obs.png", 544, 250);

	hp = new Heart();
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch(event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	col = false;

	player->update();
	obs1->update();
	obs2->update();
	if(Collision::AABB(player->getdRect(), obs1->getdRect()) || Collision::AABB(player->getdRect(), obs2->getdRect()))
	{
		col = true;
	}
	
	hp->update(col);

	if(hp->get() >= 2)
	{
		player = nullptr;
	}

} 	

void Game::render()
{
	SDL_RenderClear(renderer);

	map->render();

	obs1->render();
	obs2->render();

	if(player) player->render(); 
	hp->render();

	SDL_RenderPresent(renderer);

}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
