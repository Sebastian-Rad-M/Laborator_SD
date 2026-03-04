#include <iostream>
#include <vector>
#include <cstdlib> //rand
using namespace std;

int part(vector<int>& a, int st, int dr) {
    int pivot = st + rand() % (dr- st + 1);
    int pivotVal = a[pivot];
    swap(a[pivot], a[dr]);
    
    int nr = st;
    for (int i = st; i < dr; i++) {
        if (a[i] < pivot) {
            swap(a[i], a[nr]);
            nr++;
        }
    }
    swap(a[nr], a[dr]);
    
    return nr;
}

int quickSelect(vector<int>& a, int st, int dr, int k) {
    if (st == dr) {
        return a[st];
    }

    int pivot = part(a, st, dr);

    if (k== pivot) {
        return a[k]; 
    } else if (k < pivot) {
        return quickSelect(a, st, pivot - 1, k); 
    } else {
        return quickSelect(a, pivot + 1, dr, k); 
    }
}

int findKthSmallest(vector<int> a, int k) {
   
    return quickSelect(a, 0, a.size() - 1, k - 1); 
}           

int main() {
    vector<int> a = {12, 3, 5, 7, 4, 19, 26};
    int k = 3; 
    cout << findKthSmallest(a, k) << endl;


    return 0;
}