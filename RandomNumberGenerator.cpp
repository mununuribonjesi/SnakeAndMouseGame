// RandomNumberGenerator.cpp: implementation of the RandomNumberGenerator class
//////////////////////////////////////////////////////////////////////

#include "RandomNumberGenerator.h" 
#include <ctime>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RandomNumberGenerator::RandomNumberGenerator() {

	srand(static_cast<unsigned>(time(0)));
}

////////////////////////////////////////////////////////////////////// 
// Public functions
//////////////////////////////////////////////////////////////////////

int RandomNumberGenerator::get_random_value(int max) const {
//produce a random number in range [1..max]
	return (rand() % max) + 1;
}

int RandomNumberGenerator::get_random_value2(int max) const
{
	return (rand() % max);
}

int RandomNumberGenerator::get_random_value3(int max) const
{
	return (rand() % max) - 1;
}


//////////////////////////////////////////////////////////////////////
// Private functions
//////////////////////////////////////////////////////////////////////
/*removed seed and made a local variable inside the random number generator
instead of using a member class funtion 
void RandomNumberGenerator::seed() {
//seed the random number generator from current system time
//so that the numbers will be different every time
	
}
*/