#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scope.h"

int hashpjw( char *s );

/* constructor */
scope_t *make_scope()
{
	int i;
	scope_t *p = (scope_t *)malloc(sizeof(scope_t));

	for (i=0; i<HASH_SIZE; i++) {
		p->table[i] = NULL;
	}
	p->return_name = NULL;
	p->return_needed = 0;
	p->next = NULL;
	p->offset = 0;
	p->type = 0;

	return p;
}

/* local search */
node_t *scope_search( scope_t *scope, char *name )
{
	int index;
	node_t *head;

	if (scope != NULL) {
		index = hashpjw(name);
		head = scope->table[index];

		return node_search(head, name);
	}
	else return NULL;
}

/* local insert */
node_t *scope_insert( scope_t *scope, char *name, int type, int effective_type )
{
	int index;
	node_t *head;

	if (scope != NULL) {
		
		index = hashpjw(name);
		head = scope->table[index];
		
		scope->offset += 4;
		int offset = scope->offset;
		
		//fprintf(stderr, "  (type: %d)  ", type);
		return scope->table[index] = node_insert(head, name, type, effective_type, offset);
	}
	else return NULL;
}

/* global search */
node_t *scope_search_all( scope_t *curr_scope, char *name )
{
	node_t *p;

	while (curr_scope != NULL) {
		p = scope_search(curr_scope, name);
		if (p != NULL)
			return p;
		curr_scope = curr_scope->next;
	}
	return NULL;
}

/* push new scope */
scope_t *scope_push( scope_t *top )
{
	scope_t *new_scope = make_scope();
	assert( new_scope != NULL );

	new_scope->next = top;
	return new_scope;
}

/* pop top scope */
scope_t *scope_pop( scope_t *top )
{
	scope_t *tmp;

	if (top != NULL) {
		tmp = top;
		top = top->next;

		//free_scope(tmp);

		return top;
	}
	else return NULL;
}

void free_scope(scope_t *scope)
{
	if ( scope != NULL ){
		int i = 0;
		for(; i<HASH_SIZE; ++i){
			if ( scope->table[i] != NULL ){
				free_node(scope->table[i]);
			}
		}
	}
}

/* Weinberger's magic hash function */
/* page 436 Dragon 1 */
int hashpjw( char *s )
{
	char *p;
	unsigned h = 0, g;

	for ( p=s; *p != EOS; p++ ) {
		h = (h << 4) + (*p);
		if ( g = h&0xf0000000 ) {
			h = h ^ (g >> 24);
			h = h ^ g;
		}
	}
	return h % HASH_SIZE;
}











