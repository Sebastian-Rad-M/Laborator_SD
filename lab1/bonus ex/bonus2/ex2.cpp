#include <iostream>
#include <vector>
using namespace std;
int func(const vector<int>& v) {
    int p1 = v[0];
    int p2 = v[0];
    do {
        p1 = v[p1];           
        p2 = v[v[p2]];            
    } while (p1 != p2);

    p1 = v[0];
    while (p1 != p2) {
        p1 = v[p1];
        p2 = v[p2];
    }

    return p2; 
}

int main() {
    vector<int> v = {3, 1, 3, 4, 2};
    cout <<func(v);
    return 0;
}