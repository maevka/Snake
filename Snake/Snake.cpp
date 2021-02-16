#ifndef SNAKE_H_
#include "Snake.h"
#endif
#include "SdlApp.h"
#include "Color.h"
#include "TimeManager.h"

#include <iostream>

Snake::Snake()
{
	for (int i = 0; i < 3; i++)
	{
		bodyParts.emplace_back();
	}
	bodyParts.front().location = {0, 0};
}

bool Snake::update(const TimeManager& timeManager)
{
	if (timeManager.time > lastUpdateTime + updateDelay)
	{
		lastUpdateTime = SDL_GetTicks();
		if (!bodyParts.empty())
		{
			vector<SnakeBody>::iterator it = bodyParts.begin();
			Vec2Int lastLocation = it->location;
			it->location += direction;

			it++;

			while (it != bodyParts.end())
			{
				Vec2Int temp = it->location;
				it->location = lastLocation;
				lastLocation = temp;
				it++;
			}

			return true;
		}
	}

	return false;
}

void Snake::draw(SdlApp& app)
{
	for (SnakeBody& body : bodyParts)
	{
		body.draw(app);
	}
}

void Snake::inputs(const SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.scancode)
		{
		case SDL_SCANCODE_W: // Z to go UP
			direction = { 0, -1};
			break;
		case SDL_SCANCODE_S: // S to go DOWN
			direction = { 0, 1};
			break;
		case SDL_SCANCODE_A: // Q to go LEFT
			direction = { -1, 0};
			break;
		case SDL_SCANCODE_D: // D to go RIGHT
			direction = { 1, 0};
			break;
		default:
			break;
		}
	}
}

bool Snake::isHeadInsideAnotherSnake(const Snake& anotherSnake) const
{
	for (const SnakeBody& bodyPart : anotherSnake.bodyParts)
	{
		if (getHeadLocation() == bodyPart.location
			&& !isHead(bodyPart))
		{
			return true;
		}
	}

	return false;
}
