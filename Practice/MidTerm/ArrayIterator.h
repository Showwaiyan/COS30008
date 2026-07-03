#pragma once
#include <cassert>

template <typename T>
class ArrayIterator {
private:
    const T* fSet;          // Non-owning pointer to the native array elements
    int fLength;            // Total number of elements in the array
    int fIndex;             // Current sequence position tracker cursor

public:
    // Constructor handles baseline array binding and positions the cursor
    ArrayIterator(const T aSet[], int aLength, int aStart = 0) noexcept;

    // TODO TASK 1: DEREFERENCE OPERATOR
    // Overload the prefix dereference operator* to return a read-only const reference to the current item.
    // Remember to use an 'assert' statement to prevent out-of-bounds dereferencing!
    const ArrayIterator<T>& operator*() {
      assert(fIndex >= 0 && fIndex < fLength);
      return const_cast<T&>(fSet[fIndex]);
    }


    // TODO TASK 2: PREFIX INCREMENT OPERATOR (++itr)
    // Overload the prefix operator++ to advance the index safely and return an lvalue reference to *this.
    ArrayIterator<T>& operator++() {
      if (fIndex < fLength) {
        ++fIndex;
      }
      return *this;
    }
    

    // TODO TASK 3: POSTFIX INCREMENT OPERATOR (itr++)
    // Overload the postfix operator++ (takes a dummy int token). 
    // It must clone a snapshot copy of the current state, increment itself using prefix, and return the snapshot by value.
    ArrayIterator<T>& operator++(int) {
      ArrayIterator<T> temp = *this;
      ++(*this);
      return temp;
    }
    

    // TODO TASK 4: EQUALITY OPERATORS
    // Overload operator== and operator!=. Two iterators are equal if they share the same array base pointer and index.
    

    // TODO TASK 5: BOUNDARY ACCESSORS
    // Implement begin() and end() functions to return configured boundary tracker instances.
    
};
