// MagicSquareMain.cpp
#include "MagicSquare.h"
#include "MagicSquare.cpp"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Size of Magic Square [odd]: ";
    cin >> n;
    cout << endl << endl;
    vector<vector<int>> magicSQ = magic(n);
    read_square(magicSQ);
    print_magic(magicSQ);
    int magic_sum;
    
    if (test_magic(magicSQ, magic_sum))
    {
        cout << endl;
        cout << "Magic Test Passed -- the Magic Sum is " << magic_sum << endl;
    }
    else
    {
        cout << endl;
        cout << "Magic Test Failed" << endl;
    }

    return 0;
}