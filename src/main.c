#include <stdio.h>
#include <stdarg.h>
#include "vec3.h"
#include "image.h"
#include "ray.h"

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    const double aspect_ratio = 16.0/10.0;
    const int image_width = 640;
    const int image_height = image_width / aspect_ratio;

    // Camera
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    Point3 origin = {0, 0, 0};
    Vec3 horizonal = {viewport_width, 0, 0};
    Vec3 vertical = {0, viewport_height, 0};
    Vec3 v_misc = {0, 0, focal_length};

    Vec3 lower_left_corner = v3_sub(origin, v3_div(horizonal, 2));
    lower_left_corner = v3_sub(lower_left_corner, v3_div(vertical, 2));
    lower_left_corner = v3_sub(lower_left_corner, v_misc);

    image_ppm_create("image.ppm", image_width, image_height);

    for (int j = image_height -1; j >= 0; --j) {
        for(int i = 0; i < image_width; ++i) {
            double u = (double)i / (image_width - 1);
            double v = (double)j / (image_height - 1);
            
            Vec3 direction = v3_add(lower_left_corner, v3_mul(horizonal, u));
            direction = v3_add(direction, v3_mul(vertical, v));
            direction = v3_sub(direction, origin);
            
            Ray r = { origin, direction };

            Color pixel = ray_color(r);

            image_ppm_write(pixel);
        }
    }

    image_ppm_close();
    return 0;
}
