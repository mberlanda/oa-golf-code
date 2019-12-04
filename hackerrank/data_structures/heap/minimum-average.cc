#include <bits/stdc++.h>

using namespace std;
/*

int minimumAverage(vector<vector<int>> customers)
{
     * Write your code here.


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
*/
long minimumAverage(vector<vector<int>> customers)
{
  // Sort by arrival time
  std::sort(customers.begin(), customers.end());
  auto compareCookTime = [](vector<int> lhs, vector<int> rhs) {
    return lhs[1] > rhs[1];
  };
  // CompareArrivalTime>> arrivalHeap;
  priority_queue<vector<int>, vector<vector<int>>, decltype(compareCookTime)> waitHeap(compareCookTime);

  cout << "Customers: ";
  for (int j = 0; j < customers.size(); j++){
    cout << customers[j][0] << " ";
  }
  cout << endl;

  int sz = customers.size();
  int i = 0;
  int count = 0;
  long total_time = customers[0][0];
  long avg = 0;
  long sum = 0;

  while(count != sz)
  {
    while (i < sz && customers[i][0] <= total_time)
    {
      waitHeap.push(customers[i]);
      i++;
    }
    if (!waitHeap.empty())
    {
      vector<int> n = waitHeap.top();
      cout << "tt " << total_time;
      cout << " w " << n[1];
      waitHeap.pop();
      total_time += n[1];
      cout << " ntt " << total_time;
      cout << " sum " << sum;
      cout << " avg " << total_time - n[0] << endl;
      // avg += (total_time - n[0])/sz;
      sum += (total_time - n[0]);
      count++;
    }
    else
    {
      total_time = customers[i][0];
    }
  }

  // return int(avg);
  cout << "sum: " << sum << " size: " << sz << " result: " << sum / sz;
  cout << " int: " << (int)sum / sz << endl;
  return sum / sz;
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

  long result = minimumAverage(customers);

  fout << result << "\n";

  fout.close();

  return 0;
}
