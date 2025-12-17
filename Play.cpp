#include "Color.h"
#include "Variable.h"
#include "Draw.h"

Scene play(CAR* player, COM_CAR* computer, FUEL* fuel, INFO* info, const int* IMGCAR, const SOUND* SOUND)
{
	info->bgY = (info->bgY + 10) % HEIGHT;

	GetMousePoint(&player->pos.x, &player->pos.y);
	if (player->pos.x < 260) player->pos.x = 260;
	if (player->pos.x > 460) player->pos.x = 460;
	if (player->pos.y < 40) player->pos.y = 40;
	if (player->pos.y > 600) player->pos.y = 600;
	drawCar(player->pos.x, player->pos.y, player->type, IMGCAR);

	for (int i = 0; i < COM_MAX; i++)
	{
		
		computer[i].car.pos.y = computer[i].car.pos.y + 1 + i;

		if (computer[i].car.pos.y > HEIGHT + 100)
		{
			computer[i].car.pos.x = rand() % 180 + 270;
			computer[i].car.pos.y = -100;
			computer[i].car.type = YELLOW_CAR + rand() % 3;
			computer[i].flag = false;
		}

		VECTOR2 distance =
		{
			distance.x = abs(computer[i].car.pos.x - player->pos.x),
			distance.y = abs(computer[i].car.pos.y - player->pos.y)
		};

		VECTOR2 size =
		{
			CAR_W[player->type] / 2 + CAR_W[computer[i].car.type] / 2 - 4,
			CAR_H[player->type] / 2 + CAR_H[computer[i].car.type] / 2 - 4
		};

		if (distance.x < size.x && distance.y < size.y)
		{
			int col = GetColor(rand() % 255, rand() % 255, rand() % 255);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawBox(player->pos.x - CAR_W[player->type] / 2, player->pos.y - CAR_H[player->type] / 2, player->pos.x + CAR_W[player->type] / 2, player->pos.y + CAR_H[player->type] / 2, col, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			PlaySoundMem(SOUND->seCrash, DX_PLAYTYPE_BACK);
			fuel->fuelAmount -= 10;
		}

		if (computer[i].car.pos.y > player->pos.y && computer[i].flag == false)
		{
			computer[i].flag = true;
			info->score += 100;
			if (info->score > info->highScore) info->highScore = info->score;
		}

		drawCar(computer[i].car.pos.x, computer[i].car.pos.y, computer[i].car.type, IMGCAR);
	}

	fuel->pos.y += 4;
	if (fuel->pos.y > HEIGHT) fuel->pos.y = -100;
	if (abs(fuel->pos.x - player->pos.x) < CAR_W[player->type] / 2 + 12 && abs(fuel->pos.y - player->pos.y) < CAR_H[player->type] / 2 + 12)
	{
		fuel->pos.x = rand() % 180 + 270;
		fuel->pos.y = -500;
		fuel->fuelAmount += 200;
		PlaySoundMem(SOUND->seFuel, DX_PLAYTYPE_BACK);
	}
	DrawGraph(fuel->pos.x - FUELSIZE, fuel->pos.y - FUELSIZE, fuel->imgFuel, TRUE);


	fuel->fuelAmount -= 1;
	if (fuel->fuelAmount < 0)
	{
		fuel->fuelAmount = 0;
		info->timer = 0;
		StopSoundMem(SOUND->bgm);
		PlaySoundMem(SOUND->jin, DX_PLAYTYPE_BACK);
		return OVER;
	}

	return PLAY;

}