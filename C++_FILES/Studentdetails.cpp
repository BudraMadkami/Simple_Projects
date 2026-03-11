#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int marks;
public:
    Student(string n,int m){
        name = n;
        marks = m;
    }
void Smarks(int usermarks){
   if (usermarks >= 33){
    cout  << "congratulations! you have passed the exam with marks :"<<usermarks<< endl;
    }
    else {
        cout << "Sorry ! you have failed the exam with marks : " << usermarks << endl;
    }
}
int getMarks(){
    return marks;
}
string getname(){
    return name;
}
};
 
int main (){
    string name;
    int marks;
    cout << "Enter your name and marks : "<< endl;
    cin >> name;
    cin >> marks;
    Student s(name, marks);
    s.Smarks(marks);
   
    return 0;

}