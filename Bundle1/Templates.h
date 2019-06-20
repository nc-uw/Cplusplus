#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <iostream>

//function
template <typename T>
T stupidFunction(const T& t1, const T& t2, const T& t3) 
{
if ((t1>t2) or (t2<=t3))
    return t3 * (t1 + t2);
else
    return t3 * (t1 - t2);
}   

//class declaration
template <typename T> 
class StupidClass
{
public:
    StupidClass(T&& first, T&& second) :t1_(first), t2_(second) {}

    T t1() const;
	T t2() const;

	void setT1(T&& first);
	void setT2(T&& second);

    T f();
    T g();
private:
    T t1_, t2_;
};

//class implementation
template <typename T>
T StupidClass<T>::t1() const
{
    return t1_;
}

template <typename T>
T StupidClass<T>::t2() const
{
    return t2_;
}

template <typename T>
void StupidClass<T>::setT1(T&& first)
{
    t1_ = first;
}

template <typename T>
void StupidClass<T>::setT2(T&& second)
{
    t2_ = second;
}

template <typename T>
T StupidClass<T>::f()
{
    if (t1_ >= t2_)
        {
        return  t1_ - t2_;
        }
    else
        {
        return  t1_ + t2_;
        }
}

template <typename T>
T StupidClass<T>::g()
{
    if (t1_ != t2_)
        {
        return  t1_ * t2_;
        }
    else
        {
        return  t1_ * t1_;
        }
}

#endif