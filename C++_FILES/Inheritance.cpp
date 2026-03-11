#include <iostream>
using namespace std;
class Scooty{
   public: 
    int Speed;
    float Mileage;
    string Bootspace;
};
class Bike : public Scooty{ //Bike is the derived class which is inheriting the properties of the base class Scooty using public access specifier.
  public:  
    int Price;

    int gear;
    void detColor(string c){ //this is a public member function of the derived class Bike which can be accessed using the object of the derived class Bike.
        color = c;
    }
    void print(){
        cout <<"Price of the bike is : " << Price << "\n Speed is : " << Speed << "\n Mileage is : " << Mileage << "\n Bootspace is : " << Bootspace << " \nGear is : " << gear << "\n Color is : " << color << endl;
    }
  private:
    string color;

};
int main(){
       Bike b;
       b.Price = 50000; //we can access the members of the base class Scooty using the object of the derived class Bike because we have used public access specifier for inheritance.
      
       b.Mileage = 45.5; //we can access the members of the base class Scooty using the object of the derived class Bike because we have used public access specifier for inheritance.
      
       b.Bootspace = "Large"; //we can access the members of the base class Scooty using the object of the derived class Bike because we have used public access specifier for inheritance.
      
       b.gear = 6; //we can access the members of the base class Scooty using the object of the derived class Bike because we have used public access specifier for inheritance.

       b.Speed = 120; //we can access the members of the base class Scooty using the object of the derived class Bike because we have used public access specifier for inheritance.

       b.detColor("Red"); 
       b.print();
       Scooty s;
       s.price = 20000;
       cout << s.price << endl; //we cannot access the members of the base class Scooty using the object of the base class Scooty because we have not declared any member function in the base class Scooty to access the members of the base class Scooty.  
    }
