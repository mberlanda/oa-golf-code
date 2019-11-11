#include "node.h"

void Push(struct node **headRef, int data);
void Push(struct node **headRef, int data)
{
  struct node* newNode = malloc(sizeof(struct node));

  newNode->data = data;
  newNode->next = *headRef;
  *headRef = newNode;
}

struct node* AppendNode(struct node** headRef, int num);
struct node* AppendNode(struct node **headRef, int num)
{
  struct node* current = *headRef;
  struct node* newNode;

  newNode = malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = NULL;

  if (current == NULL)
  {
    *headRef = newNode;
  } else
  {
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
}

struct node* AppendNodeP(struct node **headRef, int num);
struct node* AppendNodeP(struct node **headRef, int num)
{
  struct node* current = *headRef;

  if (current == NULL) {
    Push(headRef, num);
  } else
  {
    while (current->next != NULL)
    {
      current = current->next;
    }
    Push(&(current->next), num);
  }
}

struct node* CopyList(struct node* head);
struct node* CopyList(struct node* head)
{
  struct node* current = head;
  struct node* newList = NULL;
  struct node* tail = NULL;

  while (current != NULL)
  {
    if (newList == NULL)
    {
      newList = malloc(sizeof(struct node));
      newList->data = current->data;
      newList->next = NULL;
      tail = newList;
    }
    else
    {
      tail->next = malloc(sizeof(struct node));
      tail = tail->next;
      tail->data = current->data;
      tail->next = NULL;
    }
    current = current->next;
  }

  return(newList);
}

struct node* CopyListP(struct node* head);
struct node* CopyListP(struct node* head)
{
  struct node *current = head;
  struct node *newList = NULL;
  struct node *tail = NULL;

  while (current != NULL)
  {
    if (newList == NULL)
    {
      Push(&newList, current->data);
      tail = newList;
    }
    else
    {
      Push(&(tail->next), current->data);
    }
    current = current->next;
  }

  return (newList);
}

struct node* CopyListDummyNode(struct node* head);
struct node* CopyListDummyNode(struct node* head)
{
  struct node* current = head;
  struct node* tail;
  struct node dummy;

  dummy.next = NULL;
  tail = &dummy;

  while (current != NULL)
  {
    Push(&(tail->next), current->data);
    tail = tail->next;
    current = current->next;
  }
  return(dummy.next);
}

struct node* CopyListLastRef(struct node* head);
struct node* CopyListLastRef(struct node* head)
{
  struct node* current = head;
  struct node* newList = NULL;
  struct node** lastPtr;

  lastPtr = &newList;

  while (current != NULL)
  {
    Push(lastPtr, current->data);
    lastPtr = &((*lastPtr)->next);
    current = current->next;
  }

  return(newList);
}

struct node* CopyListRecur(struct node* head);
struct node* CopyListRecur(struct node* head)
{
  if (head == NULL) return NULL;
  else
  {
    struct node* current = head;
    struct node* newList = malloc(sizeof(struct node));

    newList->data = current->data;
    newList->next = CopyListRecur(current->next);
    return(newList);
  }
}
