#include "SpeedUpItem.h"
#include "Snake.h"

void SpeedUpItem::consume(Snake& snake)
{
	snake.speedUp();
}

void SpeedUpItem::draw(SdlApp& app)
{
	app.drawRectangle(Color::white(), SDL_Rect{ location.x, location.y, 1, 1 });
}
