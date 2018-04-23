/* rotate_list.c *  Created on: Apr 16, 2018 * Author: hsahu */

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"



/* Rotate a SLL counter clockwise by K nodes, where k is a Positive integer.
 * I/p= 10->20->30->40->50->60 K = 4
 * O/p= 50->60->10->20->30->40
 */

/* 1. Traverse the Linked List by K nodes
 * 2. the Next node of Kth node should be set to NULL
 * 3. Cache the Previous head node and
 * 		set the next of the Last node to the head node.
 * 4. The new Head node would be the k+1 th node
 */
void rotate_list(struct node* head, int k){
	struct node* prev_head = head;
	struct node* current = head;

	// Traverse the Linked List to get to the Kth node
	for(int i = 1; i<k && current != NULL ; i++){
		current = current->next;
	}

	struct node* kth = current;
	struct node* kplus1 = current->next;

	// Get to the Last node of the Linked List
	while(current->next != NULL){
		current = current->next;
	}

	current->next = prev_head;
	head = kplus1;
	kth->next = NULL;

}

