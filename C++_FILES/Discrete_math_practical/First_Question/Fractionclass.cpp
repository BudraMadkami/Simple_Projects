#include <iostream>
using namespace std;
class A {
public:
int den;
int num;
 A (int num, int den) {this->num=num;this->den=den;}//Constructor
 void display (){  cout << num <<"/" << den << endl; }//void function 
//for Addition
 A operator+( A a){//This is a member function (a value‑returning method) of class A.
    int newnum = a.num*this->den + a.den*this->num;
    int newden = a.den * den;
    return A(newnum, newden);
 }
 //for Subtraction
 A operator-( A a){//This is a member function (a value‑returning method) of class A.
    int newnum = a.num*this->den - a.den*this->num;
    int newden = a.den * den;
    return A(newnum, newden);
 }
    //for Multiplication
 A operator*( A a){//This is a member function (a value‑returning method) of class A.
    int newnum = a.num*this->num;
    int newden = a.den*this->den;
    return A(newnum, newden);
 }
 A operator/( A a){//This is a member function (a value‑returning method) of class A.
    int newnum = a.num*this->den / a.den*this->num;
    int newden = a.den * den;
    return A(newnum, newden);
 }
 // for Modulo
 A operator%( A a){//This is a member function (a value‑returning method) of class A.
    int newnum = a.num*this->den % a.den*this->num;
    int newden = a.den * den;
    return A(newnum, newden);
 }
};
int main(){
  
    A a(1,2);
    A b(3,4);
    a.display();
    b.display();
   A d= a+b;
   A e= a-b;
   A f= a*b;
   A g= a%b;    
   A h= a/b; 
    d.display();
    e.display();
    f.display();
    g.display();
    h.display();

    

}