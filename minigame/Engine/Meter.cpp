#include "Meter.h"

void Meter::IncreaseLevel()
{
	++level;
}

int Meter::GetLevel() const
{
	return level;
}

void Meter::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, level * scale, width, c);
}
