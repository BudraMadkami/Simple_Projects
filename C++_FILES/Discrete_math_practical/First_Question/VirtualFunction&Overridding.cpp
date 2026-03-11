#include <iostream>
using namespace std;
class Scooty{
    public:
     int speed;
    virtual void sound(){
        cout <<"Terrr Terrr" << endl;
     }
};
class Bike:public Scooty{
public:
 int gears;
  void sound(){
    cout <<"Boot Boot Boottttt" << endl;
 }

};
int main(){
    Scooty* s = new Scooty();//here it is not Overridding , will give the result as defined.
    s->sound();// or (*s).sound();
    Scooty* b = new Bike();//here it is  Overridding .but gives the sound Bike ,even if using scooty's pointer.
    b->sound();//or (*b).sound();
}