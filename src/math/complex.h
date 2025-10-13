#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    double real;
    double imag;
} Complex;

Complex complex_create(double real, double imag);
Complex complex_add(Complex a, Complex b);
Complex complex_subtract(Complex a, Complex b);
Complex complex_multiply(Complex a, Complex b);
Complex complex_divide(Complex a, Complex b); // returns zero complex if division by zero
double complex_abs(Complex a);
double complex_arg(Complex a);
Complex complex_conjugate(Complex a);
Complex complex_exp(Complex a);
Complex complex_log(Complex a);
Complex complex_pow(Complex base, Complex exponent);
Complex complex_sin(Complex a);
Complex complex_cos(Complex a);
Complex complex_tan(Complex a);

#ifdef __cplusplus
}
#endif
