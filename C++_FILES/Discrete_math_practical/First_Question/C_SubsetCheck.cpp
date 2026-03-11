// Program C: subset check
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class SET {
    set<int> elements;
public:
    void input(const string &name) {
        elements.clear();
        int n;
        cout << "Number of elements in " << name << ": ";
        cin >> n;
        while (n < 0) {  // Validation for negative numbers
            cout << "Please enter a non-negative number: ";
            cin >> n;
        }
        cout << "Enter " << n << " elements (integers):\n";
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            elements.insert(x);  // Duplicates automatically ignored
        }
    }
    
    // Using std::includes - more elegant approach
    bool isSubsetOf(const SET &other) const {
        return includes(other.elements.begin(), other.elements.end(),
                        elements.begin(), elements.end());
    }
    
    void display(const string &name) const {
        cout << name << " = { ";
        bool first = true;
        for (int v : elements) {
            if (!first) cout << ", ";
            cout << v;
            first = false;
        }
        cout << " }\n";
    }
};

int main() {
    SET A, B;
    A.input("A");
    B.input("B");
    A.display("A");
    B.display("B");
    
    cout << (A.isSubsetOf(B) ? "A is a subset of B\n" 
                             : "A is not a subset of B\n");
    cout << (B.isSubsetOf(A) ? "B is a subset of A\n" 
                             : "B is not a subset of A\n");
    return 0;
}