#include <iostream>
#include <algorithm>
#include "Vector.h"
#include "Random.h"
#include "Random.cpp"
using namespace std;

int main()
{
    Vector<int> myvec;
    random_vector(25, 1, 100, myvec, 0);

    Vector<int>::iterator itr;

    cout << "Vector myvec printed with iterators: " << endl;
    for (itr = myvec.begin(); itr != myvec.end(); itr++)
        cout << *itr << " ";
    cout << endl << endl;
    
    myvec.erase(12);

    cout << "Vector myvec printed without original 13th iterator: " << endl;
    for (itr = myvec.begin(); itr != myvec.end(); itr++)
        cout << *itr << " ";
    cout << endl << endl;

    myvec.insert(myvec.begin() + 5, 999);

    cout << "Vector myvec printed with modified 6th iterator: " << endl;
    for (itr = myvec.begin(); itr != myvec.end(); itr++)
        cout << *itr << " ";
    cout << endl << endl;

    return 0;
}