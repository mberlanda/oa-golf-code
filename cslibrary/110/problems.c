#include "node.h"
#include <assert.h>
#include <stdio.h>
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
  Node root = insert(NULL, 2);
  root = insert(root, 1);
  root = insert(root, 3);
  return root;
}

// 2. size()
int size(Node node){
  if (node == NULL) return 0;
  return size(node->left) + 1 + size(node->right);
}

void testSize()
{
  assert(size(build123a()) == 3);
  assert(size(build123b()) == 3);
  assert(size(build123c()) == 3);
}

int main()
{
  testSize();
  return 0;
}
