#ifndef NODE_H
#define NODE_H

#include "types.h"

typedef struct node_s
{
	char *name;
	int type;	/* VAR, FUNCTION, PROCEDURE */
	int effective_type; /* INUM, RNUM */
	types_t *parameter_types;
	int offset;
	/* extra information */
	
	struct node_s *next;	
} 
node_t;

node_t *make_node(char *name, int type, int effective_type, int offset);

/* Linked List support */
node_t *node_search(node_t *, char *);
node_t *node_insert(node_t *, char *, int, int, int);

void free_node(node_t *);

#endif

