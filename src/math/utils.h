#pragma once
#include "cobra.h"

#ifdef __cplusplus
extern "C" {
#endif

COBRA_API double clamp(double x, double lower, double upper);
COBRA_API double lerp(double a, double b, double t);
COBRA_API double smoothstep(double edge0, double edge1, double x);

#ifdef __cplusplus
}
#endif
