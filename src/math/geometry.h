#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    double x;
    double y;
} Point2D;

typedef struct {
    double x;
    double y;
    double z;
} Point3D;

double distance_2d(Point2D a, Point2D b);
double distance_3d(Point3D a, Point3D b);
double angle_between_vectors_2d(Point2D a, Point2D b);
double angle_between_vectors_3d(Point3D a, Point3D b);

#ifdef __cplusplus
}
#endif
