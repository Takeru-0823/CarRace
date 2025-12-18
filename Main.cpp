#include "Variable.h"
#include "Color.h"
#include "Title.h"
#include "Play.h"
#include "Over.h"
#include "Draw.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	SetWindowText("カーレース");
	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;
	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);

	int bgY = 0;
	const int IMGBG = LoadGraph("image/bg.png");

	const int IMGCAR[CAR_MAX] =
	{
		LoadGraph("image/car_red.png"),
		LoadGraph("image/car_yellow.png"),
		LoadGraph("image/car_blue.png"),
		LoadGraph("image/truck.png")
	};

	CAR player = { WIDTH / 2, HEIGHT / 2, RED_CAR };

	COM_CAR computer[COM_MAX];

	for (int i = 0; i < COM_MAX; i++)
	{
		computer[i] = { rand() % 180 + 270, -100, YELLOW_CAR + rand() % 3, false };
	}

	INFO info = { 0, 0, 0, 5000 };

	FUEL fuel = { WIDTH / 2, 0, 0, LoadGraph("image/fuel.png")};

	const SOUND SOUND =
	{
		LoadSoundMem("Sound/bgm.mp3"),
		LoadSoundMem("Sound/gameover.mp3"),
		LoadSoundMem("Sound/fuel.mp3"),
		LoadSoundMem("Sound/crash.mp3")
	};

	Scene scene = TITLE;

	ChangeVolumeSoundMem(128, SOUND.bgm);
	ChangeVolumeSoundMem(128, SOUND.jin);

	while (1)
	{
		ClearDrawScreen();

		DrawGraph(0, bgY - HEIGHT, IMGBG, FALSE);
		DrawGraph(0, bgY, IMGBG, FALSE);

		info.timer++;

		switch (scene)
		{
		case TITLE:
			scene = title(&player, computer, &fuel, &info, SOUND);
			break;

		case PLAY:
			scene = play(&player, computer, &fuel, &info, IMGCAR, &SOUND);
			break;

		case OVER:
			scene = over(&info, &player, computer, IMGCAR);
			break;
		}

		drawText(10, 10, SKYBLUE, "SCORE %d", info.score, 30);
		drawText(WIDTH - 200, 10, YELLOW, "HI-SC %d", info.highScore, 30);
		int col = GREEN;
		if (fuel.fuelAmount < 400) col = ORANGE;
		if (fuel.fuelAmount < 200) col = RED;
		drawText(10, HEIGHT - 40, col, "FUEL %d", fuel.fuelAmount, 30);

		ScreenFlip();
		WaitTimer(16);
		if (ProcessMessage() == -1) break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
	}

	DeleteGraph(IMGBG);
	DeleteSoundMem(SOUND.bgm);
	DeleteSoundMem(SOUND.jin);
	DeleteSoundMem(SOUND.seFuel);
	DeleteSoundMem(SOUND.seCrash);
	for (int i = 0; i < CAR_MAX; i++)
	{
		DeleteGraph(IMGCAR[i]);
	}


	DxLib_End();
	return 0;
}