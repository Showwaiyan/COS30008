#pragma once
#include <cassert>
#include <cstddef>
#include <string>
#include <iostream>

// =======================================================================
// 1. FORWARD DECLARATIONS (Required for Template Friend Operators)
// =======================================================================
template <typename T>
class Collection;

template <typename T>
std::ostream& operator<<(std::ostream& aOStream, const Collection<T>& aCollection);


// =======================================================================
// 2. TEMPLATE CLASS SPECIFICATION
// =======================================================================
template <typename T>
class Collection {
private:
    T* fArray;              // Non-owning pointer to an array of generic objects
    size_t fSize;           // The capacity/size of the adapted array

public:
    // Type alias matching container traits conventions
    using value_type = T;

    // Constructor
    // TODO: Map parameters directly to internal attributes using an initializer list
    Collection(T aArray[], size_t aSize) noexcept : fArray(aArray), fSize(aSize) {};
    
    // Size Accessor
    size_t size() const noexcept {return fSize;};

    // TODO TASK 1: INTEGER INDEX OPERATOR (Array Semantics)
    // Overload the subscript operator to accept a size_t index and return a mutable reference.
    // Inside the body, remember to execute an 'assert' statement for boundary verification.
    T& operator[](size_t aIndex) {
      assert(aIndex < fSize);
      return fArray[aIndex];
    }

    

    // TODO TASK 2: STRING INDEX OPERATOR (Associative Semantics)
    // Overload the subscript operator to accept a key of type const std::string& and return a mutable reference.
    // Parse numeric characters, convert to base-10 shifts, and delegate to the integer index operator above.
    T& operator[](std::string aKey) {
      size_t lIndex = 0;
      for (size_t i=0; i<aKey.size(); i++) {
       lIndex = (lIndex * 10) + (static_cast<size_t>(aKey[i])-'0');
      }
      return Collection<T>::operator[](lIndex);
    }
    

    // TODO TASK 3: STREAM OUTPUT FRIEND DECLARATION
    // Complete the generic stream insertion friend match hook below to map to out-of-class templates
    friend std::ostream& operator<< <T>(std::ostream& aOStream, const Collection<T>& aCollection);
};


// =======================================================================
// 3. OUT-OF-CLASS FRIEND TEMPLATE DEFINITION
// =======================================================================
// TODO TASK 4: IMPLEMENT STREAM OUTPUT OPERATOR
// Implement the non-member function template to output your collection elements wrapped in square
// brackets, separated by a comma and a space (e.g., [elem1, elem2, elem3]).
template <typename T>
std::ostream& operator<<(std::ostream& aOStream, const Collection<T>& aCollection) {
    // Write your implementation loop here...
    aOStream << "Good"  << std::endl;
    return aOStream;
}
