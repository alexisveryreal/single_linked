/* single.c
 * Author: Alexis Villarreal
 * CreatedL 1/5/2020
 *
 * Singly linked list, using add_at, add_beginning, add_end, remove, print_list
 */


	#include <stdio.h>
	#include <stdlib.h>

	/* struct for node */
	typedef struct note_t {
		int data;
		struct node_t *next;
	} node_t;

	node_t *head = NULL;


	/******************************************/
	/* Creates a new node, and puts it at a   */
	/* certain position, checking all points  */
	/******************************************/
	void add_at (int pos, int data){

		node_t *node = malloc(sizeof(node_t) * 1);
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
			cur = cur -> next;
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







