#include "node.h"
#include <assert.h>

void DeleteList(struct node **headRef)
{
  struct node* current = *headRef;
  struct node* next;

  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  *headRef = NULL;
}

int main()
{
  struct node* myList = BuildOneTwoThree();
  DeleteList(&myList);

  assert(myList == NULL);
  return 0;
}
