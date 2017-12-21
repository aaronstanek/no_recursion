#ifndef __NO_RECURSION_C_INCLUDED__
#define __NO_RECURSION_C_INCLUDED__

#include <stdlib.h>

struct no_recursion_node;
struct no_recursion_root;

typedef void * (*no_recursion_allocator)();
typedef void (*no_recursion_deallocator)(void*);

struct no_recursion_root * no_recursion_setup(no_recursion_allocator, no_recursion_deallocator);
unsigned long no_recursion_get_depth(struct no_recursion_root * r);
void * no_recursion_active(struct no_recursion_root * r);
void * no_recursion_prev(struct no_recursion_root * r);
void * no_recursion_push(struct no_recursion_root * r);
void no_recursion_pop(struct no_recursion_root * r);
void no_recursion_cleanup(struct no_recursion_root * r);

#endif
