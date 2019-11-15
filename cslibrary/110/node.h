#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};
typedef struct node* Node;

static int lookup(Node node, int target)
{
  // when node is empty
  if (node == NULL)
    return false;
  // when target is matched
  if (target == node->data)
    return true;
  // when target is greater
  if (target > node->data)
    return lookup(node->right, target);
  // when target is smaller
  return lookup(node->left, target);
}

Node NewNode(int data)
{
  Node node = malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

Node insert(Node node, int data)
{
  if (node == NULL)
    return NewNode(data);
  if (data <= node->data)
    node->left = insert(node->left, data);
  else
    node->right = insert(node->right, data);

  return node;
}
