#include "ray.h"

Point3 ray_at(Ray r, double t) {
    return vector_add(r.origin, vector_mul(r.direction, t));
}

Color ray_color(Ray r) {
    Vec3 unit_direction = vector_unit(r.direction);
    double t = 0.5 * (unit_direction.y + 1.0);

    Color c1 = { 1.0, 1.0, 1.0 };
    Color c2 = { 0.5, 0.7, 1.0 };

    return vector_add(vector_mul(c1, 1.0 - t), vector_mul(c2, t));
}
