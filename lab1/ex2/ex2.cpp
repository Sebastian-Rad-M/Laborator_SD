#include <iostream>
#include <vector>

using namespace std;
int a,b;
void Sum(const vector<int>& v, int s) {
    int st = 0;
    int dr = v.size() - 1;

    while (st<dr) {
        int sum = v[st] + v[dr];

        if (sum==s) {
            a=v[st];
            b=v[dr];
            return; 
        } else if (sum < s) {
            st++; 
        } else {
            dr--; 
        }
    }

    }

int main() {
    vector<int> v = {1, 2, 5, 7, 11, 15};
    int s = 9;

    Sum(v, s);
    cout << a << ", " <<b << '\n';

    return 0;
}

/*class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
    int a,b;
    
    int st = 0;
    int dr = numbers.size() - 1;

    while (st<dr) {
        int sum = numbers[st] + numbers[dr];

        if (sum==target) {
            a=st+1;
            b=dr+1;
            break;
        } else if (sum < target) {
            st++; 
        } else {
            dr--; 
        }
    } 
    return {a,b};

    }
};*/