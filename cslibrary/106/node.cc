#include <stdlib.h>

int main(){
  struct Node
  {
    int value;
    struct Node *next;
  };

  // Allocate the pointers
  Node *x;
  Node *y;
  Node *z;

  // Allocate the pointees
  x = new Node;
  y = new Node;
  z = new Node;

  // Put the numbers in the pointees
  x->value = 1;
  y->value = 2;
  z->value = 3;

  // Put the pointers in the pointees
  x->next = y;
  y->next = z;
  z->next = x;

  return 0;
}

