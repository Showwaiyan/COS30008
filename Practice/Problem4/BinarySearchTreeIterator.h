
// COS30008, Problem Set 4, Problem 3, 2022

#pragma once

#include "BinarySearchTree.h"

#include <stack>

template <typename T> class BinarySearchTreeIterator {
private:
  using BSTree = BinarySearchTree<T>;
  using BNode = BinaryTreeNode<T>;
  using BTreeNode = BNode *;
  using BTNStack = std::stack<BTreeNode>;

  const BSTree &fBSTree; // binary search tree
  BTNStack fStack;       // DFS traversal stack

  void pushLeft(BTreeNode aNode) {
    while (!aNode->empty()) {
      fStack.push(aNode);
      aNode = aNode->left;
    }
  }

public:
  using Iterator = BinarySearchTreeIterator<T>;

  BinarySearchTreeIterator(const BSTree &aBSTree) : fBSTree(aBSTree) {}

  const T &operator*() const { return fStack.top()->key; }
  Iterator &operator++() {
    BTreeNode lNode = fStack.top();
    fStack.pop();
    pushLeft(lNode->right);
    return *this;
  }
  Iterator operator++(int) {
    Iterator copy = *this;
    ++(*this);
    return copy;
  }
  bool operator==(const Iterator &aOtherIter) const {
    return &fBSTree == &aOtherIter.fBSTree && fStack == aOtherIter.fStack;
  }
  bool operator!=(const Iterator &aOtherIter) const {
    return !(*this == aOtherIter);
  }

  Iterator begin() const {
    Iterator copy = *this;
    copy.fStack = BTNStack();
    copy.pushLeft(fBSTree.fRoot);
    return copy;
  }
  Iterator end() const {
    Iterator copy = *this;
    copy.fStack = BTNStack();
    return copy;
  }
};
