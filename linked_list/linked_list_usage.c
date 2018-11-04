#include <stdio.h>
#include "linked_list.h"

void prettyPrint(LinkedList *ll)
{
  printf("The linked list is now: \r\n");
  Node *n = ll->head;
  while (n != NULL)
  {
    printf("\t%d\r\n",n->key);
    n = n->next;
  }
}

int main()
{
  Node *n;
  printf("Creating a linked list\r\n");
  LinkedList *ll = LinkedList_init(0);

  for (int i=1; i<=10; i++)
  {
    printf("Inserting %d into the linked list\r\n", i);
    LinkedList_insert(ll, i);
  }

  for (int i=0; i<=11; i++)
  {
    printf("Searching for %d: ", i);
    n = LinkedList_search(ll, i);
    if (n == NULL) printf("NOT FOUND\r\n");
    else printf("FOUND\r\n");
  }

  for (int i=0; i<=10; i++)
  {
    printf("Deleting %d from the linked list\r\n", i);
    LinkedList_delete(ll, i);
  }

  prettyPrint(ll);

  for (int i=1; i<=10; i++)
  {
    printf("Inserting %d into the linked list\r\n", i);
    LinkedList_insert(ll, i);
  }

  for (int i=10; i>0; i--)
  {
    printf("Deleting %d from the linked list\r\n", i);
    LinkedList_delete(ll, i);
  }

  printf("Freeing the linked list\r\n");
  LinkedList_free(ll);

  return 0;
}
