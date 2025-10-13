#include "complex.h"
#include <cmath>

Complex complex_create(double real, double imag) {
    Complex c;
    c.real = real;
    c.imag = imag;
    return c;
}

Complex complex_add(Complex a, Complex b) {
    return complex_create(a.real + b.real, a.imag + b.imag);
}

Complex complex_subtract(Complex a, Complex b) {
    return complex_create(a.real - b.real, a.imag - b.imag);
}

Complex complex_multiply(Complex a, Complex b) {
    return complex_create(
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    );
}

Complex complex_divide(Complex a, Complex b) {
    double denom = b.real * b.real + b.imag * b.imag;
    if (denom == 0) return complex_create(0, 0);
    return complex_create(
        (a.real * b.real + a.imag * b.imag) / denom,
        (a.imag * b.real - a.real * b.imag) / denom
    );
}

double complex_abs(Complex a) {
    return std::hypot(a.real, a.imag);
}

double complex_arg(Complex a) {
    return std::atan2(a.imag, a.real);
}

Complex complex_conjugate(Complex a) {
    return complex_create(a.real, -a.imag);
}

Complex complex_exp(Complex a) {
    double e_pow = std::exp(a.real);
    return complex_create(e_pow * std::cos(a.imag), e_pow * std::sin(a.imag));
}

Complex complex_log(Complex a) {
    return complex_create(std::log(complex_abs(a)), complex_arg(a));
}

Complex complex_pow(Complex base, Complex exponent) {
    Complex log_base = complex_log(base);
    Complex exp_part = complex_multiply(log_base, exponent);
    return complex_exp(exp_part);
}

Complex complex_sin(Complex a) {
    return complex_create(
        std::sin(a.real) * std::cosh(a.imag),
        std::cos(a.real) * std::sinh(a.imag)
    );
}

Complex complex_cos(Complex a) {
    return complex_create(
        std::cos(a.real) * std::cosh(a.imag),
        -std::sin(a.real) * std::sinh(a.imag)
    );
}

Complex complex_tan(Complex a) {
    Complex numerator = complex_sin(a);
    Complex denominator = complex_cos(a);
    return complex_divide(numerator, denominator);
}
