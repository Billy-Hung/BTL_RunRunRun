#pragma once

#include "Game.hpp"
#include "Vector2D.hpp"
#include "TextureManager.hpp"

class Player
{
private:
	SDL_Texture* pTex;

	Vector2D position;
	int width = 32;
	int height = 32;
	int scale = 4;

	int frames = 4;
	int frameDelay = 100;

	SDL_Rect srcRect, destRect;

public:
	bool isdeath = false;

	Player(const char* texturesheet);
	~Player();

	SDL_Rect getdRect() const { return destRect; }
	void update();
	void render();
	void movement();
	void heart();

};