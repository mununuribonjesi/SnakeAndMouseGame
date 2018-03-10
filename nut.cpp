#include "constants.h"
#include "nut.h"

nut::nut() :MoveableGridItem(x, y, Nuts)
{
	setPrivateMember(x,y);
};

const bool nut::has_been_collected()
{
	return collected;
}

void nut::disappear()
{
	collected = true;
}

