#pragma once

#include <utility>

template <class T> struct ListNode {
  T data;
  ListNode *next;
  ListNode(const T &newData) : data(newData), next(nullptr) {}
  ListNode(const T &&newData) : data(std::move(newData)), next(nullptr) {}
};
template <class T> class MyLinkedList {
private:
  using ListNode = ListNode<T>;
  ListNode *front;
  ListNode *back;

public:
  MyLinkedList() : front(nullptr), back(nullptr) {}
  ListNode* getFront() const { return front; }
  ListNode* getBack() const { return back; }

  void addFront(const T &newData) {
    ListNode* lNode = new ListNode(newData);
    if (front == nullptr) {
      front = lNode;
    } else {
      lNode->next = front;
      front = lNode;
    }
  }
  void addBack(const T &newData) {
    ListNode* lNode = new ListNode(newData);
    if (back == nullptr) {
      back = lNode;
    } else {
      back->next = lNode;
      back = lNode; 
    }
  }
  void deleteFront() {
    if (front == nullptr) return;
    if (front == back) {
      delete front;
      front = nullptr;
      back = nullptr;
    }
    ListNode* lNode = front;
    front = front->next;
    lNode->next = nullptr;
    delete lNode;
  }
  void deleteBack() {
    if (front == nullptr) return;
    if (front == back) {
      delete front;
      front = nullptr;
      back = nullptr;
    }
    ListNode* lNode = front;
    while (lNode->next != back) {
      lNode = lNode->next;
    }
    lNode->next = nullptr;
    delete back;
    back = lNode;
  }
};
