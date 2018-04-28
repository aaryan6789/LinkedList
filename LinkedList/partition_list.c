/* partition_list.c *  Created on: Apr 23, 2018 * Author: hsahu */
#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

/* LeetCode M | CTCI M
 * Partition List
 * Given a linked list and a value x,
 * partition it such that all nodes less than x come before nodes
 * greater than or equal to x.
 *
 * NOTE: You should preserve the original relative order of the nodes in each
 * of the two partitions.
 *
 * Example:
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 */

/* 1. Create 2 different Linked Lists: smaller and greater
 * 		1. For elements less then value X		--> on smaller
 * 		2. For elements more than value X		--> on greater
 * 2. Iterate through the list,
 * 		insert the element in the head if node->data < x
 * 		insert the element in the tail if node->data > x
 * 3. Once we reach to the end of the list, merge the 2 lists
 */
struct node* partition_list_stable(struct node* head, int x){
	struct node* current = head;
	struct node* smallerHead = NULL;
	struct node* smallerLast = NULL;
	struct node* greaterHead = NULL;
	struct node* greaterLast = NULL;

	while(current != NULL){
		// If the current data is smaller or equal to X, then insert in smaller list
		if(current->data <= x){
			if(smallerHead == NULL) {
				smallerHead = smallerLast = current;
			}
			else{
				smallerLast->next = current;
				smallerLast = current;
			}
		}
		// Else, if current data is greater than X, then insert in the greater list
		else {
			if(greaterHead == NULL){
				greaterHead = greaterLast = current;
			}
			else{
				greaterLast->next = current;
				greaterLast = current;
			}
		}
		// Move the current pointer to next node
		current = current->next;
	}

	// End the resulting list by setting null to the greaterLast
	if (greaterLast != NULL)
		greaterLast->next = NULL;


	// Now connect the 2 lists
	if(smallerHead == NULL){
		return greaterHead;
	}
	else{
		smallerLast->next = greaterHead;
		return smallerHead;
	}
}


/**
 * partition_list - Partition a linked List around a value X.
 * It doesn't preserve the original order of the of the Nodes hence called UNSTABLE.
 *
 * Algorithm:
 * 1. Create 2 different Linked Lists: head and tail
 * 		1. For elements less then value X		--> on Head
 * 		2. For elements more than value X		--> on tail
 * 2. Iterate through the list,
 * 		insert the element in the head if node->data < x
 * 		insert the element in the tail if node->data > x
 * 3. Once we reach to the end of the list, merge the 2 lists
 * 		head->next = tail;
 * 		tail->next = NULL
 */
struct node* partition_list_unstable(struct node* head_list, int x){
	struct node* current = head_list;
	struct node* front = head_list;
	struct node* tail = head_list;


	printf("Partitioning the list around value = %d Head_data=%d\n", x, head_list->data);

	while (current != NULL) {
		printf("Current->data = %d\n", current->data);
		/* cache next node */
		struct node* next = current->next;
		if (current->data <= x){
			/* Insert in the Front or head */
			//printf("Front->data = %d Current->next->data = %d\n",
			//		front->data, current->next->data);
			current->next = front;		// front will be current->next
			front = current;			// current node becomes the front node
										// First node will be pointing to itself, all the subsequent nodes will be behind the 1st node
										// The front will keep on changing
		}
		else {
			/* Insert node at tail */
			tail->next = current;
			tail = current;
		}
		current = next;
	}
	tail->next = NULL;

	head_list = front;
	return head_list;
}
/* 6->5->8->15->25
 *
 * 1. current = 6 --> front = 6 | front->next is current->next which is front again so front is pointing to itself
 * 2. current = 5 --> front = 5 | this will be the new front and front->next is current->next which is previous front
 *
 * so after 2nd step --> 5-->6---
 * 						 ^   ^  |
 * 						 |   ---
 * 					   Front
 *
 * 3. current = 8 --> front = 8 | current->next = front and current = front
 *
 * so after 3rd step --> 8-->5-->6---
 * 						 ^   	 ^  |
 * 						 |        ---
 * 					   Front
 *
 * 4. current = 15 --> >10 so | tail->next = current and current =tail
 *
 * 				tail -> 15---
 * 						 ^	|
 * 						 ---
 * 5. tail
 */
