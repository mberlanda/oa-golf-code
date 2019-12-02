#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the poisonousPlants function below.
// https://www.hackerrank.com/challenges/poisonous-plants/problem
// https://www.hackerrank.com/challenges/poisonous-plants/forum/comments/132237
int poisonousPlants(vector<int> p)
{
  int mi, ma, i;
  int n = p.size();
  int* days = new int[n];
  stack <int> s;

  s.push(0);
  mi = p[0];
  ma = 0;

  for (i=1; i<n; i++)
  {
    days[i] = (p[i] > p[i - 1]) ? 1 : 0;
    mi = std::min(mi, p[i]);

    while(!s.empty() && p[s.top()] >= p[i]){
      if (p[i] > mi) {
        days[i] = std::max(days[i], days[s.top()] + 1);
      }
      s.pop();
    }
    ma = std::max(ma, days[i]);
    s.push(i);
  }
  return ma;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string p_temp_temp;
  getline(cin, p_temp_temp);

  vector<string> p_temp = split_string(p_temp_temp);

  vector<int> p(n);

  for (int i = 0; i < n; i++)
  {
    int p_item = stoi(p_temp[i]);

    p[i] = p_item;
  }

  int result = poisonousPlants(p);

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
