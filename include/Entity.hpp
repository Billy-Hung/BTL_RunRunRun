#pragma once

#include "Game.hpp"
#include "Vector2D.hpp"
#include "TextureManager.hpp"

class Entity
{
private:
	bool active = true;
	int spawn_y;

	int offSet = 180;
	float zoom;
	int lane;
	float velocity;

	SDL_Texture* eTex;
	Vector2D position;
	int width;
	int height;
	int scale;

	SDL_Rect srcRect, destRect;

	Uint32 timer;

public:
	Entity(const char* texturesheet, int x, int y);
	~Entity();

	SDL_Rect getdRect() const { return destRect; }
	int getLane();
	void update();
	void render();
	float speed();
	bool isActive() { return active; }

};