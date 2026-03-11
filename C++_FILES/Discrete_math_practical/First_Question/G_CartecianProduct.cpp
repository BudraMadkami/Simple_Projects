#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <utility>
#include <limits>
using namespace std;

class SET {
    vector<int> elems; // preserve input order
public:
    void input(const string &name) {
        elems.clear();
        int n;
        while (true) {
            cout << "Number of elements in " << name << ": ";
            if (cin >> n && n >= 0) break;
            cout << "Invalid input. Please enter a non‑negative integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter " << n << " elements (integers). Duplicates will be ignored:\n";
        unordered_set<int> seen;
        for (int i = 0; i < n; ++i) {
            int x;
            while (!(cin >> x)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (seen.insert(x).second) { // only insert if new
                elems.push_back(x);
            }
        }

        // FIX: discard any leftover characters (including extra numbers) up to newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<pair<int, int>> cartesianProduct(const SET &other) const {
        vector<pair<int, int>> res;
        for (int a : elems)
            for (int b : other.elems)
                res.emplace_back(a, b);
        return res;
    }

    void display(const string &name) const {
        cout << name << " = { ";
        for (size_t i = 0; i < elems.size(); ++i) {
            if (i > 0) cout << ", ";
            cout << elems[i];
        }
        cout << " }\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SET A, B;
    A.input("A");
    B.input("B");
    A.display("A");
    B.display("B");

    auto prod = A.cartesianProduct(B);
    cout << "A x B = { ";
    for (size_t i = 0; i < prod.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << "(" << prod[i].first << "," << prod[i].second << ")";
    }
    cout << " }\n";

    return 0;
}