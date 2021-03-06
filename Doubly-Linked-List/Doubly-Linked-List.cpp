// Doubly-Linked-List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
//declare a data structure Node
struct Node
{
	//assign an int member of data structure
	int data;
	//assign pointer values allocating memory space for previous state and next state
	struct Node* next;
	struct Node* prev;
};
struct Node* head;
struct Node* GetNewNode(int x)
{
	//using malloc to allocate space for Node
	struct Node* newNode = (struct Node*)malloc (sizeof(struct Node));
	//assign values to the Datastructure
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
};
void InsertAtHead(int x)
{
	//newNode temp variable declared
	struct Node* newNode = GetNewNode(x);
	//test the list for an empty list
	if (head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}
void Print() 
{
	struct Node* temp = head;
	printf("Forward: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void ReversePrint()
{
	struct Node* temp = head;
	if (temp == NULL) return; //empty list, exit
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	//Traversing Backward Using previous pointer
	printf("Reverse: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main()
{
	//create an empty list
	head = NULL;
	//call the function and assign variables
	InsertAtHead(1); Print(); ReversePrint();
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(3); Print(); ReversePrint();
	system("pause");
    return 0;
}

