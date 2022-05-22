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
            Color color = {
                (double)i / (image_width - 1),
                (double)j / (image_height - 1),
                0.25
            };

            image_ppm_write(color);
        }
    }

    image_ppm_close();
    return 0;
}
