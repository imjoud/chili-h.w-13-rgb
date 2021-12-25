#include "Goal.h"

void Goal::Draw(Graphics& gfx)
{
	gfx.DrawRectDim(x, y, dimention, dimention, c);
}

bool Goal::TestCollision(const Dude& dude)
{
	const int duderight = dude.GetX() + dude.GetWidth();
	const int dudebottom = dude.GetY() + dude.GetHeight();
	const int pooright = x + dimention;
	const int poobottom = y + dimention;

	return
		duderight >= x &&
		dude.GetX() <= pooright &&
		dudebottom >= y &&
		dude.GetY() <= poobottom;
}

void Goal::Respawn(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

void Goal::UpdateColor()
{
	if (colorIncreasingG)
	{
		c = Color(c.GetR() - rgbSpeed, c.GetG() + rgbSpeed, c.GetB() + 0);
		if (c.GetR() == 0 && c.GetG() == 255 && c.GetB() == 0)
		{
			colorIncreasingG = false;
			colorIncreasingB = true;
		}

	}
	if (colorIncreasingB)
	{
		c = Color(c.GetR() + 0, c.GetG() - rgbSpeed, c.GetB() + rgbSpeed);
		if (c.GetR() == 0 && c.GetG() == 0 && c.GetB() == 255)
		{
			colorIncreasingB = false;
			colorIncreasingR = true;
		}
	}
    if (colorIncreasingR)
	{
		c = Color(c.GetR() + rgbSpeed, c.GetG() + 0, c.GetB() - rgbSpeed);
		if (c.GetR() == 255 && c.GetG() == 0 && c.GetB() == 0)
		{
			colorIncreasingR = false;
			colorIncreasingG = true;
		}
	}
}
