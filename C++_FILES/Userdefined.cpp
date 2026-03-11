#include <iostream>
using namespace std;
class  Student {
    public:
    string name;
    int rollno;
    int marks;
};
// After creating this function don't have to write cout for each student to display their details
void display(Student S){
    cout << "Name : " << S.name << "\n Roll No :" << S.rollno << "\n Marks : " << S.marks << endl;
}
//Now creating change function 
void change1(int x){
    x = 100;
}
//Let'd define the function for pass by reference
void change2(int &x){
    x = 199;
}
int main(){
    int x = 19;
    cout << "The value of x before calling the change function is : " << x << endl;
    change1(x);//this x's value will be the same as 19 cause we are passing the value(called pass by value) of x to the function change and not the reference of the variable x 
    cout <<"The value of x after calling the  change function is :" << x << endl;
    cout << endl;
    //Here this will accept the reference of the variable x and change the value of x to 199
    change2(x);
    cout << "The value of x after calling the change2 fuinction is : " << x << endl;
    cout << endl;
    Student S1;
    
    S1.name = "Rohit";
    S1.rollno = 101;
    S1.marks = 85;

    Student S2;
    S2.name = "Mohit";
    S2.rollno = 102;
    S2.marks = 90;
    //cin >>S2.rollno;
//This is time consuming to write for each student 
   /* cout << "Name : " << S1.name << "\n Roll No :" << S1.rollno << "\n Marks : " << S1.marks << endl;
    cout<< endl;
    cout << "Name : " << S2.name << "\n Roll No :" << S2.rollno << "\n Marks : " << S2.marks << endl;*/
   // this section to print the dettails of students by using the function display
   display(S1);
   cout << endl;
   display(S2);
   
    return 0;
  
}


