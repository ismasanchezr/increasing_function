%module find_square

%{
#include "find.h"
double square(long n) {
    return static_cast<double> (n*n);
}
%}

%inline %{
long find_square(double y, long a, long b) {
    return find(square, y, a, b);
}
%}