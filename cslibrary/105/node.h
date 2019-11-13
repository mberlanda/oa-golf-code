#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node* next;
};

struct node *BuildOneTwoThree();
struct node* BuildOneTwoThree()
{
  struct node* head = NULL;
  struct node* second = NULL;
  struct node* third = NULL;

  head = malloc(sizeof(struct node));
  second = malloc(sizeof(struct node));
  third = malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  return head;
}

void PrintValues(struct node *head);
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
}

void Push(struct node **headRef, int data);
void Push(struct node **headRef, int data)
{
  struct node *newNode = malloc(sizeof(struct node));

  newNode->data = data;
  newNode->next = *headRef;
  *headRef = newNode;
}
