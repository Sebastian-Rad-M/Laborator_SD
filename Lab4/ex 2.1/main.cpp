#include <vector>
#include <algorithm>
using namespace std;

struct MinHeap {
    vector<int> heapArray;
    
    void siftUp(int idx) {
        while (idx > 0 && heapArray[idx] < heapArray[(idx - 1) / 2]) {
            swap(heapArray[idx], heapArray[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
    
    void siftDown(int idx) {
        int size = heapArray.size();
        while (2 * idx + 1 < size) {
            int childIdx = 2 * idx + 1;
            if (childIdx + 1 < size && heapArray[childIdx + 1] < heapArray[childIdx]) {
                childIdx++;
            }
            if (heapArray[idx] <= heapArray[childIdx]) break;
            swap(heapArray[idx], heapArray[childIdx]);
            idx = childIdx;
        }
    }
    
    void insertVal(int x) {
        heapArray.push_back(x);
        siftUp(heapArray.size() - 1);
    }
    
    int getTop() {
        return heapArray[0];
    }
    
    void popTop() {
        heapArray[0] = heapArray.back();
        heapArray.pop_back();
        if (!heapArray.empty()) siftDown(0);
    }
};
