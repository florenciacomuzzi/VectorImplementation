#include <iostream>
#include <exception>
#include <stdexcept>
#include <new> //needed for BAD_ALLOC
using namespace std;

template <class T>
class Vector{
     private:
          T* arr;
          int size; //keeps track of own size
          int capacity;
          //private member function
          //example of OOP encapsulation
          void grow()
          {
               capacity *= 2;
               try{
                    T* temp = new T[capacity];
               }catch(bad_alloc){
                    cout << "ERROR: BAD_ALLOC...FAILED TO ALLOCATE MEMORY" << endl;
                    exit(1);
               }
               for(int i = 0;i < size;i++){
                    temp[i] = arr[i];       //fill new larger array with old values
               }
               delete [] arr; //deletes what's at old location
               arr = temp;  //now array points to new larger location in memory
          }

     public:
          unsigned int size() //returns current size of vector
          { return size;}
          int getCapacity()
          { return capacity;}
          void push_back(const T& elt) //insert element elt at end of vector
          {
               if(size == capacity)//current array is full
                    grow();
               arr[size] = elt; //size points one position past end
               size++; //keep track of array size
          }

          void pop_back()   //delete last element
          {
               try{
                    if(size >= 1)    //if array is not empty
                         size--;
                    else
                        throw ex;
               }catch(std.underflow_error ex){
                    cout << "ERROR: UNDERFLOW_ERROR...VECTOR IS EMPTY" << endl << "CANNOT REMOVE ELEMENT" << endl;
                    exit(1);
               }
          }
          T& at(int pos)  //returns reference to element at position pos if pos is valid
          {
               try{
                    if(pos < size && pos >= 0){
                         return arr[pos];
                    }
                    else
                         throw empty;
                }catch(exception empty){
                     cout << "ERROR: CANNOT RETURN POSITION BECAUSE VECTOR IS EMPTY" << endl;
                     exit(1);
                }
          }

          T& front()
          {
                try{
                    if(pos < size && pos >= 0){
                         return arr[0];
                    }
                    else
                         throw empty;
                }catch(exception empty){
                     cout << "ERROR: CANNOT RETURN POSITION BECAUSE VECTOR IS EMPTY" << endl;
                     exit(1);
                }
          }
          T& back()
          {
               try{
                    if(pos < size && pos >= 0){
                         return arr[size - 1];
                    }
                    else
                         throw empty;
                }catch(exception empty){
                     cout << "ERROR: CANNOT RETURN POSITION BECAUSE VECTOR IS EMPTY" << endl;
                     exit(1);
                }
          }
          bool empty(){   //returns true if vector is empty
              if(size < 1)
                  return true;
              return false;
          }
          void insert(const T& elt, int pos)  //insert element elt at position pos
          {
               try{
                   if(size >= 1){
                         if(size == capacity)
                              grow();
                         for(int i = size; i > pos; i++){
                              arr[i] = arr[i - 1];
                         }
                         arr[pos] = elt;
                         size++;
                    }
                   else{
                       throw string("ERROR: CANNOT INSERT. VECTOR EMPTY");
                   }
               }catch(string exceptionString){
                   cout << string << endl;
                   exit(1);
               }
          }

          //unfinished
          void erase(int pos)   //deletes element at position pos
          {
              try{
                  if(size >= 1){
                        for(int i = size; i > pos; i++){
                             arr[i] = arr[i - 1];
                        }
                        arr[pos] = elt;
                        size++;
                   }
                  else{
                      throw ex;
                  }
              }catch(exception ex){
                  cout << "ERROR: CANNOT ERASE. VECTOR EMPTY" << endl;
                  exit(1);
              }
          }

          //overloaded operators
          //overloaded operator= required to prevent memberwise assignment
          //returns value of left operand to allow multiple assignment stmts, i.e. a = b = c
          Vector<T>& operator=(const Vector& v)
          {
               if(size > 0){         //if vector not empty, clear first
                   delete [] arr;
               }
               size = v.getSize();       //implicit this parameter
               capacity = v.getCapacity();
          }
          int& operator[](int n)    //returns reference to element at position n
          {
                return arr[n];
          }
          //default constructor
          Vector(){
              size = 0;
              capacity = 10;
              try{
                   arr = new T[capacity];
              }catch(bad_alloc){
                   cout << "ERROR: BAD_ALLOC...FAILED TO ALLOCATE MEMORY" << endl;
                   exit(1);
              }
          }
          //constructor
          //prevents memberwise assignment i.e. two objects pointing to same address
          //usage: v1(v2);
          Vector(const Vector<T>& v){
               size = v.size();  //must use mutator function for private members
               capacity = v.getCapacity();
               try{
                    arr = new T[capacity];
               }catch(bad_alloc){
                    cout << "ERROR: BAD_ALLOC...FAILED TO ALLOCATE MEMORY" << endl;
               }
               for(int i = 0; i < size; i++){
                    arr[i] = v.at(i);   //at method checks bounds
               }
          }
}
