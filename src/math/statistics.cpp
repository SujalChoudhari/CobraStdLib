#include "statistics.h"
#include <algorithm>
#include <cmath>

double mean(const double* data, unsigned int length) {
    if (length == 0) return 0;
    double sum = 0.0;
    for (unsigned int i = 0; i < length; ++i) {
        sum += data[i];
    }
    return sum / length;
}

double median(double* data, unsigned int length) {
    if (length == 0) return 0;
    std::sort(data, data + length);
    if (length % 2 == 1) {
        return data[length / 2];
    } else {
        return (data[length / 2 - 1] + data[length / 2]) / 2.0;
    }
}

double variance(const double* data, unsigned int length, int sample) {
    if (length <= 1) return 0;
    double m = mean(data, length);
    double sum_sq_diff = 0.0;
    for (unsigned int i = 0; i < length; ++i) {
        double diff = data[i] - m;
        sum_sq_diff += diff * diff;
    }
    return sum_sq_diff / (length - (sample ? 1 : 0));
}

double stddev(const double* data, unsigned int length, int sample) {
    return std::sqrt(variance(data, length, sample));
}

double covariance(const double* x, const double* y, unsigned int length, int sample) {
    if (length <= 1) return 0;
    double mean_x = mean(x, length);
    double mean_y = mean(y, length);
    double cov = 0.0;
    for (unsigned int i = 0; i < length; ++i) {
        cov += (x[i] - mean_x) * (y[i] - mean_y);
    }
    return cov / (length - (sample ? 1 : 0));
}

double correlation(const double* x, const double* y, unsigned int length) {
    double cov = covariance(x, y, length, 1);
    double std_x = stddev(x, length, 1);
    double std_y = stddev(y, length, 1);
    if (std_x == 0 || std_y == 0) return 0;
    return cov / (std_x * std_y);
}
