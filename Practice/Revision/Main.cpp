#include <iostream>
#include <cassert>
#include <string>
#include "LinkList.h"
#include "LinkListIterator.h"
#include "DoublyLinkList.h"

// ==========================================
// TEST CONFIGURATION
// Uncomment the sections you want to test
// ==========================================
#define TEST_SECTION_1 // ListNode creation & constructors
#define TEST_SECTION_2 // MyLinkedList constructor and basic instantiations
#define TEST_SECTION_3 // addFront implementation
#define TEST_SECTION_4 // addBack implementation
#define TEST_SECTION_5 // deleteFront implementation
#define TEST_SECTION_6 // deleteBack implementation
#define TEST_SECTION_7 // Integration / Edge Cases (Empty lists, mixed operations)
#define TEST_SECTION_8 // LinkedListIterator constructor and basic dereference
#define TEST_SECTION_9 // LinkedListIterator increment operators
#define TEST_SECTION_10 // LinkedListIterator comparison operators
#define TEST_SECTION_11 // Doubly LinkedList insertion tests
#define TEST_SECTION_12 // Doubly LinkedList deletion tests

// Since front and back are private in MyLinkedList, you can either:
// 1. Add friend class / debug helper in MyLinkedList, or
// 2. Add getter methods.
// Here we assume standard helper functions or that you can adapt these tests
// by implementing getFront() and getBack() or adding friend declarations.

