#include "stack.h"

DATA_TYPE pop(S* const s)
{
	DATA_TYPE result;

	if (is_empty(s))
	{
		result = -1;
	}
	else
	{
		s->len -= 1;

		result = s->data[s->len];
	}

	return result;
}
bool push(S* const s, DATA_TYPE data)
{
	bool result = true;

	if (is_over(s))
	{
		result = false;
	}
	else
	{
		s->data[s->len] = data;

		s->len += 1;
	}

	return result;
}
bool is_over(S* const s)
{
	if (s->len >= MAX_SIZE)
		return true;
	else
		return false;
}
bool is_empty(S* const s)
{
	bool result = false;
	if (s->len <= 0) { result = true; }

	return result;
}
void print_stack(S* const s)
{
	int len = s->len;

	printf("==============stack===============\n");
	for (int i = 0; i < len; i++)
	{
		printf("[%3d]: %c\n", i + 1, s->data[i]);
	}
}
