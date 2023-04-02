// HW3Searching.h
// CSE 2020, Fall 2022, by KV
// to be completed/enhanced for HW3
#ifndef SEARCHING_H_
#define SEARCHING_H_
#include "Vector.h"
#include "List.h"
using namespace std;

template <typename T>
void print_vector(const Vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	 	cout << vec[i] << " ";
	cout << endl;
	return;
}

// LINEAR SEARCH OF VECTOR
// return index at which target found, if not found  return -1;
template <typename T>
int linear_search_V(const Vector<T>& vec, const T& target, int& ops1)
{
	for (int i = 0; i < vec.size(); i++)
	{
		ops1++;
		if (vec[i] == target)
			return i;
	}
	return -1; // not found 
}

// LINEAR SEARCH OF LINKED LIST
// return iterator to node at which target
// found in lst; else return iterator at end() of lst;
template <typename T>
typename List<T>::const_iterator linear_search_L(const List<T>& lst, const T& target, int& ops2)
{
	typename List<T>::const_iterator itr;
	for (itr = lst.begin(); itr != lst.end(); ++itr)
	{
		ops2++;
		if (*itr == target)
			return itr;
	}
	return lst.end();  
}

// BINARY SEARCH OF VECTOR;
// returns index at which target found, else -1;
template <typename T>
int binary_search_V(const Vector<T>& vec, const T& target, int& ops3)
{
	int low = 0;
	int high = vec.size() - 1;
	while (low <= high)
	{
		ops3++;
		int mid = (low + high) / 2;

		if (vec[mid] < target)
			low = mid + 1;   // next: search upper half
		else if (vec[mid] > target)
			high = mid - 1;  // next: search lower half
		else
			return mid;   // middle item is target; return mid
	}
	return -1;
}
#endif