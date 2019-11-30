#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/simple-text-editor/problem

int main()
{
  int N;
  int size;
  // stack <string> st;
  stack <int> actions;
  stack <string> addA;
  stack <int> delA;
  string result;

  cin >> N;

  while(N--) {
    int n;
    cin >> n;
    if (n==1)
    {
      string str;
      cin >> str;
      // st.push(result);
      actions.push(2);
      int l = str.length();
      delA.push(l);
      size += l;
      result += str;
    }
    else if (n==2)
    {
      int k;
      cin >> k;
      string p = result.substr(size-k, size);
      actions.push(1);
      addA.push(p);
      while(k--){
        result.pop_back();
        size--;
      }
    }
    else if (n == 3)
    {
      int k;
      cin >> k;
      cout << result[k-1] << endl;
    }
    else if (n == 4)
    {
      int a = actions.top();
      if (a == 1)
      {
        string str = addA.top();
        result += str;
        addA.pop();
        size += str.length();
      }
      else if (a == 2)
      {
        int k = delA.top();
        while(k--){
          result.pop_back();
          size--;
        }
        delA.pop();
      }
      actions.pop();
    }
  }

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  return 0;
}
