#include <iostream>
#include "SinglyLinkedList.h"

void testFreeFunctions() {
    std::cout << "========================================" << std::endl;
    std::cout << "Testing using Free Functions Paradigm" << std::endl;
    std::cout << "========================================" << std::endl;

    SinglyLinkedList<int>* list = nullptr;

    std::cout << "1. Display empty list:" << std::endl;
    display(list);

    std::cout << "\n2. Adding to front: 10, 20" << std::endl;
    addFront(list, 10);
    addFront(list, 20);
    display(list); // Expected: 20 -> 10

    std::cout << "\n3. Adding to back: 30, 40" << std::endl;
    addBack(list, 30);
    addBack(list, 40);
    display(list); // Expected: 20 -> 10 -> 30 -> 40

    std::cout << "\n4. Inserting 15 at position 1 (0-indexed)" << std::endl;
    insert(list, 15, 1);
    display(list); // Expected: 20 -> 15 -> 10 -> 30 -> 40

    std::cout << "\n5. Inserting 5 at position 0" << std::endl;
    insert(list, 5, 0);
    display(list); // Expected: 5 -> 20 -> 15 -> 10 -> 30 -> 40

    std::cout << "\n6. Inserting 50 at position 10 (out of bounds, appends to back)" << std::endl;
    insert(list, 50, 10);
    display(list); // Expected: 5 -> 20 -> 15 -> 10 -> 30 -> 40 -> 50

    std::cout << "\n7. Removing from front" << std::endl;
    removeFront(list);
    display(list); // Expected: 20 -> 15 -> 10 -> 30 -> 40 -> 50

    std::cout << "\n8. Removing from back" << std::endl;
    removeBack(list);
    display(list); // Expected: 20 -> 15 -> 10 -> 30 -> 40

    std::cout << "\n9. Clearing list" << std::endl;
    clear(list);
    display(list); // Expected: [Empty List]
}

void testMemberFunctions() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Testing using Member Functions Paradigm" << std::endl;
    std::cout << "========================================" << std::endl;

    // Start with a single node (since non-static member functions operate on an existing object instance)
    std::cout << "1. Creating head node with value 100" << std::endl;
    SinglyLinkedList<int>* head = new SinglyLinkedList<int>(100);
    head->display();

    std::cout << "\n2. Member addFront: 90" << std::endl;
    head = head->addFront(90);
    head->display(); // Expected: 90 -> 100

    std::cout << "\n3. Member addBack: 110, 120" << std::endl;
    head->addBack(110);
    head->addBack(120);
    head->display(); // Expected: 90 -> 100 -> 110 -> 120

    std::cout << "\n4. Member insert: 105 at position 2" << std::endl;
    head = head->insert(105, 2);
    head->display(); // Expected: 90 -> 100 -> 105 -> 110 -> 120

    std::cout << "\n5. Member removeFront" << std::endl;
    head = head->removeFront();
    head->display(); // Expected: 100 -> 105 -> 110 -> 120

    std::cout << "\n6. Member removeBack" << std::endl;
    head = head->removeBack();
    head->display(); // Expected: 100 -> 105 -> 110

    // Cleanup remaining nodes
    SinglyLinkedList<int>::clear(head);
    std::cout << "Done testing member functions." << std::endl;
}

int main() {
    testFreeFunctions();
    testMemberFunctions();
    return 0;
}
