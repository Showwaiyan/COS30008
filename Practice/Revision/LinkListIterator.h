#pragma once

#include "LinkList.h"

template <class T> class LinkedListIterator {
private:
  using ListNode = ListNode<T>;
  const ListNode *list;
  const ListNode *index;

public:
  using Iterator = LinkedListIterator<T>;
  LinkedListIterator(const ListNode *aList) : list(aList), index(aList) {}
  const T &operator*() const { return index->data; }
  Iterator &operator++() {
    index = index->next;
    return *this;
  }
  Iterator operator++(int) {
    Iterator copy = *this;
    ++(*this);
    return copy;
  }
  bool operator==(const Iterator &aOther) const {
    return list == aOther.list && index == aOther.index;
  }
  bool operator!=(const Iterator &aOther) const {
    return !(*this == aOther);
  }

  Iterator begin() const {
    Iterator lCopy = *this;
    lCopy.list = this->list;
    lCopy.index = this->list;
    return lCopy;
  }
  Iterator end() const {
    Iterator lCopy = *this;
    lCopy.list = list;
    lCopy.index = nullptr;
    return lCopy;
  }
};
