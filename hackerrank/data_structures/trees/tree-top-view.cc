#include <bits/stdc++.h>

using namespace std;
// https://www.hackerrank.com/challenges/tree-top-view/problem

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

  /*
  void leftView(Node *root)
  {
    if(root == NULL) return;
    if (root->left == NULL)
      cout << root->data << " ";
      return;
    leftView(root->left);
  }

  void rightView(Node *root)
  {
    if (root == NULL)
      return;
    cout << root->data << " ";
    rightView(root->right);
  }

  void subView(Node *root, int hd, map<int, int> *m){
    if (root == NULL){
      return;
    }
    if ((*m).count(hd) == 0){
      (*m)[hd] = root->data;
    }
    subView(root->left, hd-1, m);
    subView(root->right, hd + 1, m);
  }
  */

  typedef pair<Node*, int> inode;

  void subQView(queue<inode> q, map<int, int> *m)
  {
    if (q.empty())
    {
      return;
    }
    inode el = q.front();
    Node* root = el.first;
    int hd = el.second;

    q.pop();
    if ((*m).count(hd) == 0)
    {
      (*m)[hd] = root->data;
    }
    if (root->left)
    {
      q.push(make_pair(root->left, hd-1));
    }
    if (root->right)
    {
      q.push(make_pair(root->right, hd+1));
    }
    subQView(q, m);
  }

  void topView(Node *root)
  {
    if (root == NULL)
      return;
    /*
    leftView(root->left);
    cout << root->data << " ";
    rightView(root->right);
    */
    queue<inode> q;
    map <int, int> m;
    int hd = 0;
    q.push(make_pair(root, 0));
    subQView(q, &m);
    for (auto i = m.begin(); i != m.end(); i++)
    {
      cout << i->second << " ";
    }
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

  myTree.topView(root);
  return 0;
}
