#include "Polygon.h"
#include "Vector2D.h"
#include <cmath>
// #include <sstream>
#include <string>

Polygon::Polygon() noexcept { fNumberOfVertices = 0; }

void Polygon::readData(std::istream &aIStream) {
  std::string line;
  // while(std::getline(aIStream,line)) {
  //   std::stringstream ss(line); // in order to read file data as stream
  //   ss >> fVertices[fNumberOfVertices++];
  // }
  //
  while (aIStream >> fVertices[fNumberOfVertices]) {
    fNumberOfVertices++;
  }
}

size_t Polygon::getNumberOfVertices() const noexcept {
  return this->fNumberOfVertices;
}

const Vector2D& Polygon::getVertex(size_t aIndex) const {
  return this->fVertices[aIndex];
}


float Polygon::getPerimeter() const noexcept {
  float perim = 0.0;
  for (size_t i=0; i<fNumberOfVertices; i++) {
    Vector2D current = fVertices[i];
    Vector2D next = fVertices[(i+1)%fNumberOfVertices];
    Vector2D temp = current-next;
    perim+=std::sqrt(pow(temp.x(),2)+pow(temp.y(),2));
  }
  return perim;
}

Polygon Polygon::scale( float aScalar ) const noexcept {
  Polygon result = *this;

  for (size_t i=0; i<fNumberOfVertices;i++) {
   result.fVertices[i] = this->fVertices[i]*aScalar;
  }
  return result;
}

