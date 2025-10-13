#pragma once

#ifdef __cplusplus
extern "C" {
#endif

double clamp(double x, double lower, double upper);
double lerp(double a, double b, double t);
double smoothstep(double edge0, double edge1, double x);

#ifdef __cplusplus
}
#endif
