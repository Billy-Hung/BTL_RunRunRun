#pragma once

#include "TextureManager.hpp"
#include "Collision.hpp"

class Heart
{
private:
	int hit = 0;
	SDL_Texture* hTex;
	SDL_Rect srcRect, destRect;
public:
	Heart();
	~Heart();

	void update(bool col);
	void render();
	int get() { return hit; }
};