#pragma once

#include "Item.h"

class SlowDownItem final : public Item
{
public:
	inline SlowDownItem(Vec2Int loc)
		:Item(loc)
	{

	}

	virtual void consume(Snake& snake) override final;
	virtual void draw(SdlApp& app)override final;
};

