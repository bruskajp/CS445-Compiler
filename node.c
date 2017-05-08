#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#define FUNCTION 280

node_t *make_node(char *name, int type, int effective_type)
{
	node_t *p = (node_t *)malloc(sizeof(node_t));
	p->name = strdup(name);
	p->type = type;
	p->effective_type = effective_type;
	p->parameter_types = NULL;
	return p;
}

node_t *node_search(node_t *head, char *name)
{
	node_t *p = head;
	//fprintf(stderr, "start search: ");

	while (p != NULL) {
		//fprintf(stderr, " (nn = %s) ", p->name);
		if (!strcmp(p->name, name)) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

node_t *node_insert(node_t *head, char *name, int type, int effective_type)
{
	node_t *p = make_node(name, type, effective_type);

	p->next = head;
	return p;
}




