#pragma once

#include "Vec2int.h"
#include "Item.h"

class Snake;
struct SdlApp;

struct Apple final : public Item
{
public :
	inline Apple(Vec2Int loc)
		:Item(loc)
	{

	}

	virtual void consume(Snake& snake) override final;
	virtual void draw(SdlApp& app)override final;
};

