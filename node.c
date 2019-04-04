#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"

/*
	Purpose: Initializes a Linked List with a set number of nodes
	ppHead: Points to the head of the linked list
	numNodes: The number of nodes to be created
	pStreet: The array of streets needed to initialize the property 	struct inside the node
	numStreets: The number of streets in the street array
*/
void initList (Node **ppHead, int numNodes, Street *pStreet, int numStreets)
{
	for (int i = 0; i < numNodes; i++)
	{
		Node *newNode = malloc(sizeof(Node));
		newNode->property = malloc(sizeof(Property));
		initProperty(newNode->property, pStreet, numStreets);		

		appendNode(ppHead, newNode);
	}
}

/*
	Purpose: Print the formatted value of the property struct in a node
	pNode: The node whose property value you want printed
*/
void printNode (Node *pNode)
{
	printProperty(pNode->property);
}

void printNode2 (Node *pNode)
{
	printProperty2(pNode->property);
}

/*
	Purpose: Prints all the entries in a linked list
	pHead: Points to the head of the linked list to start traversal
*/
void printList (Node *pHead)
{
	Node *temp = pHead; 
	
	//printf("\n\nPROPERTIES:");
	printf("Address\t\t\t\t\t# Rooms\t\tRent/Room\tDistance\n");
	printf("-------------------------\t\t-------\t\t---------\t---------\n");
	while (temp != NULL)
	{
		printNode(temp);
		temp = temp->next; 
	}
}

/*
	Purpose: Find the number of nodes in a linked list
	pHead: Points to the head of a linked list to start traversal
*/
int getCount (Node *pHead)
{
	int count = 0; 
	Node *temp = pHead; 
	
	while (temp != NULL)
	{
		count++;
		temp = temp->next; 
	}
	
	return count; 
}

Node * getNode (Node *pHead, int index)
{
	Node *iter = pHead; 

	for (int i = 0; i < index && iter->next != NULL; i++)
	{
		iter = iter->next; 
	} 
	
	return iter; 
}

/*
	Purpose: Adds a node to the end of a linked list
	ppHead: Points to the head to start traversal and allows for 			modification of the Nodes
	pNewNode: Points to the new node that is to be added to the linked 			  list
*/
void appendNode (Node **ppHead, Node *pNewNode)
{
	if (*ppHead == NULL)
	{
		*ppHead = pNewNode; 
		(*ppHead)->next = NULL;
	}
	else
	{
			Node *temp = *ppHead; 
			
			while (temp->next != NULL)
			{
				temp = temp->next; 
			}
			
			temp->next = pNewNode;
			temp->next->next = NULL;
	}
}

void addNodeAtIndex (Node **ppHead, Node *pNewNode, int index)
{	
	Node *iter = *ppHead; 

	if (index == 0)
	{
		pNewNode->next = *ppHead; 
		*ppHead = pNewNode; 
	}
	else if (index == getCount(*ppHead))
	{
		appendNode(ppHead, pNewNode); 
	}	
	else
	{
		for (int i = 0; i < index - 1 && iter->next != NULL; i++)
		{
			iter=iter->next; 
		}

		pNewNode->next = iter->next; 
		iter->next = pNewNode; 
	}
}

Node *removeAtIndex(Node **ppHead, int index)
{
	Node * retval = NULL;
	Node * temp   = NULL; 

	if (getCount(*ppHead) > 0)
	{
		Node * iter = *ppHead; 

		retval = getNode(*ppHead, index);

		if (index == 0)
		{
			*ppHead = (*ppHead)->next;
			return retval; 
		}
		else
		{
			for (int i = 0; i < index - 1 && iter->next != NULL; i++)
			{
				iter = iter->next;
			}

			temp = iter->next; 
			iter->next = temp->next;
			return retval;  
		}

	}
	else
	{
		printf("--THE LIST IS EMPTY!--");
		return retval; 
	}
}

void sortByHouseNumber(Node **ppHead)
{
	Node *iter = *ppHead; 
	Property *temp; 
	int currIndex = 0; 

	for (int i = 0; i < getCount(*ppHead); i++)
	{
		iter = *ppHead; 
		currIndex = 0; 
		while (iter->next != NULL)
		{
			if (strcmp(iter->property->street->name, iter->next->property->street->name) > 0 || (strcmp(iter->property->street->name, iter->next->property->street->name) == 0 && iter->property->streetNumber > iter->next->property->streetNumber))
			{
				temp = iter->property; 
				iter->property = iter->next->property;
				iter->next->property = temp;  
			}
			
			iter=iter->next; 
			currIndex++; 
		}
	}
}

void sortByRent(Node **ppHead)
{
	Node *iter = *ppHead; 
	Property *temp; 
	int currIndex = 0; 

	for (int i = 0; i < getCount(*ppHead); i++)
	{
		iter = *ppHead; 
		currIndex = 0; 
		while (iter->next != NULL)
		{
			if (iter->property->rentPerBedroom < iter->next->property->rentPerBedroom)
			{
				temp = iter->property; 
				iter->property = iter->next->property;
				iter->next->property = temp;  
			}
			
			iter=iter->next; 
			currIndex++; 
		}
	}
}

void sortByDistance(Node **ppHead)
{
	Node *iter = *ppHead; 
	Property *temp; 
	int currIndex = 0; 

	for (int i = 0; i < getCount(*ppHead); i++)
	{
		iter = *ppHead; 
		currIndex = 0; 
		while (iter->next != NULL)
		{
			if (iter->property->campusDist < iter->next->property->campusDist)
			{
				temp = iter->property; 
				iter->property = iter->next->property;
				iter->next->property = temp;  
			}
			
			iter=iter->next; 
			currIndex++; 
		}
	}
}

void sortByNumRooms(Node **ppHead)
{
	Node *iter = *ppHead; 
	Property *temp; 
	int currIndex = 0; 

	for (int i = 0; i < getCount(*ppHead); i++)
	{
		iter = *ppHead; 
		currIndex = 0; 
		while (iter->next != NULL)
		{
			if (iter->property->numBedrooms < iter->next->property->numBedrooms)
			{
				temp = iter->property; 
				iter->property = iter->next->property;
				iter->next->property = temp;  
			}
			
			iter=iter->next; 
			currIndex++; 
		}
	}
}

/*
	Purpose: To remove a node at a certain index
	ppHead: Points to the head of the linked list to allow for traversal 			and modification of the nodes
	index: The location in the linked list you want deleted
*/
void deleteAtIndex(Node **ppHead, int index)
{
	Node *toBeRemoved = removeAtIndex(ppHead, index);
	free(toBeRemoved->property);
	free(toBeRemoved); 
}

void skipToNextNode(Node **ppHead)
{
	Node *iter = *ppHead; 

	if (iter->next != NULL) {
		iter=iter->next; 
		*ppHead = iter;
	}
}
/*
	Purpose: Cleans a linked lists memory if needed
	ppHead: Points to the head of a linked list to allow for traversal 			and modification of the nodes. 
*/
void mrClean (Node **ppHead)
{
	while(getCount(*ppHead) > 0)
	{
		deleteAtIndex(ppHead, 0);
	}
}
