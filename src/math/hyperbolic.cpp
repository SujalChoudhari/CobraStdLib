#include "hyperbolic.h"
#include <cmath>

double sinh_double(double x) {
    return std::sinh(x);
}

double cosh_double(double x) {
    return std::cosh(x);
}

double tanh_double(double x) {
    return std::tanh(x);
}

double coth_double(double x) {
    return 1.0 / std::tanh(x);
}

double sech_double(double x) {
    return 1.0 / std::cosh(x);
}

double csch_double(double x) {
    return 1.0 / std::sinh(x);
}

double asinh_double(double x) {
    return std::asinh(x);
}

double acosh_double(double x) {
    return std::acosh(x);
}

double atanh_double(double x) {
    return std::atanh(x);
}

double acoth_double(double x) {
    return 0.5 * std::log((x + 1) / (x - 1));
}

double asech_double(double x) {
    return std::log((1.0 + std::sqrt(1.0 - x * x)) / x);
}

double acsch_double(double x) {
    return std::log(1.0 / x + std::sqrt(1.0 / (x * x) + 1));
}
