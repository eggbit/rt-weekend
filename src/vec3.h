#pragma once

#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Vec3, Point3, Color;

Vec3 v3_negate(Vec3 v1);
Vec3 v3_add(Vec3 v1, Vec3 v2);
Vec3 v3_sub(Vec3 v1, Vec3 v2);
Vec3 v3_mul(Vec3 v1, double t);
Vec3 v3_mul_vec(Vec3 v1, Vec3 v2);
Vec3 v3_div(Vec3 v1, double t);
Vec3 v3_cross(Vec3 v1, Vec3 v2);
Vec3 v3_unit(Vec3 v1);
double v3_dot(Vec3 v1, Vec3 v2);
double v3_length(Vec3 v1);
