#ifndef SECANT_H
#define SECANT_H

#include <string>
#include <memory>
#include "Functions.h"

class Secant
{
public:
	Secant(std::unique_ptr<RealFunction> realFunc);
    
    // rule of 5
    // for unique pointers, disable all the copy operators..
    //unique pointer: encapsulates allocation, deletion

    Secant(const Secant& rhs) = delete;
    Secant& operator = (const Secant& rhs) = delete;
    Secant(Secant&& rhs) = default;
    Secant& operator = (Secant&& rhs) = default;
    ~Secant() = default;

    double root(double x0, double x1, float tolScale, int maxIters);

private:
	std::unique_ptr<RealFunction> realFunc_;
    double secantAlgo_(double x1, double x0);
};

#endif