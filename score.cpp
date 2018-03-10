#include "score.h"

void  score::updateAmount(int score)
{
	amount = amount + score;
}

int score::get_amount()const
{   
	return amount;
}