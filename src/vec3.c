#include "vec3.h"

Vec3 vector_negate(Vec3 v1) {
    return (Vec3){ -v1.x, -v1.y, -v1.z };
}

Vec3 vector_add(Vec3 v1, Vec3 v2) {
    return (Vec3){
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z
    };
}

Vec3 vector_sub(Vec3 v1, Vec3 v2) {
    return (Vec3){
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    };
}

Vec3 vector_mul(Vec3 v1, double t) {
    return (Vec3) {
        v1.x * t,
        v1.y * t,
        v1.z * t
    };
}

Vec3 vector_mul_vec(Vec3 v1, Vec3 v2) {
    return (Vec3) {
        v1.x * v2.x,
        v1.y * v2.y,
        v1.z * v2.z
    };
}

Vec3 vector_div(Vec3 v1, double t) {
    return (Vec3) {
        v1.x * 1/t,
        v1.y * 1/t,
        v1.z * 1/t
    };
}

Vec3 vector_cross(Vec3 v1, Vec3 v2) {
    return (Vec3) {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    };
}

Vec3 vector_unit(Vec3 v1) {
    double l = vector_length(v1);
    
    return (Vec3) {
        v1.x / l,
        v1.y / l,
        v1.z / l
    };
}

double vector_dot(Vec3 v1, Vec3 v2) {
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

double vector_length(Vec3 v1) {
    return sqrt(v1.x*v1.x + v1.y*v1.y + v1.z*v1.z);
}
