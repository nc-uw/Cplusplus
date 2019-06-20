#include "Fraction.h"
#include "Functions.h"
#include "Secant.h"
#include "Templates.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

void stliterators();

int main()
{ 
    // Q.3.
    cout << endl << endl << " ### Q.3 ### " << endl;
    stliterators();

    //test for remaining functions
    // Q.2.
    cout << endl << endl << " ### Q.2 ### " << endl;

    PolyFunction poly(1.0, -0.5, 1.0, -0.5);    
    auto polyPtr = std::make_unique<PolyFunction>(poly);
    Secant sec(std::move(polyPtr)); // transfer possession of a unique pointer
    double root = sec.root(2.0, 3.0, 1000, 10000);
    cout << endl << " root of poly: " << root << endl;

    // Q.1.
    cout << endl << endl << " ### Q.1 ### " << endl;
    Fraction fA(2, 4); 
	Fraction fB(8, 10);

    Fraction fC = fA + fB;
    fC.print();
    fA += fB;
    fA.print();

    Fraction fD = fA - fB;
    fD.print();
    fA -= fB;
    fA.print();
    
    cout << (fA > fB) <<endl;
    cout << (fA <= fB) <<endl;

    // testing template functions
    auto temp_out = stupidFunction(fA, fB, fC);
    cout << temp_out << endl;

    // testing template class
    StupidClass<Fraction> stupidFrac(std::move(fB), std::move(fA));  
    cout << stupidFrac.f() << endl;
    cout << stupidFrac.g() << endl;
    cout << stupidFrac.t1() << endl;
    cout << stupidFrac.t2() << endl;
    Fraction fX(2, 9);
    stupidFrac.setT1(std::move(fX));
    cout << stupidFrac.t1() << endl;
    Fraction fY(3, 8);
    stupidFrac.setT2(std::move(fY));
    cout << stupidFrac.t2() << endl;
}

void stliterators()
{
    PolyFunction poly(-1.0, 1.0, -2.0, -10.0);
    TrigFunction trig(1, 1);
    const std::vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    std::vector<double> polyVals = {};
    std::vector<double> trigVals = {};
    
    for (unsigned int i = 0; i < x.size(); ++i)
    {
        polyVals.push_back(poly(x[i]));
        trigVals.push_back(trig(x[i]));
        //cout << " poly at i = " << i << ": " << poly(x[i]) << endl;
        //cout << " trig at i = " << i << ": " << trig(x[i]) << endl;
    }

    std::vector<double> sums = {};
    std::vector<double>::iterator pos1;
    std::vector<double>::iterator pos2;
    
    for(auto pos1 = polyVals.begin(), pos2 = trigVals.begin(); pos1 != polyVals.end(), pos2 != trigVals.end(); ++pos1, ++pos2) 
    {
        sums.push_back(*pos1 + *pos2);
    }
    
    cout << endl << "sum of trigVals and polyVals at each i: " << endl;
    for (unsigned int i = 0; i < sums.size(); ++i)
    {
        if (i == sums.size() - 1)
            cout << sums[i] << ". ";
        else
            cout << sums[i] << ", ";
    }
    cout << endl;
}