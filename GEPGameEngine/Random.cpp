#include "Random.h"


namespace GEP
{
	void InitRandom()
	{
		srand(time(0));
	}

	
	int RandomRange(int minRange, int maxRange)
	{
		return (rand() % (maxRange - minRange + 1)) + minRange;
	}

	
}
