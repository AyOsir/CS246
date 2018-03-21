#include <iostream>
#define MAX_SIZE 20
using namespace std;

class Bag {
private:
int numbers[MAX_SIZE]; // LIST OF NUMBERS
int currentSize; // current size of the list

public:
Bag() {
currentSize = 0; // set the current size to 0
}

// parametrized constructor
Bag(int arr[], int size){  
if(size > MAX_SIZE) {
cout << "Max size 20 allowed..." << endl;
return;
}
for(int i=0; i<size; i++)
numbers[i] = arr[i];
currentSize = size;
}

// add a number to bag
void addToBag(int n) {
if(currentSize == MAX_SIZE) {
cout << "Bag is already full..." << endl;
return;
}
numbers[currentSize++] = n;
}
  
// get the bag numbers
int* getNumbers(){
return numbers;
}

// get bag's current size
int getSize() {
return currentSize;
}

  
// print the bag numbers
void display() {
for(int i=0; i<currentSize; i++)
cout << numbers[i] << " ";
cout << endl;
}
};
