#pragma once

#include "Game.hpp"
#include "Player.hpp"
#include "Entity.hpp"

class Collision
{
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};