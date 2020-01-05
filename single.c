/* single.c
 * Author: Alexis Villarreal
 * CreatedL 1/5/2020
 *
 * Singly linked list, using add_at, add_beginning, add_end, remove, dump?
 */


	#include <stdio.h>
	#include <stdlib.h>

	/* struct for node */
	typedef struct note_t {
		int data;
		struct node_t *next
	} node_t;

	node_t *head = NULL;


	/******************************************/
	/* Creates a new node, and puts it at a   */
	/* certain position, checking all points  */
	/******************************************/
	void add_at (int pos, int data){

		note_t *node = malloc(sizeof(note_t) * 1);
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
			++idx;
			prev = cur;
			cur = cur -> next;
		}







	}
