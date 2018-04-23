/*
 * list_intersection.c
 *
 *  Created on: Apr 16, 2018
 *      Author: hsahu
 */

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

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
 * get_intersection - Gets the intersection point of a definite Intersecting Lists
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
			printf("current2->data = %d , current1->data = %d\n",
					current2->data, current1->data );
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
 * 3. Get the difference "diff"
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
