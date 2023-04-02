#ifndef SET_FUNCTIONS_H_
#define SET_FUNCTIONS_H_
#include "BST_Set-1.h"

template <typename T>
Set<T> set_union(const Set<T>& set1, const Set<T>& set2)
{
    // code to produce set that is union of set1 and set2, which
    // is the set of all elements in set1 OR set2;
    Set<T> setU;
    Set<int>::const_iterator itr1;
    Set<int>::const_iterator itr2;
    for(itr1 = set1.begin(); itr1 != set1.end(); itr1++)
        setU.insert(*itr1);
    for(itr2 = set2.begin(); itr2 != set2.end(); itr2++)
        if(!setU.contains(*itr2))
            setU.insert(*itr2);
    return setU;
}

template <typename T>
Set<T> set_intersection(const Set<T>& set1, const Set<T>& set2)
{
    // code to produce set that is intersection of set1 and set2, which
    // is the set of all elements that are in set1 AND set2;
    Set<T> setI;
    Set<int>::const_iterator itr1;
    Set<int>::const_iterator itr2;
    for(itr1 = set1.begin(); itr1 != set1.end(); itr1++)
        for(itr2 = set2.begin(); itr2 != set2.end(); itr2++)
            if(*itr1 == *itr2)
                setI.insert(*itr2);
    return setI;
}

template <typename T>
Set<T> set_difference(const Set<T>& set1, const Set<T>& set2)
{
    // code to produce set that is intersection of set1 and set2, which
    // is the set of all elements that are in set1 AND set2;
    Set<T> setD;
    Set<int>::const_iterator itr1;
    Set<int>::const_iterator itr2;
    for(itr1 = set1.begin(); itr1 != set1.end(); itr1++)
        setD.insert(*itr1);
    for(itr2 = set2.begin(); itr2 != set2.end(); itr2++)
        if(setD.contains(*itr2))
            setD.remove(*itr2);
        else
            setD.insert(*itr2);
    /*
    for(itr1 = set1.begin(); itr1 != set1.end(); itr1++)
        for(itr2 = set2.begin(); itr2 != set2.end(); itr2++)
            if(*itr1 != *itr2)
                setD.insert(*itr1);
    */
    return setD;
}
#endif