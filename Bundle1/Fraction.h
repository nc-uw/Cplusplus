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

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>		// for friend operator <<

// Fraction class: Continued evolution
class Fraction		// Not to be confused with the Jackson 5
{
public:
	Fraction();
	Fraction(int n);
	Fraction(int n, int d);

	void print();

	Fraction operator + (const Fraction& rhs) const;
	Fraction operator - (const Fraction& rhs) const;
	Fraction operator * (const Fraction& rhs) const;
	void operator += (const Fraction& rhs);
	void operator -= (const Fraction& rhs);
	void operator *= (const Fraction& rhs);
	bool operator < (const Fraction& rhs) const;
	bool operator <= (const Fraction& rhs) const;
	bool operator > (const Fraction& rhs) const;
	bool operator >= (const Fraction& rhs) const;

	// New: increment operators:
	Fraction& operator ++ ();
	Fraction operator ++ (int notused);

	// New: equality and non-equality operators:
	bool operator == (const Fraction& rhs) const;
	bool operator != (const Fraction& rhs) const;

	int numer() const;
	int denom() const;

	void setNumer(int n);
	void setDenom(int d);

	// friend operator so that we can output a fraction with cout
// Take this as given and use it; the mechanics are beyond 
// the scope of the current topic.
	friend std::ostream& operator << (std::ostream& os, const Fraction& rhs);

private:
	void simplify_();
	int gcd_() const;

	// new: private member function to check for a zero in the denominator
	void checkForZero_(int d) const;

	// new: private member to move negative sign from denominator to numerator
	void checkNegativeDenominator_();

	int numer_;
	int denom_;
};


#endif    // FRACTION_H