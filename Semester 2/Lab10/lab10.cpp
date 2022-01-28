/*
Program: lab10.cpp
Date: 04/5/2021
Author: Khan, Muhammad
Purpose: Object Oriented Programming 
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
#include <iostream>

struct Complex
{
    double real, imag;

    void Initialize(double r, double i)
    {
        real = r; 
        imag = i; 
    }

    Complex operator*(Complex b)
    {
        Complex result;

        result.real = (real * b.real) - (imag * b.imag);
        result.imag = (real * b.imag) + (imag * b.real);

        return result;
    }

    void Display()
    {
        if (imag >= 0.0)
            cout << real << " + " << imag << " i ";
        else
            cout << real << " - " << -imag << " i ";
    }



};


int main()
{
    // declare x, y, and z as Complex type
    Complex x, y, z;

    // Initialize the real and imaginary parts of x and y
    x.Initialize(2.5, 3.0);
    y.Initialize(1.5, -2.5);

    // calculate x * y using the overloaded + operator
    // store result in z
    z = x * y;

    // Display z
    z.Display();

    return 0;
}