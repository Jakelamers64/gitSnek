#include "Goal.h"
#include <random>

Goal::Goal(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	respawn(rng, brd, snake);
}

void Goal::respawn(std::mt19937 & rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution <int> xDist(0, brd.getWidth() - 1);
	std::uniform_int_distribution <int> yDist(0, brd.getHeight() - 1);

	Location newLoc;
	do
	{
		newLoc = { xDist(rng), yDist(rng) };
	} while ( snake.isInTile( newLoc ));

	loc = newLoc;
}

void Goal::draw(Board & brd)
{
	brd.draw(loc, c);
}

const Location & Goal::getLocation() const
{
	return loc;
}
