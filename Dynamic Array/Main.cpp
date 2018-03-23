#include <iostream>
#define MAX_SIZE 20
using namespace std;

class Bag {
private:
    int *numbers; // LIST OF NUMBERS
    int currentSize; // current size of the list
    int size;

public:
    Bag()
    {
       numbers = new int[MAX_SIZE];
        currentSize = 0; // set the current size to 0
        size = MAX_SIZE;
    }

    // parametrized constructor
    Bag(int arr[], int size)
    {
        this->size = size;
        numbers = new int[size];
        for (int i = 0; i < size; i++)
            numbers[i] = arr[i];
        currentSize = size;
    }

    // add a number to bag
    void addToBag(int n)
    {
        if (currentSize == size) {
            cout << "Bag is already full..." << endl;
            return;
        }
        numbers[currentSize++] = n;
    }

    // get the bag numbers
    int* getNumbers()
    {
        return numbers;
    }

    // get bag's current size
    int getSize()
    {
        return currentSize;
    }

    // print the bag numbers
    void display()
    {
        for (int i = 0; i < currentSize; i++)
            cout << numbers[i] << " ";
        cout << endl;
    }
};

class Set : public Bag {
public:
    Set(int arr[], int size)
        : Bag(arr, size)
    {
    }
    Bag unionBag(Bag bag)
    {
        int union_set[2 * MAX_SIZE];
        // copy the current bag's elements to this array
        for (int i = 0; i < getSize(); i++)
            union_set[i] = getNumbers()[i];

        int k = this->getSize();

        for (int i = 0; i < bag.getSize(); i++) {
            int toAdd = 1; // to decide whether to add en element or not
            for (int j = 0; j < getSize(); j++) {
                if (getNumbers()[j] == bag.getNumbers()[i])
                    toAdd = 0; // it means that bag.getNumbers()[i] already present in the bag, don't include
            }
            if (toAdd)
                union_set[k++] = bag.getNumbers()[i];
        }

        Bag unionBag(union_set, k);
        return unionBag;
    }

    Bag intersectionBag(Bag bag)
    {
        int intersection_set[MAX_SIZE];

        int k = 0;

        for (int i = 0; i < bag.getSize(); i++) {
            int toAdd = 0; // to decide whether to add en element or not
            for (int j = 0; j < getSize(); j++) {
                if (getNumbers()[j] == bag.getNumbers()[i])
                    toAdd = 1; // it means that bag.getNumbers()[i] already present in the bag, hence include
            }
            if (toAdd)
                intersection_set[k++] = bag.getNumbers()[i];
        }

        Bag intersectionBag(intersection_set, k);
        return intersectionBag;
    }
};

int main()
{
    int arr1[6] = { 1, 4, 6, 7, 2, 9 };
    int arr2[5] = { 3, 2, 6, 9, 8 };
    Set b1(arr1, 6);
    Set b2(arr2, 5);
    cout << "Set 1: ";
    b1.display();

    cout << "\nSet 2: ";
    b2.display();

    Bag union_set = b1.unionBag(b2);
    cout << "\nThe union set is : ";
    union_set.display();

    Bag intersection_set = b1.intersectionBag(b2);
    cout << "\nThe intersection set is : ";
    intersection_set.display();
    return 0;
}
