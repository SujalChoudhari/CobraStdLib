#pragma once
#include "cobra.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    double real;
    double imag;
} Complex;

COBRA_API Complex complex_create(double real, double imag);
COBRA_API Complex complex_add(Complex a, Complex b);
COBRA_API Complex complex_subtract(Complex a, Complex b);
COBRA_API Complex complex_multiply(Complex a, Complex b);
COBRA_API Complex complex_divide(Complex a, Complex b); // returns zero complex if division by zero
COBRA_API double complex_abs(Complex a);
COBRA_API double complex_arg(Complex a);
COBRA_API Complex complex_conjugate(Complex a);
COBRA_API Complex complex_exp(Complex a);
COBRA_API Complex complex_log(Complex a);
COBRA_API Complex complex_pow(Complex base, Complex exponent);
COBRA_API Complex complex_sin(Complex a);
COBRA_API Complex complex_cos(Complex a);
COBRA_API Complex complex_tan(Complex a);

#ifdef __cplusplus
}
#endif
