#include "Heart.hpp"

Heart::Heart()
{
	hTex = TextureManager::LoadTexture("res/player/heart_sprite.png");
}

void Heart::update(bool col)
{
	if(col)
	{
		hit++;
	}

	srcRect.x = hit * 32; 
	srcRect.y = 0;
	srcRect.w = srcRect.h = 32;

	destRect.x = destRect.y = 50;
	destRect.w = destRect.h = 32 * 3;
}

void Heart::render()
{
	TextureManager::Draw(hTex, srcRect, destRect);
}