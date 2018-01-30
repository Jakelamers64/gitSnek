#include "Snake.h"
#include <assert.h>

void Snake::Segmants::initHead(const Location & in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segmants::initBody()
{
	c = Snake::bodyColor;
}

void Snake::Segmants::moveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.add(delta_loc);
}

void Snake::Segmants::follow(const Segmants & next)
{
	loc = next.loc;
}

void Snake::Segmants::draw(Board & brd) const
{
	brd.draw(loc, c);
}

const Location& Snake::Segmants::getLocation() const
{
	return loc;
}

Snake::Snake(const Location & loc)
{
	segmants[0].initHead(loc);
}

void Snake::moveBy(const Location & delta_loc)
{
	for (int i = numberOfSegmants - 1; i > 0; --i)
	{
		segmants[i].follow(segmants[i - 1]);
	}
	segmants[0].moveBy(delta_loc);
}

void Snake::grow()
{
	if (numberOfSegmants < maxNumberOfSegmants)
	{
		segmants[numberOfSegmants].initBody();
		++numberOfSegmants;
	}
}

void Snake::draw(Board & brd) const
{
	for (int i = 0; i < numberOfSegmants; ++i)
	{
		segmants[i].draw(brd);
	}
}

Location Snake::getNextHeadLocation(const Location & delta_loc) const
{
	Location l(segmants[0].getLocation());
	l.add(delta_loc);
	return l;
}

bool Snake::isInTileExceptEnd(const Location & target) const
{
	for (int i = 0; i < numberOfSegmants - 1; ++i)
	{
		if (segmants[i].getLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::isInTile(const Location & target) const
{
	for (int i = 0; i < numberOfSegmants; ++i)
	{
		if (segmants[i].getLocation() == target)
		{
			return true;
		}
	}
	return false;
}
