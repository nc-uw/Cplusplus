#include "Functions.h"
#include <iostream>
#include <cmath>
#include<limits>

//TrigFunction
TrigFunction::TrigFunction(double a, double b): a_(a), b_(b)
{
}

double TrigFunction::operator()(double x) const
{
	return std::sin(a_*x) - std::cos(b_*x);
}

// PolyFunction
PolyFunction::PolyFunction(double a, double b, double c, double d): a_(a), b_(b), c_(c), d_(d)
{
}

double PolyFunction::operator()(double x) const
{
	return a_*std::pow(x, 5) + b_*std::pow(x, 3) + c_*x + d_;
}

// LogFunction
LogFunction::LogFunction(double a, double b, double p): a_(a), b_(b), p_(p)
{
}

double LogFunction::operator()(double x)  const
{
	const double epsilon_ = p_ * std::numeric_limits<double>::epsilon();
	const double undefined = std::numeric_limits<double>::quiet_NaN();
	//if (std::abs(x - b_) > epsilon_)
	if (x - b_ > epsilon_)
	{		
		return a_*std::log(x - b_);
	}
	else if (std::abs(x - b_) < epsilon_)
	{
		//std::cout << 'aha' << std::endl;
		return a_*std::log(epsilon_);
	}
	else
	{
		return undefined;
	}
	
}
