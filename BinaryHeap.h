#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <cassert>
#include "Vector.h"
using namespace std;

template <typename T>
class BinaryHeap
{
    public:
        BinaryHeap(int capacity = 100) : theHeap(capacity + 1), theSize{0} {}
        BinaryHeap(const Vector<T> & items) : theHeap(items.size() + 10), theSize{items.size()}
            {
                for (int i = 0; i < items.size(); ++i)
                    theHeap[i + 1] = items[i];
                buildHeap();
            }
        bool empty() const
            {return theSize == 0;}
        const T & findMin() const
        {
            assert(!theHeap.empty());
            return theHeap[1];
        }
        void insert(const T & x)
        {
            if (theSize == theHeap.size() - 1)
                theHeap.resize(theHeap.size() * 2);
                    int hole = theSize + 1;
            theSize++;

            T copy = x;
            theHeap[0] = copy;
            for (; x < theHeap[hole / 2]; hole /= 2)
                theHeap[hole] = theHeap[hole / 2];
            
            theHeap[hole] = theHeap[0];
        }
        void deleteMin()
        {
            assert(!theHeap.empty());
            theHeap[1] = theHeap[theSize];
            theSize--;
            percolateDown(1);
        }
        void deleteMin(T & minItem)
        {
            assert(!theHeap.empty());
            minItem = theHeap[1];
            theHeap[1] = theHeap[theSize];
            theSize--;
            percolateDown(1);
        }
        void makeEmpty()
        {theSize = 0;}
        void printHeap()
        {
            cout << endl;
            if (empty())
                cout << "Empty heap";
            else
                printHeap(1, 0);
            cout << endl;
        }
    private:
        int theSize;
        Vector<T> theHeap;

        void buildHeap()
        {
            for (int i = theSize / 2; i > 0; --i)
                percolateDown(i);
        }
        void printHeap(int index, int offset)
        {
            if (index > theSize)
                return;
            for (int i = 1; i <= offset; i++)
                cout << "..";
            cout << theHeap[index] << endl;
            printHeap(2 * index, offset + 1);
            printHeap(2 * index + 1, offset + 1);
        }
        void percolateDown(int hole)
        {
            int child;
            T tmp = theHeap[hole];
            for (; hole * 2 <= theSize; hole = child)
            {
                child = hole * 2;
                if (child != theSize && theHeap[child + 1] < theHeap[child])
                    child++;
                if (theHeap[child] < tmp)
                    theHeap[hole] = theHeap[child];
                else
                    break;
            }
            theHeap[hole] = tmp;
        }
};

#endif