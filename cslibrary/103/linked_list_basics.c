#include "node.h"

void ArrayTest()
{
  int scores[100];

  scores[0] = 1;
  scores[1] = 2;
  scores[2] = 3;
}

// Excercise
struct node* BuildOneTwoThreeBis()
{
  struct node* head;
  struct node* second;
  struct node* third;

  head = malloc(sizeof(struct node));
  second = malloc(sizeof(struct node));
  third = malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;

  return head;
};

int Length(struct node* head)
{
  struct node *current = head;
  int count = 0;

  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

int main()
{
  struct node *head = BuildOneTwoThreeBis();
  printf("Length of head: %d\n", Length(head));
  printf("Length of NULL: %d\n", Length(NULL));
  return 0;
}
