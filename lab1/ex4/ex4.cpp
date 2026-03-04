#include <iostream>
#include <vector>
#include <cstdlib> //rand
using namespace std;

int part(vector<int>& a, int st, int dr) {
    int pivotIndex = st + rand() % (dr- st + 1);
    int pivotValue = a[pivotIndex];
    swap(a[pivotIndex], a[dr]);
    
    int storeIndex = st;
    for (int i = st; i < dr; i++) {
        if (a[i] < pivotValue) {
            swap(a[i], a[storeIndex]);
            storeIndex++;
        }
    }
    swap(a[storeIndex], a[dr]);
    
    return storeIndex;
}

int quickSelect(vector<int>& a, int st, int dr, int k_index) {
    if (st == dr) {
        return a[st];
    }

    int pivotIndex = part(a, st, dr);

    if (k_index == pivotIndex) {
        return a[k_index]; 
    } else if (k_index < pivotIndex) {
        return quickSelect(a, st, pivotIndex - 1, k_index); 
    } else {
        return quickSelect(a, pivotIndex + 1, dr, k_index); 
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