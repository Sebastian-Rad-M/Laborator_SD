#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> a(n), st;
    for (int i = 0; i < n; i++) cin >> a[i];
    a.push_back(0);
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && a[st.back()] >= a[i]) {
            long long h = a[st.back()];
            st.pop_back();
            long long w = st.empty() ? i : i - st.back() - 1;
            ans = max(ans, h * w);
        }
        st.push_back(i);
    }
    cout << ans;
    return 0;
}