int main() {
  std::cout << "Starting MyLinkedList Test Suite..." << std::endl;

#ifdef TEST_SECTION_1
  std::cout << "\n--- Section 1: ListNode Tests ---" << std::endl;
  {
    // Test copy constructor (const T&)
    int val1 = 42;
    ListNode<int> node1(val1);
    assert(node1.data == 42);
    assert(node1.next == nullptr);
    std::cout << "ListNode copy constructor test passed." << std::endl;

    // Test move constructor (const T&& / std::move)
    std::string str = "Hello Move";
    ListNode<std::string> node2(std::move(str));
    assert(node2.data == "Hello Move");
    assert(node2.next == nullptr);
    std::cout << "ListNode move constructor test passed." << std::endl;
  }
#endif

#ifdef TEST_SECTION_2
  std::cout << "\n--- Section 2: MyLinkedList Constructor Tests ---"
            << std::endl;
  {
    MyLinkedList<int> list;
    // Verify list is initialized correctly (front and back should be nullptr)
    assert(list.getFront() == nullptr);
    assert(list.getBack() == nullptr);
    std::cout << "MyLinkedList instantiated successfully." << std::endl;
  }
#endif

#ifdef TEST_SECTION_3
  std::cout << "\n--- Section 3: addFront Tests ---" << std::endl;
  {
    MyLinkedList<int> list;
    list.addFront(10);
    assert(list.getFront() != nullptr);
    assert(list.getFront()->data == 10);
    std::cout << "Added 10 to front." << std::endl;

    list.addFront(20);
    assert(list.getFront() != nullptr);
    assert(list.getFront()->data == 20);
    assert(list.getFront()->next != nullptr);
    assert(list.getFront()->next->data == 10);
    std::cout << "Added 20 to front." << std::endl;

    std::cout << "addFront test complete." << std::endl;
  }
#endif

#ifdef TEST_SECTION_4
  std::cout << "\n--- Section 4: addBack Tests ---" << std::endl;
  {
    MyLinkedList<int> list;
    list.addBack(100);
    assert(list.getBack() != nullptr);
    assert(list.getBack()->data == 100);
    std::cout << "Added 100 to back." << std::endl;
    list.addBack(200);
    assert(list.getBack() != nullptr);
    assert(list.getBack()->data == 200);
    std::cout << "Added 200 to back." << std::endl;
    std::cout << "addBack test complete." << std::endl;
  }
#endif

#ifdef TEST_SECTION_5
  std::cout << "\n--- Section 5: deleteFront Tests ---" << std::endl;
  {
    MyLinkedList<int> list;
    list.addFront(5);
    list.addFront(10);

    list.deleteFront();
    std::cout << "Deleted from front once." << std::endl;

    list.deleteFront();
    std::cout << "Deleted from front twice." << std::endl;
    std::cout << "deleteFront test complete." << std::endl;
  }
#endif

#ifdef TEST_SECTION_6
  std::cout << "\n--- Section 6: deleteBack Tests ---" << std::endl;
  {
    MyLinkedList<int> list;
    list.addBack(50);
    list.addBack(60);

    list.deleteBack();
    std::cout << "Deleted from back once." << std::endl;

    list.deleteBack();
    std::cout << "Deleted from back twice." << std::endl;
    std::cout << "deleteBack test complete." << std::endl;
  }
#endif

#ifdef TEST_SECTION_7
  std::cout << "\n--- Section 7: Integration & Edge Cases ---" << std::endl;
  {
    MyLinkedList<int> list;

    // Edge Case: Deleting from an empty list
    std::cout << "Attempting to deleteFront from empty list..." << std::endl;
    list.deleteFront();
    std::cout << "Attempting to deleteBack from empty list..." << std::endl;
    list.deleteBack();

    // Add, delete, and add again
    list.addFront(1);
    list.deleteFront();
    list.addBack(2);
    list.deleteBack();

    std::cout << "Integration and edge case tests complete." << std::endl;
  }
#endif
#ifdef TEST_SECTION_8
    std::cout << "\n--- Section 8: LinkedListIterator Basics ---" << std::endl;
    {
        MyLinkedList<int> list;
        list.addFront(42);
        
        LinkedListIterator<int> it(list.getFront());
        LinkedListIterator<int> startIt = it.begin();
        LinkedListIterator<int> endIt = it.end();

        // Test dereference on begin
        assert(*startIt == 42);
        std::cout << "LinkedListIterator basic instantiation and dereferencing passed." << std::endl;
    }
#endif

#ifdef TEST_SECTION_9
    std::cout << "\n--- Section 9: LinkedListIterator Increments ---" << std::endl;
    {
        MyLinkedList<int> list;
        list.addFront(10);
        list.addFront(20);
        list.addFront(30);

        LinkedListIterator<int> it(list.getFront());
        LinkedListIterator<int> startIt = it.begin();

        // Test post-increment
        assert(*(startIt++) == 30);
        assert(*startIt == 20);

        // Test pre-increment
        assert(*(++startIt) == 10);
        
        std::cout << "LinkedListIterator increment operators passed." << std::endl;
    }
#endif

#ifdef TEST_SECTION_10
    std::cout << "\n--- Section 10: LinkedListIterator Comparisons ---" << std::endl;
    {
        MyLinkedList<int> list;
        list.addFront(100);

        LinkedListIterator<int> it(list.getFront());
        LinkedListIterator<int> startIt = it.begin();
        LinkedListIterator<int> endIt = it.end();

        // Test equality & inequality
        assert(startIt != endIt);
        
        startIt++;
        assert(startIt == endIt);

        std::cout << "LinkedListIterator comparison operators passed." << std::endl;
    }
#endif
#ifdef TEST_SECTION_11
    std::cout << "\n--- Section 11: Doubly LinkedList Insertion ---" << std::endl;
    {
        NodePtr first = nullptr;
        addToBack(first, 10);
        addToBack(first, 20);
        addToBack(first, 30);
        
        assert(first != nullptr);
        assert(first->data == 10);
        assert(first->next != nullptr);
        assert(first->next->data == 20);
        assert(first->next->next != nullptr);
        assert(first->next->next->data == 30);
        assert(first->next->next->next == nullptr);
        assert(first->next->previous == first);

        addToFront(first, 40);
        addToFront(first, 50);

        assert(first != nullptr);
        assert(first->data == 50);
        assert(first->next->data == 40);
        assert(first->next->next->data == 10);
        
        std::cout << "Doubly LinkedList Insertion tests passed." << std::endl;
    }
#endif

#ifdef TEST_SECTION_12
    std::cout << "\n--- Section 12: Doubly LinkedList Deletion ---" << std::endl;
    {
        NodePtr first = nullptr;
        addToBack(first, 10);
        addToBack(first, 20);
        addToBack(first, 30);
        addToFront(first, 40);
        addToFront(first, 50);

        removeBack(first);
        assert(first->data == 50);
        assert(first->next->next->next->data == 20);
        assert(first->next->next->next->next == nullptr);

        removeFront(first);
        assert(first->data == 40);
        assert(first->previous == nullptr);
        assert(first->next->data == 10);

        std::cout << "Doubly LinkedList Deletion tests passed." << std::endl;
    }
#endif

    std::cout << "\nAll enabled tests finished running successfully."
              << std::endl;
    return 0;
}
