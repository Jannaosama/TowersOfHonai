#include <iostream>
#include "Stackt.h"  // Include your Stackt.h header

using namespace std;

template <class Type>
Stackt<Type>::Stackt(int nelements) {
    MaxSize = nelements;
    stack = new Type[MaxSize];
    top = -1;
}

template <class Type>
void Stackt<Type>::push(Type v) {
    stack[++top] = v;
}

template <class Type>
void Stackt<Type>::pop(Type& v) {
    v = stack[top--];
}

void towerOfHanoi(int nelements, Stackt<int>& source, Stackt<int>& target, Stackt<int>& auxiliary, int& count ,const string& sourceName, const string& targetName, const string& auxiliaryName) {
    if (nelements == 0) {
        return;
    }

    towerOfHanoi(nelements - 1, source, auxiliary, target, count, sourceName, auxiliaryName, targetName);
    int disk;
    source.pop(disk);
    target.push(disk);
    cout << "Move disk " << nelements << " from peg " << sourceName << " to peg " << targetName << endl;
    count++;
    towerOfHanoi(nelements - 1, auxiliary, target, source, count, auxiliaryName, targetName, sourceName);
}

int main() {
    int nelements;
    cout << "Enter number of disks: ";
    cin >> nelements;
    int count = 0;

    Stackt<int> A(nelements);
    Stackt<int> B(nelements);
    Stackt<int> C(nelements);

    towerOfHanoi(nelements, A, C, B, count, "A", "B","C");

    cout <<"All the disks were moved successfully from Peg A to Peg C with total moves: " << count << endl;

    return 0;
}
