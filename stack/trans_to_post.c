#include "trans_to_post.h"

void push_post(S* post_exp, S* opt_s)
{
	if (is_empty())

	while (is_post_push(post_exp->data[post_exp->len - 1], opt_s->data[opt_s->len - 1]))
	{
		DATA_TYPE temp = pop(post_exp);
		
		if (temp == -1)
		{
			
		}
		push(opt_s, );
	}
}

bool is_post_push(const char exp_opt, const char stk_opt)
{
	return opt_priority(exp_opt, false) >= opt_priority(stk_opt, true);
}

size_t opt_priority(const char opt, bool is_in_stack)
{
	size_t result;

	switch (opt)
	{
	case PLUS: case MINUS:
		result = 2;
		break;
	
	case MULTI: case DIVIS:
		result = 2;
		break;
	case O_BRKET:
		if (is_in_stack) { result = 3; }
		else { result = 0; }
	}

	return result;
}

S* trans_to_post(const char* in_exp)
{
	size_t b_cnt = 0;
	S post_exp = {
		.data = (DATA_TYPE[MAX_SIZE]) { '\0', },
		.len = 0
	};
	S opt_s = {
		.data = (DATA_TYPE[MAX_SIZE]) { '\0', },
		.len = 0
	};

	for (int i = 0; in_exp[i]; i++)
	{
		switch (in_exp[i])
		{
		case PLUS:
			push(&opt_s, PLUS);
			break;

		case MINUS:
			push(&opt_s, MINUS);
			break;

		case MULTI:
			push(&opt_s, MULTI);
			break;

		case DIVIS:
			push(&opt_s, DIVIS);
			break;

		case O_BRKET:
			push(&opt_s, O_BRKET);
			b_cnt += 1;
			break;

		case C_BRKET:
			push(&opt_s, O_BRKET);
			b_cnt -= 1;
			break;

		case SPACE:
			break;

		default:
			push(&post_exp, in_exp[i]);
			break;
		}

		if (opt_priority(in_exp[i], false))
		{
			
		}
	}
}