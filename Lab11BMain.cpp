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

    int Car1 = digits1.cardinality();
    int Car2 = digits2.cardinality();

    cout << "Set 1 of cardinality " << Car1 << ": ";
    digits1.printSet();
    cout << endl;
    cout << "Set 2 of cardinality " << Car2 << ": ";
    digits2.printSet();
    cout << endl;

    for (int i = 0; i <= 3; i++)
    {
        if (i == 0)
        {
            s = "Union ";
            mySet = digits1.set_union(digits2);
        }
        else if (i == 1)
        {
            s = "Intersection ";
            mySet = digits1.set_intersection(digits2);
        }
        else if (i == 2)
        {
            s = "Difference 1:2 ";
            mySet = digits1.set_difference(digits2);
        }
        else
        {
            s = "Difference 2:1 ";
            mySet = digits2.set_difference(digits1);
        }
        int CarS = mySet.cardinality();
        cout << s <<  "set with cardinality " << CarS << ": ";
        mySet.printSet();
        cout << endl;
        mySet.makeEmpty();
    }
    
    return 0;
}