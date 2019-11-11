#include "node.h"

void Push(struct node** headRef, int data)
{
  struct node *newNode = malloc(sizeof(struct node));

  newNode->data = data;
  newNode->next = *headRef;
  *headRef = newNode;
};

int main()
{
  struct node* head = BuildOneTwoThree();
  PrintValues(head);

  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = 0;
  newNode->next = head;
  PrintValues(newNode);

  struct node *empty = NULL;
  Push(&empty, 13);
  Push(&empty, 1);
  PrintValues(empty);

  return 0;
}
