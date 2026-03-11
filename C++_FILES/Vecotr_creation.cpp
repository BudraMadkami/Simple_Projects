#include <iostream>
using namespace std;

class MyVector {                // avoid global-name collision
private:
    int  capacity;
    int  size;
    int* data;

    void grow() {
        capacity *= 2;
        int* newData = new int[capacity];   // allocate an array
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;                      // free old buffer
        data = newData;
    }

public:
    MyVector()
        : capacity(1), size(0), data(new int[1])
    {}

    ~MyVector() {                       // destructor to avoid leak
        delete[] data;
    }

    // copy operations omitted for brevity; add if you copy instances

    void add(int ele) {
        if (size == capacity)
            grow();
        data[size++] = ele;
    }

    void print() const {
        for (int i = 0; i < size; ++i)
            std::cout << data[i] << ' ';
        std::cout << '\n';
    }

    int get(int index) const {
        if (size == 0) {
            std::cout << "Array is empty\n";
            return -1;
        }
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds\n";
            return -1;
        }
        return data[index];
    }

    void remove() {
        if (size == 0)
            std::cout << "Array is empty\n";
        else
            --size;
    }

    // accessors if you want to read size/capacity from outside
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
};

int main() {
    MyVector v;
    std::cout << "initial size: " << v.getSize()
         << " capacity: " << v.getCapacity() << '\n';
    v.print();                     // prints nothing

    v.add(1);
    std::cout << "size: " << v.getSize()
         << " capacity: " << v.getCapacity() << '\n';
    v.print();

    // …rest of your tests…
}