#pragma once
#include "cobra.h"

#ifdef __cplusplus
extern "C" {
#endif

COBRA_API double mean(const double* data, unsigned int length);
COBRA_API double median(double* data, unsigned int length);
COBRA_API double variance(const double* data, unsigned int length, int sample);
COBRA_API double stddev(const double* data, unsigned int length, int sample);
COBRA_API double covariance(const double* x, const double* y, unsigned int length, int sample);
COBRA_API double correlation(const double* x, const double* y, unsigned int length);

#ifdef __cplusplus
}
#endif
