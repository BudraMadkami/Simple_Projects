// Program B: powerset
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class SET {
    vector<int> elements;
public:
    void input() {
        elements.clear();
        int n; 
        cout << "Number of elements: "; 
        cin >> n;
        cout << "Enter elements (integers). Duplicates will be ignored:\n";
        set<int> tmp;
        for (int i = 0; i < n; ++i) { 
            int x;
            cin >> x;
            tmp.insert(x); 
        }
        for (int v : tmp) elements.push_back(v);
    }
    
    void powerset() const {
        int n = (int)elements.size();
        if (n > 60) {
            cout << "Set too large to enumerate powerset safely.\n"; 
            return; 
        }
        unsigned long long total = 1ULL << n;
        cout << "Power set (total " << total << " subsets):\n";
        for (unsigned long long mask = 0; mask < total; ++mask) {
            cout << "{ ";
            bool first = true;
            for (int i = 0; i < n; ++i) if (mask & (1ULL << i)) {
                if (!first) cout << ", ";
                cout << elements[i];
                first = false;
            }
            cout << " }\n";
        }
    }
};

int main() {
    SET A;
    cout << "Input Set A for powerset:\n";
    A.input();
    A.powerset();
    return 0;
}