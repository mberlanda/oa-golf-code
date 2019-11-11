#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node *next;
};

// printValues prints the list of elements
void printValues(struct node* head);
void printValues(struct node* head)
{
  struct node* current = head;

  for (current = head; current != NULL; current = current->next)
  {
    printf("%d ", current->data);
  }
  printf("\n");
}

void Push(struct node** headRef, int data);
void Push(struct node** headRef, int data)
{
  struct node* newNode = malloc(sizeof(struct node));

  newNode->data = data;
  newNode->next = *headRef;
  *headRef = newNode;
}

struct node* AddAtHead();
struct node* AddAtHead()
{
  struct node* head = NULL;
  int i;

  for (i=1; i<6; i++)
  {
    Push(&head, i);
  }

  printf("AddAtHead:\n");
  printValues(head);
  return head;
}

struct node* BuildWithSpecialCase();
struct node* BuildWithSpecialCase()
{
  struct node* head = NULL;
  struct node* tail;
  int i;

  Push(&head, 1);
  tail = head;

  for (i = 2; i < 6; i++)
  {
    Push(&(tail->next), i);
    tail = tail->next;
  }

  printf("BuildWithSpecialCase:\n");
  printValues(head);
  return(head);
}

struct node* BuildWithDummyNode();
struct node* BuildWithDummyNode()
{
  struct node dummy;
  struct node* tail = &dummy;
  int i;

  dummy.next = NULL;

  for (i = 1; i < 6; i++)
  {
    Push(&(tail->next), i);
    tail = tail->next;
  }

  printf("BuildWithDummyNode:\n");
  printValues(dummy.next);
  return (dummy.next);
}

struct node* BuildWithLocalRef();
struct node* BuildWithLocalRef()
{
  struct node* head = NULL;
  struct node** lastPtrRef = &head;
  int i;

  for (i = 1; i < 6; i++)
  {
    Push(lastPtrRef, i);
    lastPtrRef = &((*lastPtrRef)->next);
  };

  printf("BuildWithLocalRef:\n");
  printValues(head);
  return (head);
}

int main()
{
  AddAtHead();
  BuildWithSpecialCase();
  BuildWithDummyNode();
  BuildWithLocalRef();
  return 0;
}
