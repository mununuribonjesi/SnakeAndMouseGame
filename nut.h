#pragma once
#include "constants.h"
#include "MoveableGridItem.h"

class nut : public MoveableGridItem
{
private:
	int x = rng_.get_random_value2(SIZE), y = rng_.get_random_value2(SIZE);
	bool collected;
	RandomNumberGenerator rng_;
public:
	nut();
	const bool has_been_collected();
	void disappear();
};