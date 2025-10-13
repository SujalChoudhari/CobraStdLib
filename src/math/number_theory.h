#pragma once
#include "cobra.h"

#ifdef __cplusplus
extern "C" {
#endif

COBRA_API unsigned int gcd(unsigned int a, unsigned int b);
COBRA_API unsigned int lcm(unsigned int a, unsigned int b);
COBRA_API int is_prime(unsigned int n);
COBRA_API void prime_factors(unsigned int n, unsigned int* factors, unsigned int* count);
COBRA_API int mod_inverse(int a, int m);
COBRA_API unsigned int totient(unsigned int n);

#ifdef __cplusplus
}
#endif
