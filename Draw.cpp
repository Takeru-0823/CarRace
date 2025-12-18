#include "Color.h"
#include "Variable.h"

void drawText(VECTOR2 pos, int col, const char* txt, int val, int siz)
{
	SetFontSize(siz);
	DrawFormatString(pos.x + 2, pos.y + 2, BLACK, txt, val);
	DrawFormatString(pos.x, pos.y, col, txt, val);
}

void drawCar(VECTOR2 pos, int type, const int* IMGCAR)
{
	DrawGraph(pos.x - CAR_W[type] / 2, pos.y - CAR_H[type] / 2, IMGCAR[type], TRUE);
}
