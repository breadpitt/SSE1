// Iterative C program to reverse a linked list
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
typedef struct Node {
	int data;
	struct Node *next;
	int fill;
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
				head->fill = counter; // store the remainder count for printing
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
	
	return head;
}

/* Adds contents of two linked lists and return the head node of resultant list */
_node* addTwoLists(_node* first, _node* second)
{
	_node* res = NULL; // res is head node of the resultant list
	_node *temp = NULL;
	_node *prev = NULL;
	_node *carrynode = NULL;
	int carry = 0;
	int sum = 0;

	while (first != NULL || second != NULL) //while both lists exist
	{
		// Calculate value of next digit in resultant list.
		// The next digit is sum of following things
		// (i)  Carry
		// (ii) Next digit of first list (if there is a next digit)
		// (ii) Next digit of second list (if there is a next digit)
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

		// update carry for next calulation
		carry = (sum >= 10) ? 1 : 0;

		// update sum if it is greater than 10
		sum = sum % 10;

		// Create a new node with sum as data
		push(&temp, sum); 

		// if this is the first node then set it as head of the resultant list
		if (res == NULL)
			res = temp;
		else // If this is not the first node then connect it to the rest.
			prev->next = temp;

		// Set prev for next insertion
		prev = temp;

		// Move first and second pointers to next nodes
		if (first) first = first->next;
		if (second) second = second->next;
	}

	if (carry > 0) {		
		push(&carrynode, carry);
		temp->next = carrynode;
	}
	// return head of the resultant list
	return res;
}



/*_node* add(_node *p, _node *q)
{
	int carry = 0;

	_node *sHead, *sCurr;
	_node *pHead, *qHead;

	pHead = p;
	qHead = q;

	sHead = NULL;

	while (p)
	{
		sCurr = (_node*) malloc(sizeof(_node));
		sCurr->data = p->data + q->data + carry;
		sCurr->next = sHead;
		sHead = sCurr;

		carry = 0;

		/*
		* If the current digits sum to greater than 9,
		* create a carry value and replace the current
		* value with value mod 10.
		
		if (sCurr->data > 9)
		{
			carry = 1;
			sCurr->data = sCurr->data % 10;
		}

		/*
		* If the most significant digits of the numbers
		* sum to 10 or greater, create an extra node
		* at the end of the sum list and assign it the
		* value of 1.
		
		if (carry == 1 && sCurr->next == NULL)
		{
			_node *sCarry = (_node*) malloc(sizeof(_node));
			sCarry->data = 1;
			sCarry->next = NULL;
			//reverse(&sCurr);
			sCurr->next = sCarry;
			//reverse(&sCurr);
		}

		p = p->next;
		if (q->next) q = q->next;
		else q->data = 0;
	}
	printList(sHead);
	return sHead;
}

*/






/* Driver program to test above function*/
int main(){
	
	_node* numone = NULL;
	_node* numtwo = NULL;
	_node* sum = NULL;
	
		printf("Please enter the first number: "); // 13242197849762.  should: 9762 9784 2421 13 acutal: 62  8497  2197  1324
		numone = buildList(numone);
		printList(numone);
		printf("\n");
		getchar(); // Clear input stream
		printf("Please enter a second number: "); // 676941
		numtwo = buildList(numtwo);
		printList(numtwo);
		printf("\n");
		getchar();
		printf("Sum is: "); //6703 9852 2421 13
		sum = addTwoLists(numone, numtwo);
		printList(sum);
		printf("\n");
		
	return 0;
}

