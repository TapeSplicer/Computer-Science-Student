// MaxSubSumMain.cpp
// by KV, CSE 2020, Fall 2021, Lab 3, Exercise 2
//
// modified by student: __________________

#include <iostream>
#include <fstream>
#include "Vector.h"

using namespace std;

// prototypes
Vector<int> max_subseq_sum_alg4_collect(const Vector<int>&, int&);
void print_vector(const Vector<int>&);

int main()
{
	Vector<int> myseq;
	ifstream inp;
	inp.open("lab3ex2_input.txt"); // uniform input for all

	int next;
	inp >> next;
	myseq.push_back(next);
	while (!inp.fail())
	{
		myseq.push_back(next);
		inp >> next;
	}

	cout << endl << endl;
	print_vector(myseq);

	Vector<int> maxsubseq;
	int maxsum;

	maxsubseq = max_subseq_sum_alg4_collect(myseq, maxsum);

	cout << endl;
	cout << "Max subseq sum: " << maxsum << endl << endl;
	cout << "Sum of: ";
	print_vector(maxsubseq);
	cout << endl << endl;

	return 0;
}

// version of alg4 that collects max subsum values; 
// for Fall 2020 CSE 2020
Vector<int> max_subseq_sum_alg4_collect(const Vector<int>& vec, int& max)
{
	int maxsum = 0;
	int localsum = 0;
	Vector<int> maxseq;
	Vector<int> localseq;

	for (int i = 0; i < vec.size(); i++)
	{
		localsum += vec[i];
		localseq.push_back(vec[i]);

		if (localsum > maxsum)
		{
			maxsum = localsum;
			maxseq = localseq;
		}
		else if (localsum < 0)
		{
			localsum = 0;
			localseq.clear();
		}
	}
	max = maxsum;
	return maxseq;
}

// just printing a vector of int
void print_vector(const Vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	return;
}