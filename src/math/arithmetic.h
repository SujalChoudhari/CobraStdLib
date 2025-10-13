#pragma once

#ifdef __cplusplus
extern "C" {
#endif

double abs_double(double x);
double sign(double x);
double floor_double(double x);
double ceil_double(double x);
double round_double(double x);
double trunc_double(double x);

double round_to_double(double x, int decimals);
double round_significant_double(double x, int n);
double machine_epsilon(void);

#ifdef __cplusplus
}
#endif
