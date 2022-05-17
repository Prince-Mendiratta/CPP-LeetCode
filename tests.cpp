#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int numRows = 35555;
  vector<vector<int>> out(numRows);
  out[0] = {1};
  for (int i = 1; i < numRows; i++) {
    vector<int> temp(i + 1, 1);
    for (int j = 1; j < i; j++) {
      temp[j] = out[i - 1][j - 1] + out[i - 1][j];
    }
    out[i] = temp;
  }
  cout<<"[";
  for (int i = 0; i < numRows; i++) {
    cout<<"[";
    for (int j = 0; j < out[i].size(); j++) {
        cout<<out[i][j]<<"";
    }
    cout<<"], ";
  }
  cout<<"]";
  return 0;
}

// 71
// 81
// 286