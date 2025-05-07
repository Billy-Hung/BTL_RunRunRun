#include "Map.hpp"

Map::Map(const char* fileName)
{
	mTex1 = TextureManager::LoadTexture(fileName);
}

Map::Map(const char* fileName1, const char* fileName2)
{
	mTex1 = TextureManager::LoadTexture(fileName1);
	mTex2 = TextureManager::LoadTexture(fileName2);
}

void Map::render()
{
	if(static_cast<int>(SDL_GetTicks() / 200) % 2 == 0)
	{
		SDL_RenderCopy(Game::renderer, mTex1, NULL, NULL);
	}
	else{
		SDL_RenderCopy(Game::renderer, mTex2, NULL, NULL);
	}
}