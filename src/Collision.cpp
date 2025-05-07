#include "Collision.hpp"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
	if(recA.y == recB.y && recA.x + recA.w >= recB.x && recB.x + recB.w >= recA.x)
	{
		return true;
	}

	return false;
}