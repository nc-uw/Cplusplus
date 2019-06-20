
#include "Secant.h"
#include "Functions.h"
#include <iostream>
#include <cmath> 
#include <utility>
using std::cout;
using std::endl;

Secant::Secant(std::unique_ptr<RealFunction> realFunc): realFunc_(std::move(realFunc))
{
}

double Secant::root(double x0, double x1, float tolScale, int maxIters)
{	
    double eps = tolScale * std::numeric_limits<double>::epsilon();
    double root;
    for (int i = 1; i <= maxIters; ++i)
    {
        root = secantAlgo_(x0, x1);
        //cout << "iter = " << i << ", x0 = " << x0 << ", x1 = " << x1 << ", root = " << root << endl;
        if (std::abs(root - x1) <= eps)
        {
            //std::cout << "terminated at i = " << i << std::endl;
            return root;
        }
        x0 = x1;
        x1 = root;
    }
    return std::numeric_limits<double>::quiet_NaN();
}

double Secant::secantAlgo_(double x1, double x0)
{	
    // another way: (*realFunc_)(x1)
    double Fx1 = realFunc_->operator()(x1);
    double Fx0 = realFunc_->operator()(x0);
    double x2 = x1 - (Fx1 * ((x1 - x0) / (Fx1 - Fx0)));
    return x2;
}
