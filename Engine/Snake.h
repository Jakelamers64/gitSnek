#pragma once
#include "Location.h"
#include "Board.h"

class Snake
{
private:
	class Segmants
	{
	public:
		void initHead(const Location& in_loc);
		void initBody();
		void moveBy(const Location& delta_loc);
		void follow(const Segmants& next);
		void draw(Board& brd) const;
		const Location& getLocation() const;
	private:
		Location loc;
		Color c;
	};

public:
	Snake(const Location& loc);
	void moveBy(const Location& delta_loc);
	void grow();
	void draw( Board& brd) const;
	Location getNextHeadLocation(const Location& delta_loc) const;
	bool isInTileExceptEnd(const Location& target) const;
	bool isInTile(const Location& target) const;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int maxNumberOfSegmants = 100;
	Segmants segmants[maxNumberOfSegmants];
	int numberOfSegmants = 1;
};