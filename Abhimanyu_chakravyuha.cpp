#include <bits/stdc++.h>

using namespace std;

bool solveChakravyuha(int p, int a, int b, vector<int> &k)
{
  int n = 11;
  // n = number of vyuh = 1;
  // a no of time abhimanyu can skip;
  // b no of time abhimany can regebrate or recharge;
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(a + 1, vector<int>(b + 1, -1)));
  dp[0][a][b] = p;
  // used dp and check all possiblities
  for (int i = 1; i <= n; i++) // runs 11 times
  {
    for (int j = 0; j <= a; j++) // runs a times
    {
      for (int l = 0; l <= b; l++) // runs b times
      {
        if (dp[i - 1][j][l] != -1)
        {
          if (dp[i - 1][j][l] >= k[i - 1]) // if he can fight
          {
            dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l] - k[i - 1]);
          }
          if (j > 0)
          {
            dp[i][j - 1][l] = max(dp[i][j - 1][l], dp[i - 1][j][l]); // he can skip
          }
          if (l > 0)
          {
            dp[i][j][l - 1] = max(dp[i][j][l - 1], p - k[i - 1]); // recharge
          }
        }
        if (i == 4 && dp[i - 1][j][l] != -1 && dp[i - 1][j][l] >= k[2] / 2) // special cases for k3 and k8
        {
          dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l] - k[2] / 2);
        }
        if (i == 8 && dp[i - 1][j][l] != -1 && dp[i - 1][j][l] >= k[6] / 2) // special cases for k3 and k8
        {
          dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l] - k[6] / 2);
        }
      }
    }
  }

  for (int j = 0; j <= a; j++)
  {
    for (int l = 0; l <= b; l++)
    {
      if (dp[n][j][l] >= 0) // after crossing all the vyuha if he has power >0 that means  he successfully pass the vyuha
      {
        return true;
      }
    }
  }
  return false;
}

// Function to run a single test case and compare the result with the expected outcome
void runSingleTestCase(int p, int a, int b, vector<int> &k, bool expected)
{
  bool result = solveChakravyuha(p, a, b, k);
  if (result == true)
  {
    cout << "Abhimanyu can pass the chakravyuha" << endl;
  }
  else
  {
    cout << "Abhimanyu can't make it" << endl;
  }
}

int main()
{

  //  some manual test cases
  vector<int> k1 = {30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130};
  runSingleTestCase(100, 0, 0, k1, false); // Expected: Failure

  vector<int> k3 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
  runSingleTestCase(0, 5, 5, k3, false); // Expected: false

  vector<int> k2 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
  runSingleTestCase(100, 5, 5, k2, true); // Expected: Success

  vector<int> k4 = {0, 10, 2, 3, 9, 5, 6, 7, 8, 4, 1};
  runSingleTestCase(10, 5, 5, k4, true); // success

  vector<int> k5 = {0, 10, 2, 3, 9, 5, 6, 7, 8, 4, 7};
  runSingleTestCase(5, 3, 2, k5, false); // failure

  vector<int> k6 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  runSingleTestCase(500, 11, 11, k6, true); // success

  vector<int> k7 = {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200};
  runSingleTestCase(1, 0, 0, k7, false); // failure
  vector<int> k8 = {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200};
  runSingleTestCase(100000, 0, 0, k8, true); // success

  return 0;
}
