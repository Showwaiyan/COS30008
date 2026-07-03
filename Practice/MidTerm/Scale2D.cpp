#include "Scale2D.h"

// Constructor
Scale2D::Scale2D(float aX, float aY) noexcept : fX(aX), fY(aY) {}

// Getter
float Scale2D::getX() const noexcept { return fX; }
float Scale2D::getY() const noexcept { return fY; }

// Member Operators
Scale2D Scale2D::operator*(const Scale2D &aRHS) const noexcept {
  return Scale2D(fX * aRHS.fX, fY * aRHS.fY);
}
Scale2D &Scale2D::operator*=(const Scale2D &aRHS) noexcept {
  *this = *this * aRHS;
  return *this;
}

// Stream i/o
std::ostream& operator<<(std::ostream& aOStream, const Scale2D& aScale) {
  return aOStream << "X: " << aScale.fX << "\n" << "Y: " << aScale.fY << "\n" << std::endl;
}
std::istream& operator>>(std::istream& aIStream, Scale2D& aScale) {
  aIStream >> aScale.fX;
  aIStream >> aScale.fY;
  return aIStream;
}

// Ad Hoc Operator
Scale2D operator*(float aScalar, const Scale2D& aScale) noexcept {
  return Scale2D(aScale.getX()*aScalar, aScale.getY()*aScalar);
}
Scale2D operator*(const Scale2D& aScale, float aScalar) noexcept {
  return aScalar * aScale;
}
