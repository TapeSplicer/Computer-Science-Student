#ifndef SEARCHING_H_
#define SEARCHING_H_
#include "List.h"
#include "Vector.h"
using namespace std;

//return index at which target found
//if not found, return -1
template <typename T>
int linear_search_V(const Vector<T>& vec, const T& target)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == target)
            return i;
    }
    return -1; //not found
}

//return iterator under which target is found in list
//else return end() iterator
template <typename T>
typename List<T>::const_iterator linear_search_L(const List<T>& lst, const T& target)
{
    typename List<T>::const_iterator itr;
    for (itr = lst.begin(); itr != lst.end(); ++itr)
    {
        if (*itr == target)
            return itr;
    }
    return lst.end();
}

template <typename T>
int rec_linear_search_V(int k, const Vector<T>& vec, const T& target)
{
    if (vec.empty() || k >= vec.size())
        return -1;
    if (vec[k] == target)
        return k;
    return rec_linear_search_V(k + 1, vec, target);
}

template <typename T>
typename List<T>::const_iterator rec_linear_search_L(typename List<T>::const_iterator itr, const List<T>& lst, const T& target)
{
    if (itr == lst.end() || lst.empty())
        return lst.end();
    
    if (*itr == target)
        return itr;
    ++itr;
    return rec_linear_search_L(itr, lst, target);
}

//Binary search of vector
template <typename T>
int binary_search_V(const Vector<T>& vec, const T& target)
{
    int low = 0;
    int high = vec.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (vec[mid] < target)
            low = mid + 1;
        else if (vec[mid] > target)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

//Binary recursive search of vector
template <typename T>
int rec_binary_search_V(int low, int high, const Vector<T>& vec, const T& target)
{
    if (low > high || vec.empty())
        return -1;
    int mid = (low + high)/2;

    if (vec[mid] == target)
        return mid;
    if (vec[mid] > target)
        return rec_binary_search_V(low, mid - 1, vec, target);
    else
        return rec_binary_search_V(mid + 1, high, vec, target);
}
#endif