#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

#include "Snake.h"
#include "Item.h"
#include "SdlApp.h"
#include "TimeManager.h"

using namespace std;

class Game
{
private :
	int width = 800;
	int height = 600;

	bool closeWindow = false;

	TimeManager timeManager;

	SdlApp app;

	unique_ptr<Snake> snake = make_unique<Snake>();
	vector<unique_ptr<Item>> items;
	int nbCasesX = 0;
	int nbCasesY = 0;

public :
	Game();
	~Game();

	void run();

	void inputs(const SDL_Event& event);
	void update();
	void draw();

	void checkSnakeItemsCollision(Snake& snake);
	bool isSnakeInWall(const Snake& snake);
	bool isSnakeHeadInSnake(const Snake& snake);

	template<typename ITEM_TYPE>
	inline void addItem(const Vec2Int location)
	{
		items[location.x + location.y * nbCasesX] = make_unique<ITEM_TYPE>(location);
	}

	template<typename ITEM_TYPE>
	inline void addItemAtRandomLocation()
	{
		assert(nbCasesX > 0 && nbCasesY > 0);
		Vec2Int randomLocation = { rand() % nbCasesX, rand() % nbCasesY };
		addItem<ITEM_TYPE>(randomLocation);
	}

	void addRandomItemAtRandomLocation();
};

#endif // !GAME_H_


