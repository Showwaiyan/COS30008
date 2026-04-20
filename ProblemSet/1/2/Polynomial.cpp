#include <iostream>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial()
{
	fDegree = -1;
	for (int i = 0; i <= MAX_DEGREE; i++)
		fCoeffs[i] = 0;
}

bool Polynomial::operator==(const Polynomial& aRHS) const
{
	if (fDegree != aRHS.fDegree)
		return false;
	for (int i = 0; i <= fDegree; i++)
	{
		if (fCoeffs[i] != aRHS.fCoeffs[i])
			return false;
	}
	return true;
}



istream& operator>>(istream& aIStream, Polynomial& aObject)
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




ostream& operator<<(ostream& aOStream, const Polynomial& aObject)
{
    for (size_t i = aObject.fDegree; i >= 1; i--)
    {
        aOStream << " " << aObject.fCoeffs[i] << "x^" << i << ((aObject.fCoeffs[i+1]!=0)?"" :" +");
    }
    
    if (aObject.fCoeffs[0] != 0) aOStream << " "<< aObject.fCoeffs[0] << "x^" << 0;
    
    return aOStream;
}





Polynomial Polynomial::operator*(const Polynomial& aRHS) const
{
	Polynomial result;

	result.fDegree = fDegree + aRHS.fDegree;
	for (int i = fDegree; i>=0; i--)
	{
		for (int j = aRHS.fDegree; j >= 0; j--)
		{
			double coeff = fCoeffs[i] * aRHS.fCoeffs[j];
			size_t degree = i + j;
			result.fCoeffs[degree] += coeff;
		}
	}
	return result;
}
