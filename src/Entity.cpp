#include "Entity.hpp"

Entity::Entity(const char* texturesheet, int x, int y)
{
	eTex = TextureManager::LoadTexture(texturesheet);
	width = 32;
	height = 32;
	scale = 2;
	velocity = 0.0f;

	timer = SDL_GetTicks();
	position = Vector2D(x, y);
	spawn_y = y;
}

Entity::~Entity() {}

void Entity::update()
{	
	if(position.y > 576)
	{
		position.y = spawn_y;

		lane = rand() % 3 + 1;
	}

	srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / 150) % 3);
	srcRect.y = 0;
	srcRect.w = width;
	srcRect.h = height;

	zoom = ((position.y - 144) / 144);

	position.y += speed();
	position.x = (1152 - width * scale * zoom) / 2 + getLane() * offSet * zoom;

	destRect.x = position.x;
	destRect.y = static_cast<int>(position.y);
	destRect.w = static_cast<int>(width * scale * zoom);
	destRect.h = static_cast<int>(height * scale * zoom);
}

void Entity::render()
{
	TextureManager::Draw(eTex, srcRect, destRect);
}

float Entity::speed()
{
	velocity = 0.01 + 2 * ((position.y - 144) / 144) * ((position.y - 144) / 144);
	return velocity;
}

int Entity::getLane()
{
	switch(lane)
	{
	case 1:
		return -1;
	case 2:
		return 0;
	case 3:
		return 1;
	default:
		return 0;
	}
}