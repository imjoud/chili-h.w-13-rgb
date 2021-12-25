#pragma once

#include "Graphics.h"

class Meter
{
public:
	Meter(int x, int y)
		:
		x(x),
		y(y)
	{}
	void IncreaseLevel();
	void Draw(Graphics& gfx);
	int GetLevel() const;
private:
	static constexpr Color c = Colors::Green;
	static constexpr int width = 12;
	static constexpr int scale = 10;//it was 4
	int level = 0;
	int x;
	int y;
};