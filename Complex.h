//
//  Complex.h
//  FFT
//
//  Created by dtl on 21/04/2016.
//  Copyright (c) 2016 Dan Lismore. All rights reserved.
//

#ifndef FFT_Complex_h
#define FFT_Complex_h

#include <iostream>
#include <type_traits>

template<class Type>
class Complex
{
public:
    Complex(Type r = 0.0, Type i = 0.0)
    : real(r), imag(i)
    {
        static_assert(std::is_floating_point<Type>::value, "Floating point required.");
    }
    
    friend Complex operator+(const Complex &a, const Complex &b)
    {
        Complex result;
        result.real = a.real + b.real;
        result.imag = a.imag + b.imag;
        return result;
    }
    
    friend Complex operator-(const Complex &a, const Complex &b)
    {
        Complex result;
        result.real = a.real - b.real;
        result.imag = a.imag - b.imag;
        return result;
    }
    
    friend Complex operator*(const Complex &a, const Complex &b)
    {
        Complex result;
        result.real = (a.real * b.real - a.imag * b.imag);
        result.imag = (a.real * b.real - a.imag * b.real);
        return result;
    }
    
    friend Complex operator/(const Complex &a, const Complex &b)
    {
        Complex result;
        result.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
        result.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
        return result;
    }
private:
    Type real;
    Type imag;
    
};

#endif
