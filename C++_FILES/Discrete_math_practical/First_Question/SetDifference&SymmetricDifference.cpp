// Program F: set difference and symmetric difference
#include <bits/stdc++.h>
using namespace std;

class SET {
    set<int> elems;
public:
    void input(const string &name) {
        elems.clear();
        int n; cout << "Number of elements in " << name << ": "; cin >> n;
        cout << "Enter elements (integers):\n";
        for (int i = 0; i < n; ++i) { int x; cin >> x; elems.insert(x); }
    }
    SET difference(const SET &other) const {
        SET res;
        for (int x : elems) if (!other.elems.count(x)) res.elems.insert(x);
        return res;
    }
    SET setUnion(const SET &other) const {
        SET res; res.elems = elems;
        for (int x : other.elems) res.elems.insert(x);
        return res;
    }
    void display(const string &name) const {
        cout << name << " = { ";
        bool first = true;
        for (int v : elems) { if (!first) cout << ", "; cout << v; first = false; }
        cout << " }\n";
    }
    // expose elems for internal use
    friend int main();
private:
    const set<int>& getElems() const { return elems; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    SET A, B;
    A.input("A");
    B.input("B");
    A.display("A");
    B.display("B");
    SET AminusB = A.difference(B);
    SET BminusA = B.difference(A);
    SET symDiff = AminusB.setUnion(BminusA);
    AminusB.display("A \\ B");
    BminusA.display("B \\ A");
    symDiff.display("A Δ B (symmetric difference)");
    return 0;
}