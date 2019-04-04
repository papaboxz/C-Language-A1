#ifndef NODE_H
#define NODE_H

#include "street.h"
#include "rentalProperty.h"

typedef struct Node 
{
	
	Property *property;
	struct Node *next; 
	
} Node; 

void initList (Node **ppHead, int numNodes, Street *pStreet, int numStreets);

void printNode (Node *pNode);

void printList (Node *pHead);

int getCount (Node *pHead);

Node * getNode (Node *pHead, int index);

void appendNode (Node **ppHead, Node *pNewNode);

void addNodeAtIndex (Node **ppHead, Node *pNewNode, int index);

Node * removeAtIndex(Node **ppHead, int index);

void deleteAtIndex (Node **ppHead, int index); 

void mrClean (Node **ppHead);

void sortByHouseNumber (Node **ppHead);

void sortByDistance (Node **ppHead);

void sortByNumRooms (Node **ppHead);

void sortByRent (Node **ppHead);

void skipToNextNode(Node **ppHead);

#endif
