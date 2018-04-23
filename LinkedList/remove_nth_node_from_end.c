/*
 * remove_nth_node_from_end.c
 *
 *  Created on: Apr 16, 2018
 *      Author: hsahu
 */
#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"
/* LeetCode M
 * Given a Linked List,
 * Remove the nth node from the end of list and return its head. */
/* Algorithm:
 * The Logic remains the same as the Nth node from the end detection.
 * Find the Nth Node and remove this Node.
 */
struct node* remove_nth_node_from_end(struct node** head_ref, int n){
	printf("Removing %dth node from the end\n", n);

	struct node* slow = *head_ref;
	struct node* fast = *head_ref;
	struct node* prev;

	if(slow->next == NULL)
		return NULL;

	//Advances fast pointer so that the gap between fast and slow is n nodes apart
/*	int count = 1;

	while (count != n) {
		count++;
		fast = fast->next;
	}
*/
	for(int i = 1; i<n; i++){
		fast = fast->next;
	}

	while (fast->next != NULL){
		prev = slow;
		fast = fast->next;
		slow = slow->next;
	}

	// Now Slow Pointer is actually pointing to the nth node from end
	printf("%dth node from the end = %d\n", n, slow->data);

	// Skip over this node
	// If this is the last node
	if(slow->next == NULL){
		prev->next = NULL;
		free(slow);
	}
	else{
		struct node*  temp = slow->next;

		slow->data = temp->data;
		slow->next = temp->next;
		free(temp);
	}

	return *head_ref;
}

// Two Pointer without
// Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/solution/
// Just move slow to the node behind the Node to be deleted.
// Now delete the next node
void remove_nth_node_from_end_2(struct node** head_ref, int n){
	printf("Removing %dth node from the end 2\n", n);
	struct node* fast = *head_ref;
	struct node* slow = *head_ref;

	// Check for invalid n
	if(n <= 0){
		return;
	}

	int count = 1;
	while(count != n+1){
		fast = fast->next;
		count++;
	}

	while (fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	}

	printf("Node behind the %dth node from the end is %d\n",n ,slow->data);
	// Now slow is pointing to one node behind the target node
	slow->next = slow->next->next;
}


/*Algorithm
The above algorithm could be optimized to one pass.
Instead of one pointer, we could use two pointers.
The first pointer advances the list by n+1 steps from the beginning,
while the second pointer starts from the beginning of the list.

Now, both pointers are exactly separated by n nodes apart.
We maintain this constant gap by advancing both pointers together until the
first pointer arrives past the last node.
The second pointer will be pointing at the nth node counting from the last.
We relink the next pointer of the node referenced by the second pointer to point
to the node's next next node.

 */
