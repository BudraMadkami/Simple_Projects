#include <iostream>
#include <string>
using namespace std;
class cricketer {
    public:
    string name;
    int runs;
    cricketer(string name ,int runs){
        this->name = name;
        this->runs = runs;
    }
    void change(cricketer* c2){
        (*c2).runs = 5000; //modifying the runs of c2 using pointer
        //c2->runs = 5000;
    }
};
int main(){
    cricketer c1("virat kohli", 12000);
    cricketer c2("Abhishek", 1000);

    cricketer* pter = &c1; //poiter variable which is storing the address of c1 (&C1 is the reference operator which gives the address of c1)
    cout << "Name of cricketer is : " << (*pter).name << endl; //accessing the name of c1 using pointer
    cout << "Runs scored by cricketer is : " << (*pter).runs << endl;
    (*pter).runs =15000; //modifying the runs of c1 using pointer
    //or this can be written as pter->runs = 15000;
    pter->runs = 1578; //modifying the runs of c1 using pointer
    cout << "Modified runs scored by cricketer is : " << (*pter).runs << endl;
    cout << "2nd\n Name of cricketer is : " << pter->name << endl; //accessing the name of c1 using pointer
    cout << c2.runs << endl;
    c2.change(&c2); //passing the address of c2 to the change function to modify the runs of c2.
    cout << "Modified runs scored by cricketer is : " << c2.runs << endl; //printing the modified runs of c2 after calling the change function

    int x = 10;
    cout << "Value of x is : " << x << endl;
    int* ptr = &x; //poiter variable which is storing the address of x
    //or can be written as int ptr->x
    
    cout << "Address of x is : " << ptr  << endl;
    cout << "Value of x using pointer (ptr) is : " << *ptr << endl; //dereferencing the pointer to get the value of x 
}
   
