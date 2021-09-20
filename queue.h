
#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 
    void enqueue(): push_front();
    int dequeue(): pop_back();
};