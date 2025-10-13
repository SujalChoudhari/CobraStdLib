#include "random.h"
#include <random>

static std::mt19937 rng(std::random_device{}());

void seed_random(unsigned int seed) {
    rng.seed(seed);
}

double random_uniform(void) {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}

int random_int(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

double random_gauss(double mean, double stddev) {
    std::normal_distribution<double> dist(mean, stddev);
    return dist(rng);
}
