#ifndef TYPES_H
#define TYPES_H


typedef struct tree_s tree_t;

typedef struct types_s
{
	int *types;
	int size;
	tree_t *expression_list;
} 
types_t;

types_t *make_types ();
void insert_type (types_t *t, int type, tree_t *expression_list);
void free_types (types_t *t);
void print_types (types_t *t);
int compare_types (types_t *t1, types_t *t2);

int deref_type(int type);
int ref_type(int type);

int semError(char *message);

#endif
