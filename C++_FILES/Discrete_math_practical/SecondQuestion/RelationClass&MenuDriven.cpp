//Second Question
#include <iostream>
using namespace std;

class RELATION {
private:
    int n; // number of elements in the underlying set (assume elements 0..n-1)
    vector<vector<int>> mat; // adjacency matrix: mat[i][j] == 1 if (i, j) in R

public:
    RELATION(int size = 0) {
         setSize(size);
         }

    void setSize(int size) {
        n = max(0, size);
        mat.assign(n, vector<int>(n, 0));
    }

    int size() const { 
        return n; 
    }

    // Input relation as adjacency matrix
    void inputMatrix() {
        if (n <= 0) {
            cout << "Set size is zero. Set size first.\n";
            return;
        }
        cout << "Enter adjacency matrix (" << n << " rows, each " << n << " entries 0/1):\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                while (!(cin >> x) || (x != 0 && x != 1)) {
                    cout << "Enter 0 or 1: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                mat[i][j] = x;
            }
        }
    }

    // Input relation as list of ordered pairs
    void inputPairs() {
        if (n <= 0) {
            cout << "Set size is zero. Set size first.\n";
            return;
        }
        cout << "Enter number of ordered pairs: ";
        int m; cin >> m;
        cout << "Enter pairs as two integers i j (0 <= i,j < " << n << "):\n";
        for (int k = 0; k < m; ++k) {
            int i, j; cin >> i >> j;
            if (0 <= i && i < n && 0 <= j && j < n) mat[i][j] = 1;
            else cout << "Pair (" << i << "," << j << ") ignored (out of range).\n";
        }
    }

    // Display matrix
    void displayMatrix() const {
        cout << "Adjacency matrix (" << n << "x" << n << "):\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << mat[i][j] << " ";
            cout << "\n";
        }
    }

    // a. Reflexive: for all i, (i,i) in R
    bool isReflexive() const {
        for (int i = 0; i < n; ++i) if (mat[i][i] == 0) return false;
        return true;
    }

    // b. Symmetric: for all i,j, if (i,j) in R then (j,i) in R
    bool isSymmetric() const {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] != mat[j][i]) return false;
        return true;
    }

    // c. Anti-symmetric: for all i != j, if (i,j) and (j,i) in R then i == j (i.e., no mutual pairs for distinct elements)
    bool isAntiSymmetric() const {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != j && mat[i][j] && mat[j][i]) return false;
        return true;
    }

    // d. Transitive: for all i,j,k, if (i,j) in R and (j,k) in R then (i,k) in R
    bool isTransitive() const {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j])
                    for (int k = 0; k < n; ++k)
                        if (mat[j][k] && !mat[i][k]) return false;
        return true;
    }

    // Utility: compute transitive closure using Floyd-Warshall style (not used for check but useful to show closure)
    vector<vector<int>> transitiveClosure() const {
        vector<vector<int>> closure = mat;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                if (closure[i][k])
                    for (int j = 0; j < n; ++j)
                        if (closure[k][j]) closure[i][j] = 1;
        return closure;
    }

    // Determine classification
    string classification() const {
        bool R = isReflexive();
        bool S = isSymmetric();
        bool AS = isAntiSymmetric();
        bool T = isTransitive();

        bool isEquivalence = R && S && T;
        bool isPartialOrder = R && AS && T;

        if (isEquivalence) return "Equivalence relation";
        if (isPartialOrder) return "Partial order relation";
        return "None of Equivalence or Partial Order";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    RELATION rel;
    while (true) {
        cout << "\n--- RELATION Menu ---\n";
        cout << "1  Set size (n)\n";
        cout << "2  Input relation as adjacency matrix\n";
        cout << "3  Input relation as ordered pairs\n";
        cout << "4  Display adjacency matrix\n";
        cout << "5  Check Reflexive\n";
        cout << "6  Check Symmetric\n";
        cout << "7  Check Anti-symmetric\n";
        cout << "8  Check Transitive\n";
        cout << "9  Show Transitive Closure\n";
        cout << "10 Show classification (Equivalence / Partial Order / None)\n";
        cout << "0  Exit\n";
        cout << "Choose option: ";

        int opt;
        if (!(cin >> opt)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }
        if (opt == 0) break;

        switch (opt) {
            case 1: {
                cout << "Enter set size n (number of elements, indexed 0..n-1): ";
                int n; cin >> n;
                if (n < 0) n = 0;
                rel.setSize(n);
                cout << "Size set to " << n << ".\n";
                break;
            }
            case 2:
                rel.inputMatrix();
                break;
            case 3:
                rel.inputPairs();
                break;
            case 4:
                rel.displayMatrix();
                break;
            case 5:
                cout << (rel.isReflexive() ? "Relation is Reflexive\n" : "Relation is NOT Reflexive\n");
                break;
            case 6:
                cout << (rel.isSymmetric() ? "Relation is Symmetric\n" : "Relation is NOT Symmetric\n");
                break;
            case 7:
                cout << (rel.isAntiSymmetric() ? "Relation is Anti-symmetric\n" : "Relation is NOT Anti-symmetric\n");
                break;
            case 8:
                cout << (rel.isTransitive() ? "Relation is Transitive\n" : "Relation is NOT Transitive\n");
                break;
            case 9: {
                auto closure = rel.transitiveClosure();
                cout << "Transitive closure:\n";
                for (auto &row : closure) {
                    for (int v : row) cout << v << " ";
                    cout << "\n";
                }
                break;
            }
            case 10:
                cout << "Classification: " << rel.classification() << "\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }

    cout << "Program terminated.\n";
    return 0;
}