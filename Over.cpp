#include "Color.h"
#include "Variable.h"
#include "Draw.h"

Scene over(INFO* info,CAR* player, COM_CAR* computer, const int* IMGCAR)
{
	for (int i = 0; i < COM_MAX; i++)
	{
		computer[i].car.pos.y = computer[i].car.pos.y - 1 - i;
		if (computer[i].car.pos.y < -100) computer[i].car.pos.y = HEIGHT + 100;

		drawCar(computer[i].car.pos, computer[i].car.type, IMGCAR);

	}
	drawCar(player->pos, player->type, IMGCAR);

	drawText({ 180, 240 }, RED, "GAME OVER", 0, 80);
	if (info->timer > 60 * 5) return TITLE;
	return OVER;
}