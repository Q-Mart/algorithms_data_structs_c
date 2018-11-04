#include <stddef.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
} LinkedList;

Node *__LinkedList_new_node(int i);

LinkedList *LinkedList_init(int i);

void LinkedList_insert(LinkedList *ll, int i);

Node *LinkedList_search(LinkedList *ll, int i);

void LinkedList_delete(LinkedList *ll, int i);

void LinkedList_free(LinkedList *ll);
