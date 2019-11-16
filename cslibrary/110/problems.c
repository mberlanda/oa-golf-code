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

// 3. maxDepth()
int max(int a, int b)
{
  if (a > b) return a;
  return b;
}

int maxDepth(Node node)
{
  if (node == NULL) return 0;
  int lDepth, rDepth;
  lDepth = maxDepth(node->left);
  rDepth = maxDepth(node->right);

  return max(lDepth, rDepth) + 1;
}

void testMaxDepth()
{
  assert(maxDepth(NULL) == 0);
  Node n = build123a();
  assert(maxDepth(n) == 2);
  insert(n, 5);
  assert(maxDepth(n) == 3);
}

/*
  4. minValue()
  Given a non-empty binary search tree,
  return the minimum data value found in that tree.
*/

int minValue(Node node){
  assert(node != NULL);
  Node current = node;

  while(current->left != NULL){
    current = current->left;
  }

  return current->data;
}

int minValueRec(Node node)
{
  if (node->left != NULL)
    return minValueRec(node->left);
  return node->data;
}

void testMinValue()
{
  Node n = build123a();
  assert(minValue(n) == 1);
  assert(minValueRec(n) == 1);
  insert(n, 5);
  assert(minValue(n) == 1);
  assert(minValueRec(n) == 1);
  insert(n, -3);
  insert(n, 0);
  assert(minValue(n) == -3);
  assert(minValueRec(n) == -3);
}

int main()
{
  testSize();
  testMaxDepth();
  testMinValue();
  return 0;
}
