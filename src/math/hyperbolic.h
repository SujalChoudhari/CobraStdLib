#pragma once
#include "cobra.h"

#ifdef __cplusplus
extern "C" {
#endif

COBRA_API double sinh_double(double x);
COBRA_API double cosh_double(double x);
COBRA_API double tanh_double(double x);
COBRA_API double coth_double(double x);
COBRA_API double sech_double(double x);
COBRA_API double csch_double(double x);
    
COBRA_API double asinh_double(double x);
COBRA_API double acosh_double(double x);
COBRA_API double atanh_double(double x);
COBRA_API double acoth_double(double x);
COBRA_API double asech_double(double x);
COBRA_API double acsch_double(double x);

#ifdef __cplusplus
}
#endif
