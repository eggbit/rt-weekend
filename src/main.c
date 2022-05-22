#include <stdio.h>
#include "vec3.h"
#include "image.h"

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    const int image_width = 256;
    const int image_height = 256;

    image_ppm_create("image.ppm", image_width, image_height);

    for (int j = image_height -1; j >= 0; --j) {
        for(int i = 0; i < image_width; ++i) {
            double r = (double)i / (image_width - 1);
            double g = (double)j / (image_height - 1);
            double b = 0.25;

            int ir = 255.999 * r;
            int ig = 255.999 * g;
            int ib = 255.999 * b;

            image_ppm_write(ir, ig, ib);
        }
    }

    image_ppm_close();
    return 0;
}
