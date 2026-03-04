#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data;        
    size_t lmax;  
    size_t lc;  

    void resize(size_t lnou) {
        T* temp = new T[lnou];
        for (size_t i = 0; i < lc; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        lmax = lnou;
    }

public:
    MyVector() {
        data = new T[1];
        lmax = 1;
        lc = 0;
    }

    ~MyVector() {
        delete[] data;
    }

    void push_back(T value) {
        if (lc == lmax) {
            resize(2 * lmax);
        }
        data[lc] = value;
        lc++;
    }

    void pop_back() {
        if (lc > 0) {
            lc--;
        } else {
            throw std::underflow_error("V is empty");
        }
    }

    size_t get_size() const {
        return lc;
    }
    T get(size_t index) const {
        if (index < lc) {
            return data[index];
        }
        throw std::out_of_range("Index out of bounds");
    }
};

int main() {
    MyVector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << v.get_size() << std::endl;
    
    v.pop_back();
    std::cout <<  v.get_size() << std::endl;

    for(size_t i = 0; i < v.get_size(); i++) {
        std::cout << "Element " << i << ": " << v.get(i) << std::endl;
    }

    return 0;
}