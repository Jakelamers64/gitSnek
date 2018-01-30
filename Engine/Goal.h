#pragma once

#include "Board.h"
#include "Snake.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snake );
	void respawn( std::mt19937& rng, const Board& brd, const Snake& snake );
	void draw(Board& brd);
	const Location& getLocation() const;
private:
	static constexpr Color c = Colors::Red;
	Location loc;
};