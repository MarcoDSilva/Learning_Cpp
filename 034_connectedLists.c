//linked lists
//ms
//15-07-2019

#include <stdio.h>
#include <stdlib.h>

//creating the structure to make nodes
typedef struct node {
	int data;
	struct node *next; //pointer to the address of the next node
} *node;

//logic that checks the nodes and updates the info
//if the first element is empty, the new node is inserted as head
//if the element is bigger than the last, it's the tail
//if it's greater than head and less than tail, verifies where it's the pos
//at the body 
void insert_node(node **head, node **tail, node *newNode)
{
	node *temp; //temporary node pointer

	// --------- first element insertion -------
	if(head == NULL)
	{
		head = newMode;
		tail = newMode;
	} else {
		// ----------- HEAD INSERTION ----------
		if(newNode->data <= (*head)->data)
		{
			newNode->next = *head;
			*head = newNode;
		}
		else {
			// ------- TAIL INSERTION ----------
			if(newNode->data >= (*tail)->data)
			{
				(*tail)->next = newNode;
				(*tail) = (*tail)->next;
			} 
			else {
			// ------ BODY INSERTION ----------
				for(temp = *head; temp->next->data < newNode->data; temp = temp->next)
				{
					newNode->next = temp->next;
					temp->next = newNode;
				}
			}
		}
	}
}

// ----------- create a node -------------------
node *create_node (int value) {

	node *new = (node*)malloc(sizeof(node));
	if(new != NULL) 
	{
		new->data = value;
		new->next = NULL;
	}
	return new;
}

// ----------- counter of nodes ----------------

int nodeCounter(node *list)
{
	node *temp = NULL;
	int total = 0;

	for(temp = list, total = 0; temp != NULL; temp = temp->next)
	{
		total++;
	}
}

