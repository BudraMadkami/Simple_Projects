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
//Function onside the class to print the details of the cricketer
void printdetails(int runs){
    cout << "Name : " << name << "\n Runs : " << runs << endl;
    cout << runs << endl;
}
int matches(){
    return runs/100;
}
};
int main(){
    cricketer c1("virat kohli", 12000);
    cricketer c2("Abhishek", 1000);
   /* cout << "Name : " << c1.name << "\n Runs : " << c1.runs << endl;
    cout << endl;
    cout << "Name : " << c2.name << "\n Runs : " << c2.runs << endl;
    */
    c1.printdetails(67);
    c2.printdetails(45);
    cout << "Number of matches played by " << c1.name << " is : " << c1.matches() << endl;
    cout << "Number of matches played by " << c2.name << " is : " << c2.matches() << endl;
}