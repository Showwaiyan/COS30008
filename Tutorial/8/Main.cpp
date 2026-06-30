#include <iostream>
#include <string>
#include <utility>
#include "InkLinkedList.h"
#include "MyIterator.h"

// Helper structure to track copy and move constructions
struct MoveTracked {
    static int copyCount;
    static int moveCount;

    int value;

    explicit MoveTracked(int val) : value(val) {}
    MoveTracked(const MoveTracked& other) : value(other.value) {
        copyCount++;
    }
    MoveTracked(MoveTracked&& other) noexcept : value(other.value) {
        moveCount++;
    }
    MoveTracked& operator=(const MoveTracked&) = default;
    MoveTracked& operator=(MoveTracked&&) = default;
};

int MoveTracked::copyCount = 0;
int MoveTracked::moveCount = 0;

// Helper to safely get the address of getNext() without compiler warnings about null references
template <typename T>
const IntLinkedList<T>* getNextAddress(const IntLinkedList<T>& node) {
    const IntLinkedList<T>* ptr = &node.getNext();
    return ptr;
}

void resetTracker() {
    MoveTracked::copyCount = 0;
    MoveTracked::moveCount = 0;
}

// Global test tracker variables
int testsRun = 0;
int testsPassed = 0;

#define RUN_TEST(testFunc) \
    do { \
        testsRun++; \
        std::cout << "[RUN] " << #testFunc << std::endl; \
        try { \
            if (testFunc()) { \
                std::cout << "  [PASS] " << #testFunc << std::endl; \
                testsPassed++; \
            } else { \
                std::cerr << "  [FAIL] " << #testFunc << " (returned false)" << std::endl; \
            } \
        } catch (const std::exception& e) { \
            std::cerr << "  [FAIL] " << #testFunc << " (threw exception: " << e.what() << ")" << std::endl; \
        } catch (...) { \
            std::cerr << "  [FAIL] " << #testFunc << " (threw unknown exception)" << std::endl; \
        } \
    } while (0)

// Test 1: Verify l-value copy constructor, r-value move constructor, and dereference operator
bool testConstructorsAndDereference() {
    resetTracker();
    
    // Test 1a: L-value constructor (should copy fData)
    MoveTracked src(42);
    IntLinkedList<MoveTracked> node1(src);
    
    if ((*node1).value != 42) {
        std::cerr << "    Error: Dereference of node1 returned value " << (*node1).value << ", expected 42" << std::endl;
        return false;
    }
    if (MoveTracked::copyCount != 1) {
        std::cerr << "    Error: L-value constructor did not copy fData. Copy count: " << MoveTracked::copyCount << std::endl;
        return false;
    }
    if (MoveTracked::moveCount != 0) {
        std::cerr << "    Error: L-value constructor unexpectedly triggered move. Move count: " << MoveTracked::moveCount << std::endl;
        return false;
    }
    
    // Test 1b: R-value constructor (should move fData)
    IntLinkedList<MoveTracked> node2(MoveTracked(100));
    
    if ((*node2).value != 100) {
        std::cerr << "    Error: Dereference of node2 returned value " << (*node2).value << ", expected 100" << std::endl;
        return false;
    }
    if (MoveTracked::moveCount != 1) {
        std::cerr << "    Error: R-value constructor did not move fData. Move count: " << MoveTracked::moveCount << std::endl;
        return false;
    }

    // Test 1c: Basic pointer initialization to null
    const IntLinkedList<MoveTracked>* nextPtr = getNextAddress(node1);
    if (nextPtr != nullptr) {
        std::cerr << "    Error: Newly constructed node's next pointer is not nullptr" << std::endl;
        return false;
    }

    return true;
}

// Test 2: Verify push_back and getNext methods for traversal
bool testPushBackAndTraversal() {
    IntLinkedList<std::string> nodeA("First");
    IntLinkedList<std::string> nodeB("Second");
    IntLinkedList<std::string> nodeC("Third");

    // Initially all next pointers should be null
    if (getNextAddress(nodeA) != nullptr || getNextAddress(nodeB) != nullptr || getNextAddress(nodeC) != nullptr) {
        std::cerr << "    Error: Initial next pointers are not null" << std::endl;
        return false;
    }

    // Push nodeB onto nodeA
    nodeA.push_back(nodeB);
    if (getNextAddress(nodeA) != &nodeB) {
        std::cerr << "    Error: nodeA's next does not point to nodeB after push_back" << std::endl;
        return false;
    }
    if (getNextAddress(nodeB) != nullptr) {
        std::cerr << "    Error: nodeB's next changed unexpectedly" << std::endl;
        return false;
    }

    // Push nodeC onto nodeA (should traverse to the end and append to nodeB)
    nodeA.push_back(nodeC);
    if (getNextAddress(nodeA) != &nodeB) {
        std::cerr << "    Error: nodeA's next changed after second push_back" << std::endl;
        return false;
    }
    if (getNextAddress(nodeB) != &nodeC) {
        std::cerr << "    Error: nodeC was not appended to the end of the chain (nodeB's next)" << std::endl;
        return false;
    }
    if (getNextAddress(nodeC) != nullptr) {
        std::cerr << "    Error: nodeC's next is not null" << std::endl;
        return false;
    }

    // Traverse and verify data sequence
    const IntLinkedList<std::string>* current = &nodeA;
    if (*(*current) != "First") return false;
    
    current = getNextAddress(*current);
    if (current == nullptr || *(*current) != "Second") return false;
    
    current = getNextAddress(*current);
    if (current == nullptr || *(*current) != "Third") return false;
    
    current = getNextAddress(*current);
    if (current != nullptr) {
        std::cerr << "    Error: Traversal did not terminate with nullptr" << std::endl;
        return false;
    }

    return true;
}

