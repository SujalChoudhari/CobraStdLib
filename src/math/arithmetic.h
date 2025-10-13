#pragma once
#include "cobra.h"

#ifdef __cplusplus
extern "C" {
#endif

COBRA_API double abs_double(double x);
COBRA_API double sign(double x);
COBRA_API double floor_double(double x);
COBRA_API double ceil_double(double x);
COBRA_API double round_double(double x);
COBRA_API double trunc_double(double x);

COBRA_API double round_to_double(double x, int decimals);
COBRA_API double round_significant_double(double x, int n);
COBRA_API double machine_epsilon(void);

#ifdef __cplusplus
}
#endif
