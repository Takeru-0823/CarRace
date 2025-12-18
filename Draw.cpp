#include "Color.h"
#include "Variable.h"

void drawText(VECTOR2 pos, int col, const char* txt, int val, int siz)
{
	SetFontSize(siz);
	DrawFormatString(pos.x + 2, pos.y + 2, BLACK, txt, val);
	DrawFormatString(pos.x, pos.y, col, txt, val);
}

void drawCar(const CAR& CAR, const int* IMGCAR)
{
	DrawGraph(CAR.pos.x - CAR_W[CAR.type] / 2, CAR.pos.y - CAR_H[CAR.type] / 2, IMGCAR[CAR.type], TRUE);
}
