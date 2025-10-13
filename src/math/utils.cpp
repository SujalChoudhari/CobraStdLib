#include "utils.h"

double clamp(double x, double lower, double upper) {
    if (x < lower) return lower;
    if (x > upper) return upper;
    return x;
}

double lerp(double a, double b, double t) {
    return a + t * (b - a);
}

double smoothstep(double edge0, double edge1, double x) {
    if (x <= edge0) return 0.0;
    if (x >= edge1) return 1.0;
    double t = (x - edge0) / (edge1 - edge0);
    return t * t * (3 - 2 * t);
}