// Test 3: Test with standard integers type
bool testIntType() {
    IntLinkedList<int> head(1);
    IntLinkedList<int> second(2);
    IntLinkedList<int> third(3);

    head.push_back(second);
    head.push_back(third);

    int expectedValues[] = {1, 2, 3};
    const IntLinkedList<int>* current = &head;
    for (int i = 0; i < 3; i++) {
        if (current == nullptr) {
            std::cerr << "    Error: List shorter than expected at index " << i << std::endl;
            return false;
        }
        if (*(*current) != expectedValues[i]) {
            std::cerr << "    Error: Node value at index " << i << " is " << *(*current) << ", expected " << expectedValues[i] << std::endl;
            return false;
        }
        current = getNextAddress(*current);
    }
    if (current != nullptr) {
        std::cerr << "    Error: List longer than expected" << std::endl;
        return false;
    }

    return true;
}

// Test 4: Verify MyIterator construction, dereference, increment, equality, and traversal
bool testIteratorBasicAndTraversal() {
    IntLinkedList<int> head(10);
    IntLinkedList<int> second(20);
    IntLinkedList<int> third(30);

    head.push_back(second);
    head.push_back(third);

    // Create iterator
    MyIterator<int> it(&head);

    // Test operator*
    if (*it != 10) {
        std::cerr << "    Error: Iterator dereference returned " << *it << ", expected 10" << std::endl;
        return false;
    }

    // Test prefix increment
    auto itPrefix = ++it;
    if (*it != 20 || *itPrefix != 20) {
        std::cerr << "    Error: Prefix increment failed. *it: " << *it << ", *itPrefix: " << *itPrefix << std::endl;
        return false;
    }

    // Test postfix increment
    auto itPostfix = it++;
    if (*itPostfix != 20 || *it != 30) {
        std::cerr << "    Error: Postfix increment failed. *itPostfix: " << *itPostfix << ", *it: " << *it << std::endl;
        return false;
    }

    // Move to end (increment once more)
    it++;
    
    // Create end iterator
    MyIterator<int> endItr = MyIterator<int>(&head).end();
    if (it != endItr) {
        std::cerr << "    Error: Iterator did not equal end() iterator at the end of the list" << std::endl;
        return false;
    }

    // Test begin() and end() with standard loop traversal
    int expectedValues[] = {10, 20, 30};
    int count = 0;
    
    MyIterator<int> startItr(&head);
    for (auto loopIt = startItr.begin(); loopIt != startItr.end(); ++loopIt) {
        if (count >= 3) {
            std::cerr << "    Error: Loop ran longer than 3 elements" << std::endl;
            return false;
        }
        if (*loopIt != expectedValues[count]) {
            std::cerr << "    Error: Value at index " << count << " is " << *loopIt << ", expected " << expectedValues[count] << std::endl;
            return false;
        }
        count++;
    }

    if (count != 3) {
        std::cerr << "    Error: Traversal visited " << count << " nodes, expected 3" << std::endl;
        return false;
    }

    return true;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Running IntLinkedList and MyIterator Tests..." << std::endl;
    std::cout << "========================================" << std::endl;

    RUN_TEST(testConstructorsAndDereference);
    RUN_TEST(testPushBackAndTraversal);
    RUN_TEST(testIntType);
    RUN_TEST(testIteratorBasicAndTraversal);

    std::cout << "========================================" << std::endl;
    std::cout << "Test Summary: " << testsPassed << " / " << testsRun << " passed." << std::endl;
    std::cout << "========================================" << std::endl;

    if (testsPassed == testsRun) {
        std::cout << "ALL TESTS PASSED SUCCESSFULLY!" << std::endl;
        return 0;
    } else {
        std::cerr << "SOME TESTS FAILED." << std::endl;
        return 1;
    }
}
