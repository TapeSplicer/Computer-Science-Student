#include <iostream>
#include "BinaryHeap.h"
#include "Vector.h"
#include "Random.h"
#include "Random.cpp"
using namespace std;

int main()
{
    BinaryHeap<int> myHeap;
    Vector<int> inputs;

    rand_seed();
    random_vector(7, 1, 250, inputs, 0);

    for (int i = 0; i < inputs.size(); i++)
        myHeap.insert(inputs[i]);
    
    cout << endl << "This is my heap: " << endl;
    myHeap.printHeap();
    cout << endl;

    cout << endl << "Taking down my heap..." << endl;
    int themin;
    while (!myHeap.empty())
    {
        myHeap.deleteMin(themin);
        cout << "Deleting minimum value: " << themin << endl;
        myHeap.printHeap();
        cout << endl;
    }

    return 0;
}