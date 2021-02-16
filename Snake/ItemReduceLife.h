#pragma once

#include "Item.h"

struct SdlApp;

class ItemReduceLife final : public Item
{
public:
	inline ItemReduceLife(Vec2Int loc)
		:Item(loc)
	{

	}

	virtual void consume(Snake& snake) override final;
	virtual void draw(SdlApp& app)override final;
};

