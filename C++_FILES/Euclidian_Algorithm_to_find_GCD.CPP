//Iterative Version (to find gcd)
//_______________________________
#include <iostream>
using namespace std;

int Iterative_Gcd(int a,int b){
  while (b != 0){ 
    int temp = b;
    b = a%b;
    a = temp;
  }
    return a ; }

//###########################################
//Recursive way to find gcd

int Recursive_Gcd(int a,int b){
    if (b ==0){
        return a;
    }
    return Recursive_Gcd(b,a%b);
    return 0;
}

int main(){
    int a,b;
    cout <<"Enter numbers:"<<endl;
    cin >> a;
    cin >>b;
    int result1 = Iterative_Gcd(a,b);
    int result2 = Recursive_Gcd(a,b);
    cout <<"Your gcd is :"<<result1<<endl;
    cout <<"This is your recursive gcd result :"<<result2<<endl;
    return 0;
}
