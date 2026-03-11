#include <iostream>
using namespace std;
class cricketer {
    public:
    string name;
    int runs;
cricketer(string name ,int runs){//Constructor
    this->name =name;       
    this->runs = runs;
}
};  
int main(){
    cricketer c1("Sachin Tendulkar", 14000);
    cricketer* c2  = new cricketer("Rohit sharma", 5000); //dynamic allocation of memory for a cricketer object using new operator.
   cout << "Name of cricketer is : " << c1.name << endl; //accessing the name of the cricketer using object.
    cout << "Runs scored by cricketer is : " << c1.runs << endl; //accessing the runs of the cricketer using object.
    cout << "Name of cricketer is : " << c2->name << endl; //accessing the name of the cricketer using pointer.
    cout << "Runs scored by cricketer is : " << c2->runs << endl; //accessing the runs of the cricketer using pointer.
  
}