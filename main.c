//Circular Queue using array

#include <stdio.h>

#define MAX 10

int queue[MAX];
int front, rear;

void int_queue(void)
{
	front = rear = 0;
}

void clear_queue(void)
{
	front = rear;
}

int put(int k)
{
	if(((rear + 1) % MAX)==front) //큐가 꽉 찾는지 확인
	{
		printf("\n Queue overflow.");
		return -1;
	}

	queue[rear] = k; //rear는 빈 공간을 가르키므로 바로 k를 저장
	rear = ++rear % MAX; //rear를 다음으로
	//rear의 다음이라는 표현한 것은 원형큐의 인덱스로서 만약에 배열의 경계에
	//도달 했을 경우 % 연산을 통하여 다시 제일 앞이나 뒤로 돌아가야 하기 때문이다.

	return k;
}

int get(void)
{
	int i;
	if(front == rear) // 큐가 비어 있는가?
	{
		printf("\n    Queue underflow.");
		return -1;
	}

	i = queue[front];
	front = ++front % MAX;
	return i;
}

void print_queue(void)
{
	int i;
	printf("\n Queue contents : Front ---> Rear\n");
	for(i = front; i != rear ; i == (++i % MAX)) // 주의 !!!
	{
		printf("%-6d", queue[i]);
	}
}

int main(void)
{
	int i;
	int_queue();

	printf("\nPut 5, 4, 7, 8, 2, 1");
	put(5);
	put(4);
	put(7);
	put(8);
	put(2);
	put(1);
	print_queue();

	printf("\nGet");
	i = get();
	print_queue();
	printf("\n  Getting value is %d", i);

//	printf("\nPut 3, 2, 5, 7");
	printf("\nPut 3, 2, 5");
	put(3);
	put(2);
	put(5);
//	put(7);
	print_queue();

	printf("\nNow queue is full, put 3");
	put(3);
	print_queue();


	return 0;
}





