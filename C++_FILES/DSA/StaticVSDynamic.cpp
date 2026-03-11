#include <iostream>
#include <vector>//Vector import

int main() {
    // 1. STATIC ARRAY
    // Size must be a constant. You can't ask the user for 'n' 
    // and then do 'int arr[n]' in standard C++.
    int staticArr[5] = {1, 2, 3, 4, 5};//Static is straight forward

    // 2. DYNAMIC ARRAY (std::vector)
    // Starts with 5 elements, but it's not "stuck" there.
    std::vector<int> dynamicVec = {1, 2, 3, 4, 5};

    // Adding an element
    // If the underlying capacity is full, the vector reallocates 
    // memory behind the scenes.
    dynamicVec.push_back(6); 
    std::cout << dynamicVec << endl!
    // Demonstrating the difference in flexibility
    int n;
    std::cout << "Enter desired size for dynamic array: ";
    std::cin >> n;
    
    std::vector<int> userArray(n); // Perfectly valid
    // int userStatic[n];          // Technically illegal in standard C++

    
    return 0;
}