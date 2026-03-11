#include <iostream>
using namespace std;
class Student {
    public:
        string name;
        int rollno;
     Student(string n, int r, float m){//this is the parameterised constructor of the class student which will initialize the data members of the class student when we create an object of the class student and
        name = n;
        rollno = r;
        marks = m;
    }
    void print(){
        cout << "Name : " << name << "\n Roll No :" << rollno << "\n Marks : " << marks << endl;

    }
    float getmarks(){//This is getter function to get the value of marks for the student object. This function will return the value of marks for the student object.
        return marks;
       
    }
    void setmarks(float m){//This is setter function to set the value of marks for the student object. This function will accept the value of marks as a parameter and set the value of marks for the student object.
        marks = m;
    }
    private:
        float marks;
};  
    

int main(){
    Student S1("Agatha", 1234, 89.65);
    S1.print();
   // S1.getmarks();
    S1.setmarks(90.23);
    S1.print();
   
}