#include <stdio.h>
#include <stdlib.h>

/*
 Stack! by linked list!

 [charactor]
 1. first in, last out
 2. last in, first out

 [기능]
 1. push
	- push data after last data in stack
 2. pop
	- extraction last data in stack

	스텍은 포인팅 방향이 거꾸로 되기 때문에 그거 지금 고려 하고 있었음

*/

typedef struct Node {						// Linked list node
	int data;
	struct Node* next;
}N;

typedef struct Linked_list {				// it's represent linked list head
	N* last;
}L;

typedef struct Stack {
	L* list;						// real
	int length;
	int (*pop)(struct Stack* const);		// pop function
	int (*push)(struct Stack* const, int);	// push funciton
}S;


int push(S* const stack, int data)
{
	N* temp = last_node(stack->list);
	temp->next = make_node_with_data(data);
}

int pop(S* const stack)
{
	int last_index_number = stack->length;

	if (last_index_number == -1)
	{
		return -1;
	}
	else
	{
		N* temp = last_node(stack->list);
		stack->length--;
		return temp->data;
	}
}

void print_stack(S* const stack)
{
	N* temp = last_node(stack->list);
	printf("\n==========print_stack==========\n");
	for (int i = stack->length; i >= 0; i--)
	{
		printf("[%d]: %d\n", i, temp->data);
		temp = temp->next;
	}
}

N* make_node_with_data(int data)
{
	N* temp = (N*)malloc(sizeof(N));
	*temp = (N){ .data = data, .next = NULL };

	return temp;
}

void* append_node(L* list, int new_data)
{
	list->last->next = make_node_with_data(new_data);
}

N* last_node(L* list)
{
	N* temp = list->last;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	return temp;
}

int main(void)
{
	int dummy_array[] = { 10, 20, 30, 40, 50 };
	S stack = { 
		&(L) { .last = NULL },
		0,
		pop,
		push
	};

	for (int i = 0; i < 5; i++)
	{
		printf("\n==============push=============\n");

		printf("push data [%d]: %d\n"
			, stack.length
			, stack.push(&stack, dummy_array[i])
		);

		print_stack(&stack);
	}

	printf("\n\n\n\n\n");

	for (int i = stack.length; i >= 0; i--)
	{
		printf("\n==============pop==============\n");
		printf("pop data [%d]: %d\n"
			, stack.length + 1
			, stack.pop(&stack)
		);

		print_stack(&stack);
	}


	free(stack.list);
}