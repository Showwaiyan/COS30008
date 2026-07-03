#pragma once
#include <iostream>

class Scale2D {
private:
    float fX;
    float fY;

public:
    // Constructor
    Scale2D(float aX = 1.0f, float aY = 1.0f) noexcept;

    // Getters
    float getX() const noexcept;
    float getY() const noexcept;

    // 1. MEMBER OPERATORS
    Scale2D operator*(const Scale2D& aRHS) const noexcept;
    Scale2D& operator*=(const Scale2D& aRHS) noexcept;

    // 2. STREAM I/O OPERATORS (Ad hoc functions declared as friends)
    friend std::ostream& operator<<(std::ostream& aOStream, const Scale2D& aScale);
    friend std::istream& operator>>(std::istream& aIStream, Scale2D& aScale);
};

// 3. AD HOC OPERATORS (Non-member commutative operators)
Scale2D operator*(float aScalar, const Scale2D& aScale) noexcept;
Scale2D operator*(const Scale2D& aScale, float aScalar) noexcept;
