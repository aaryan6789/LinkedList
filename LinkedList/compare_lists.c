/*
 * compare_lists.c
 *
 *  Created on: Apr 23, 2018
 *      Author: hsahu
 */
#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

/* Write a function to check if the given two linked lists are identical or not.
 *
 * Identical Lists:
 * 2 Lists are identical if they have the same data and arrangement of the data.
 *
 * Example:
 * a = 1->2->3
 * b = 1->2->3
 *
 * areIdentical: True
 */


int compare_lists(struct node* a, struct node* b) {

	while(1){
		if(a == NULL && b == NULL)
			return 1;

		if(a == NULL && b != NULL)
			return 0;

		if(a != NULL && b == NULL)
			return 0;

		if(a->data != b->data)
			return 0;

		a = a->next;
		b = b->next;
	}
}
