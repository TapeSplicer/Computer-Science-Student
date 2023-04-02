#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include "List.h"
#include "Vector.h"
#include "HW3searching.h"
#include "Random.h"
#include "Random.cpp"
using namespace std;

void printTable(const Vector<Vector<int>> theVec);

int main()
{
    Vector<Vector<int> > statsLSV;
    Vector<Vector<int> > statsLSL;
    Vector<Vector<int> > statsBSV;
    rand_seed();
    for (int k = 50; k <= 1000; k += 50)
    {
        Vector<int> row1, row2, row3;
        row1.push_back(k);
        row2.push_back(k);
        row3.push_back(k);

        Vector<int> myvec;
        random_vector_norep(k, 1, 10000, myvec, 0);

        Vector<int> sortvec(myvec);
        sort(sortvec.begin(), sortvec.end());
        List<int> sortlst;
        for (int i = 0; i < sortvec.size(); i++)
            sortlst.push_back(sortvec[i]);

        Vector<int> targets;
        random_vector_norep(10, 0, myvec.size() - 1, targets, 0);

        int ops1 = 0;
        int ops2 = 0;
        int ops3 = 0;
        for (int i = 0; i < targets.size(); i++)
        {
            ops1 = 0;
            ops2 = 0;
            ops3 = 0;
            int target = myvec[targets[i]];
            //cout << "Searching for target " << target << endl << endl;
            linear_search_V(sortvec, target, ops1);
            linear_search_L(sortlst, target, ops2);
            binary_search_V(sortvec, target, ops3);

            row1.push_back(ops1);
            row2.push_back(ops2);
            row3.push_back(ops3);
        }
        statsLSV.push_back(row1);
        statsLSL.push_back(row2);
        statsBSV.push_back(row3);
    }
    cout << endl;

    // output 3 data tables with rows and columns from Vector<Vector<int> >’s statsLSV, statsLSL, and statsBSV (see sample output in Lab 10 instructions)
    cout << "Linear search of vector:" << endl;
    printTable(statsLSV);
    cout << "Linear search of list:" << endl;
    printTable(statsLSL);
    cout << "Binary search of vector:" << endl;
    printTable(statsBSV);
    
    return 0;
}

void printTable(const Vector<Vector<int>> theVec)
{
    for (int N = 1; N < theVec[N].size(); N++)
    {
        if (N == 1)
            cout << setw(12) << N;
        else
            cout << setw(6) << N;
    }
    cout << endl;

    for (int R = 0; R < theVec.size(); R++)
    {
        for (int C = 0; C < theVec[R].size(); C++)
            cout << setw(6) << theVec[R][C];
        cout << endl;
    }
    cout << endl;
    return;
}