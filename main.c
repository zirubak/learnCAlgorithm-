/*
 * main.c
 *
 *  Created on: Jun 23, 2014
 *      Author: jh
 */

#include <stdio.h>

//data structure of simple linked list
typedef struct _node{
	int key; //save data
	struct _node *next; // the point of next node
} node;


//to init linked list

node *head, *tail; //define by global variable

void init_list(void)
{
	head = (node*)malloc(sizeof(node)); // make space of head
	tail = (node*)malloc(sizeof(node)); // make space of tail

	head->next = tail;
	tail->next = tail;
}


int main(void)
{

	return 0;
}

