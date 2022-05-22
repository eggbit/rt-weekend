#pragma once

#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Vec3, Point3, Color;

Vec3 vector_negate(Vec3 v1);
Vec3 vector_add(Vec3 v1, Vec3 v2);
Vec3 vector_sub(Vec3 v1, Vec3 v2);
Vec3 vector_mul(Vec3 v1, double t);
Vec3 vector_mul_vec(Vec3 v1, Vec3 v2);
Vec3 vector_div(Vec3 v1, double t);
Vec3 vector_cross(Vec3 v1, Vec3 v2);
Vec3 vector_unit(Vec3 v1);
double vector_dot(Vec3 v1, Vec3 v2);
double vector_length(Vec3 v1);
