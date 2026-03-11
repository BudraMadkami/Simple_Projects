// Program A: is member
#include <iostream>
#include <set>
using namespace std;

class SET {
    set<int> elems;
public:
    void input() {
        elems.clear();
        int n; 
        cout << "Number of elements: ";
        cin >> n;
        cout << "Enter elements (integers):\n";
        for (int i = 0; i < n; ++i) 
         { int x; cin >> x; elems.insert(x); }
    }
    bool isMember(int x) const { return elems.find(x) != elems.end(); }
    void display() const {
        cout << "{ ";
        bool first = true;
        for (int v : elems) { if (!first) cout << ", "; cout << v; first = false; }
        cout << " }\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    SET A;
    cout << "Input Set A:\n"; A.input();
    cout << "Set A = "; A.display();
    cout << "Enter element to check membership: ";
    int x; cin >> x;
    cout << x << (A.isMember(x) ? " is " : " is not ") << "a member of A\n";
    return 0;
}