#include <iostream>
using namespace std;
class  Student {
    public:
        string name;
        int rollno;
        int marks;

    //This is the default constructor of the class student 
  /*   Student(){//default constructor
        name = "Rohit";
        rollno = 101;
        marks = 85;
    }
   //or empty default constructor
    Student(){//empty default constructor

    }*/
    //creating a constructor for the class student 
    Student(string n, int r, int m){//parameterised constructor
        name = n;
        rollno = r;
        marks = m;
            }
  //this is print function to print the details of students
    void printdetails(Student S1){//this function will accept the object of the class student and print the details of the student . This is void one changes nothing and just prints the details of the student .
    cout << "Name : " << S1.name << "\n Roll No :" << S1.rollno << "\n Marks : " << S1.marks << endl;
}  
//This is second void funtion to represent/write in a different way.
void printdetails2(){
    cout << "This is the result of second void function \nName : " << name << "\n Roll No :" << rollno << "\n Marks : " << marks << endl;
}        
};
int main(){
    Student S1("Emily", 102,90);
    Student S2("Sophia", 1034, 98);
    S1.printdetails(S1);
    cout << endl;
    S2.printdetails(S2);
    cout << endl;
    //This is the result of second void function
    cout << "The result of second void function is :" << endl;
    cout << endl;
    S1.printdetails2();
    cout << endl;

    Student S4 = S1;//Deep copy of the object S1 to S4
    S4.name = "Ava";//Changing the name of S4 to AVa in second result.
    S4.rollno = 123;
    S4.marks = 78;
    S4.printdetails2();
    //return 0;
    //This is the representation of the default constructor
   /* Student S3;
    S3.name = "Rohit";
    S3.rollno = 1204;
    S3.marks = 68;
    cout << "This is the result of default constructor : " << endl;
    cout << "Name :"<< S3.name << "\n Roll  No:"<< S3.rollno << "\n Marks :" << S3.marks << endl;
    return 0;*/
    

}