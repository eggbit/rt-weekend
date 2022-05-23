#include <stdio.h>
#include "vec3.h"
#include "image.h"
#include "ray.h"

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    const double aspect_ratio = 16.0/10.0;
    const int image_width = 400;
    const int image_height = image_width / aspect_ratio;

    // Camera
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    Point3 origin = {0, 0, 0};
    Vec3 horizonal = {viewport_width, 0, 0};
    Vec3 vertical = {0, viewport_height, 0};

    Vec3 horizonal_half = vector_div(horizonal, 2);
    Vec3 vertical_half = vector_div(vertical, 2);
    Vec3 v_misc = {0, 0, focal_length};

    // NOTE: This may be broken, too.
    // TODO: Clean this up.
    Vec3 lower_left_corner1 = vector_sub(origin, horizonal_half);
    Vec3 lower_left_corner2 = vector_sub(lower_left_corner1, vertical_half);
    Vec3 lower_left_corner = vector_sub(lower_left_corner2, v_misc);

    image_ppm_create("image.ppm", image_width, image_height);

    for (int j = image_height -1; j >= 0; --j) {
        for(int i = 0; i < image_width; ++i) {
            double u = (double)i / (image_width - 1);
            double v = (double)j / (image_height - 1);

            Vec3 h1 = vector_mul(horizonal, u);
            Vec3 v1 = vector_mul(vertical, v);
            
            Vec3 three = vector_add(lower_left_corner, h1);
            Vec3 four = vector_add(three, v1);
            Vec3 final = vector_sub(four, origin);
            
            Ray r = {
                origin,
                final
            };

            Color pixel = ray_color(r);

            image_ppm_write(pixel);
        }
    }

    image_ppm_close();
    return 0;
}
