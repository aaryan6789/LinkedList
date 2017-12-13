//__LINKEDLIST__C_

#include <stdlib.h>
#include <stdio.h>
#include <error.h>

/* 1. Define a Linked List
 * 2. Insert in a Linked List
 * 3. Delete from a Linked List
 */

struct node {
	int data;
	struct node* next;
};

void print_list(struct node* head)
{
	struct node *current = head;
	int num_nodes=0;

	printf("\nPrint Linked List:\n");
	while(current != NULL) {
		printf("%d ", current->data);
		num_nodes++;
		current = current->next;
	}
	printf("\nNumber of Nodes: %d\n", num_nodes);
}

int length_of_list(struct node *head)
{
	struct node *current = head;
	int num_nodes = 0;
	while(current != NULL) {
		num_nodes++;
		current = current->next;
	}
	return num_nodes;
}

/* insert : Insert in a Linked List
 * @head_ref: Pointer to the pointer to head of the linked list
 * @data	: Data to be inserted in the linked list
 * @k		: Position where you want to insert the data
 */
void insert(struct node** head_ref, int data, int k){
	/*1. In the beginning
	 *2. In the middle
	 *3. In the end
	 */
}

void insert_beginning (struct node** head_ref, int data) {
	/* 1. Allocate a newNode
	 * 2. Fill in the data field
	 * 3. Make current head as the next of newNode
	 * 4. newNode will be the new Head of the linked list
	 */
	printf("Inserting %d in the beginning\n", data);
	struct node* newNode;
	newNode = (struct node* )malloc(sizeof(struct node));
	/* Check for Null pointer */
	if (!newNode){
		printf("malloc failed\n");
		return;
	}

	newNode->data = data;		//2
	newNode->next = *head_ref;	//3
	*head_ref = newNode;		//4
}

void insert_last(struct node **head_ref, int data){
	/* 1. Allocate a newNode (malloc) + check for NULL pointer
	 * 2. Fill in the data field
	 * 3. Fill in the next field of the node.
	 * 	  The next of the newNode will be NULL as its gonna be the last node.
	 * 4. Now we have to position the node to be the last node.
	 * 	- If the Linked list is empty then the newNode will be the 1st and Last
	 * 	  node. We will handle this condition check first as then we can save
	 * 	  the time of traversing the linked list.
	 * 	- Else, we have to traverse the linked list till the end of the LL.
	 * 	  And attach the newNode at the end now.
	 */
	printf("Insert %d in the end\n", data);
	struct node *current = *head_ref;
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	/* check for NULL node */
	if (!newNode){
		printf("malloc failed\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;

	if (*head_ref == NULL) {
		printf("The Current Linked List is empty. So this node will be the head node\n");
		*head_ref = newNode;
		return;
	}
	else {
		/* traverse to the last node */
		while(current->next != NULL) {
			current = current->next;
		}
		printf("Last node of the current linked list is: %d\n", current->data);
		current->next = newNode;
	}
}

/* insert_middle : Insert a node in the middle of the LL
 * @head	: Head Pointer of the LL
 * @data	: The data of the node to be inserted
 * @pos		: newNode to be added after pos node
 */
void insert_after(struct node **head_ref, int data, int pos) {
	printf("Inserting %d in the LL after %dth node\n", data, pos);
	/* 1. Allocate a newNode (malloc) + NULL check
	 * 2. Fill in the data field.
	 * 3. Traverse the ll up to pos
	 */
	struct node *current = *head_ref;
	struct node *temp;

	int count = 0;
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	if(!newNode)
		printf("malloc failed\n");

	newNode->data = data;

	if ((pos < 0) || (pos > length_of_list(*head_ref))) { 			// Handle invalid negative position and Empty list
		printf("Invalid position\n");
		return;
	}
	/* Insert at the beginning */
	else if (pos == 1){
		newNode->next = *head_ref;
		*head_ref = newNode;
	}
	else{
		/* 1. somewhere in the middle
		 * 2. in the end
		 * 3. handle for invalid position ****
		 */
		while((current != NULL) && (count < pos-1)){
			count++;
			temp = current;
			current = current->next;
			printf("current: %d count:%d\n", current->data, count);
		}
		/* if position is the last node */
		if (current == NULL){
			temp->next = newNode;
			newNode->next = NULL;
		}
		/* Insert somewhere in the middle */
		else {
			temp->next = newNode;
			newNode->next = current;
		}
	}
}

/* Given a pointer to a node, delete that node. */
void delete_node(struct node *node2Bdeleted) {
	/* Method 1 : With Temp variable
	 * 1. Allocate a temp node
	 * 2. temp->data = node2Bdeleted->next->data;
	 * 3. temp->next = node2Bdeleted->next->next;
	 *
	 * Method 2 : Without temp variable
	 */

	if (!node2Bdeleted) {
		printf("NO Node to be deleted\n");
		return;
	}

	printf("Node to be deleted - %d\n", node2Bdeleted->data);
	node2Bdeleted->data = node2Bdeleted->next->data;
	node2Bdeleted->next = node2Bdeleted->next->next;
}

/* Get the nth node from the front */
void get_nth_node(struct node *head, int n) {
	// The linked list will start from 1
	struct node *current = head;
	int count = 1;

	while (current != NULL) {
		count++;
		current= current->next;

		if (count == n)
			break;
	}

	printf("The %dth node is %d\n", n, current->data);
}

/* Get the nth node from the last */
void get_nth_last(struct node* head, int n){
	struct node *fast, *slow;

	fast = slow = head;
	int count = 1;

	while (count != n) {
		count++;
		fast = fast->next;
	}

	while (fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	}

	printf("%dth node from the last is %d\n", n, slow->data);
}

/* Get the middle of the Linked List */
void get_middle(struct node *head) {
	// Method 1 : Using Length of the list
	// Method 2 : Double Pointers

	struct node *fast, *slow;
	fast = slow = head;

	if (head == NULL) {
		printf("No LL to find middle from\n");
		return;
	}

	while ( fast != NULL && fast->next != NULL){ // TODO: Analyse the condition properly
		fast = fast->next->next;
		slow = slow->next;
	}

	printf("The middle of the Linked List is=%d\n", slow->data);
}

/* detect_loop - Detect a loop in a Linked List
 * Method: Floyd's Cycle Finding Algorithm
 * 1. Declare 2 pointers for traversing the LL
 * -- fast  --> increment by 2 nodes
 * -- slow  --> increment by 1 node
 * 2. If these 2 pointers meet at some point in then there definitely
 * there is a loop. If they dont then no loop.
 *
 * This concept can be extended for removing the loop too.
 */
void detect_loop(struct node* head) {

	struct node *slow, *fast;
	slow = fast = head;

	while (slow && fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast){
			printf("There is a loop in this linked list.\n");
			return;
		}
	}
	printf("No loop detected.\n");
}

void _remove_loop(struct node *loop_node, struct node *head){
	struct node *ptr1, *ptr2;
	ptr1 = ptr2 = loop_node;

	// count the number of nodes in the loop
	int k = 1;
	int i;

	while (ptr1->next != ptr2){
		ptr1 = ptr1->next;
		k++;
	}
	printf("Number of LoopNodes:%d\n", k);

	// Set ptr1 to head & ptr2 to (head + k)
	ptr1 = ptr2 = head;

	for (i = 0 ; i< k ; i++)
		ptr2 = ptr2->next;

	// Move both pointers at the same pace now
	while (ptr2 != ptr1) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	// Get the next of the start of the loop node
	ptr2 = ptr2->next;

	while(ptr2->next != ptr1)
		ptr2 = ptr2->next;

	ptr2->next = NULL;

	printf("Loop removed.\n");
}

void detect_remove_loop(struct node *head) {

	struct node *slow, *fast;
	slow = fast = head;

	while (slow && fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast){
			printf("There is a loop in this linked list.\nRemoving Loop now.\n");
			_remove_loop(slow, head);
			return;
		}
	}
	printf("No loop detected.\n");
}

