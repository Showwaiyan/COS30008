// COS30008, tutorial 3, 2025

#include "Matrix3x3.h"
#include <cassert>
#include <cmath>

Matrix3x3::Matrix3x3() noexcept
    : fRows{
          Vector3D(1.0f, 0.0f, 0.0f),
          Vector3D(0.0f, 1.0f, 0.0f),
          Vector3D(0.0f, 0.0f, 1.0f),
      } {}

Matrix3x3::Matrix3x3(const Vector3D &aRow1, const Vector3D &aRow2,
                     const Vector3D &aRow3) noexcept
    : fRows{aRow1, aRow2, aRow3} {}

Matrix3x3 Matrix3x3::operator*(const float aScalar) const noexcept {
  Matrix3x3 M = Matrix3x3((*this)[0] * aScalar, (*this)[1] * aScalar,
                          (*this)[2] * aScalar);

  return M;
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &aOther) const noexcept {
  // TODO: implement
  return *this;
}

Vector3D Matrix3x3::operator*(const Vector3D &aVector) const noexcept {
  return Vector3D((*this)[0].dot(aVector), (*this)[1].dot(aVector),
                  (*this)[2].dot(aVector));
}

Matrix3x3 Matrix3x3::getS(const float aX, const float aY) noexcept {
  return Matrix3x3(Vector3D(aX, 0.0f, 0.0f), Vector3D(0.0f, aY, 0.0f),
                   Vector3D(0.0f, 0.0f, 1.0f));
}

Matrix3x3 Matrix3x3::getT(const float aX, const float aY) noexcept {
  return Matrix3x3(Vector3D(1.0f, 0.0f, aX), Vector3D(0.0f, 1.0f, aY),
                   Vector3D(0.0f, 0.0f, 1.0f));
}

Matrix3x3 Matrix3x3::getR(const float aAngleInDegree) noexcept {
  float radian = aAngleInDegree * (M_PI / 180.0f);
  return Matrix3x3(Vector3D(std::cos(radian), -std::sin(radian), 0.0f),
                   Vector3D(std::sin(radian), std::cos(radian), 0.0f),
                   Vector3D(0.0f, 0.0f, 1.0f));
}

const Vector3D &Matrix3x3::row(size_t aRowIndex) const noexcept {
  // TODO: implement
  return fRows[0];
}

const Vector3D Matrix3x3::column(size_t aColumnIndex) const noexcept {
  // TODO: implement
  return Vector3D();
}

const Vector3D &Matrix3x3::operator[](size_t aRowIndex) const noexcept {
  // TODO: implement
  assert(aRowIndex < 3);
  return fRows[aRowIndex];
}
