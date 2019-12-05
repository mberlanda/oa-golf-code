#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */

struct node
{
  int data;
  int level;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data, int level){
  struct node *n = new node();
  n->data = data;
  n->level = level;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void swapNode (struct node* n, int k)
{
  if (n == NULL) return;
  if (n->level % k == 0)
  {
    struct node* tmp = n->left;
    n->left = n->right;
    n->right = tmp;
    // tmp = NULL;
  }
  swapNode(n->left, k);
  swapNode(n->right, k);
}

void traverse(struct node* n, vector<int> *v)
{
  if (n == NULL) return;
  traverse(n->left, v);
  (*v).push_back(n->data);
  traverse(n->right, v);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
  /*
    * Write your code here.
  */
  // Build tree
  queue<struct node*> q;
  struct node* root = newNode(1, 1);
  q.push(root);

  for (int i = 0; i < indexes.size(); i++)
  {
    struct node* cur = q.front();
    q.pop();
    // leftData
    if (indexes[i][0] != -1)
    {
      cur->left = newNode(indexes[i][0], cur->level+1);
      q.push(cur->left);
    }
    // rightData
    if (indexes[i][1] != -1)
    {
      cur->right = newNode(indexes[i][1], cur->level + 1);
      q.push(cur->right);
    }
  }

  vector<vector <int>> result;
  for (int j = 0; j < queries.size(); j++)
  {
    swapNode(root, queries[j]);
    vector<int> v;
    traverse(root, &v);
    result.push_back(v);
  }

  return result;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<int>> indexes(n);
  for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++)
  {
    indexes[indexes_row_itr].resize(2);

    for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++)
    {
      cin >> indexes[indexes_row_itr][indexes_column_itr];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int queries_count;
  cin >> queries_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> queries(queries_count);

  for (int queries_itr = 0; queries_itr < queries_count; queries_itr++)
  {
    int queries_item;
    cin >> queries_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    queries[queries_itr] = queries_item;
  }

  vector<vector<int>> result = swapNodes(indexes, queries);

  for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++)
  {
    for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++)
    {
      fout << result[result_row_itr][result_column_itr];

      if (result_column_itr != result[result_row_itr].size() - 1)
      {
        fout << " ";
      }
    }

    if (result_row_itr != result.size() - 1)
    {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}
