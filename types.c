#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "types.h"

types_t *make_types ()
{
  types_t *t = (types_t *)malloc(sizeof(types_t));
	assert(t != NULL);
	
  t->size = 0;
  t->types = (int *)malloc(0*sizeof(int));
}

void insert_type (types_t *t, int type)
{
  t->size = t->size + 1;
  t->types = (int *)realloc(t->types, t->size*sizeof(int));
  t->types[(t->size)-1] = type;
}

void free_types (types_t *t)
{
  free(t->types);
  t->types = NULL;
  t->size = 0;
}

void print_types (types_t *t)
{
	int i = 0;
	fprintf(stderr, "( ");
	if ( t != NULL ){
		for (; i < t->size; ++i){
			fprintf(stderr, "%d", (t->types)[i]);
			if ( i != t->size - 1 ){ fprintf(stderr, ", "); }
		}
	}
	fprintf(stderr, " )");
}

int compare_types (types_t *t1, types_t *t2)
{
	if ( t1->size > t2->size ){
		semError("Function passed too few arguements");
	} else if ( t1->size < t2->size ){
		semError("Function passed too many arguements");
	} else {
		int i = 0;
		for (; i < t1->size; ++i){
			if ( (t1->types)[i] != (t2->types)[i] ){
				char *msg;
				asprintf(&msg, "Function arguement %d is not the correct type", i+1);
				semError(msg);
			}
		}
		return 1;
	}
}

int semError(char *message)
{ 
  fprintf(stderr, "\n\nSemantic Error: %s\n", message);
  exit(1);
}



