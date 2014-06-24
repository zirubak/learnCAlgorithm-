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


// t is previous node.
node *insert_after(int k, node *t)
{
	node *s;
	s = (node*)malloc(sizeof(node*));
	s->key = k;
	s->next = t->next;
	t->next = s;

	return s;
}


// delete node
int delete_next(node *t)
{
	node *s;

	if (t->next == tail)
	{
		return 0;
	}

	s = t->next;
	t->next = t->next->next;
	free(s);

	return 1;
}

//find node
node *find_node(int k)
{
	node *s;

	s = head->next; // head->next is first node of the list.
	while(s->key != k && s != tail)
		s = s->next;
	return s;
}

// after finding value if the value is existed delete the node
int delete_node(int k)
{
	node *s; // node for searching
	node *p; // previous node of s

	p = head;
	s = p->next;

	while(s->key != k && s != tail)
	{
		p = p->next;
		s = p->next;
	}

	if(s != tail)
	{
		p->next = s->next;
		free(s);
		return 1;
	}
	else
	{
		return 0;
	}
}




int main(void)
{

	return 0;
}

