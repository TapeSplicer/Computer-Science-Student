// For CSE 2020 Lab8
// KV, Fall 2022
#include <iostream>
//#include <algorithm>
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
	return 0;
}