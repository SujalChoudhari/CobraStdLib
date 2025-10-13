#include "number_theory.h"

unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

unsigned int lcm(unsigned int a, unsigned int b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

int is_prime(unsigned int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (unsigned int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

void prime_factors(unsigned int n, unsigned int* factors, unsigned int* count) {
    *count = 0;
    while (n % 2 == 0) {
        factors[(*count)++] = 2;
        n /= 2;
    }
    for (unsigned int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors[(*count)++] = i;
            n /= i;
        }
    }
    if (n > 2) {
        factors[(*count)++] = n;
    }
}

int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

unsigned int totient(unsigned int n) {
    unsigned int result = n;
    for (unsigned int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
