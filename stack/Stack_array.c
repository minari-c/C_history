#include <stdio.h>
#include <stdlib.h>

/*
 Stack! by array ~

 [charactor]
 1. first in, last out
 2. last in, first out
 
 [±â´É]
 1. push
	- push data after last data in stack
 2. pop
	- extraction last data in stack
*/

typedef struct Stack {
	int* data;						// real
	int last_index_number;
	int max_length;						// length of data
	int (*pop)(struct Stack* const);		// pop function
	int (*push)(struct Stack* const, int);	// push funciton
}S;

int push(S * const stack, int data)
{
	int next_index_number = stack->last_index_number + 1;

	if (next_index_number == stack->max_length)
	{
		return -1;
	}
	else
	{
		stack->last_index_number++;
		return stack->data[next_index_number] = data;
	}
}

int pop(S* const stack)
{
	int last_index_number = stack->last_index_number;

	if (last_index_number == -1)
	{
		return -1;
	}
	else 
	{
		stack->last_index_number--;
		return stack->data[last_index_number];
	}
}

void print_stack(S* const stack)
{
	printf("\n==========print_stack==========\n");
	for (int i = stack->last_index_number; i >= 0; i--)
		printf("[%d]: %d\n", i, stack->data[i]);
}

int main(void)
{
	int dummy_array[] = { 10, 20, 30, 40, 50 };
	S stack = { NULL, -1, 5, pop, push };

	stack.data = (int*)malloc(sizeof(int) * 5);

	for (int i = 0; i < 5; i++)
	{
		printf("\n==============push=============\n");
		printf("push data [%d]: %d\n"
			, stack.last_index_number
			, stack.push(&stack, dummy_array[i])
		);

		print_stack(&stack);
	}

	printf("\n\n\n\n\n");

	for (int i = stack.last_index_number; i >= 0; i--)
	{
		printf("\n==============pop==============\n");
		printf("pop data [%d]: %d\n"
			, stack.last_index_number + 1
			, stack.pop(&stack)
		);

		print_stack(&stack);
	}


	free(stack.data);
}