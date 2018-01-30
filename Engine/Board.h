#pragma once

#include "Graphics.h"
#include "Location.h"


class Board
{
public:
	Board(Graphics& gfx);
	void draw(const Location& loc, Color c);
	int getWidth() const;
	int getHeight() const;
	bool snekIsInsideBrd(const Location& loc) const;
private:
	static constexpr int dimensions = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
	Graphics& gfx;

};
