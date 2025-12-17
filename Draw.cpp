#include "Color.h"
#include "Variable.h"

void drawText(int x, int y, int col, const char* txt, int val, int siz)
{
	SetFontSize(siz);
	DrawFormatString(x + 2, y + 2, BLACK, txt, val);
	DrawFormatString(x, y, col, txt, val);
}

void drawCar(int x, int y, int type, const int* IMGCAR)
{
	DrawGraph(x - CAR_W[type] / 2, y - CAR_H[type] / 2, IMGCAR[type], TRUE);
}
