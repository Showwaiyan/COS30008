#pragma once

#include <iostream>
#include <utility>

template <class T>
struct DoubleListNode
{
    T data;
    DoubleListNode* next, * previous;

    DoubleListNode(const T& newData) : data(newData), next(nullptr),
    previous(nullptr)
    {}

    DoubleListNode(const T&& newData) : data(std::move(newData)), next(nullptr),
    previous(nullptr)
    {}
};

using NodePtr = DoubleListNode<int>*;
using DoubleListNodeInt = DoubleListNode<int>;

void addToBack(NodePtr& first, int value) {
  if (first == nullptr) {
    first = new DoubleListNodeInt(value);
    return;
  }
  NodePtr lNode = first;
  while (lNode->next != nullptr) {
    lNode = lNode->next;
  }
  DoubleListNodeInt* node = new DoubleListNodeInt(value);
  node->previous = lNode;
  lNode->next = node;
}
void addToFront(NodePtr& first, int value) {
  if (first == nullptr) {
    first = new DoubleListNodeInt(value);
    return;
  }
  NodePtr lNode = first;
  while (lNode->previous != nullptr) {
    lNode = lNode->previous;
  }
  DoubleListNodeInt* node = new DoubleListNodeInt(value);
  node->next = lNode;
  lNode->previous = node;
  first = node;
}
void removeBack(NodePtr& first) {
  NodePtr lNode = first;
  while(lNode->next != nullptr) {
    lNode = lNode->next;
  }
  NodePtr node = lNode->previous;
  node->next = nullptr;
  delete lNode;
}
void removeFront(NodePtr& first) {
  NodePtr lNode = first;
  first = lNode->next;
  first->previous = nullptr;
  delete lNode;
}
void displayAll(NodePtr& first);
