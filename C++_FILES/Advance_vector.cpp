#include <iostream>
using namespace std;

class vector{
public:
   int  capacity;
    int size;
    int* data;
 vector(){
   size = 0;
    capacity = 1;
    data = new int[1];
   
}
~vector() {                       // destructor to avoid leak
        delete[] data;
    }

void add (int ele) {
      if (size == capacity) {
         capacity *= 2;
         int* newData = new int(capacity);
         for (int i = 0; i < size; i++) {
            newData[i] = data[i];
         }
         delete[] data;
         data = newData;
      }
      data[size++] = ele;
}

void print() {
     for (int i = 0; i < size; i++) {
         std::cout << data[i] << " ";            
     }
     std::cout << std::endl;
}

int get(int index) {
     if (size == 0){
      std::cout << "Array is empty"<<std::endl;

       return -1;
     }
     if (index < 0 || index >= size) {
         std::cout << "Index out of bounds" << std::endl;
         return -1;
     }
     return data[index];
   }

 void remove() {
     if (size == 0) {
      std::cout << "Array is empty" << std::endl;
     } else {
         size--;
     }
   }
};
int main(){
 vector v;
  std::cout << "size: " << v.size << " capacity: " << v.capacity << std::endl;
  v.print();
 v.add(1);
 std::cout << "size: " << v.size << " capacity: " << v.capacity << std::endl;
 v.print();
  v.add(23);
  std::cout << "size: " << v.size << " capacity: " << v.capacity << std::endl;
 v.print();
  v.add(4);
  std::cout << "size: " << v.size << " capacity: " << v.capacity << std::endl;
 v.print();
 std::cout << std::endl;

 v.remove();
 v.print();
    
}