#include "Polynomial.h"
#include <cmath>
#include <sstream>
#include <iomanip>

Polynomial::Polynomial() : fDegree(0), fCoeffs{} 
{
    for (size_t i = 0; i <= MAX_DEGREE; i++)
    {
        fCoeffs[i] = 0.0;
    }
}

Polynomial Polynomial::operator*( const Polynomial& aRHS ) const
{
    Polynomial result;
    
    for (size_t i = 0; i <= fDegree; i++)
    {
        for (size_t j = 0; j <= aRHS.fDegree; j++)
        {
            result.fCoeffs[i + j] += fCoeffs[i] * aRHS.fCoeffs[j];
        }
    }
    
    result.fDegree = fDegree + aRHS.fDegree;
    return result;
}

bool Polynomial::operator==( const Polynomial& aRHS ) const
{
    if (fDegree != aRHS.fDegree)
    {
        return false;
    }
    
    for (size_t i = 0; i <= fDegree; i++)
    {
        if (fCoeffs[i] != aRHS.fCoeffs[i])
        {
            return false;
        }
    }
    
    return true;
}

std::istream& operator>>( std::istream& aIStream, Polynomial& aObject )
{
    size_t degree;
    aIStream >> degree;
    
    aObject.fDegree = degree;
    
    for (size_t i = 0; i <= MAX_DEGREE; i++)
    {
        aObject.fCoeffs[i] = 0.0;
    }
    
    for (size_t i = degree; i >= 1; i--)
    {
        aIStream >> aObject.fCoeffs[i];
    }
    
    aIStream >> aObject.fCoeffs[0];
    
    return aIStream;
}

std::ostream& operator<<( std::ostream& aOStream, const Polynomial& aObject )
{
    
    for (size_t i = aObject.fDegree; i >= 1; i--)
    {
        aOStream << " " << aObject.fCoeffs[i] << "x^" << i << ((aObject.fCoeffs[i+1]!=0)?"" :" +");
    }
    
    if (aObject.fCoeffs[0] != 0) aOStream << " "<< aObject.fCoeffs[0] << "x^" << 0;
    
    return aOStream;
}

double Polynomial::operator()( double aX ) const
{
    double result = 0.0;
    double power = 1.0;
    
    for (size_t i = 0; i <= fDegree; i++)
    {
        result += fCoeffs[i] * power;
        power *= aX;
    }
    
    return result;
}

Polynomial Polynomial::getDerivative() const
{
    Polynomial result;
    
    if (fDegree == 0)
    {
        return result;
    }
    
    result.fDegree = fDegree - 1;
    
    for (size_t i = 1; i <= fDegree; i++)
    {
        result.fCoeffs[i - 1] = fCoeffs[i] * i;
    }
    
    return result;
}

Polynomial Polynomial::getIndefiniteIntegral() const
{
    Polynomial result;
    
    result.fDegree = fDegree + 1;
    
    for (size_t i = 0; i <= fDegree; i++)
    {
        result.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);
    }
    
    result.fCoeffs[0] = 0.0; // should it be +c?
    
    return result;
}

double Polynomial::getDefiniteIntegral( double aXLow, double aXHigh ) const
{
    Polynomial integral = getIndefiniteIntegral();
    
    return integral(aXHigh) - integral(aXLow);
}
