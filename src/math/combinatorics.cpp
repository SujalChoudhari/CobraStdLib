#include "combinatorics.h"
#include <cmath>

unsigned long long factorial(unsigned int n) {
    if (n == 0) return 1;
    unsigned long long result = 1;
    for (unsigned int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

unsigned long long double_factorial(unsigned int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (unsigned int i = n; i > 1; i -= 2)
        result *= i;
    return result;
}

double gamma_double(double x) {
    return std::tgamma(x);
}

unsigned long long binomial(unsigned int n, unsigned int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k;
    unsigned long long c = 1;
    for (unsigned int i = 0; i < k; ++i) {
        c = c * (n - i) / (i + 1);
    }
    return c;
}

unsigned long long permute(unsigned int n, unsigned int k) {
    if (k > n) return 0;
    unsigned long long result = 1;
    for (unsigned int i = 0; i < k; ++i)
        result *= (n - i);
    return result;
}