/**
 * Form a Loop in a Linked List by attaching the last node to a node in the
 * middle of the Linked list.
 * Pretty sweet implementation :)
 */
void form_a_loop(struct node *head, struct node *loop_attach) {
	struct node *current = head;

	// Go to the last node
	while (current->next != NULL){
		current = current->next;
	}

	// Forming loop
	printf("loop_attach->data:%d current->data:%d\n", loop_attach->data, current->data);
	current->next = loop_attach;

	printf("current->next->data:%d\n", current->next->data);
	printf("Loop Formed.\n");
}

/** Delete a Linked List */
void delete_list(struct node **head_ref) {

	struct node *current, *next;
	current = *head_ref;

	while (current->next != NULL) {
		next = current->next;
		//printf("Deleting %d\n", current->data);
		free(current);
		current = next;
	}
	/* Set the head pointer to null linked list is deleted */
	*head_ref = NULL;
	return;
}


int main(){
	printf("------ Linked List Practice file ------------ \n");
	/* Start with a Empty list */
	struct node *head = NULL;

	// Insert
	insert_last(&head, 9);
	print_list(head);
	insert_beginning(&head, 5);
	insert_beginning(&head, 6);
	insert_beginning(&head, 4);
	print_list(head);
	//printf("\nHead of the Linked list: %d\n", head->data);
	insert_after(&head, 1 , 4);
	print_list(head);
	insert_after(&head, 3 , 2);
	print_list(head);
	insert_last(&head, 8);
	print_list(head);
	insert_after(&head, 10 , 7);
	print_list(head);
	struct node *current = head;
	struct node *loop_attach = current->next;
	//delete_node(current->next->next);
	//delete_node(head);
	insert_after(&head, 11 , 11);
	print_list(head);

	get_nth_node(head, 4);
	get_nth_last(head, 5);
	print_list(head);
	get_middle(head);
	detect_loop(head);
	form_a_loop(head, loop_attach);
	detect_remove_loop(head);
	delete_list(&head);

	print_list(head);

	return 0;
}
