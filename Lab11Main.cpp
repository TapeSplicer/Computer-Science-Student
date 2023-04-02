#include <iomanip>
#include <iostream>
#include <string>
#include "Set_functions.h"
#include "BST_Set-1.h"
#include "Vector.h"
#include "Random.h"
#include "Random.cpp"
using namespace std;

int main()
{
    string s;
    Set<int> mySet;

    Set<int> digits1;
    for (int M = 1; M <= 10; M++)
        digits1.insert(rand_int(0, 20));
    Set<int> digits2;
    for (int N = 1; N <= 10; N++)
        digits2.insert(rand_int(0, 20));

    cout << "Set 1: ";
    digits1.printSet();
    cout << endl;
    cout << "Set 2: ";
    digits2.printSet();
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            s = "Union ";
            mySet = set_union(digits1, digits2);
        }
        else if (i == 1)
        {
            s = "Intersection ";
            mySet = set_intersection(digits1, digits2);
        }
        else
        {
            s = "Difference ";
            mySet = set_difference(digits1, digits2);
        }
        cout << s <<  "set: ";
        mySet.printSet();
        cout << endl;
        mySet.makeEmpty();
    }

    return 0;
}