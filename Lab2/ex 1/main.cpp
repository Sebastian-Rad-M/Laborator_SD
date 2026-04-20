#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> a(n), st;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        cout << (st.empty() ? -1 : st.back()) << " ";
        st.push_back(i);
    }
    return 0;
}
