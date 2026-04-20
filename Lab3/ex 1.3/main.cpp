#include <string>
#include <vector>

long long getHash(std::string str) {
    long long h = 0;
    long long p = 31;
    long long m = 1000000009;
    long long pp = 1;
    for (int i = 0; i < str.length(); i++) {
        h = (h + (str[i] - 'a' + 1) * pp) % m;
        pp = (pp * p) % m;
    }
    return h;
}

std::vector<long long> hashAll(std::vector<std::string> v) {
    int n = v.size();
    std::vector<long long> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = getHash(v[i]);
    }
    return r;
}
