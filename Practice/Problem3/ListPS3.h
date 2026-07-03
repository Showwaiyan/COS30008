
// COS30008, List, Problem Set 3, 2022

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

#include <cstddef>
#include <functional>
#include <stdexcept>

template <typename T> class List {
private:
  // auxiliary definition to simplify node usage
  using Node = DoublyLinkedList<T>;

  Node *fRoot;   // the first element in the list
  size_t fCount; // number of elements in the list

public:
  // auxiliary definition to simplify iterator usage
  using Iterator = DoublyLinkedListIterator<T>;

  ~List() // destructor - frees all nodes
  {
    while (fRoot != nullptr) {
      if (fRoot != &fRoot->getPrevious()) // more than one element
      {
        Node *lTemp = const_cast<Node *>(&fRoot->getPrevious()); // select last

        lTemp->isolate(); // remove from list
        delete lTemp;     // free
      } else {
        delete fRoot; // free last
        break;        // stop loop
      }
    }
  }

  void remove(const T &aElement) // remove first match from list
  {
    Node *lNode = fRoot; // start at first

    while (lNode != nullptr) // Are there still nodes available?
    {
      if (**lNode == aElement) // Have we found the node?
      {
        break; // stop the search
      }

      if (lNode != &fRoot->getPrevious()) // not reached last
      {
        lNode = const_cast<Node *>(&lNode->getNext()); // go to next
      } else {
        lNode = nullptr; // stop search
      }
    }

    // At this point we have either reached the end or found the node.
    if (lNode != nullptr) // We have found the node.
    {
      if (fCount != 1) // not the last element
      {
        if (lNode == fRoot) {
          fRoot = const_cast<Node *>(&fRoot->getNext()); // make next root
        }
      } else {
        fRoot = nullptr; // list becomes empty
      }

      lNode->isolate(); // isolate node
      delete lNode;     // release node's memory
      fCount--;         // decrement count
    }
  }

  //////////////////////////////////////////////////////////////////
  //// PS3
  //////////////////////////////////////////////////////////////////

  // P1

  List() : fRoot(nullptr), fCount(0) {} // default constructor

  bool empty() const {
    return fRoot == nullptr && fCount == 0;
  } // Is list empty?
  size_t size() const { return fCount; } // list size

  void push_front(const T &aElement) {
    Node *node = new DoublyLinkedList<T>(aElement);
    if (empty()) {
      fRoot = node;
    } else {
      fRoot->push_front(*node);
      fRoot = node;
    }
    fCount++;
  } // adds aElement at front

  Iterator begin() const {
    return Iterator(fRoot).begin();
  } // return a forward iterator
  Iterator end() const {
    return Iterator(fRoot).end();
  } // return a forward end iterator
  Iterator rbegin() const {
    return Iterator(fRoot).rbegin();
  } // return a backwards iterator
  Iterator rend() const {
    return Iterator(fRoot).rend();
  } // return a backwards end iterator

  // P2

  void push_back(const T &aElement) {
    Node *current_root = fRoot;
    push_front(aElement);
    if (current_root != nullptr)
      fRoot = current_root;
  } // adds aElement at back

  // P3

  const T &operator[](size_t aIndex) const {
    if (aIndex > fCount)
      throw std::out_of_range("Index out of range");
    const Node *lNode = fRoot;
    for (size_t i = 0; i < aIndex; i++) {
      lNode = &lNode->getNext();
    }
    return **lNode;
  } // list indexer

  // P4

  List(const List &aOtherList) : fRoot(nullptr), fCount(0) {
    *this = aOtherList;
  } // copy constructor
  List &operator=(const List &aOtherList) {
    if (this == &aOtherList) {
      return *this;
    }
    this->~List();
    fRoot = nullptr;
    fCount = 0;
    for (const T &lElement : aOtherList) {
      push_back(lElement);
    }
    return *this;
  } // assignment operator

  // P5

  List(List &&aOtherList) : fRoot(aOtherList.fRoot), fCount(aOtherList.fCount) {
    aOtherList.fCount = 0;
    aOtherList.fRoot = nullptr;
  } // move constructor
  List &operator=(List &&aOtherList) {
    if (this == &aOtherList) {
      return *this;
    }
    this->~List();
    fRoot = aOtherList.fRoot;
    fCount = aOtherList.fCount;

    aOtherList.fCount = 0;
    aOtherList.fRoot = nullptr;
    return *this;
  } // move assignment operator

  void push_front(T &&aElement) {
    Node *lNode = new Node(std::move(aElement));
    if (fRoot == nullptr) {
      fRoot = lNode;
    } else {
      fRoot->push_front(*lNode);
      fRoot = lNode;
    }
    fCount++;
  } // move push_front
  void push_back(T &&aElement) {
    Node *current_root = fRoot;
    push_front(aElement);
    if (current_root != nullptr)
      fRoot = current_root;
  } // move push_back
};
