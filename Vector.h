#include <iostream>
using namespace std;

class Vector{
     private:
          int* arr;
          int size; //keeps track of own size
          int capacity;

     public:

          unsigned int size() //returns current size of vector
          { return size;}
          int getCapacity()
          { return capacity;}
          void push_back(const int& elt) //insert element elt at end of vector
          {             ;}
          void pop_back()   //delete last element
          {             ;}
          int& at(int pos)  //returns reference to element at position pos if pos is valid
          {                 ;}

          int& front()
          {             ;}
          int& back()
          {                 ;}
          bool empty(){   //returns true if vector is empty
              if(size < 1)
                  return true;
              return false;
          }
          void insert(const int& elt, int pos)  //insert element elt at position pos
          {             ;}
          void erase(int pos)   //deletes element at position pos
          {             ;}

          //overloaded operators
          Vector<int>& operator=(const Vector& v)
          {             ;}
          int& operator[](int n)    //returns reference to element at position n
          {                     ;}



}
