#include <iostream>
using namespace std;
class cricketer {
    public:
    string name;
    int runs;
cricketer(string name ,int runs){
    this->name =name;
    this->runs = runs;
}
};
int main(){
    cricketer c1("virat kohli", 12000);
    cricketer c2("Abhishek", 1000);
    cout << "Name : " << c1.name << "\n Runs : " << c1.runs << endl;
    cout << endl;
    cout << "Name : " << c2.name << "\n Runs : " << c2.runs << endl;
    
}