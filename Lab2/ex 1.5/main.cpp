#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s; 
    int k;
    cin >> s >> k;
    vector<pair<char, int>> st;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!st.empty() && st.back().first == c) {
            st.back().second++;
            if (st.back().second == k) st.pop_back();
        } else {
            st.push_back({c, 1});
        }
    }
    string ans = "";
    for (int i = 0; i < st.size(); i++) {
        ans.append(st[i].second, st[i].first);
    }
    cout << ans;
    return 0;
}
