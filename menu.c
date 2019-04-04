
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "street.h"
#include "rentalProperty.h"
#include "node.h"
#include <stdbool.h>

char selection[3];
bool favorite;


int menu(Node **ppFavHead, Node **ppUndecidedHead, Node **ppCurrentHead) {
	ppCurrentHead = ppUndecidedHead;
	favorite = false;

	printf("\nUndecided Rental Properties\n");
	printList(*ppCurrentHead);


	while (1) {
		printf("\nWhat do you think of this rental property? \n");
		printNode2(getNode(*ppCurrentHead, 0));
		//printProperty2(**ppCurrentHead,0);

		printf("\nCommand ('h' for help): ");

		scanf("%s", selection);
		
		if ( !strncmp(selection, "h", 1 ) )
			printHelp();

		if ( !strncmp(selection, "a", 1 ) ) {
			//printf("\nFavourite Rental Properties\n");
			//printf("Address\t\t\t\t\t# Rooms\tRent/Room\tDistance\n");
			//printf("-------------------------\t\t-------\t---------\t---------\n");
			printList(*ppCurrentHead);
		}

		if ( !strncmp(selection, "f", 1 ) ) {
			//switchToFavoritesList();
			if (!favorite) {
				ppCurrentHead = ppFavHead;
				favorite = true;
			}
			printf("Favourite Rental Properties\n");
			//printf("Address\t\t\t\t\t# Rooms\tRent/Room\tDistance\n");
			//printf("-------------------------\t\t-------\t---------\t---------\n");
			if (getCount(*ppCurrentHead) <= 0) 
				printf("\nNo Rental Properties in Favourites List");
			else
				printList(*ppCurrentHead);
		}

		if ( !strncmp(selection, "u", 1 ) ) {
			//switchToUndecidedList();
			if (favorite) {
				ppCurrentHead = ppUndecidedHead;
				favorite = false;
			}
			printf("\nUndecided Rental Properties\n");
			printList(*ppCurrentHead);
		}

		if ( !strncmp(selection, "l", 1 ) ) {
			//swipeLeft();
			deleteAtIndex(ppCurrentHead, 0);
			printf("Rental property deleted\n");
		
			// Check if we have deleted the last rental property
			if (getCount(*ppCurrentHead) <= 0) {
				printf("\nNo more rental properties");
			}
		}

		if ( !strncmp(selection, "r", 1 ) ) {
			//swipeRight();
			if (!favorite) {
				Node * newNode = removeAtIndex(ppCurrentHead, 0);
				appendNode(ppFavHead, newNode);
				printf("Rental property moved to your favourites list\n");
			} else {
				printf("This rental property is already on your favourites list\n");
			}
		}

		if ( !strncmp(selection, "n", 1 ) )
			skipToNextNode(ppCurrentHead);

		if ( !strncmp(selection, "sa", 2 ) )
			sortByHouseNumber(ppCurrentHead); 

		if ( !strncmp(selection, "sn", 2 ) )
			sortByNumRooms(ppCurrentHead); 

		if ( !strncmp(selection, "sr", 2 ) )
			sortByRent(ppCurrentHead); 

		if ( !strncmp(selection, "sd", 2 ) )
			sortByDistance(ppCurrentHead); 

		if ( !strncmp(selection, "q", 1 ) )
			return(0);
	}
}

void printHelp() {
	printf("Valid commands are:\n");
	printf("\ta - display all the rental properties on the current list\n");
	printf("\tf - switch to the favorites list\n");
	printf("\tu - switch to the undecided list\n");
	printf("\tl - 'swipe left' on the current rental property\n");
	printf("\tr - 'swipe right' on the current rental property\n");
	printf("\tn - skip to the next rental property\n");
	printf("\tsa - set the sorting to 'by address'\n");
	printf("\tsn - set the sorting to 'by number of rooms'\n");
	printf("\tsr - set the sorting to 'by rent'\n");
	printf("\tsd - set the sorting to 'by distance'\n");
	printf("\tq - quit the program\n");
}


