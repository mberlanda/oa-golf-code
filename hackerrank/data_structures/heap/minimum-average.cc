#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the minimumAverage function below.
struct CompareArrivalTime
{
  // 0 indexed value is cooked time
  bool operator()(vector<int> a, vector<int> b)
  {
    return a[0] < b[0];
  }
};

bool compareArrivalTime(vector<int> a, vector<int> b) {
  return a[0] < b[0];
}


struct CompareCookTime
{
  // 1 indexed value is cooked time
  bool operator()(vector<int>& a, vector<int>& b) {
    return a[1] > b[1];
  }
};

int minimumAverage(vector<vector<int>> customers)
{
  /*
     * Write your code here.

  auto compareArrivalTime = [](vector<int> lhs, vector<int> rhs) {
    return lhs[0] < rhs[0];
  };
  auto compareCookTime = [](vector<int> lhs, vector<int> rhs) {
    return lhs[1] > rhs[1];
  };
  priority_queue < vector<int>, vector<vector<int>>, decltype(compareArrivalTime) > arrivalHeap(compareArrivalTime);
  // CompareArrivalTime>> arrivalHeap;
  priority_queue<vector<int>, vector<vector<int>>, decltype(compareCookTime)> waitHeap(compareCookTime);

  int n = customers.size();

  for (int i = 0; i < n; i++){
    arrivalHeap.push(customers[i]);
  }

  int count = 0;
  int total_time = 0;
  int sum = 0;

  while(count != n){
    while(!arrivalHeap.empty() && arrivalHeap.top()[0] <= total_time)
    {
      waitHeap.push(arrivalHeap.top());
      arrivalHeap.pop();
    }
    if (!waitHeap.empty())
    {
      vector<int> n = waitHeap.top();
      waitHeap.pop();
      total_time += n[1];
      sum += total_time - n[0];
      count++;
    }
    else if (!arrivalHeap.empty())
    {
      vector<int> n = arrivalHeap.top();
      arrivalHeap.pop();
      total_time += n[1];
      count++;
    }
  }
  return sum / count;
}

*/

int minimumAverage(vector<vector<int>> customers)
{
  /*
     * Write your code here.
  */

  auto compareArrivalTime = [](vector<int> lhs, vector<int> rhs) {
    return lhs[0] > rhs[0];
  };
  auto compareCookTime = [](vector<int> lhs, vector<int> rhs) {
    return lhs[1] > rhs[1];
  };
  priority_queue<vector<int>, vector<vector<int>>, decltype(compareArrivalTime)> arrivalHeap(compareArrivalTime);
  // CompareArrivalTime>> arrivalHeap;
  priority_queue<vector<int>, vector<vector<int>>, decltype(compareCookTime)> waitHeap(compareCookTime);

  int n = customers.size();

  for (int i = 0; i < n; i++)
  {
    arrivalHeap.push(customers[i]);
  }

  int count = 0;
  int total_time = 0;
  int sum = 0;

  while (count != n)
  {
    while (!arrivalHeap.empty() && arrivalHeap.top()[0] <= total_time)
    {
      vector<int> n = arrivalHeap.top();
      cout << "Debug t " << n[0] << endl;
      waitHeap.push(arrivalHeap.top());
      arrivalHeap.pop();
    }
    if (!waitHeap.empty())
    {
      vector<int> n = waitHeap.top();
      cout << "Debug w " << n[1] << endl;
      waitHeap.pop();
      total_time += n[1];
      sum += total_time - n[0];
      count++;
    }
    else if (!arrivalHeap.empty())
    {
      vector<int> n = arrivalHeap.top();
      arrivalHeap.pop();
      total_time += n[1];
      count++;
    }
  }
  return sum / count;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<int>> customers(n);
  for (int customers_row_itr = 0; customers_row_itr < n; customers_row_itr++)
  {
    customers[customers_row_itr].resize(2);

    for (int customers_column_itr = 0; customers_column_itr < 2; customers_column_itr++)
    {
      cin >> customers[customers_row_itr][customers_column_itr];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int result = minimumAverage(customers);

  fout << result << "\n";

  fout.close();

  return 0;
}
