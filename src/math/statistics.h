#pragma once

#ifdef __cplusplus
extern "C" {
#endif

double mean(const double* data, unsigned int length);
double median(double* data, unsigned int length);
double variance(const double* data, unsigned int length, int sample);
double stddev(const double* data, unsigned int length, int sample);
double covariance(const double* x, const double* y, unsigned int length, int sample);
double correlation(const double* x, const double* y, unsigned int length);

#ifdef __cplusplus
}
#endif
