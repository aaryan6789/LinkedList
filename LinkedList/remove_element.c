/* remove_element.c *  Created on: Apr 9, 2018 *      Author: hsahu */
#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

/* LEETCODE M
 * Remove all elements from a linked list of integers that have a given value "val".
 */

/* Algorithm:
 *
 *
 */
struct node* removeElements(struct node* head, int val) {
    struct node* current = head;
    struct node* prev;
    struct node* temp;

    // Case 1 -- When the head node itself is the key, or contains multiple
    //           instances of the key
    // Case 2 -- When the last node is the key
    // Case 3 -- When the key is somewhere in the middle

    // Case 1	e.g = 1->1->1->2->3->NULL , val = 1
    while ( current != NULL && current->data == val){
        if(current->next == NULL)
            return NULL;

        temp = current->next;		// Cache the next node
        current->data = temp->data;
        current->next = temp->next;
        free(temp);
        head = current;
    }

    // Case 2 and 3
    while(current != NULL){

    	while(current!= NULL && current->data != val){
            prev = current;
            current = current->next;
        }

        // Here the current node contains the value to be deleted or is the NUll node
        if (current == NULL)
            return head;

        // current->data == Val here
        prev->next = current->next;			// Cache the next node in prev->next
        free(current);
        current = prev->next;
   }

    return head;
}
