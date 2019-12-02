#include <bits/stdc++.h>

using namespace std;
// https://www.hackerrank.com/challenges/tree-inorder-traversal/problem?h_r=next-challenge&h_v=zen

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution
{
public:
  Node *insert(Node *root, int data)
  {
    if (root == NULL)
    {
      return new Node(data);
    }
    else
    {
      Node *cur;
      if (data <= root->data)
      {
        cur = insert(root->left, data);
        root->left = cur;
      }
      else
      {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }


  void inOrder(Node *root)
  {
    if (root == NULL)
      return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  }

}; //End of Solution

int main()
{

  Solution myTree;
  Node *root = NULL;

  int t;
  int data;

  std::cin >> t;

  while (t-- > 0)
  {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.inOrder(root);
  return 0;
}
