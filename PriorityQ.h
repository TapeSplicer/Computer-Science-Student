#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include "BinaryHeap.h"
using namespace std;

template <typename T>
class PriorityQueue
{
    public:
        PriorityQueue() {}
        int size() const {return priorq.size();}
        bool empty() const {return priorq.empty();}
        void push(const T & x) {priorq.insert(x);}
        void pop() {priorq.deleteMin();}
        const T & top() {return priorq.findMin();}
    private:
        BinaryHeap<T> priorq;
};
#endif