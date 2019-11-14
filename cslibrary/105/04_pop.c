#include "node.h"
#include <assert.h>

int Pop(struct node** headRef)
{
  struct node* head = *headRef;
  int data;

  assert(head != NULL);
  data = head->data;

  *headRef = head->next;
  free(head);

  return data;
}

int main()
{
  struct node* myList = NULL;
  Push(&myList, 3);
  Push(&myList, 2);
  Push(&myList, 1);

  PrintValues(myList);
  assert(Pop(&myList) == 1);
  PrintValues(myList);

  assert(Pop(&myList) == 2);
  PrintValues(myList);

  assert(Pop(&myList) == 3);
  PrintValues(myList);

  return 0;
}
