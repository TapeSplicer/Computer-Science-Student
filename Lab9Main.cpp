// For CSE 2020 Lab8
// KV, Fall 2022
#include <iostream>
#include <algorithm>
#include "List.h"
#include "Vector.h"
#include "Random.h"
#include "Random.cpp"
#include "Searching.h"
#include "Utilities.h"
using namespace std;

int main()
{
	rand_seed();
	Vector<int> myvec;
	random_vector_norep(25, 1, 250, myvec, 0);
    sort(myvec.begin(), myvec.end());

	List<int> mylst;
	for (int i = 0; i < myvec.size(); i++)
		mylst.push_back(myvec[i]);

	Vector<int> targets;
	targets.push_back(myvec[rand_int(0,25)]);
	targets.push_back(myvec[rand_int(0,25)]);
	targets.push_back(333);
	
	cout << endl;
	cout << "Sequence of random numbers (both in Vector and List):" << endl;
	print_Vector(myvec);
	cout << endl;

	/*
	for (int i = 0; i < targets.size(); i++)
	{
		cout << endl;
		cout << "Linear Search of Vector for target value " << targets[i] << ":\t";
	
		if (linear_search_V(myvec, targets[i]) != -1)
		{
			cout << "Found :-)" << endl;
		}
		else
		{
			cout << "Not found :-(" << endl;
		}

		cout << endl;
		cout << "Linear Search of List for target value " << targets[i] << ":\t";

		if (linear_search_L(mylst, targets[i]) != mylst.end())
		{
			cout << "Found :-)" << endl;
		}
		else
		{
			cout << "Not found :-(" << endl;
		}
	}
	cout << endl << endl;

	for (int i = 0; i < targets.size(); i++)
	{
		cout << endl;
		cout << "Recursive Linear Search of Vector for target value " << targets[i] << ":\t";

		if (rec_linear_search_V(0, myvec, targets[i]) != -1)
		{
			cout << "Found :-)" << endl;
		}
		else
		{
			cout << "Not found :-(" << endl;
		}

		cout << endl;
		cout << "Recursieve Linear Search of List for target value " << targets[i] << ":\t";

		if (rec_linear_search_L(mylst.begin(), mylst, targets[i]) != mylst.end())
		{
			cout << "Found :-)" << endl;
		}
		else
		{
			cout << "Not found :-(" << endl;
		}
	}
	*/

    for (int k = 20; k <= 100; k += 20)
    {
        Vector<int> myvec;
        random_vector_norep(k, 1, 1000, myvec, 0);

        Vector<int> sortvec(myvec);
        sort(sortvec.begin(), sortvec.end());

        List<int> sortlist;
        for (int i = 0; i < sortvec.size(); i++)
            sortlist.push_back(sortvec[i]);
        Vector<int> five_targets;
        random_vector_norep(5, 0 , myvec.size() - 1, five_targets, 0);
        for (int i = 0; i < 5; i++)
        {
            int target = myvec[five_targets[i]];
            //linear_search_V(sortvec, target);
            //linear_search_L(sortlist, target);
            binary_search_V(sortvec, target);
			rec_binary_search_V(i, sortvec.size() - 1, sortvec, target);
            
            cout << endl;
            cout << "Binary Searching vector of size " << myvec.size() << " for target " << target << ":\t";
			if (binary_search_V(myvec, targets[i]) == -1)
			{
				cout << " Not found :-(" << endl;
			}
			else
			{
				cout << " Found :-)" << endl;
			}

			cout << endl;
            cout << "Recursive Binary Searching vector of size " << myvec.size() << " for target " << target << ":\t";
			if (rec_binary_search_V(0, myvec.size() - 1, myvec, targets[i]) == -1)
			{
				cout << " Not found :-(" << endl;
			}
			else
			{
				cout << " Found :-)" << endl;
			}
        }
    }
	return 0;
}