#pragma once

#ifdef __cplusplus
extern "C" {
#endif

unsigned long long factorial(unsigned int n);
unsigned long long double_factorial(unsigned int n);
double gamma_double(double x);
unsigned long long binomial(unsigned int n, unsigned int k);
unsigned long long permute(unsigned int n, unsigned int k);

#ifdef __cplusplus
}
#endif
