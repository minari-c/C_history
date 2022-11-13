#ifndef STACK_H

#define STACK_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 200
#define DATA_TYPE char

typedef struct stack{
	DATA_TYPE data[MAX_SIZE];
	size_t len;
}S;

DATA_TYPE pop(const S*);
bool push(const S*, DATA_TYPE);
bool is_over(const S*);
bool is_empty(const S*);
void print_stack(const S*);

#endif
