// simple linked list example
// page 136


#include <stdio.h>

typedef struct _node{
	int key;
	struct _node *next;
} node;

//to init linked list
node *head, *tail; //define by global variable

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

node *find_node(int k)
{
	node *s;
	s = head->next; //head 부터 검색을 해야 하니 처음 node를 세팅해 주어야 함
	while( s->key != k && s != tail)
	{
		s = s->next;
	}

	return s;
}

node *insert_after(int k, node *t)
{
	node *s;
	s = (node*)malloc(sizeof(node*));
	s->key = k;
	s->next = t->next;
	t->next = s;
	return s;
}

int delete_next(node *t)
{
	node *s;
	if( t->next == tail)
		return 0;	//꼬리는 지울 수가 없다
	s = t->next;
	t->next = t->next->next;
	free(s);
	return 1;
}

node *insert_node(int t, int k) // before k, insert t
{
	node *s;
	node *p;
	node *r;

	p = head;
	s = p->next;

	while(s->key !=k && s != tail)
	{
		p = p->next;
		s = p->next;
	}

	if(s != tail) // if find
	{
		r = (node*)malloc(sizeof(node));
		r->key = t;
		p->next = r;
		r->next = s;
	}

	return p->next;
}

int delet_node(int t)
{
	node *s;
	node *p;

	p = head;
	s = p->next;

	while( s->key != t && s != tail)
	{
		p = p->next;
		s = s->next;
	}

	if(s != tail) //if find
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

node *delete_all(void)
{
	node *s;
	node *t;

	t = head->next;
	while( t != tail)
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
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);
	ordered_insert(8);

	printf("\nInitial Linked list is ");
	print_list(head->next);
	printf("\n");

	t = find_node(5);
	printf("\nFinding 5 is %ssuccessful", t == tail ? "un" : "");

//	t = find_node(0);
//	printf("\nFinding 0 is %ssuccessful", t == tail ? "un" : "");

	printf("\nInserting 9 after 5");
	insert_after(9, t);
	print_list(head->next);

	t = find_node(10);
	printf("\nDeleting next last node.");
	delete_next(t);
	print_list(head->next);	//10의 뒤는 tail이라서 지울 수가 없다. return 0 함

	t = find_node(3);
	printf("\nDeleting next 3.");
	delete_next(t);
	print_list(head->next);

	printf("\nInsert node 2 before 3");
	insert_node(2,3);
	print_list(head->next);

	printf("\nDeleting node 2");
	if(!delet_node(2))
		printf("\n deleting 2 is unsuccessful");
	print_list(head->next);

	printf("\nDeleting node 1");
	delet_node(1);
	print_list(head->next);

	printf("\nDeleting all node.");
	delete_all();
	print_list(head->next);

	return 0;
}
