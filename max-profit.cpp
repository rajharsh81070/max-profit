#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int totalTime;
  cin >> totalTime;
  vector<pair<int, int>> Arr(3);
  Arr[0] = {5, 1500};
  Arr[1] = {4, 1000};
  Arr[2] = {10, 3000};
  int maxMoneyEarned = 0;
  vector<int> earned(3);
  vector<vector<int>> count(3, vector<int>(4, 0));
  for(int i=0; i<3; i++) {
    int maxOfCurr = 0;
    int timeToMake = Arr[i].first;
    int earning = Arr[i].second;
    int noOfBuildingsForCurr = totalTime/timeToMake;
    if(noOfBuildingsForCurr < 1) {
      earned[i] = 0;
      continue;
    }
    for(int j=1; j<noOfBuildingsForCurr; j++) {
      maxOfCurr += timeToMake * j * earning;
    }
    int remainingTime = totalTime % timeToMake;
    maxOfCurr += remainingTime * noOfBuildingsForCurr * earning;
    count[i][i] += noOfBuildingsForCurr;
    if(remainingTime >= 5) {
      if(remainingTime == 5) {
        maxOfCurr += 1000;
        count[i][1]++;
      } else {
        maxOfCurr += (remainingTime - 5)*1500;
        count[i][0]++;
      }
    }
    count[i][3] = maxOfCurr;
    maxMoneyEarned = max(maxMoneyEarned, maxOfCurr);
  }
  cout << "Earnings : " << maxMoneyEarned << endl;
  for(int i=0; i<3; i++) {
    if(maxMoneyEarned == count[i][3]) {
      cout << "T : " << count[i][0] << ", P : " << count[i][1] << ", C : " << count[i][2] << endl;  
    }
  }
  return 0;
}
