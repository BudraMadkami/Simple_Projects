// Program D: union and intersection with input validation
#include <iostream>
#include <set>
#include <string>
#include <limits>   // for numeric_limits
using namespace std;

class SET {
    set<int> elems;
public:
    void input(const string &name) {
        elems.clear();
        int n;
        // Validate number of elements
        while (true) {
            cout << "Number of elements in " << name << ": ";
            if (cin >> n) {
                if (n >= 0) break;
                else cout << "Please enter a non‑negative number.\n";
            } else {
                cout << "Invalid input. Please enter an integer.\n";
                cin.clear(); // clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            }
        }
        // Read the elements
        cout << "Enter " << n << " elements (integers):\n";
        for (int i = 0; i < n; ++i) {
            int x;
            while (!(cin >> x)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            elems.insert(x);
        }
    }
    
    SET setUnion(const SET &other) const {
        SET res;
        res.elems = elems;
        for (int x : other.elems)
            res.elems.insert(x);
        return res;
    }
    
    SET setIntersection(const SET &other) const {
        SET res;
        for (int x : elems)
            if (other.elems.count(x))
                res.elems.insert(x);
        return res;
    }
    
    void display(const string &name) const {
        cout << name << " = { ";
        bool first = true;
        for (int v : elems) {
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
    
    SET U = A.setUnion(B);
    SET I = A.setIntersection(B);
    U.display("A ∪ B");
    I.display("A ∩ B");
    
    return 0;
}