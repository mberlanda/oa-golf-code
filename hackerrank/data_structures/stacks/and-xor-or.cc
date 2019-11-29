#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int solve(int x, int y) {
  return ((x & y) ^ (x | y)) & (x ^ y);
}

/*
 * Complete the andXorOr function below.
 */
int andXorOr(vector<int> a)
{
  /*
     * Write your code here.
  */
  stack <int> s;
  int i;
  int asize = a.size();
  int m = -1; // max_value

  for(i = 0; i < asize; i++ ){
    while(!s.empty()){
      m = std::max(m, solve(a[i], s.top()));
      if (a[i] < s.top()) {
        s.pop();
      } else {
        break;
      }
    }
    s.push(a[i]);
  }
  return m;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int a_count;
  cin >> a_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split_string(a_temp_temp);

  vector<int> a(a_count);

  for (int a_itr = 0; a_itr < a_count; a_itr++)
  {
    int a_item = stoi(a_temp[a_itr]);

    a[a_itr] = a_item;
  }

  int result = andXorOr(a);

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
