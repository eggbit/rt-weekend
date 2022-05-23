#pragma once

#include "vec3.h"

typedef struct {
    Point3 origin;
    Vec3 direction;
} Ray;

Point3 ray_at(Ray r, double t);
Color ray_color(Ray r);
