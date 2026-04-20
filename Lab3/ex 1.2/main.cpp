#include <vector>

class HashOpen {
    std::vector<int> t;
    std::vector<int> s;
    int len;
    int max;

    void resize() {
        int nmax = max;
        max *= 2;
        std::vector<int> nt(max, 0);
        std::vector<int> ns(max, 0);
        for (int i = 0; i < nmax; ++i) {
            if (s[i] == 1) {
                int p = t[i] % max;
                if (p < 0) p += max;
                while (ns[p] == 1) {
                    p = (p + 1) % max;
                }
                nt[p] = t[i];
                ns[p] = 1;
            }
        }
        t = nt;
        s = ns;
    }

public:
    HashOpen() {
        max = 16;
        len = 0;
        t.assign(max, 0);
        s.assign(max, 0);
    }

    void insert(int x) {
        if (exists(x)) return;
        if (len * 2 >= max) resize();
        int p = x % max;
        if (p < 0) p += max;
        while (s[p] == 1) {
            p = (p + 1) % max;
        }
        t[p] = x;
        s[p] = 1;
        len++;
    }

    void erase(int x) {
        int p = x % max;
        if (p < 0) p += max;
        while (s[p] != 0) {
            if (s[p] == 1 && t[p] == x) {
                s[p] = 2;
                len--;
                return;
            }
            p = (p + 1) % max;
        }
    }

    bool exists(int x) {
        int p = x % max;
        if (p < 0) p += max;
        while (s[p] != 0) {
            if (s[p] == 1 && t[p] == x) return true;
            p = (p + 1) % max;
        }
        return false;
    }
};
