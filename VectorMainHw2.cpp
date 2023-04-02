// VectorMainHw2.cpp
// KV, Sept 2022
// to be used for Lab 5/ HW2

// in order to test Exercise 2, uncomment portion of code
// as indicated; 

#include <iostream>
#include <fstream>
#include <cmath>
#include "VectorHw2.h"

using namespace std;

// prototypes
void print_vector(const Vector<int>&);

int main()
{
	Vector<int> myvec;
	ifstream inp;
	inp.open("hw2_input.txt");

	int next;
	inp >> next;
	while (!inp.fail())
	{
		myvec.push_back(next);
		inp >> next;
	}
	cout << endl << endl;
	cout << "The initial vector:";
	print_vector(myvec);
	cout << endl << endl;

	myvec.erase(myvec.size() - 1);
	cout << "After erasing value at index "
		<< myvec.size() - 1 << ":";
	print_vector(myvec);
	cout << endl << endl;

	myvec.erase(0);
	cout << "After erasing value at index 0:";
	print_vector(myvec);
	cout << endl << endl;

	myvec.erase(5);
	cout << "After erasing value at index 5:";
	print_vector(myvec);
	cout << endl << endl;

	Vector<int>::iterator itr;
	itr = myvec.begin();
	myvec.insert(itr, 333);
	cout << "After inserting (with iterator) value 333 in front:";
	print_vector(myvec);
	cout << endl << endl;

	itr = myvec.end();
	myvec.insert(itr, 777);
	cout << "After inserting (with iterator) value 777 at back:";
	print_vector(myvec);
	cout << endl << endl;

	itr = myvec.begin();
	for (int i = 1; i <= 11; i++)
		itr++;
	myvec.insert(itr, 555);
	cout << "After inserting (with iterator) value 555 in 12th place:";
	print_vector(myvec);
	cout << endl << endl;

	// Testing the lab code for Exercise 2 -- UNCOMMENT!
	itr = myvec.end();
	itr--;
	myvec.erase(itr);
	cout << "After erasing at rightmost iterator:";
	print_vector(myvec);
	cout << endl << endl;

	itr = myvec.begin();
	myvec.erase(itr);
	cout << "After erasing at leftmost iterator:";
	print_vector(myvec);
	cout << endl << endl;

	for (int i = 1; i <= 5; i++)
		itr++;
	myvec.erase(itr);
	cout << "After erasing (with iterator) value in 6th place:";
	print_vector(myvec);
	cout << endl << endl;

	myvec.insert(0, 444);
	cout << "After inserting value 444 at index 0:";
	print_vector(myvec);
	cout << endl << endl;

	myvec.insert(myvec.size(), 888);
	cout << "After inserting value 888 at index "
		<< myvec.size() << ":" << endl;
	print_vector(myvec);
	cout << endl << endl;

	myvec.insert(8, 666);
	cout << "After inserting value 666 at index 8:";
	print_vector(myvec);
	cout << endl << endl;

	// HW2 EXTRA CREDIT: erase all odd-valued elements with 'erase at index' or 'erase at iterator'
	for (int i = 0; i < myvec.size(); i++)
	{
		// if myvec[i] is odd, erase value at index i;
		if (myvec[i] % 2 != 0)
		{
			myvec.erase(i);
			i--;
		}
	}

	cout << "After erasing all odd numbers:";
	print_vector(myvec);
	cout << endl << endl;

	return 0;
}

void print_vector(const Vector<int>& v)
{
	cout << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}