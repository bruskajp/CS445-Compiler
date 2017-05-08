#ifndef TYPES_H
#define TYPES_H

typedef struct types_s
{
	int *types;
	int size;
} 
types_t;

types_t *make_types ();
void insert_type (types_t *t, int type);
void free_types (types_t *t);
void print_types (types_t *t);
int compare_types (types_t *t1, types_t *t2);

int semError(char *message);

#endif
