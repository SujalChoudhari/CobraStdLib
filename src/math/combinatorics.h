#pragma once
#include "cobra.h"

#ifdef __cplusplus
extern "C" {
#endif

COBRA_API unsigned long long factorial(unsigned int n);
COBRA_API unsigned long long double_factorial(unsigned int n);
COBRA_API double gamma_double(double x);
COBRA_API unsigned long long binomial(unsigned int n, unsigned int k);
COBRA_API unsigned long long permute(unsigned int n, unsigned int k);

#ifdef __cplusplus
}
#endif
