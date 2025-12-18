#include "Color.h"
#include "Variable.h"
#include "Draw.h"


Scene title(CAR* player, COM_CAR* computer, FUEL* fuel, INFO* info, const SOUND& SOUND)
{
	drawText({ 160, 160 }, WHITE, "Car Race", 0, 100);
	if (info->timer % 60 < 30) drawText({ 210, 400 }, GREEN, "Click to start.", 0, 40);
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		player->pos.x = WIDTH / 2;
		player->pos.y = HEIGHT / 2;
		for (int i = 0; i < COM_MAX; i++)
		{
			computer[i].car.pos.y = HEIGHT + 100;
			computer->flag = 0;
		}
		fuel->pos.x = WIDTH / 2;
		fuel->pos.y = -100;
		info->score = 0;
		fuel->fuelAmount = 1000;
		PlaySoundMem(SOUND.bgm, DX_PLAYTYPE_LOOP);
		return PLAY;
	}

	return TITLE;

}