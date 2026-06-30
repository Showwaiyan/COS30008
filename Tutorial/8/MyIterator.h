#pragma once
#include "InkLinkedList.h"

template <class T> class MyIterator {
private:
  using ListNode = IntLinkedList<T>;
  const ListNode *fList;
  const ListNode *fIndex;

public:
  using Iterator = MyIterator<T>;
  MyIterator(const ListNode *aList): fList(aList), fIndex(aList) {}
  const T &operator*() const {
    return **fIndex;
  }
  Iterator operator++() {
    fIndex = &fIndex->getNext();
    return *this;
  }
  Iterator operator++(int) {
    Iterator copy = *this;
    ++(*this);
    return copy;
  }
  bool operator==(const Iterator &aItr) const {
    return fList == aItr.fList && fIndex == aItr.fIndex;
  }
  bool operator!=(const Iterator &aItr) const {
    return !(*this == aItr);
  }
  const Iterator begin() {
    Iterator copy = *this;
    copy.fIndex = fList;
    return copy;
  }
  const Iterator end() {
    Iterator copy = *this;
    copy.fIndex = nullptr;
    return copy;
  }
};
