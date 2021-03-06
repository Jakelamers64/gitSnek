#include "Board.h"
#include <assert.h>

Board::Board(Graphics & gfx)
	: gfx(gfx)
{}

void Board::draw(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.y >= 0);
	assert(loc.x < width);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x * dimensions, loc.y * dimensions, dimensions, dimensions, c);
}

int Board::getWidth() const
{
	return width;
}

int Board::getHeight() const
{
	return height;
}

bool Board::snekIsInsideBrd(const Location & loc) const
{
	return loc.x >= 0 &&
		loc.x < width &&
		loc.y >= 0 &&
		loc.y < height;
}
