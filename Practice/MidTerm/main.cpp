#include "Collection.h"
#include "Scale2D.h"

int main() {
    // Example A: Instantiating with your custom Scale2D elements
    Scale2D lScaleArray[] = { Scale2D(1.2f, 3.4f), Scale2D(5.6f, 7.8f) };
    Collection<Scale2D> lScaleCollection(lScaleArray, 2);
    
    lScaleCollection[0] = Scale2D(2.0f, 2.0f);          // Integer lookup modification
    lScaleCollection["1"] = Scale2D(10.0f, 10.0f);      // String associative lookup modification
    std::cout << lScaleCollection << std::endl;         // Prints out: [{2, 2}, {10, 10}]

    // Example B: Instantiating with primitive integers to prove template behavior [cite: 72]
    int lIntArray[] = { 10, 20, 30 };
    Collection<int> lIntCollection(lIntArray, 3);
    std::cout << lIntCollection << std::endl;           // Prints out: [10, 20, 30]
    
    return 0;
}
