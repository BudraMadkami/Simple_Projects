#include <iostream>
#include <set>
#include <vector>

using namespace std;

class SET {
private:
    set<int> elements;

public:
    // Constructors
    SET() {}
    SET(const set<int>& s) : elements(s) {}

    // Basic modifiers
    void insert(int x) { elements.insert(x); }
    void erase(int x) { elements.erase(x); }

    // a. Check membership
    bool isMember(int x) const {
        return elements.find(x) != elements.end();
    }

    // Check if set is empty
    bool empty() const { return elements.empty(); }

    // Display the set
    void display() const {
        cout << "{ ";
        for (int x : elements) cout << x << " ";
        cout << "}";
    }

    // b. List all elements of the power set
    void powerset() const {
        vector<int> vec(elements.begin(), elements.end());
        vector<int> current;
        cout << "Power set:\n";
        powersetHelper(vec, 0, current);
    }

    // c. Check if this set is a subset of another set
    bool subset(const SET& other) const {
        for (int x : elements) {
            if (!other.isMember(x)) return false;
        }
        return true;
    }

    // d. Union of two sets
    SET setUnion(const SET& other) const {
        set<int> result = elements;
        result.insert(other.elements.begin(), other.elements.end());
        return SET(result);
    }

    // d. Intersection of two sets
    SET intersection(const SET& other) const {
        set<int> result;
        for (int x : elements) {
            if (other.isMember(x)) result.insert(x);
        }
        return SET(result);
    }

    // e. Complement relative to a universal set
    SET complement(const SET& universal) const {
        set<int> result;
        for (int x : universal.elements) {
            if (!isMember(x)) result.insert(x);
        }
        return SET(result);
    }

    // f. Set difference (this - other)
    SET difference(const SET& other) const {
        set<int> result;
        for (int x : elements) {
            if (!other.isMember(x)) result.insert(x);
        }
        return SET(result);
    }

    // f. Symmetric difference
    SET symmetricDifference(const SET& other) const {
        SET d1 = difference(other);
        SET d2 = other.difference(*this);
        return d1.setUnion(d2);
    }

    // g. Cartesian product (prints ordered pairs)
    void cartesianProduct(const SET& other) const {
        cout << "Cartesian product: { ";
        for (int a : elements) {
            for (int b : other.elements) {
                cout << "(" << a << "," << b << ") ";
            }
        }
        cout << "}\n";
    }

private:
    // Helper for recursive power set generation
    void powersetHelper(const vector<int>& vec, int idx, vector<int>& current) const {
        if (idx == vec.size()) {
            cout << "{ ";
            for (int x : current) cout << x << " ";
            cout << "}\n";
            return;
        }
        // Exclude current element
        powersetHelper(vec, idx + 1, current);
        // Include current element
        current.push_back(vec[idx]);
        powersetHelper(vec, idx + 1, current);
        current.pop_back();
    }
};

// Menu‑driven program
int main() {
    SET A, B, U;
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1.  Enter set A\n";
        cout << "2.  Enter set B\n";
        cout << "3.  Enter universal set U\n";
        cout << "4.  Check if an element is member of A\n";
        cout << "5.  Check if an element is member of B\n";
        cout << "6.  List powerset of A\n";
        cout << "7.  List powerset of B\n";
        cout << "8.  Check if A is subset of B\n";
        cout << "9.  Check if B is subset of A\n";
        cout << "10. Union of A and B\n";
        cout << "11. Intersection of A and B\n";
        cout << "12. Complement of A (relative to U)\n";
        cout << "13. Complement of B (relative to U)\n";
        cout << "14. Set difference A - B\n";
        cout << "15. Set difference B - A\n";
        cout << "16. Symmetric difference of A and B\n";
        cout << "17. Cartesian product A x B\n";
        cout << "18. Cartesian product B x A\n";
        cout << "19. Display sets A, B, U\n";
        cout << "0.  Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n, x;
                cout << "Enter number of elements in A: ";
                cin >> n;
                A = SET();  // reset A
                cout << "Enter elements: ";
                for (int i = 0; i < n; ++i) {
                    cin >> x;
                    A.insert(x);
                }
                break;
            }
            case 2: {
                int n, x;
                cout << "Enter number of elements in B: ";
                cin >> n;
                B = SET();
                cout << "Enter elements: ";
                for (int i = 0; i < n; ++i) {
                    cin >> x;
                    B.insert(x);
                }
                break;
            }
            case 3: {
                int n, x;
                cout << "Enter number of elements in universal set U: ";
                cin >> n;
                U = SET();
                cout << "Enter elements: ";
                for (int i = 0; i < n; ++i) {
                    cin >> x;
                    U.insert(x);
                }
                break;
            }
            case 4: {
                int x;
                cout << "Enter element to check in A: ";
                cin >> x;
                cout << (A.isMember(x) ? "True" : "False") << endl;
                break;
            }
            case 5: {
                int x;
                cout << "Enter element to check in B: ";
                cin >> x;
                cout << (B.isMember(x) ? "True" : "False") << endl;
                break;
            }
            case 6:
                cout << "Powerset of A:\n";
                A.powerset();
                break;
            case 7:
                cout << "Powerset of B:\n";
                B.powerset();
                break;
            case 8:
                cout << (A.subset(B) ? "A is subset of B" : "A is not subset of B") << endl;
                break;
            case 9:
                cout << (B.subset(A) ? "B is subset of A" : "B is not subset of A") << endl;
                break;
            case 10: {
                SET C = A.setUnion(B);
                cout << "Union: ";
                C.display();
                cout << endl;
                break;
            }
            case 11: {
                SET C = A.intersection(B);
                cout << "Intersection: ";
                C.display();
                cout << endl;
                break;
            }
            case 12:
                if (U.empty()) {
                    cout << "Universal set U is empty. Please set U first.\n";
                } else {
                    SET C = A.complement(U);
                    cout << "Complement of A: ";
                    C.display();
                    cout << endl;
                }
                break;
            case 13:
                if (U.empty()) {
                    cout << "Universal set U is empty. Please set U first.\n";
                } else {
                    SET C = B.complement(U);
                    cout << "Complement of B: ";
                    C.display();
                    cout << endl;
                }
                break;
            case 14: {
                SET C = A.difference(B);
                cout << "A - B: ";
                C.display();
                cout << endl;
                break;
            }
            case 15: {
                SET C = B.difference(A);
                cout << "B - A: ";
                C.display();
                cout << endl;
                break;
            }
            case 16: {
                SET C = A.symmetricDifference(B);
                cout << "Symmetric difference: ";
                C.display();
                cout << endl;
                break;
            }
            case 17:
                A.cartesianProduct(B);
                break;
            case 18:
                B.cartesianProduct(A);
                break;
            case 19:
                cout << "A = "; A.display(); cout << endl;
                cout << "B = "; B.display(); cout << endl;
                cout << "U = "; U.display(); cout << endl;
                break;
            case 0:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}