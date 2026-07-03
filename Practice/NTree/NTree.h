#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <memory>
#include <utility>

template <typename T, std::size_t N> class NTree {
public:
  using node = std::unique_ptr<NTree>;

  NTree(const T &aKey = T{}) noexcept : fKey(aKey) {}
  NTree(T &&aKey) noexcept : fKey(std::move(aKey)) {}

  template <typename... Args> static node makeNode(Args &&...args) {
    return std::make_unique<NTree>(std::forward<Args>(args)...);
  }

  const T &operator*() const noexcept {
    return fKey;
  }
  NTree &operator[](std::size_t aIndex) const {
    assert(aIndex < N && fNodes[aIndex]);
    return *fNodes[aIndex];
  }

  void attach(std::size_t aIndex, node &aNode) {
    assert(aIndex < N && !fNodes[aIndex]);
    fNodes[aIndex] = std::move(aNode);
  }
  node detach(std::size_t aIndex) {
    assert(aIndex < N && fNodes[aIndex]);
    return std::move(fNodes[aIndex]);
  }

  bool leaf() const noexcept {
    for (size_t i = 0; i < N; i++) {
      if (fNodes[i])  {
        return false;
      }
    }
    return true;
  }
  std::size_t height() const noexcept {
    size_t Result = 0;
    if (!leaf()) {
      for (size_t i = 0; i < N; i++) {
        if (fNodes[i]) {
          Result = std::max(Result,fNodes[i]->height()+1);
        }
      }
    }
    return Result;
  }

  void swap(NTree &aOther) noexcept {
    std::swap(fKey, aOther.fKey);

    for (size_t i = 0; i<N; i++) {
      std::swap(fNodes[i],aOther.fNodes[i]);
    }
  }

  // Copy and Move semantics constructors are also included...
private:
  T fKey;
  node fNodes[N];
};

