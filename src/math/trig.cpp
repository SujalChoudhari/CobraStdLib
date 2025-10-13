#include "trig.h"
#include <cmath>

double sin_double(double x) {
    return std::sin(x);
}

double cos_double(double x) {
    return std::cos(x);
}

double tan_double(double x) {
    return std::tan(x);
}

double cot_double(double x) {
    return 1.0 / std::tan(x);
}

double sec_double(double x) {
    return 1.0 / std::cos(x);
}

double csc_double(double x) {
    return 1.0 / std::sin(x);
}

double asin_double(double x) {
    return std::asin(x);
}

double acos_double(double x) {
    return std::acos(x);
}

double atan_double(double x) {
    return std::atan(x);
}

double atan2_double(double y, double x) {
    return std::atan2(y, x);
}

double acot_double(double x) {
    return std::atan(1.0 / x);
}

double asec_double(double x) {
    return std::acos(1.0 / x);
}

double acsc_double(double x) {
    return std::asin(1.0 / x);
}
