#include <vector>
#include <list>

class HashChain {
    std::vector<std::list<int> > t;
    int len;
    int max;

    void resize() {
        int nmax = max;
        max *= 2;
        std::vector<std::list<int> > nt(max);
        for (int i = 0; i < namx; ++i) {
            for (std::list<int>::iterator it = t[i].begin(); it != t[i].end(); ++it) {
                int nv = *it;
                int p = nv % max;
                if (p < 0) p += max;
                nt[p].push_back(nv);
            }
        }
        t = nt;
    }

public:
    HashChain() {
        max = 16;
        len = 0;
        t.resize(max);
    }

    void insert(int x) {
        if (exists(x)) return;
        if (len >= max) resize();
        int p = x % max;
        if (p < 0) p += max;
        t[p].push_back(x);
        len++;
    }

    void erase(int x) {
        int p = x % max;
        if (p < 0) p += max;
        for (std::list<int>::iterator it = t[p].begin(); it != t[p].end(); ++it) {
            if (*it == x) {
                t[p].erase(it);
                len--;
                return;
            }
        }
    }

    bool exists(int x) {
        int p = x % max;
        if (p < 0) p +=max;
        for (std::list<int>::iterator it = t[p].begin(); it != t[p].end(); ++it) {
            if (*it == x) return true;
        }
        return false;
    }
};
