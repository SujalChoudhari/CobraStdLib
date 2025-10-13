#pragma once

#include "random.h"
#include <random>

#include "cobra.h"
#ifdef __cplusplus
extern "C" {
#endif


COBRA_API void seed_random(unsigned int seed);
COBRA_API double random_uniform(void);
COBRA_API int random_int(int min, int max);
COBRA_API double random_gauss(double mean, double stddev);


#ifdef __cplusplus
}
#endif
