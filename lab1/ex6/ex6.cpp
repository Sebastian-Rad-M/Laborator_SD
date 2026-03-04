#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class RandomizedSet {
private:
    std::vector<int> nums;

public:
    RandomizedSet() {
      
        srand(time(NULL));
    }

    void insert(int x) {
        nums.push_back(x);
    }

    void pop() {
        if (nums.empty()) {
            std::cout << "empty" << std::endl;
            return;
        }

        int randomIndex = rand() % nums.size();
        
        std::cout<<nums[randomIndex]<<std::endl;

        nums[randomIndex] = nums.back();
        
        nums.pop_back();
    }
};

int main() {
    RandomizedSet rs;
    
    rs.insert(10);
    rs.insert(20);
    rs.insert(30);
    rs.insert(40);

    rs.pop();
    rs.pop();

    return 0;
}