#ifndef FUNCTION_H
#define FUNCTION_H
#include<limits>

class RealFunction
{
public:
	virtual double operator()(double x) const = 0;
	virtual ~RealFunction() = default;
	//virtual ~RealFunction() {};
};


class TrigFunction: public RealFunction
{
public:
	TrigFunction(double a, double b);
	virtual double operator()(double x) const override;

private:
	double a_;
	double b_;

};

class PolyFunction: public RealFunction
{
public:
	PolyFunction(double a, double b, double c, double d);
	virtual double operator()(double x) const override;

private:
	double a_;
	double b_;
	double c_;
	double d_;
};

class LogFunction: public RealFunction
{
public:
	LogFunction(double a, double b, double p);
	virtual double operator()(double x) const override;

private:
	double a_;
	double b_;
	double p_;
};

#endif