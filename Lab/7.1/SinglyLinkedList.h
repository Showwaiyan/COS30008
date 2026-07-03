#pragma once

#include <iostream>
#include <utility>

template <class T> class SinglyLinkedList {
public:
  T fValue;
  SinglyLinkedList *fNext;
  
  SinglyLinkedList(const T &aValue, SinglyLinkedList *aNext = nullptr);
  SinglyLinkedList(T &&aValue, SinglyLinkedList *aNext = nullptr);

  // --- Paradigm 1: Non-static Member Functions (operating on this) ---
  SinglyLinkedList* addBack(const T &aValue);
  SinglyLinkedList* addBack(T &&aValue);
  
  SinglyLinkedList* addFront(const T &aValue);
  SinglyLinkedList* addFront(T &&aValue);
  
  SinglyLinkedList* removeBack();
  SinglyLinkedList* removeFront();
  
  SinglyLinkedList* insert(const T &aValue, int aPosition);
  SinglyLinkedList* insert(T &&aValue, int aPosition);
  
  void display() const;

  // --- Paradigm 2: Static Member Functions (operating on head reference) ---
  static void addBack(SinglyLinkedList*& aHead, const T &aValue);
  static void addBack(SinglyLinkedList*& aHead, T &&aValue);
  
  static void addFront(SinglyLinkedList*& aHead, const T &aValue);
  static void addFront(SinglyLinkedList*& aHead, T &&aValue);
  
  static void removeBack(SinglyLinkedList*& aHead);
  static void removeFront(SinglyLinkedList*& aHead);
  
  static void insert(SinglyLinkedList*& aHead, const T &aValue, int aPosition);
  static void insert(SinglyLinkedList*& aHead, T &&aValue, int aPosition);
  
  static void display(const SinglyLinkedList* aHead);
  static void clear(SinglyLinkedList*& aHead);
};

// ==========================================
// Implementation of Constructors
// ==========================================

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const T &aValue, SinglyLinkedList *aNext)
    : fValue(aValue), fNext(aNext) {}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(T &&aValue, SinglyLinkedList *aNext)
    : fValue(std::move(aValue)), fNext(aNext) {}

// ==========================================
// Implementation of Non-static Member Functions
// ==========================================

template <class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::addBack(const T &aValue) {
  SinglyLinkedList* current = this;
  while (current->fNext != nullptr) {
    current = current->fNext;
  }
  current->fNext = new SinglyLinkedList(aValue);
  return this;
}

template <class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::addBack(T &&aValue) {
  SinglyLinkedList* current = this;
  while (current->fNext != nullptr) {
    current = current->fNext;
  }
  current->fNext = new SinglyLinkedList(std::move(aValue));
  return this;
}

template <class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::addFront(const T &aValue) {
  return new SinglyLinkedList(aValue, this);
}

template <class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::addFront(T &&aValue) {
  return new SinglyLinkedList(std::move(aValue), this);
}

template <class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::removeBack() {
  if (fNext == nullptr) {
    delete this;
    return nullptr;
  }
  SinglyLinkedList* current = this;
  while (current->fNext->fNext != nullptr) {
    current = current->fNext;
  }
  delete current->fNext;
  current->fNext = nullptr;
  return this;
}

template <class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::removeFront() {
  SinglyLinkedList* nextNode = fNext;
  delete this;
  return nextNode;
}

template <class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::insert(const T &aValue, int aPosition) {
  if (aPosition <= 0) {
    return addFront(aValue);
  }
  SinglyLinkedList* current = this;
  int currentPosition = 0;
  while (current->fNext != nullptr && currentPosition < aPosition - 1) {
    current = current->fNext;
    currentPosition++;
  }
  current->fNext = new SinglyLinkedList(aValue, current->fNext);
  return this;
}

template <class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::insert(T &&aValue, int aPosition) {
  if (aPosition <= 0) {
    return addFront(std::move(aValue));
  }
  SinglyLinkedList* current = this;
  int currentPosition = 0;
  while (current->fNext != nullptr && currentPosition < aPosition - 1) {
    current = current->fNext;
    currentPosition++;
  }
  current->fNext = new SinglyLinkedList(std::move(aValue), current->fNext);
  return this;
}

template <class T>
void SinglyLinkedList<T>::display() const {
  const SinglyLinkedList* current = this;
  while (current != nullptr) {
    std::cout << current->fValue;
    if (current->fNext != nullptr) {
      std::cout << " -> ";
    }
    current = current->fNext;
  }
  std::cout << std::endl;
}

