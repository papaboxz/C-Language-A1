#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "street.h"
#include "rentalProperty.h"
#include "node.h"

int main ()
{
	//One Linked List
	Node *undecidedHead = NULL;
	Node **ppUndecidedHead = &undecidedHead; 
	
	Node *favHead = NULL;
	Node **ppFavHead = &favHead;


	Node *curHead = NULL;
	Node **ppCurrentHead = &curHead;


	int numStreets = 10;

	int numNodes = 10;

	srand(time(NULL));
	
	Street myStreets [] = { {"Barney Ave.", 0}, {"Mo St.", 0}, {"Homer Blvd.", 0}, {"Lisa Rd.", 0}, {"Bart Dr.", 0}, {"Marge Pwky.", 0}, {"Frink Crcl.", 0}, {"Krusty Rd.", 0}, {"Ned Dr.", 0}, {"Klang Ave.", 0} }; 
	
	Street *pStreet;
	
	pStreet = &myStreets[0];
	
	//Initializes the street array
	initStreetArr(pStreet, numStreets);

	//Initializes a Linked List with 10 values
	//initList(ppUndecidedHead, 5, pStreet, numStreets);
	initList(ppUndecidedHead, numNodes, pStreet, numStreets);
	
	//int selection = 0; 

	menu(ppFavHead, ppUndecidedHead, ppCurrentHead);

	/*while (1)
	{
		printf("MENU:\n");
		printf("01) Add a node to the end of the list\n");
		printf("02) Remove a node at a specified index\n");
		printf("03) Swap a node to the fav list\n");
		printf("04) Print the undecided list\n");
		printf("05) Print the fav list\n");
		printf("06) Add at Index\n");
		printf("07) Sort by house number\n");
		printf("08) Sort by number of rooms\n");
		printf("09) Sort by distance from campus\n");
		printf("10) Sort by rent per room\n");
		printf("11) Quit\n");
		printf("Enter Command: ");
		scanf("%d", &selection);

		if (selection == 1)
		{
			Node *newNode = malloc(sizeof(Node));
			newNode->property = malloc(sizeof(Property));
			initProperty(newNode->property, pStreet, numStreets);

			appendNode(ppUndecidedHead, newNode);
		}
		else if (selection == 2)
		{
			int i = 0; 
			printf("What index would you like to delete from?: ");
			scanf("%d", &i);

			deleteAtIndex(ppUndecidedHead, i);
		}
		else if (selection == 3)
		{
			int i = 0; 
			printf("What index would you like to remove from?: ");
			scanf("%d", &i);

			Node * newNode = removeAtIndex(ppUndecidedHead, i);
			appendNode(ppFavHead, newNode);
		}
		else if (selection == 4)
		{
			printList(*ppUndecidedHead);
		}
		else if (selection == 5)
		{
			printList(*ppFavHead);
		}
		else if (selection == 6)
		{
			int i = 0; 
			printf("What index would you like to add to?: ");
			scanf("%d", &i);

			Node *newNode = malloc(sizeof(Node));
			newNode->property = malloc(sizeof(Property));
			initProperty(newNode->property, pStreet, numStreets);

			addNodeAtIndex(ppUndecidedHead, newNode, i); 
		}
		else if (selection == 7)
		{
			sortByHouseNumber(ppUndecidedHead); 
		}
		else if (selection == 8)
		{
			sortByNumRooms(ppUndecidedHead); 
		}
		else if (selection == 9)
		{
			sortByDistance(ppUndecidedHead); 
		}
		else if (selection == 10)
		{
			sortByRent(ppUndecidedHead); 
		}
		else if (selection == 11) 
		{
			break;
		}
		else
		{
			printf("--INVALID COMMAND--");
			while (getchar() != '\n') { getchar(); }
		}
	}*/
	
	mrClean(ppUndecidedHead);
	mrClean(ppFavHead);
	
	return 0;
}
