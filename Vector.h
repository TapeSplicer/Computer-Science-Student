#ifndef VECTOR_H_
#define VECTOR_H_
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Vector
{
    public:
        Vector(int initSize = 0) : theSize(initSize), theCapacity(initSize + Spare_Capacity)
        {
            data = new T[theCapacity];
        }
        Vector(int initSize, int initVal) : theSize(initSize), theCapacity(initSize + Spare_Capacity)
        {
            data = new T[theCapacity];
            for (int i = 0; i < theCapacity; i++)
                data[i] = initVal;
        }
        Vector(const Vector& rhs) : theSize(rhs.theSize), theCapacity(rhs.theCapacity), data(nullptr)
        {
            data = new T[theCapacity];
            for (int k = 0; k < theSize; k++)
                data[k] = rhs.data[k];
        }
        Vector& operator = (const Vector& rhs)
        {
            Vector copy = rhs;
            swap(*this, copy);
            return *this;
        }
        Vector(Vector&& rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, data{rhs.data}
        {
            rhs.data = nullptr;
            rhs.theSize = 0;
            rhs.theCapacity = 0;
        }
        Vector& operator = (Vector&& rhs)
        {
            swap(theSize, rhs.theSize);
            swap(theCapacity, rhs.theCapacity);
            swap(data, rhs.data);
            return *this;
        }
        ~Vector()
        {
            delete[] data;
        }
        bool empty() const
        {
            return size() == 0;
        }
        int size() const
        {
            return theSize;
        }
        int capacity() const
        {
            return theCapacity;
        }
        T& operator[](int index)
        {
            assert(index >= 0 && index < theSize);
            return data[index];
        }
        const T& operator[](int index) const
        {
            assert(index >= 0 && index < theSize);
            return data[index];
        }
        void resize(int newSize)
        {
            if (newSize > theCapacity)
                reserve(newSize * 2);
            theSize = newSize;
        }
        void reserve(int newCapacity)
        {
            if (newCapacity < theSize)
                return;
            T* newArray = new T[newCapacity];
            for (int k = 0; k < theSize; k++)
                newArray[k] = move(data[k]);
            theCapacity = newCapacity;
            swap(data, newArray);
            delete[] newArray;
        }
        void push_back(const T& x)
        {
            if (theSize == theCapacity)
                reserve(2 * theCapacity + 1);
            data[theSize++] = x;
        }
        void pop_back()
        {
            assert(theSize >= 1);
            --theSize;
        }
        void clear()
        {
            theSize = 0;
        }
        const T& back() const
        {
            assert(theSize >= 1);
            return data[theSize - 1];
        }
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef T value_type;
        iterator begin()
        {
            return &data[0];
        }
        const_iterator begin() const
        {
            return &data[0];
        }
        iterator end()
        {
            return &data[size()];
        }
        const_iterator end() const
        {
            return &data[size()];
        }
        void erase(int index)
        {
            assert(index >= 0 && index < theSize);
            if (index == theSize - 1)
            {
                pop_back();
                return;
            }
            for (int i = index + 1; i < theSize; i++)
            {
                data[i-1] = data[i];
            }
            pop_back();
            return;
        }
        void insert(iterator itr, int value)
        {
            if (itr == end())
            {
                push_back(value);
                return;
            }
            assert(itr >= begin() && itr < end());
            push_back(back());
            iterator itr1 = end() - 2;
            iterator itr2 = end() - 1;
            while (itr1 >= itr)
            {
                *itr2 = *itr1;
                itr1--;
                itr2--;
            }
            *itr = value;
            return;
        }
        static const int Spare_Capacity = 2;
    private:
        int theSize;
        int theCapacity;
        T* data;
};

#endif