#include <cmath>
#include <numeric>

#include "cobra.h"

extern "C" {

COBRA_API double math_abs(double x) { return std::abs(x); }
COBRA_API double math_sign(double x) { return (x > 0) ? 1.0 : ((x < 0) ? -1.0 : 0.0); }
COBRA_API double math_floor(double x) { return std::floor(x); }
COBRA_API double math_ceil(double x) { return std::ceil(x); }
COBRA_API double math_round(double x) { return std::round(x); }
COBRA_API double math_trunc(double x) { return std::trunc(x); }
COBRA_API double math_round_to(double x, int decimals) {
    if (decimals < 0) decimals = 0;
    double factor = std::pow(10.0, decimals);
    return std::round(x * factor) / factor;
}

COBRA_API double math_sin(double x) { return std::sin(x); }
COBRA_API double math_cos(double x) { return std::cos(x); }
COBRA_API double math_tan(double x) { return std::tan(x); }
COBRA_API double math_asin(double x) { return std::asin(x); }
COBRA_API double math_acos(double x) { return std::acos(x); }
COBRA_API double math_atan(double x) { return std::atan(x); }
COBRA_API double math_atan2(double y, double x) { return std::atan2(y, x); }

COBRA_API double math_sinh(double x) { return std::sinh(x); }
COBRA_API double math_cosh(double x) { return std::cosh(x); }
COBRA_API double math_tanh(double x) { return std::tanh(x); }

COBRA_API long long math_factorial(int n) {
    if (n < 0 || n > 20) return 0; // Prevent overflow
    if (n == 0) return 1;
    long long result = 1;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}

COBRA_API long long math_binomial(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k;
    long long res = 1;
    for (int i = 1; i <= k; ++i) res = res * (n - i + 1) / i;
    return res;
}

COBRA_API int math_gcd(int a, int b) { return std::gcd(a, b); }
COBRA_API int math_lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return std::abs(a * b) / std::gcd(a, b);
}
COBRA_API bool math_is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

COBRA_API double math_clamp(double x, double lower, double upper) {
    return (x < lower) ? lower : (x > upper) ? upper : x;
}
COBRA_API double math_lerp(double a, double b, double t) { return a + t * (b - a); }
COBRA_API double math_smoothstep(double edge0, double edge1, double x) {
    if (x <= edge0) return 0.0;
    if (x >= edge1) return 1.0;
    double t = (x - edge0) / (edge1 - edge0);
    return t * t * (3.0 - 2.0 * t);
}

}
