#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s = "()";
    int count = 0;
    for (int i = 0 ; i < s.size(); i++) {
        count += int(s[i]);
    }
    cout<<int(count);
    return 0;
}

// 71
// 81
// 286