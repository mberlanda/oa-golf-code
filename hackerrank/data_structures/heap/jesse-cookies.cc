#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/jesse-and-cookies/problem

vector<string> split_string(string);

/*
 * Complete the cookies function below.
 */
int cookies(int k, priority_queue<int, vector<int>, greater<int>> pq)
{
  /*
     * Write your code here.
     */
  int count = 0;

  while(true)
  {
    int x = pq.top();
    if (x < k)
    {
      pq.pop();
      if (pq.empty()){
        return -1;
      }
      int y = 2 * pq.top();
      pq.pop();
      pq.push(x+y);
      count++;
    }
    else
    {
      return count;
    }
  }
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string nk_temp;
  getline(cin, nk_temp);

  vector<string> nk = split_string(nk_temp);

  int n = stoi(nk[0]);

  int k = stoi(nk[1]);

  string A_temp_temp;
  getline(cin, A_temp_temp);

  vector<string> A_temp = split_string(A_temp_temp);

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int A_itr = 0; A_itr < n; A_itr++)
  {
    int A_item = stoi(A_temp[A_itr]);

    pq.push(A_item);
  }

  int result = cookies(k, pq);

  fout << result << "\n";

  fout.close();

  return 0;
}

vector<string> split_string(string input_string)
{
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
    return x == y and x == ' ';
  });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ')
  {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos)
  {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
