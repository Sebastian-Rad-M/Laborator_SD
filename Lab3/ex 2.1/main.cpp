#include <vector>
#include <algorithm>

std::vector<int> func(std::vector<int> a, int s) {
    int n = a.size();
    std::sort(a.begin(), a.end());
    std::vector<int> r;
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            long long sum = (long long)a[i] + a[j] + a[k];
            if (sum == s) {
                r.push_back(i);
                r.push_back(j);
                r.push_back(k);
                return r;
            } else if (sum < s) j++; 
                  else k--;
        }
    }
    return r;
}
