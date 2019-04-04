#include <stdlib.h>
#include <time.h>

#include "street.h"

void initStreetArr (Street *pStreet, int numStreets)
{	
	srand(time(NULL));

	for (int i = 0; i < numStreets; i++)
	{
		int randDist = 500 + (100 * (rand() % 36)); //0-35
	
		pStreet[i].campusDist = randDist;
	}
}