#ifndef STREET_H
#define STREET_H

	typedef struct Street
	{
			char* name;
			int campusDist; 
	} Street;
	
	void initStreetArr (Street *pStreet, int numStreets);
	
#endif