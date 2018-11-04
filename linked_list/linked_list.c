#include "linked_list.h"

Node *__LinkedList_new_node(int i)
{
  Node *n = (Node*) malloc(sizeof(Node));
  n->key = i;
  n->next = NULL;
  return n;
}

LinkedList *LinkedList_init(int i)
{
  Node *n = __LinkedList_new_node(i);

  LinkedList *ll = (LinkedList*) malloc(sizeof(LinkedList));
  ll->head = n;

  return ll;
}

void LinkedList_insert(LinkedList *ll, int i)
{
  Node *new = __LinkedList_new_node(i);

  if (ll->head == NULL)
  {
    ll->head = new;
  }
  else
  {
    Node *currentNode = ll->head;
    while (currentNode->next != NULL) currentNode = currentNode->next;

    currentNode->next = new;
  }
}

Node *LinkedList_search(LinkedList *ll, int i)
{
  Node *currentNode = ll->head;
  while (currentNode->key != i)
  {
    if (currentNode->next == NULL) return NULL;

    currentNode = currentNode->next;
  }
  return currentNode;
}

void LinkedList_delete(LinkedList *ll, int i)
{
  Node *currentNode = ll->head;
  Node *prevNode = NULL;

  while (currentNode->key != i)
  {
    if (currentNode->next == NULL) return;

    prevNode = currentNode;
    currentNode = currentNode->next;
  }

  // We have now found the node in question

  // Edge case for deleting first node
  if (prevNode == NULL)
  {
    ll->head = currentNode->next;
  }
  else
  {
  prevNode->next = currentNode->next;
  }
  free(currentNode);
}

void LinkedList_free(LinkedList *ll)
{
  Node *currentNode = ll->head;
  Node *prevNode = NULL;

  while (currentNode != NULL)
  {
    prevNode = currentNode;
    currentNode = currentNode->next;
    free(prevNode);
  }

  free(ll);
}
