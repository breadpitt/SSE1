// Iterative C program to reverse a linked list
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
typedef struct Node {
	int data;
	struct Node *next;
} _node;

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

_node* buildList(_node *head) {
	//struct Node *head = NULL;
	char token = 'a';
	int counter = 0;
	int digit = 0;
	int _intcast = 0;

	
	while (token != '\0') {
		token = getc(stdin);	// Wil only read in one char; use a loop
		counter++;
		//printf("token %c\n", token);
		if (token == 46)
		{
			if (digit == -1)
			{
				break;	// last node has 4 digits, no need to do anything else
			}

			else {
				push(&head, digit); // else push whatever digits are left onto a node
				break;
			}
		}
		// Validate user input
		if (token >= 48 && token <= 57) {

			_intcast = (int)(token)-48;

			if (counter == 1) {
				digit = _intcast;
			}
			else if (counter > 1 && counter < 4) {
				digit = digit * 10 + _intcast;	// Move over one decimal place
			}
			else if (counter == 4) {
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
	printList(head);
	return head;
}
/* Driver program to test above function*/
int main(){
	
	_node* numone = NULL;
	_node* numtwo = NULL;
	
		printf("Please enter the first number: ");
		buildList(numone);
		printf("\n");
		getchar(); // Clear input stream
		printf("Please enter a second number: ");
		buildList(numtwo);
		printList(numtwo);
		printf("\n");
	return 0;
}

