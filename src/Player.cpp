#include "Player.hpp"
	

Player::Player(const char* texturesheet)
{
	pTex = TextureManager::LoadTexture(texturesheet);
	position = Vector2D(512, 428);
}

Player::~Player() {}

void Player::update()
{
	movement();
	srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / frameDelay) % frames);
	srcRect.y = 0;
	srcRect.w = width;
	srcRect.h = height;

	destRect.x = position.x;
	destRect.y = position.y;
	destRect.w = width * scale;
	destRect.h = height * scale;
}

void Player::render()
{
	TextureManager::Draw(pTex, srcRect, destRect);
}

void Player::movement()
{
	if(Game::event.type == SDL_KEYDOWN && Game::event.key.repeat == 0)
	{
		switch(Game::event.key.keysym.sym)
		{
		case SDLK_a:
			position.x -= 377;
			break;
		case SDLK_d:
			position.x += 377;
			break;
		case SDLK_LEFT:
			position.x -= 377;
			break;
		case SDLK_RIGHT:
			position.x += 377;
			break;
		default:
			break;	
		}
	}

	if(position.x < 0)
	{
		position.x = 135;	
	}
	if(position.x > 1024)
	{
		position.x = 889;
	}
}