// ==========================================
// Implementation of Static Member Functions
// ==========================================

template <class T>
void SinglyLinkedList<T>::addBack(SinglyLinkedList*& aHead, const T &aValue) {
  if (aHead == nullptr) {
    aHead = new SinglyLinkedList(aValue);
  } else {
    aHead->addBack(aValue);
  }
}

template <class T>
void SinglyLinkedList<T>::addBack(SinglyLinkedList*& aHead, T &&aValue) {
  if (aHead == nullptr) {
    aHead = new SinglyLinkedList(std::move(aValue));
  } else {
    aHead->addBack(std::move(aValue));
  }
}

template <class T>
void SinglyLinkedList<T>::addFront(SinglyLinkedList*& aHead, const T &aValue) {
  if (aHead == nullptr) {
    aHead = new SinglyLinkedList(aValue);
  } else {
    aHead = aHead->addFront(aValue);
  }
}

template <class T>
void SinglyLinkedList<T>::addFront(SinglyLinkedList*& aHead, T &&aValue) {
  if (aHead == nullptr) {
    aHead = new SinglyLinkedList(std::move(aValue));
  } else {
    aHead = aHead->addFront(std::move(aValue));
  }
}

template <class T>
void SinglyLinkedList<T>::removeBack(SinglyLinkedList*& aHead) {
  if (aHead == nullptr) {
    return;
  }
  aHead = aHead->removeBack();
}

template <class T>
void SinglyLinkedList<T>::removeFront(SinglyLinkedList*& aHead) {
  if (aHead == nullptr) {
    return;
  }
  aHead = aHead->removeFront();
}

template <class T>
void SinglyLinkedList<T>::insert(SinglyLinkedList*& aHead, const T &aValue, int aPosition) {
  if (aHead == nullptr) {
    aHead = new SinglyLinkedList(aValue);
  } else {
    aHead = aHead->insert(aValue, aPosition);
  }
}

template <class T>
void SinglyLinkedList<T>::insert(SinglyLinkedList*& aHead, T &&aValue, int aPosition) {
  if (aHead == nullptr) {
    aHead = new SinglyLinkedList(std::move(aValue));
  } else {
    aHead = aHead->insert(std::move(aValue), aPosition);
  }
}

template <class T>
void SinglyLinkedList<T>::display(const SinglyLinkedList* aHead) {
  if (aHead == nullptr) {
    std::cout << "[Empty List]" << std::endl;
  } else {
    aHead->display();
  }
}

template <class T>
void SinglyLinkedList<T>::clear(SinglyLinkedList*& aHead) {
  while (aHead != nullptr) {
    removeFront(aHead);
  }
}

// ==========================================
// --- Paradigm 3: Free Functions ---
// ==========================================

template <typename T>
void addBack(SinglyLinkedList<T>*& aHead, const T &aValue) {
  SinglyLinkedList<T>::addBack(aHead, aValue);
}

template <typename T>
void addBack(SinglyLinkedList<T>*& aHead, T &&aValue) {
  SinglyLinkedList<T>::addBack(aHead, std::move(aValue));
}

template <typename T>
void addFront(SinglyLinkedList<T>*& aHead, const T &aValue) {
  SinglyLinkedList<T>::addFront(aHead, aValue);
}

template <typename T>
void addFront(SinglyLinkedList<T>*& aHead, T &&aValue) {
  SinglyLinkedList<T>::addFront(aHead, std::move(aValue));
}

template <typename T>
void removeBack(SinglyLinkedList<T>*& aHead) {
  SinglyLinkedList<T>::removeBack(aHead);
}

template <typename T>
void removeFront(SinglyLinkedList<T>*& aHead) {
  SinglyLinkedList<T>::removeFront(aHead);
}

template <typename T>
void insert(SinglyLinkedList<T>*& aHead, const T &aValue, int aPosition) {
  SinglyLinkedList<T>::insert(aHead, aValue, aPosition);
}

template <typename T>
void insert(SinglyLinkedList<T>*& aHead, T &&aValue, int aPosition) {
  SinglyLinkedList<T>::insert(aHead, std::move(aValue), aPosition);
}

template <typename T>
void display(const SinglyLinkedList<T>* aHead) {
  SinglyLinkedList<T>::display(aHead);
}

template <typename T>
void clear(SinglyLinkedList<T>*& aHead) {
  SinglyLinkedList<T>::clear(aHead);
}
