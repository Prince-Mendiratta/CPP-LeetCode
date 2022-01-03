#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int> bb = {1,9};
    vector<int>::iterator ptr = bb.end() - 1;
    // *ptr = *ptr + 1;
    for (int i = 0; i < bb.size(); i++) {
        cout<<bb[i]<<" ";
    }
    cout<<endl<<*(--ptr);
    cout<<*ptr;
    return 0;
}