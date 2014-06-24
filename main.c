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

// after finding value if the value is existed add the node
// add t in front of k
node *insert_node(int t, int k)
{
	node *s; // point for searching
	node *p; // point to point previous of s
	node *r; // point to insert value

	p = head;
	s = p->next;

	//finding value of key
	while( s->key != k && s != tail)
	{
		p = p->next;
		s = p->next;
	}

	if(s != tail)
	{
		r = (node*)malloc(sizeof(node));
		r->key = t;
		p->next = r;
		r->next = s;
	}

	return p->next;
}

node *ordered_insert(int k)
{
	node *s;
	node *p;
	node *r;

	p = head;
	s = p->next;

	while( s->key <= k && s != tail)
	{
		p = p->next;
		s = s->next;
	}

	r = (node*)malloc(sizeof(node));
	r->key = k;
	p->next = r;
	s->next = s;

	return r;
}

// print list
void print_list(node *t)
{
	printf("\n");
	while(t != tail)
	{
		printf("\n %d", t->key);
		t = t->next;
	}

}

//delete all
node *delete_all(void)
{
	node *s;
	node *t;

	t = head->next;

	while(t != tail)
	{
		s = t;
		t = t->next;
		free(s);
	}

	head->next = tail;
	return head;
}


int main(void)
{

	node *t;

	init_list();
	ordered_insert(10);
	ordered_insert(5);

	printf("\nInitial Linked list is ");
	print_list(head->next);

	return 0;
}

