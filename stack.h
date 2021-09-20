#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> { 
    void push(): push_front();
    int pop(): pop_front();
};