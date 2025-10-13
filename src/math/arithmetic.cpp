#include "arithmetic.h"
#include <cmath>
#include <limits>

double abs_double(double x) {
    return std::abs(x);
}

double sign(double x) {
    if (x > 0) return 1.0;
    if (x < 0) return -1.0;
    return 0.0;
}

double floor_double(double x) {
    return std::floor(x);
}

double ceil_double(double x) {
    return std::ceil(x);
}

double round_double(double x) {
    return std::round(x);
}

double trunc_double(double x) {
    return std::trunc(x);
}

double round_to_double(double x, int decimals) {
    double factor = std::pow(10.0, decimals);
    return std::round(x * factor) / factor;
}

double round_significant_double(double x, int n) {
    if (x == 0) return 0;
    double d = std::ceil(std::log10(std::fabs(x)));
    int power = n - static_cast<int>(d);
    double factor = std::pow(10.0, power);
    return std::round(x * factor) / factor;
}

double machine_epsilon(void) {
    return std::numeric_limits<double>::epsilon();
}
