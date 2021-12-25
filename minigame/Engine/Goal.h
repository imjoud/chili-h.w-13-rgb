#pragma once
#include "Graphics.h"
#include "Dude.h"

class Goal
{
public:
	Goal (int in_x, int in_y)
		:
		x(in_x),
		y(in_y)
	{}
	void Draw(Graphics& gfx);
	bool TestCollision(const Dude& dude);
	void Respawn(int in_x, int in_y);
	void UpdateColor();
private:
	static constexpr int dimention = 20;
	Color c = { 255,0,0 };
	bool colorIncreasingG = true;
	bool colorIncreasingB = false;
	bool colorIncreasingR = false;
	int rgbSpeed = 5;
	int x;
	int y;
};
