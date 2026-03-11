// Program A: is member
#include <iostream>
#include <set>
using namespace std;

class SET {
    set<int> elements;
public:
    void input() {
        elements.clear();
        int n; 
        cout << "Number of elements: ";
        cin >> n;
        cout << "Enter elements (integers):\n";
        for (int i = 0; i < n; ++i){
             int x;
             cin >> x;
             elements.insert(x);
             }
         }

         bool isMember(int x) const { 
            return elements.find(x) != elements.end();
         } 

        void display() const {
            cout << "{ ";
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
    SET A;
    cout << "Input Set A:\n"; 
    A.input();
    cout << "Set A = "; 
    A.display();
    cout << "Enter element to check membership: ";
    int x; 
    cin >> x;
    cout << x << (A.isMember(x) ? " is " : " is not ") << "a member of A\n";
    return 0;
}