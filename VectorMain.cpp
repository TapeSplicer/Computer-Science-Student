#include <iostream>
#include "Vector.h"
using namespace std;

void print_vector(const Vector<int> &);

int main()
{
    Vector<int> myvec;

    for (int i = 1; i <= 10; i++)
        myvec.push_back(i);
    cout << endl;
    cout << "Here is vector 'myvec': ";
    print_vector(myvec);
    cout << endl;
    
    Vector<int> anothervec(myvec);
    for (int i = 0; i < anothervec.size(); i++)
        anothervec[i] += 5;
    cout << "Here is another vector (copy of myvec, add 5 to all): ";
    print_vector(anothervec);
    cout << endl;

    Vector<int> yetanother = anothervec;
    for (int i = 0; i < yetanother.size(); i++)
        yetanother[i] = yetanother[i] * 2;
    cout << "Here is yet another vector (assigned, all X2): ";
    print_vector(yetanother);
    cout << endl;
    
    cout << "The original vector 'myvec': ";
    print_vector(myvec);
    cout << endl;

    return 0;
}

void print_vector(const Vector<int> &v)
{
    cout << endl;
    for (int x : v)
        cout << x << " ";
    cout << endl;
    return;
}