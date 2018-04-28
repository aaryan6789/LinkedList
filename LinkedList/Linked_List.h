/* Linked_List.h */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

/* Q's
 *
 * 0. Representation of a SLL
 * 1. Traverse a Linked List
 * 2. Count number of nodes in a LL
 * 3. Print a linked List
 * 4. Print a linked list in reverse.
 * 5. Insert_begin
 * 6. Insert_end
 * 7. insert_after or Insert_nth
 * 8. Given a pointer to a node, delete that node.
 * 9. Get the middle of the linked list
 *10. Detect loop in a Linked List
 *11. Remove the loop in a linked list
 *12. Delete a Linked List
 *13. Reverse a Linked list
 *14.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */


/* Structure to represent a Singly Linked List */
struct node {
	int data;
	struct node* next;
};

int length_of_list(struct node *head);

void insert_last(struct node **head_ref, int data);
struct node* addTwoLists(struct node* head1, struct node* head2);
struct node* removeElements(struct node* head, int val);
struct node* remove_nth_node_from_end(struct node** head_ref, int n);
void remove_nth_node_from_end_2(struct node** head_ref, int n);
void deleteNskipM(struct node* head, int n, int m);
void deleteNskipM_alternatively(struct node* head, int n, int m);

// List Intersection
struct node* get_tail(struct node* head);
void get_intersection(int diff, struct node* head1, struct node* head2);
void find_intersection(struct node *head1, struct node* head2);

// Detect Remove Loop
void detect_loop(struct node* head);
void _remove_loop(struct node *loop_node, struct node *head);
void detect_remove_loop(struct node *head);
void form_a_loop(struct node *head, struct node *loop_attach);
struct node* partition_list_unstable(struct node* head_list, int x);

void rotate_list(struct node* head, int k);


#endif /* LINKED_LIST_H_ */
