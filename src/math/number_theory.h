#pragma once

#ifdef __cplusplus
extern "C" {
#endif

unsigned int gcd(unsigned int a, unsigned int b);
unsigned int lcm(unsigned int a, unsigned int b);
int is_prime(unsigned int n);
void prime_factors(unsigned int n, unsigned int* factors, unsigned int* count);
int mod_inverse(int a, int m);
unsigned int totient(unsigned int n);

#ifdef __cplusplus
}
#endif
