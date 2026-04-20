#include "Polygon.h"
#include <cstddef>

float Polygon::getSignedArea() const {
  float result = 0.0;
  for(size_t i = 0; i < fNumberOfVertices; i++) {
    result += fVertices[i].cross(fVertices[(i+1)%fNumberOfVertices]);
  }
  return result/2.0f;
}
