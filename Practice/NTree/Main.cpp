#include <iostream>
#include <cassert>
#include <string>
#include <utility>
#include "NTree.h"
#include "BTree.h"

// Comment/Uncomment the lines below to enable/disable tests for specific sections
#define S1 // Constructors and operator*
// #define S2 // static node makeNode(Args&&...)
// #define S3 // leaf() and height() for basic leaves
// #define S4 // attach(), detach(), and operator[]
// #define S5 // height() for non-leaf trees
// #define S6 // swap()

int main() {
    std::cout << "Starting NTree Tests..." << std::endl;

#ifdef S1
    std::cout << "--- Testing S1: Constructors and operator* ---" << std::endl;
    {
        // Default/Key constructor
        NTree<int, 3> tree1(42);
        assert(*tree1 == 42);

        // Move constructor
        NTree<int, 3> tree2(std::move(tree1));
        assert(*tree2 == 42);

        // String tree to test object copy/move
        NTree<std::string, 2> stringTree("hello");
        assert(*stringTree == "hello");

        // BTree tests
        BTree<int> btree1(42);
        assert(*btree1 == 42);

        BTree<int> btree2(std::move(btree1));
        assert(*btree2 == 42);

        BTree<std::string> bstringTree("hello");
        assert(*bstringTree == "hello");
    }
    std::cout << "S1 Passed!" << std::endl;
#endif

#ifdef S2
    std::cout << "--- Testing S2: makeNode ---" << std::endl;
    {
        auto nodePtr = NTree<int, 3>::makeNode(99);
        assert(nodePtr != nullptr);
        assert(**nodePtr == 99);

        // BTree tests
        auto bnodePtr = BTree<int>::makeNode(99);
        assert(bnodePtr != nullptr);
        assert(**bnodePtr == 99);
    }
    std::cout << "S2 Passed!" << std::endl;
#endif

#ifdef S3
    std::cout << "--- Testing S3: leaf() and height() for leaf node ---" << std::endl;
    {
        NTree<int, 4> leafTree(10);
        assert(leafTree.leaf() == true);
        assert(leafTree.height() == 0);

        // BTree tests
        BTree<int> bleafTree(10);
        assert(bleafTree.leaf() == true);
        assert(bleafTree.height() == 0);
    }
    std::cout << "S3 Passed!" << std::endl;
#endif

#ifdef S4
    std::cout << "--- Testing S4: attach(), detach(), and operator[] ---" << std::endl;
    {
        NTree<int, 3> parent(1);
        auto child = NTree<int, 3>::makeNode(2);
        
        assert(parent.leaf() == true);
        
        // Attach child at index 0
        parent.attach(0, child);
        
        assert(parent.leaf() == false);
        assert(*(parent[0]) == 2);
        assert(child == nullptr); // attach should transfer ownership
        
        // Detach child
        auto detachedChild = parent.detach(0);
        assert(parent.leaf() == true);
        assert(detachedChild != nullptr);
        assert(**detachedChild == 2);

        // BTree tests
        BTree<int> bparent(1);
        auto bchildL = BTree<int>::makeNode(2);
        auto bchildR = BTree<int>::makeNode(3);

        assert(bparent.leaf() == true);
        assert(bparent.hasLeft() == false);
        assert(bparent.hasRight() == false);

        // Attach left & right
        bparent.attachLeft(bchildL);
        bparent.attachRight(bchildR);

        assert(bparent.leaf() == false);
        assert(bparent.hasLeft() == true);
        assert(bparent.hasRight() == true);
        assert(*(bparent.left()) == 2);
        assert(*(bparent.right()) == 3);
        assert(bchildL == nullptr);
        assert(bchildR == nullptr);

        // Detach left & right
        auto bdetachedL = bparent.detachLeft();
        auto bdetachedR = bparent.detachRight();

        assert(bparent.leaf() == true);
        assert(bparent.hasLeft() == false);
        assert(bparent.hasRight() == false);
        assert(bdetachedL != nullptr);
        assert(bdetachedR != nullptr);
        assert(**bdetachedL == 2);
        assert(**bdetachedR == 3);
    }
    std::cout << "S4 Passed!" << std::endl;
#endif

#ifdef S5
    std::cout << "--- Testing S5: height() for trees with children ---" << std::endl;
    {
        NTree<int, 3> root(1);
        auto child1 = NTree<int, 3>::makeNode(2);
        auto child2 = NTree<int, 3>::makeNode(3);
        
        root.attach(0, child1);
        root.attach(1, child2);
        
        // height should be 1 (root + longest path to child)
        assert(root.height() == 1);

        // Add a deeper grandchild
        auto grandchild = NTree<int, 3>::makeNode(4);
        root[0].attach(0, grandchild);
        
        // height should now be 2
        assert(root.height() == 2);

        // BTree tests
        BTree<int> broot(1);
        auto bchild1 = BTree<int>::makeNode(2);
        auto bchild2 = BTree<int>::makeNode(3);

        broot.attachLeft(bchild1);
        broot.attachRight(bchild2);

        assert(broot.height() == 1);

        auto bgrandchild = BTree<int>::makeNode(4);
        broot.left().attachLeft(bgrandchild);

        assert(broot.height() == 2);
    }
    std::cout << "S5 Passed!" << std::endl;
#endif

#ifdef S6
    std::cout << "--- Testing S6: swap() ---" << std::endl;
    {
        NTree<int, 2> treeA(10);
        NTree<int, 2> treeB(20);
        
        treeA.swap(treeB);
        
        assert(*treeA == 20);
        assert(*treeB == 10);

        // BTree tests
        BTree<int> btreeA(10);
        BTree<int> btreeB(20);

        btreeA.swap(btreeB);

        assert(*btreeA == 20);
        assert(*btreeB == 10);
    }
    std::cout << "S6 Passed!" << std::endl;
#endif

    std::cout << "All enabled tests completed successfully!" << std::endl;
    return 0;
}
