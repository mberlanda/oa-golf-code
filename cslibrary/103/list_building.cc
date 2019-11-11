#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node *next;
};

void PrintValues(struct node *head)
{
  struct node *current = head;
  int count = 0;

  while (current != NULL)
  {
    count++;
    printf("%d ", current->data);
    current = current->next;
  }

  if (count > 0)
  {
    printf("\n");
  }
};

void Push(struct node*& headRef, int data)
{
  struct node *newNode = new struct node;

  newNode->data = data;
  newNode->next = headRef;
  headRef = newNode;
};

int main()
{
  struct node* empty = NULL;
  Push(empty, 13);
  Push(empty, 1);
  PrintValues(empty);

  return 0;
}
