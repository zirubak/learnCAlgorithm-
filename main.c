// simple linked list example
// page 136


#include <stdio.h>

typedef struct _node{
	int key;
	struct _node *next;
} node;

node *head, *tail;

void init_list(void)
{
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));

	head->next = tail;
	tail->next = tail;
}

node *ordered_insert(int k)
{
	node *s;  //현재의 node
	node *p;  //이전의 node
	node *r;  //삽입되는 node

	p = head;
	s = p->next;

	while(s->key <= k && s != tail)
	{
		p = p->next;
		s = s->next;
	}

	r = (node*)malloc(sizeof(node));
	r->key = k;
	p->next = r;
	r->next = s;

	return r;
}

// print list
void print_list(node *t)
{
	printf("\n");
	while(t != tail)
	{
		printf("%-8d", t->key);
		t = t->next;
	}

}

int main(void)
{

	node *t;

	init_list();
	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);
	ordered_insert(8);

	printf("\nInitial Linked list is ");
	print_list(head->next);

	return 0;
}
