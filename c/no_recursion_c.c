#include "no_recursion_c.h"

struct no_recursion_node {
  struct no_recursion_node * prev;
  void * frame;
};

struct no_recursion_root {
  struct no_recursion_node * root;
  unsigned long depth;
  no_recursion_allocator n;
  no_recursion_deallocator d;
};

struct no_recursion_root * no_recursion_setup(no_recursion_allocator n, no_recursion_deallocator d) {
  struct no_recursion_root * r = malloc(sizeof(struct no_recursion_root));
  (r->root) = malloc(sizeof(struct no_recursion_node));
  (r->depth) = 1;
  (r->n) = n;
  (r->d) = d;
  (r->root->frame) = n();
  return r;
}

unsigned long no_recursion_get_depth(struct no_recursion_root * r) {
  return r->depth;
}

void * no_recursion_active(struct no_recursion_root * r) {
  return r->root->frame;
}

void * no_recursion_prev(struct no_recursion_root * r) {
  return r->root->prev->frame;
}

void * no_recursion_push(struct no_recursion_root * r) {
  struct no_recursion_node * mi = malloc(sizeof(struct no_recursion_node));
  (mi->prev) = r->root;
  (mi->frame) = (r->n)();
  (r->root) = mi;
  (r->depth) = (r->depth)+1;
  return (r->root->frame);
}

void no_recursion_pop(struct no_recursion_root * r) {
  struct no_recursion_node * mi = r->root->prev;
  (r->d)(r->root->frame);
  free(r->root);
  (r->root) = mi;
  (r->depth) = (r->depth)-1;
}

void no_recursion_cleanup(struct no_recursion_root * r) {
  while (r->depth!=0) {
    no_recursion_pop(r);
  }
  free(r);
}
