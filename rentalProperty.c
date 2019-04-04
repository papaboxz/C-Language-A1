#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "rentalProperty.h"
#include "node.h"

void initProperty (Property *pProperty, Street *pStreet, int numStreets)
{	
	int randPos = rand() % numStreets; //0-(numStreets - 1)
	
	pProperty->street = &pStreet[randPos];
	
	int randStreetNumber = rand() % 201; //0-200 
	int randNumBedrooms = (rand() % 4) + 1; //1-4
	int randRentPerBedroom = 200 + (50 * (rand() % 9)); //200-600
	
	pProperty->streetNumber = randStreetNumber;
	pProperty->numBedrooms = randNumBedrooms;
	pProperty->rentPerBedroom = randRentPerBedroom; 
	
	pProperty->campusDist = pProperty->street->campusDist + pProperty->streetNumber * 20;
}

void printProperty (Property *pProperty)
{
	float floatRep = 0; 
	floatRep = (float)pProperty->campusDist / 1000; 
	
	//printf("\n\n%i %s     Bedrooms: %i Rent Per Room: %i Distance From Campus: %.2f km\n", pProperty->streetNumber, pProperty->street->name, 
	//		pProperty->numBedrooms, pProperty->rentPerBedroom, floatRep);
	printf("%i %s\t\t\t\t%i\t\t%i\t\t%.2f km\n", pProperty->streetNumber, pProperty->street->name, 
			pProperty->numBedrooms, pProperty->rentPerBedroom, floatRep);
}

void printProperty2 (Property *pProperty)
{
	float floatRep = 0; 
	floatRep = (float)pProperty->campusDist / 1000; 


		
	printf("\t\tAddr: %i %s, # Rooms: %i, Rent/Room: $%i, Distance: %.2f km\n", pProperty->streetNumber, pProperty->street->name,	pProperty->numBedrooms, pProperty->rentPerBedroom, floatRep);
	//printf("\t\tAddr: %i %s, # Rooms: %i, Rent/Room: $%i, Distance: %.2f km\n", nodeToPrint->property->streetNumber, nodeToPrint->property->street->name, nodeToPrint->property->numBedrooms, nodeToPrint->property->rentPerBedroom, floatRep);
}
