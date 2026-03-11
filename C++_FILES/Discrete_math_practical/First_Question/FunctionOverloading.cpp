#include <iostream>
using namespace std;
class Load{
    public:
     void sum(int a,int b){
        cout << a+b <<endl;
     }
     void sum(int a,int b,int c){
        cout << a+b+c <<endl;
     }
     void sum(string  a,string b){
        cout << a+b <<endl;
     }

};
int main(){
    Load l;
    l.sum(12,45);
    l.sum(12,45,567);
    l.sum("Hello","World");
}