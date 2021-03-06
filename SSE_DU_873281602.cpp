// SSE_DU_873281602.cpp : Defines the entry point for the console application.
//

#include <cstdlib>
#include <cstdio>

struct _node {
	short int data;
	struct _node *next;
};

struct _linkedlist {
	_node *head = NULL;
	_node *tail = NULL;
} linkedlist; // Initialize linked list

void _addnode(int _firstint);
void _tester(char token, int _intcast, int _firstint, int counter);

int main() {
	// Ask for user input
	printf("Please enter a number: ");

	char token = 'a'; // Placeholder initializer
	int _intcast = 0; // Gets the int value from the token read in by stdin
	int _firstint = 0;; // First int of a new node
	int counter = 0; // Counts how many digits have been read

	_tester(token, _intcast, _firstint, counter);

	return 0;
}

void _tester(char token, int _intcast, int _firstint, int counter) {
	
	while (token != '\0') {
		token = getc(stdin); // Wil only read in one char; use a loop
		counter++;

		// Validate user input
		if (token >= 48 && token <= 57 || token == 46) {

			if (token == 46) {
				if (_firstint == -1) {
					printf("Node Numbers: %i\n", linkedlist.head->data);
					break; // last node has 4 digits, no need to do anything else
				}

				else {
					_addnode(_firstint); // Add whatever digits remain into a a new node and end loop
					printf("Node Numbers: %i\n", linkedlist.head->data);
					break;
				}

			}

			_intcast = (int)(token)-48;

			if (counter == 1) {
				_firstint = _intcast;
			}

			else if (counter > 1 && counter < 4) {
				_firstint = _firstint * 10 + _intcast; // Move over one decimal place
			}

			else if (counter == 4) {
				_firstint = _firstint * 10 + _intcast;
				_addnode(_firstint);
				counter = 0;
			}
		}

		else {
			break;
		}
	}
}

void _addnode(int _firstint) {

	_node newnode;
	newnode.data = _firstint;

	if (linkedlist.head == NULL && linkedlist.tail == NULL) { // If the linked list is empty add the first node
		linkedlist.head = &newnode;
		linkedlist.tail = &newnode;
	}

	else {
		newnode.next = linkedlist.head; // Set the link to the next node and change the head of the linked list
		linkedlist.head = &newnode;
	}

	_firstint = -1; // Poison the variable so it can be checked if the last node is full or not

}


/*
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

void _addnode(int _firstint);
void _tester(char token, int _intcast, int _firstint, int counter);

int main() {
	// Ask for user input
	printf("Please enter a number: ");

	char token = 'a'; // Placeholder initializer
	int _intcast; // Gets the int value from the token read in by stdin
	int _firstint = 0;; // First int of a new node
	int counter = 0; // Counts how many digits have been read

	while (token != '\0') {
		token = getc(stdin); // Wil only read in one char; use a loop
		counter++;

		// Validate user input
		if (token >= 48 && token <= 57 || token == 46) {

			if (token == 46) {
				if (_firstint == -1) {
					printf("Node Numbers: %i\n", linkedlist.head->data);
					break; // last node has 4 digits, no need to do anything else
				}

				else {
					_addnode(_firstint); // Add whatever digits remain into a a new node and end loop
					printf("Node Numbers: %i\n", linkedlist.head->data);
					break;
				}

			}

			_intcast = (int)(token)-48;

			if (counter == 1) {
				_firstint = _intcast;
			}

			else if (counter > 1 && counter < 4) {
				_firstint = _firstint * 10 + _intcast; // Move over one decimal place
			}

			else if (counter == 4) {
				_firstint = _firstint * 10 + _intcast;
				_addnode(_firstint);
				counter = 0;
			}
		}

		else {
			break;
		}
	}
	return 0;
}



void _addnode(int _firstint) {

	_node newnode;
	newnode.data = _firstint;

	if (linkedlist.head == NULL && linkedlist.tail == NULL) { // If the linked list is empty add the first node
		linkedlist.head = &newnode;
		linkedlist.tail = &newnode;
	}

	else {
		newnode.next = linkedlist.head; // Set the link to the next node and change the head of the linked list
		linkedlist.head = &newnode;
	}

	_firstint = -1; // Poison the variable so it can be checked if the last node is full or not

} 
*/