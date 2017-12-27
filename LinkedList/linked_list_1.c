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

/**
 * insert_in_sorted_list - Insert a newNode in a Sorted Single Linked List
 * @IP : Head reference, neWNode
 * Algorithm:
 * 1. If the linked List is empty then make this node as the head and return.
 * 2. If the value of this node is smaller than the head node then insert in the
 * 	  front of the head node and make this as the new head.
 * 3. Traverse through the Linked List,
 * 		Find the node where you can insert this node. This node will be inserted
 * 		before the node which is larger than data.
 * 		Insert the node and make links.
 */
void insert_in_sorted_list(struct node** head_ref, struct node* newNode){
	printf("Inserting in a Sorted Linked List..\n");
	struct node *current = *head_ref; // For Traversing

	if (current == NULL || current->data >= newNode->data){
		//printf("Current->data = %d\n", current->data);
		newNode->next = current;
		current = newNode;
		*head_ref = current;
		return;
	}
	else {
		// Find the appropriate place to insert the newNode
		while ((current->next != NULL) && (current->next->data <= newNode->data)){
			current = current->next;
		}
		// Now current is pointing to the node right after which the newNode should
		// be inserted
		newNode->next = current->next;
		current->next = newNode;
	}
	return;
}

/**
 * Remove Duplicates from a Sorted Single Linked List
 *
 * 1. next_next
 * 2. Current
 *
 *1. Traverse through the Linked List
 *2. If its an Empty List return immediately
 *3. Else, In a loop,
 *		compare the nodes data and the data of the next node
 *		since its a sorted linked list the duplicates will be adjacent.
 *		If its a hit
 *		Store the next->next node in next_next pointer to create the link.
 */
void remove_duplicates_from_sorted_list(struct node **head_ref) {

	struct node* current;
	struct node* next_next;

	current = *head_ref;

	if (current == NULL)
		return;

	while(current->next != NULL){
		if(current->data == current->next->data){
			next_next = current->next->next;
			free(current->next);
			current->next = next_next;
		}
		else
			current = current->next;
	}
}

/**
 * Remove Duplicates from Unsorted Linked List [CTCI]
 * Method 1 : Using 2 Loops
 * 1. Loop 1 will pick elements one by one
 * 2. Loop 2 will compare the picked element with the rest of the elements
 * 		When a duplicate is encountered. Delete it.
 */
void remove_duplicates_from_unsorted_list(struct node** head_ref){
	// @2 loops -- Time: O(n2) but Space: O(1)

	struct node* current1;
	struct node* current2;
	struct node* next_next;

	current1 = *head_ref;

	while (current1 != NULL || current1->next != NULL){
		current2 = current1;
		while(current2->next != NULL){
			if(current1->data == current2->next->data){
				next_next = current2->next->next;
				free(current2->next);
				current2->next = next_next;
			}
			else
				current2= current2->next;
		}
		current1 = current1->next;
	}
}

/**
 * get_tail - Gets the last node of a Linked List
 */
struct node* get_tail(struct node* head){
	struct node* current = head;

	while(current->next != NULL){
		current = current->next;
	}

	printf("Tail : %d Address = %p\n", current->data, current);
	return current;
}

/**
 * get_intersection - Gets the intersection point of a definite Intesecting Lists
 */
void get_intersection(int diff, struct node* head1, struct node* head2){

	struct node* current1 = head1;
	struct node* current2 = head2;

	for (int i = 0; i<diff; i++){
		if (current2 == NULL){
			printf("NULL current 2");
			return;
		}
		printf("current2->data = %d\n", current2->data);
		current2 = current2->next;
	}

	while (current2 != NULL && current1 != NULL){
		if (current2 == current1){
			printf("Intersection point is %d", current2->data);
			return;
		}
		else {
			printf("current2->data = %d , current1->data = %d\n", current2->data, current1->data );
			current2 = current2->next;
			current1 = current1->next;
		}
	}
	return;
}

/**
 * find_intersection - Find the intersection of 2 linked lists, if any.
 * 1. Get Length of List1
 * 2. Get length of List2
 * 3. Get the difference
 * 4. Traverse the Longer list by diff nodes
 * 5. Traverse both the lists together comparing the nodes references.
 */
