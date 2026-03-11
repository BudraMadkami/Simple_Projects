#include <bits/stdc++.h>
using namespace std;

class SET {
private:
    set<int> elems;
public:
    SET() = default;

    // Input elements interactively
    void input(const string &name = "") {
        elems.clear();
        int n;
        if (!name.empty()) cout << "Enter number of elements in " << name << ": ";
        else cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements (integers). Duplicates will be ignored:\n";
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            elems.insert(x);
        }
    }

    // Display set
    void display(const string &label = "") const {
        if (!label.empty()) cout << label << " = ";
        cout << "{ ";
        bool first = true;
        for (int x : elems) {
            if (!first) cout << ", ";
            cout << x;
            first = false;
        }
        cout << " }";
    }

    // a. is member
    bool isMember(int x) const {
        return elems.find(x) != elems.end();
    }

    // b. powerset (prints all subsets)
    void powerset() const {
        vector<int> v(elems.begin(), elems.end());
        int n = (int)v.size();
        if (n > 60) {
            cout << "Set too large to enumerate powerset safely.\n";
            return;
        }
        unsigned long long total = 1ULL << n;
        cout << "Power set (total " << total << " subsets):\n";
        for (unsigned long long mask = 0; mask < total; ++mask) {
            cout << "{ ";
            bool first = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1ULL << i)) {
                    if (!first) cout << ", ";
                    cout << v[i];
                    first = false;
                }
            }
            cout << " }\n";
        }
    }

    // c. subset: this ⊆ other ?
    bool isSubsetOf(const SET &other) const {
        for (int x : elems) if (!other.isMember(x)) return false;
        return true;
    }

    // d. union
    SET setUnion(const SET &other) const {
        SET res;
        res.elems = elems;
        for (int x : other.elems) res.elems.insert(x);
        return res;
    }

    // d. intersection
    SET setIntersection(const SET &other) const {
        SET res;
        for (int x : elems) if (other.isMember(x)) res.elems.insert(x);
        return res;
    }

    // e. complement with respect to universal set U: U \ this
    SET complement(const SET &universal) const {
        SET res;
        for (int x : universal.elems) if (!isMember(x)) res.elems.insert(x);
        return res;
    }

    // f. set difference: this \ other
    SET difference(const SET &other) const {
        SET res;
        for (int x : elems) if (!other.isMember(x)) res.elems.insert(x);
        return res;
    }

    // f. symmetric difference: (A \ B) ∪ (B \ A)
    SET symmetricDifference(const SET &other) const {
        SET a_minus_b = difference(other);
        SET b_minus_a = other.difference(*this);
        return a_minus_b.setUnion(b_minus_a);
    }

    // g. cartesian product: returns vector of pairs
    vector<pair<int,int>> cartesianProduct(const SET &other) const {
        vector<pair<int,int>> res;
        for (int a : elems) for (int b : other.elems) res.emplace_back(a,b);
        return res;
    }

    // utility: size
    size_t size() const { return elems.size(); }
};

void printCartesian(const vector<pair<int,int>> &prod) {
    cout << "{ ";
    bool first = true;
    for (auto &p : prod) {
        if (!first) cout << ", ";
        cout << "(" << p.first << "," << p.second << ")";
        first = false;
    }
    cout << " }";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SET A, B, U;
    bool hasA = false, hasB = false, hasU = false;

    while (true) {
        cout << "\n\n--- SET Operations Menu ---\n";
        cout << "1  Input Set A\n";
        cout << "2  Input Set B\n";
        cout << "3  Input Universal Set U\n";
        cout << "4  Display Sets\n";
        cout << "5  a. Is member (check element in A)\n";
        cout << "6  b. Powerset of A\n";
        cout << "7  c. Check subset (A subset of B)\n";
        cout << "8  c. Check subset (B subset of A)\n";
        cout << "9  d. Union of A and B\n";
        cout << "10 d. Intersection of A and B\n";
        cout << "11 e. Complement of A with respect to U\n";
        cout << "12 f. Set difference A \\ B\n";
        cout << "13 f. Set difference B \\ A\n";
        cout << "14 f. Symmetric difference A Δ B\n";
        cout << "15 g. Cartesian product A × B\n";
        cout << "0  Exit\n";
        cout << "Choose an option: ";

        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }
        if (choice == 0) break;

        switch (choice) {
            case 1:
                A.input("A");
                hasA = true;
                break;
            case 2:
                B.input("B");
                hasB = true;
                break;
            case 3:
                U.input("Universal U");
                hasU = true;
                break;
            case 4:
                cout << "Set A: ";
                if (hasA) A.display("A"); else cout << "Not defined";
                cout << "\nSet B: ";
                if (hasB) B.display("B"); else cout << "Not defined";
                cout << "\nUniversal U: ";
                if (hasU) U.display("U"); else cout << "Not defined";
                cout << "\n";
                break;
            case 5: {
                if (!hasA) { cout << "Define Set A first.\n"; break; }
                cout << "Enter element to check in A: ";
                int x; cin >> x;
                cout << x << (A.isMember(x) ? " is " : " is not ") << "a member of A\n";
                break;
            }
            case 6:
                if (!hasA) { cout << "Define Set A first.\n"; break; }
                A.powerset();
                break;
            case 7:
                if (!hasA || !hasB) { cout << "Define both A and B first.\n"; break; }
                cout << (A.isSubsetOf(B) ? "A is a subset of B\n" : "A is not a subset of B\n");
                break;
            case 8:
                if (!hasA || !hasB) { cout << "Define both A and B first.\n"; break; }
                cout << (B.isSubsetOf(A) ? "B is a subset of A\n" : "B is not a subset of A\n");
                break;
            case 9:
                if (!hasA || !hasB) { cout << "Define both A and B first.\n"; break; }
                {
                    SET UAB = A.setUnion(B);
                    cout << "A ∪ B = ";
                    UAB.display();
                    cout << "\n";
                }
                break;
            case 10:
                if (!hasA || !hasB) { cout << "Define both A and B first.\n"; break; }
                {
                    SET IAB = A.setIntersection(B);
                    cout << "A ∩ B = ";
                    IAB.display();
                    cout << "\n";
                }
                break;
            case 11:
                if (!hasA || !hasU) { cout << "Define A and universal U first.\n"; break; }
                {
                    SET compA = A.complement(U);
                    cout << "Complement of A with respect to U is: ";
                    compA.display();
                    cout << "\n";
                }
                break;
            case 12:
                if (!hasA || !hasB) { cout << "Define both A and B first.\n"; break; }
                {
                    SET d = A.difference(B);
                    cout << "A \\ B = ";
                    d.display();
                    cout << "\n";
                }
                break;
            case 13:
                if (!hasA || !hasB) { cout << "Define both A and B first.\n"; break; }
                {
                    SET d = B.difference(A);
                    cout << "B \\ A = ";
                    d.display();
                    cout << "\n";
                }
                break;
            case 14:
                if (!hasA || !hasB) { cout << "Define both A and B first.\n"; break; }
                {
                    SET s = A.symmetricDifference(B);
                    cout << "A Δ B = ";
                    s.display();
                    cout << "\n";
                }
                break;
            case 15:
                if (!hasA || !hasB) { cout << "Define both A and B first.\n"; break; }
                {
                    auto prod = A.cartesianProduct(B);
                    cout << "A × B = ";
                    printCartesian(prod);
                    cout << "\n";
                }
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    cout << "Program terminated.\n";
    return 0;
}