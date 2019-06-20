/* The following code example is taken from the book
* "Object-Oriented Programming in C++"
* by Nicolai M. Josuttis, Wiley, 2002
*
* (C) Copyright Nicolai M. Josuttis 2002.
* Permission to copy, use, modify, sell and distribute this software
* is granted provided this copyright notice appears in all copies.
* This software is provided "as is" without express or implied
* warranty, and with no claim as to its suitability for any purpose.
*/

// include header file with the class declaration
#include "Fraction.h"

// include standard header files
#include <cstdlib>	// std::exit
#include <cmath>	// std::abs

using std::cout;
using std::endl;
using std::exit;
using std::abs;

Fraction::Fraction()
	: numer_(0), denom_(1)    
{
	// no further instructions
}

Fraction::Fraction(int n) : numer_(n), denom_(1)    
{
	// no further instructions
}

Fraction::Fraction(int n, int d) :numer_(n), denom_(d)
{
	// 0 is not allowed as a denominator
	checkForZero_(d);
	checkNegativeDenominator_();
	simplify_();
}

// print
void Fraction::print()
{
	if (denom_ != 1)
	{
		std::cout << numer_ << '/' << denom_ << std::endl;
	}
	else
	{
		std::cout << numer_ << std::endl;
	}
}

// new: operator family + (ADDITION)
Fraction Fraction::operator + (const Fraction& rhs) const
{
	Fraction fracProd(numer_ * rhs.denom_ + denom_ * rhs.numer_, denom_ * rhs.denom_);
	fracProd.simplify_();		// since fracProd is a Fraction object,
								// we may call its private method simplify_().
	return fracProd;			// Returns product in simplest form.
}

// new: operator family - (SUBTRACTION)
Fraction Fraction::operator - (const Fraction& rhs) const
{
	Fraction fracProd(numer_ * rhs.denom_ - denom_ * rhs.numer_, denom_ * rhs.denom_);
	fracProd.simplify_();		// since fracProd is a Fraction object,
								// we may call its private method simplify_().
	return fracProd;			// Returns product in simplest form.
}

// new: operator family * (multiplication)
Fraction Fraction::operator * (const Fraction& rhs) const
{
	Fraction fracProd(numer_ * rhs.numer_, denom_ * rhs.denom_);
	fracProd.simplify_();		// since fracProd is a Fraction object,
								// we may call its private method simplify_().
	return fracProd;			// Returns product in simplest form.
}

void Fraction::operator += (const Fraction& rhs)
{
	*this = *this + rhs;
	simplify_();
}

void Fraction::operator -= (const Fraction& rhs)
{
	*this = *this - rhs;
	simplify_();
}

void Fraction::operator *= (const Fraction& rhs)
{
	*this = *this * rhs;
	simplify_();
}

// new: operator <
bool Fraction::operator < (const Fraction& rhs) const
{
	return numer_ * rhs.denom_ < rhs.numer_ * denom_;
}

// new: operator >
bool Fraction::operator > (const Fraction& rhs) const
{
	return numer_ * rhs.denom_ > rhs.numer_ * denom_;
}

// new: operator <=
bool Fraction::operator <= (const Fraction& rhs) const
{
	return !(*this > rhs);
}

// new: operator >=
bool Fraction::operator >= (const Fraction& rhs) const
{
	return !(*this < rhs);
}

void Fraction::simplify_()
{
	int gcd = gcd_();
	numer_ /= gcd;
	denom_ /= gcd;

	if (numer_ == denom_)
	{
		numer_ = 1;
		denom_ = 1;
	}
}

int Fraction::gcd_() const
{
	int  gcd = 0;
	for (int i = 1; (i <= std::abs(numer_) && i <= std::abs(denom_)); ++i)
	{
		if (std::abs(numer_) % i == 0 && std::abs(denom_) % i == 0)
		{
			gcd = i;
		}
	}

	return gcd;
}

Fraction& Fraction::operator ++()
{
	numer_ += denom_;
	simplify_();

	return *this;
}

Fraction Fraction::operator ++ (int notused)
{
	Fraction retFrac = *this;	// Take a copy of current object
	retFrac.simplify_();

	numer_ += denom_;

	return retFrac;					// Return a copy of the non-incremented object
}

bool Fraction::operator == (const Fraction& rhs) const
{
	return((numer_ == rhs.numer_) && (denom_ == rhs.denom_));
}

bool Fraction::operator != (const Fraction& rhs) const
{
//	return((numer_ != rhs.numer_) || (denom_ != rhs.denom_));
	return !(*this == rhs);
}

int Fraction::numer() const
{
	return numer_;
}

int Fraction::denom() const
{
	return denom_;
}

void Fraction::setNumer(int n) 
{
	numer_ = n;
	simplify_();
}

void Fraction::setDenom(int d) 
{
	checkForZero_(d);
	denom_ = d;
	checkNegativeDenominator_();
	simplify_();
}

void Fraction::checkForZero_(int d) const
{
	// 0 is not allowed as a denominator
	if (d == 0) 
	{
		// exit program with error message
		std::cout << "error: denominator is 0" << std::endl;
		std::exit(EXIT_FAILURE);		// This is a stopgap measure until we cover exceptions.
	}
}

void Fraction::checkNegativeDenominator_() 
{
	/* Move a negative sign of the denominator to the numerator.
	* This avoids, among other things, special treatment with the operator <
	*/
	if (denom_ < 0) {
		numer_ = -numer_;
		denom_ = -denom_;
	}
}

// This is a 'friend' of the FractionThree class
// Need not be concerned with the implementation.  Just use it.
std::ostream& operator << (std::ostream& os, const Fraction& rhs)
{
	if (rhs.denom_ != 1)
	{
		os << rhs.numer_ << '/' << rhs.denom_;
	}
	else
	{
		os << rhs.numer_;
	}
	return os;
}