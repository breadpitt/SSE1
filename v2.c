// Iterative C program to reverse a linked list
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node {
	int data;
	struct Node *next;
};


/* Function to reverse the linked list */
static void reverse(struct Node **head_ref){
	struct Node *prev = NULL;
	struct Node *current = *head_ref;
	struct Node *next = NULL;

	while (current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head_ref = prev;
}

/* Function to push a node */
void push(struct Node **head_ref, int new_data){
	/* allocate node */
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	/* put in the data  */
	new_node->data = new_data;
	/* link the old list off the new node */
	new_node->next = (*head_ref);
	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct Node *head){
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}

/* Driver program to test above function*/
int main(){
	/* Start with the empty list */
	struct Node *head = NULL;
	char token = 'a';
	int counter = 0;
	int digit = 0;
	int _intcast = 0;

	printf("Please enter a number: ");
	while (token != '\0') {
		token = getc(stdin);	// Wil only read in one char; use a loop
		counter++;
		printf("digit: %i\n", digit);
		if (token == 46)
		{
			if (digit == -1)
			{
				
				break;	// last node has 4 digits, no need to do anything else
			}

			else {
				push(&head, digit);
				break;
			}
		}
		// Validate user input
		if (token >= 48 && token <= 57) {
			
			_intcast = (int)(token)-48;

			if (counter == 1){
				digit = _intcast;
			}
			else if (counter > 1 && counter < 4){
				digit = digit * 10 + _intcast;	// Move over one decimal place
			}
			else if (counter == 4){
				digit = digit * 10 + _intcast;
				push(&head, digit);
				counter = 0; // Reset byte counter
				digit = -1; // Set stop condition
			}
		}

		else {
			break;
		}	
	}
	printf("Given linked list\n");
	printList(head);
	return 0;
}









































































/*  SSE_DU_873281602.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <stdio.h>

struct _node {
	short int data;
	struct _node *next;
};
typedef struct _node node;

struct _linkedlist {
	struct _node *head;
} linkedlist; // Initialize linked list

node* _addnode(int digit, node *list);
node* _buildlist(char token, int _intcast, int digit, int counter); // Validates user input and builds a linked list
void printList(node* list);
int main() {
	// Ask for user input
	printf("Please enter a number: ");

	char token = 'a'; // Placeholder initializer
	int _intcast = 0; // Gets the int value from the token read in by stdin
	int digit = 0; // First int of a new node
	int counter = 0; // Counts how many digits have been read
	node *linkedlist = NULL;

	linkedlist = _buildlist(token, _intcast, digit, counter);
	printList(linkedlist);
	return 0;
}

node* _buildlist(char token, int _intcast, int digit, int counter) {
	node *head, *first, *temp = 0;

	while (token != '\0') {
		token = getc(stdin); // Wil only read in one char; use a loop
		counter++;

		// Validate user input
		if (token >= 48 && token <= 57 || token == 46) {

			if (token == 46) {
				if (digit == -1) {
					//printList(list);
					break; // last node has 4 digits, no need to do anything else
				}

				else {

					//_addnode(digit, list); // Add whatever digits remain into a a new node and end loop
					//printList(list);
					break;
				}

			}

			_intcast = (int)(token)-48;

			if (counter == 1) {
				digit = _intcast;
			}

			else if (counter > 1 && counter < 4) {
				digit = digit * 10 + _intcast; // Move over one decimal place
			}

			else if (counter == 4) {

					digit = digit * 10 + _intcast;
					//_addnode(digit, list);
					head = (node*)malloc(sizeof(node));
					head->data;
					if (first != 0) {
						temp->next = head;
						temp = head;
					}
					else {
						first = temp = head;
					}

					counter = 0;
			}
		}

		else {
			break;
		}
	}
	return temp;
}

node* _addnode(int digit, node *list) {

	node *temp = malloc(sizeof(node));
	temp->data = digit;
	temp->next = list;
	list = temp;
	return list;

	digit = -1; // Poison the variable so it can be checked if the last node is full or not

}

void printList(node * list) {
	node * counter = list;
	while (counter != NULL) {
		printf(" %d ", counter->data);
		counter = counter->next;
	}
	printf("\n\n");
}

#include <cstdlib>
#include <cstdio>

struct _node {
	short int data;
	struct _node *next;
};

struct _linkedlist {
	_node *head = NULL;
	_node *tail = NULL;
} linkedlist;

void _addnode(int digit);
void _tester(char token, int _intcast, int digit, int counter);

int main() {
	// Ask for user input
	printf("Please enter a number: ");

	char token = 'a'; // Placeholder initializer
	int _intcast; // Gets the int value from the token read in by stdin
	int digit = 0;; // First int of a new node
	int counter = 0; // Counts how many digits have been read

	while (token != '\0') {
		token = getc(stdin); // Wil only read in one char; use a loop
		counter++;

		// Validate user input
		if (token >= 48 && token <= 57 || token == 46) {

			if (token == 46) {
				if (digit == -1) {
					printf("Node Numbers: %i\n", linkedlist.head->data);
					break; // last node has 4 digits, no need to do anything else
				}

				else {
					_addnode(digit); // Add whatever digits remain into a a new node and end loop
					printf("Node Numbers: %i\n", linkedlist.head->data);
					break;
				}

			}

			_intcast = (int)(token)-48;

			if (counter == 1) {
				digit = _intcast;
			}

			else if (counter > 1 && counter < 4) {
				digit = digit * 10 + _intcast; // Move over one decimal place
			}

			else if (counter == 4) {
				digit = digit * 10 + _intcast;
				_addnode(digit);
				counter = 0;
			}
		}

		else {
			break;
		}
	}
	return 0;
}



void _addnode(int digit) {

	_node newnode;
	newnode.data = digit;

	if (linkedlist.head == NULL && linkedlist.tail == NULL) { // If the linked list is empty add the first node
		linkedlist.head = &newnode;
		linkedlist.tail = &newnode;
	}

	else {
		newnode.next = linkedlist.head; // Set the link to the next node and change the head of the linked list
		linkedlist.head = &newnode;
	}

	digit = -1; // Poison the variable so it can be checked if the last node is full or not

}
*/