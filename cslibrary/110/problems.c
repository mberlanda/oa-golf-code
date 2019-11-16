#include "node.h"

/*
1. build123()
      2
    /   \
   1     3

  a: by calling newNode() three times,
     and using three pointer variables
  b: by calling newNode() three times,
     and using only one pointer variable
  c: by calling insert() three times passing
     it the root pointer to build up the tree
*/
Node build123a() {
  Node root = NewNode(2);
  Node l = NewNode(1);
  Node r = NewNode(3);

  root->left = l;
  root->right = r;

  return root;
}

Node build123b()
{
  Node root = NewNode(2);
  root->left = NewNode(1);
  root->right = NewNode(3);

  return root;
}

Node build123c()
{
  Node root = NULL;
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
}

int main()
{
  return 0;
}
