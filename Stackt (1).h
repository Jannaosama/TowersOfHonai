#pragma once

#ifndef STACKT_H
#define STACKT_H

template <class Type>
class Stackt
{
public:
    Stackt(int nelements = 128); // Constructor
    
    // Member Functions
    void push(Type v); // Push
    void pop(Type& v); // Pop

private:
    Type* stack; // Pointer to dynamic array
    int top, MaxSize;
};

// Tower of Hanoi function declaration
void towerOfHanoi(int nelements, Stackt<int>& source, Stackt<int>& target, Stackt<int>& auxiliary, int& count);

#endif // STACKT_H
