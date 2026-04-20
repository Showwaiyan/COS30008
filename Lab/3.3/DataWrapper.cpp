// COS30008, Tutorial 5, 2024

#include "DataWrapper.h"
#include <cstddef>
#include <fstream>

DataWrapper::DataWrapper() {
  fSize = 0;
  fData = nullptr;
}

DataWrapper::~DataWrapper() { delete[] fData; }

bool DataWrapper::load(const std::string &aFileName) {
  std::ifstream file(aFileName);
  if (!file.is_open())
    return false;
  if (!file.good())
    return false;
  file >> fSize;
  fData = new DataMap[fSize];
  for (size_t i = 0; i < fSize; i++) {
    size_t key;
    size_t value;
    file >> key >> value;
    fData[i] = DataMap(key, value);
  }
  return true;
}

size_t DataWrapper::size() const noexcept { return fSize; }

const DataMap &DataWrapper::operator[](size_t aIndex) const {
  return fData[aIndex];
}
