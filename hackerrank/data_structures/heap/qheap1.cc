#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  priority_queue<int, vector<int>, greater<int>> minheap;
  std::vector <int> heap;
  std::make_heap(begin(heap), end(heap));
  int N;
  cin >> N;

  while(N--)
  {
    int n;
    cin >> n;
    if (n==3)
    {
      cout << minheap.top() << endl;
    }
    else
    {
      int v;
      cin >> v;

      if (n==1)
      {
        minheap.push(v);
      }
      else if (n==2)
      {
        if (minheap.top() == v)
        {
          minheap.pop();
        }
      }
    }
  }
  return 0;
}
