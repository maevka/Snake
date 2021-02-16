#pragma once

#include "Vec2Int.h"
#include "SdlApp.h"
#include "Color.h"

struct SnakeBody
{
	Vec2Int location = { -10, -10};

	void draw(SdlApp& app);
};

