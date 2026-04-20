#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) cin >> a[i][j];
    
    vector<int> h(m, 0);
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || a[i][j] != a[i-1][j]) h[j]++;
            else h[j] = 1;
        }
        int l = 0;
        while (l < m) {
            int r = l;
            while (r + 1 < m && a[i][r] != a[i][r+1]) r++;
            vector<int> st;
            for (int k = l; k <= r + 1; k++) {
                int cur = (k <= r) ? h[k] : 0;
                while (!st.empty() && h[st.back()] >= cur) {
                    int ht = h[st.back()];
                    st.pop_back();
                    int w = st.empty() ? (k - l) : (k - st.back() - 1);
                    ans = max(ans, ht * w);
                }
                if (k <= r) st.push_back(k);
            }
            l = r + 1;
        }
    }
    cout << ans;
    return 0;
}