void find_intersection(struct node *head1, struct node* head2){

	int diff = 0;
	int length1, length2;
	struct node* tail1;
	struct node* tail2;

	tail1 = get_tail(head1);
	tail2 = get_tail(head2);

	if ((tail1) == (tail2)){
		printf("Intersecting Lists. %p\n", tail1);
	}
	else {
		printf("Not Intersecting Lists.\n");
		return;
	}

	length1 = length_of_list(head1);
	printf("Length1 = %d\n", length1);
	length2 = length_of_list(head2);
	printf("Length2 = %d\n", length2);

	if (length2 > length1) {
		diff = length2 - length1;
		get_intersection(diff, head1, head2);
	}
	else {
		diff = length1-length2;
		get_intersection(diff, head2, head1);
	}

	return;
}

/**
 * partition_list - Partition a linked List around a value X.
 * It doesn't preserve the original order of the of the Nodes hence called UNSTABLE.
 */
struct node* partition_list_unstable(struct node* head_list, int x){
	struct node* current = head_list;
	struct node* head = head_list;
	struct node* tail = head_list;

	while (current != NULL) {
		/* cache next node */
		struct node* next = current->next;
		if (current->data < x){
			/* Insert in the Front or head */
			current->next = head;
			head = current;
		}
		else {
			/* Insert node at tail */
			tail->next = current;
			tail = current;
		}

		current = next;
	}

	tail->next = NULL;

	head_list = head;
	return head_list;
}




// Reverse a Linked List
// Compare 2 lists Identical or not
// Check if a Linked List is a Palindrome or not.


int main(){
	printf("------ Linked List Practice file ------------ \n");
	/* Start with a Empty list */
	struct node *head = NULL;


	// Insert
	//insert_last(&head, 9);
	//print_list(head);
	//insert_beginning(&head, 8);
	//insert_beginning(&head, 6);
	//insert_beginning(&head, 4);
	//print_list(head);
	//printf("\nHead of the Linked list: %d\n", head->data);
	//insert_after(&head, 1 , 4);
	//print_list(head);
	//insert_after(&head, 3 , 2);
	//print_list(head);
	//insert_last(&head, 10);
	//print_list(head);
	//insert_after(&head, 10 , 7);
	//print_list(head);
	//struct node *current = head;
	//struct node *loop_attach = current->next;
	//delete_node(current->next->next);
	//delete_node(head);
	//insert_after(&head, 11 , 11);
	//print_list(head);

	//get_nth_node(head, 4);
	//get_nth_last(head, 5);
	//print_list(head);
	//get_middle(head);
	//detect_loop(head);
	//form_a_loop(head, loop_attach);
	//detect_remove_loop(head);
	//delete_list(&head);
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	if(!newNode)
		printf("malloc failed\n");

	newNode->data = 5;
	newNode->next = NULL;

	insert_in_sorted_list(&head, newNode);
	print_list(head);

	/* Test Intersection Code */
	struct node *head1 = NULL;
	struct node *head2 = NULL;

	insert_last(&head1, 11);
	insert_last(&head1, 13);
	insert_last(&head1, 9);
	insert_last(&head1, 7);
	insert_last(&head1, 5);

	insert_last(&head, 11);
	insert_last(&head, 13);
	insert_last(&head2, 1);
	insert_last(&head2, 3);
	insert_last(&head2, 5);

	struct node *intersectingNode = (struct node*)malloc(sizeof(struct node));
	if(!intersectingNode)
		printf("malloc failed\n");

	intersectingNode->data = 6;
	intersectingNode->next = NULL;

	print_list(head1);
	print_list(head2);
	form_a_loop(head1, intersectingNode);
	form_a_loop(head2, intersectingNode);
	print_list(head1);
	insert_last(&head1, 15);
	insert_last(&head1, 25);
	print_list(head1);
	print_list(head2);

	find_intersection(head1, head2);

	print_list(head1);
	head1 = partition_list_unstable(head1, 14);
	print_list(head1);
	return 0;
}
