#ifndef TRANS_TO_POST_H

#define TRANS_TO_POST_H
#include "stack.h"

#define DEFLUAT_OPT_COUNT 5

#define PLUS	'+'
#define MINUS	'-'
#define MULTI	'*'
#define DIVIS	'/'
#define REMAIN	'%'

#define O_BRKET	'('
#define C_BRKET	')'
#define SPACE	' '

typedef struct opt_def{
	const char opt;
	const size_t priority;
}OPT_DEF;

S* trans_to_post(const char*);

#endif
