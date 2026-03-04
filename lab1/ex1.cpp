#include <iostream>
#include <vector>

using namespace std;
   
vector<int> sp;//sume partiale 

void gen_sp(vector<int>& a) {
    int n = a.size();
    sp.assign(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        sp[i + 1] = sp[i] + a[i];
        }
}

int sumsecv(int l, int r) {
    return sp[r + 1] - sp[l];
    }

int main() {
    
    
    vector<int> a = {2, 4, -1, 5, 8, 3};
    gen_sp(a);

    cout << "Sum [0, 2]: " << sumsecv(0, 2) << endl; 
    cout << "Sum [2, 5]: " << sumsecv(2, 5) << endl; 

    return 0;
}
