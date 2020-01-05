/* single.c
 * Author: Alexis Villarreal
 * CreatedL 1/5/2020
 *
 * Singly linked list, using add_at, add_beginning, add_end, remove, print_list
 */


	#include <stdio.h>
	#include <stdlib.h>

	/* struct for node */
	typedef struct node_t {
		int data;
		struct node_t *next;
	} node_t;

	node_t *head = NULL;


	/******************************************/
	/* Creates a new node, and puts it at a   */
	/* certain position, checking all points  */
	/******************************************/
	void add_at (int pos, int data){

		node_t *node = malloc(sizeof(node_t) *1);
		node -> data = data;
		node -> next = NULL;

		/* if empty */
		if(head == NULL){
			head = node;
			return;
		}

		int index = 0;

		node_t *prev = NULL;
		node_t *cur = head;


		/* loop until position found, OR end */
		while (cur != NULL && index != pos){
			++index;
			prev = cur;
			cur = cur->next;
		}

		/* head update, begin of list */
		if (index == 0) {
			head = node;
			node -> next = cur;
			return;
		}

		/* end of list */
		if (cur == NULL) {
			prev -> next = node;
			return;
		}

		/* middle of list */
		prev -> next = node;
		node -> next = cur;
	}

	/*********************************/
	/* adds at the beginning of the  */
	/* linked list, using the add_at */
	/* function.                     */
	/*********************************/
	void add_beginning(int data){
		add_at(0, data);
	}

	/***************************************/
	/* adds at the end of the linked list, */
	/* using the add_at function. Using -1 */
	/* because it will never reach a pos,  */
	/* meaning it will always go to NULL   */
	/***************************************/
	void add_end(int data){
		add_at(-1, data);
	}

	/* Prints the list using temporary node */
	void print_list(){
		node_t *temp = head;

		while(temp != NULL) {
			printf("data: %d\n", temp->data);
			temp = temp->next;
		}

	}

	/* removes a certain item from the linked list */
	void remove_item(int data){
		node_t *prev = NULL;
		node_t *cur = head;

		while(cur != NULL && cur->data != data){
			prev = cur;
			cur = cur->next;
		}

		/* no data, return */
		if (cur == NULL){
			return;
		}

		if (prev == NULL){
			if(cur->next == NULL){
				head = NULL;
			} else {
				head = cur -> next;
			}

			free(cur);
			return;
		}

		/* last item in the list */
		if(cur->next == NULL) {
			prev->next = NULL;

			free(cur);
			return;
		}

		/* item in the middle of list */
		if (prev != NULL && cur -> next != NULL){
			prev -> next = cur-> next;

			free(cur);
			return;
		}

	}

	/* destroys the list */
	void destroy_list(){
		node_t *temp = head;

		while(head->next != NULL){
			temp = head->next;
			head->next = temp->next;
			free(temp);
		}
		temp = head;
		head = NULL;
		free(temp);
	}

	int main(int argc, char **argv) {
		add_end(2);
		add_end(3);
		add_end(5);
		add_beginning(1);
		add_at(3, 4);

		printf("After adding...\n");
		print_list();

		remove_item(1);
		remove_item(3);
		remove_item(5);
		printf("After removals...\n");
		print_list();

		destroy_list();

		return 0;
	}







