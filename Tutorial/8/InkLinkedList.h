#pragma  once
#include <utility>
template <class T> class IntLinkedList {
private:
  T fData;
  IntLinkedList *fNext;

public:
  // l-value constructor
  explicit IntLinkedList(const T &aData) : fData(aData), fNext(nullptr) {}
  // r-value constructor
  explicit IntLinkedList(T &&aData) : fData(std::move(aData)), fNext(nullptr) {}
  // adding a node to the back
  void push_back(const IntLinkedList &aNode) {
    if (fNext == nullptr) {
      fNext = const_cast<IntLinkedList *>(&aNode);
      return;
    }

    IntLinkedList* lNext = fNext;
    while (lNext->fNext != nullptr) {
      lNext = lNext->fNext;
    }
    lNext->fNext = const_cast<IntLinkedList *>(&aNode);
  }
  // dereference operator that return the data of the node
  const T &operator*() const { return fData; }
  // returns const reference to next node
  const IntLinkedList &getNext() const { return *fNext; }
};
