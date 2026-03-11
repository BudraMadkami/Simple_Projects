// Program E: complement with respect to universal set U
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
    bool isMember(int x) const { return elems.count(x) > 0; }
    SET complement(const SET &universal) const {
        SET res;
        for (int x : universal.elems) if (!isMember(x)) res.elems.insert(x);
        return res;
    }
    void display(const string &name) const {
        cout << name << " = { ";
        bool first = true;
        for (int v : elems) { if (!first) cout << ", "; cout << v; first = false; }
        cout << " }\n";
    }
    // expose elems for complement implementation
    friend int main();
private:
    // allow access in friend if needed
    const set<int>& getElems() const { return elems; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    SET A, U;
    A.input("A");
    U.input("Universal U");
    A.display("A");
    U.display("U");
    // compute complement U \ A
    SET comp;
    for (int x : U.getElems()) if (!A.isMember(x)) comp.elems.insert(x);
    comp.display("Complement of A (U \\ A)");
    return 0;
}