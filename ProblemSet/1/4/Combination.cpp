// COS30008, Problem Set 1/3, 2022

#include "Combination.h"
#include <cstddef>

Combination::Combination( size_t aN, size_t aK ) : fN(aN), fK(aK)
{
}

size_t Combination::getN() const
{
  return fN;
}

size_t Combination::getK() const
{
  return fK;
}

unsigned long long Combination::operator()() const
{
  unsigned long long result = 1;
  for (size_t i = 1; i <= fK; i++) {
    result = result * (fN-(i-1)) / i;
  }
  return result;
}
