#ifndef RENTALPROPERTY_H
#define RENTALPROPERTY_H

#include "street.h"

	typedef struct rentalProperty
	{
		Street *street;
		int streetNumber;
		int numBedrooms;
		int rentPerBedroom; 
		int campusDist; 
	} Property;

	void initProperty (Property *pProperty, Street *pStreet, int numStreets);
	void printProperty (Property *pProperty);
	
#endif
