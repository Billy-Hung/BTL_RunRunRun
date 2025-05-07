#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"

class Map
{
private:
	SDL_Texture* mTex1;
	SDL_Texture* mTex2;
public:
	Map(const char* fileName);
	Map(const char* fileName1, const char* fileName2);
	~Map();

	void render();
};