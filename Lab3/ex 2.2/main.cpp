#include <vector>
#include <unordered_map>

long long atMost(std::vector<int> a, int k) {
    int n = a.size();
    long long r = 0;
    int j = 0;
    int c = 0;
    std::unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        while (j < n) {
            if (m[a[j]] == 0 && c == k) break;
            if (m[a[j]] == 0) c++;
            m[a[j]]++;
            j++;
        }
        r += (j - i);
        m[a[i]]--;
        if (m[a[i]] == 0) {c--;
    }
    return r;
}

long long solveSecventa(std::vector<int> a, int l, int u) {
    return atMost(a, u) - atMost(a, l - 1);
}
