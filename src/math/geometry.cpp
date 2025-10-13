#include "geometry.h"
#include <cmath>

double distance_2d(Point2D a, Point2D b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return std::hypot(dx, dy);
}

double distance_3d(Point3D a, Point3D b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double dz = b.z - a.z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

double angle_between_vectors_2d(Point2D a, Point2D b) {
    double dot = a.x * b.x + a.y * b.y;
    double mag_a = std::hypot(a.x, a.y);
    double mag_b = std::hypot(b.x, b.y);
    return std::acos(dot / (mag_a * mag_b));
}

double angle_between_vectors_3d(Point3D a, Point3D b) {
    double dot = a.x * b.x + a.y * b.y + a.z * b.z;
    double mag_a = std::sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
    double mag_b = std::sqrt(b.x*b.x + b.y*b.y + b.z*b.z);
    return std::acos(dot / (mag_a * mag_b));
}
