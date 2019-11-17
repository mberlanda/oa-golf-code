#include "node.h"
#include <assert.h>
#include <stdio.h>

#define MAX_TREE_SIZE 1000
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

/*
  5. printTree()
    The tree...
        4
       / \
      2   5
     / \
    1   3
    Produces the output "1 2 3 4 5"
*/

void printTree(Node node){
  if (node == NULL) return;

  printTree(node->left);
  printf("%d ", node->data);
  printTree(node->right);
}

/*
  6. printPostorder()
    The tree...
        4
       / \
      2   5
     / \
    1   3
    Produces the output "1 3 2 5 4"
*/

void printPostorder(Node node)
{
  if (node == NULL)
    return;

  printPostorder(node->left);
  printPostorder(node->right);
  printf("%d ", node->data);
}

// 7. hasPathSum()
int hasPathSum(Node node, int sum){
  if (node == NULL) return sum == 0;

  int subSum = sum - node->data;
  return hasPathSum(node->left, subSum) || hasPathSum(node->right, subSum);
};

void testHasPathSum(){
  assert(hasPathSum(NULL, 0) == 1);
  assert(hasPathSum(NULL, 1) == 0);
  Node n = build123a();
  assert(hasPathSum(n, 3) == 1);
  assert(hasPathSum(n, 5) == 1);
  assert(hasPathSum(n, 4) == 0);
}

// 8. printPaths()
void printArray(int array[], int len)
{
  int i;
  for(i = 0; i < len; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void printPathsRecur(Node node, int path[], int pathLen)
{
  if (node == NULL)
    return;
  // printf("len: %d, data: %d\n", pathLen, node->data);
  path[pathLen] = node->data;
  pathLen++;

  if (node->left == NULL && node->right == NULL){
    printArray(path, pathLen);
  } else {
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}

void printPaths(Node node){
  int path[MAX_TREE_SIZE];
  printPathsRecur(node, path, 0);
}

void testPrints()
{
  Node n = NewNode(4);
  n->left = build123a();
  n->right = NewNode(5);
  printTree(n);
  printf("\n");
  printPostorder(n);
  printf("\n");
  printPaths(n);
}

int main()
{
  testSize();
  testMaxDepth();
  testMinValue();
  testPrints();
  testHasPathSum();
  return 0;
}
