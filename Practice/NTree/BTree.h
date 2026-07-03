#pragma once

#include <cstddef>
#include <memory>
#include <utility>

template <typename T> class BTree {
public:
  using node = std::unique_ptr<BTree>;
  BTree(const T &aKey = T{}) noexcept
      : fKey(aKey), fLeft(nullptr), fRight(nullptr) {}
  BTree(T &&aKey) noexcept
      : fKey(std::move(aKey)), fLeft(nullptr), fRight(nullptr) {}
  template <typename... Args> static node makeNode(Args &&...args) {
    return std::make_unique<BTree>(std::forward(args)...); 
  }
  BTree(const BTree &aOther)
      : fKey(aOther.fKey), fLeft(nullptr), fRight(nullptr) {
    if (aOther.fLeft)
      fLeft = std::make_unique<BTree>(*aOther.fLeft);
    if (aOther.fRight)
      fRight = std::make_unique<BTree>(*aOther.fRight);
  }
  BTree &operator=(const BTree &aOther) {
    if (this != aOther) {
      this->~BTree();
      new (this) BTree<T>(aOther);
    }
    return *this;
  }
  BTree(BTree &&aOther) noexcept { swap(aOther); }
  BTree &operator=(BTree &&aOther) noexcept {
    if (this != aOther) {
      this->~BTree();
      new (this) BTree<T>(std::move(aOther));
    }
    return *this;
  }
  void swap(BTree &aOther) noexcept {
    std::swap(fKey, aOther.fKey);
    std::swap(fLeft, aOther.fLeft);
    std::swap(fRight, aOther.fRight);
  }
  const T &operator*() const noexcept { return fKey; }
  bool hasLeft() const noexcept;
  BTree &left() const;
  bool hasRight() const noexcept;
  BTree &right() const;
  void attachLeft(node &aNode);
  void attachRight(node &aNode);
  node detachLeft();
  node detachRight();
  bool leaf() const noexcept;
  size_t height() const noexcept;

private:
  T fKey;
  node fLeft;
  node fRight;
};
