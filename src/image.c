#include "image.h"

static FILE *image;

void image_ppm_create(const char *filename, int width, int height) {
    image = fopen(filename, "wb");
    fprintf(image, "P3 %d %d 255\n", width, height);
}

void image_ppm_write(Color c) {
    fprintf(image, "%d %d %d\n", (int)(255.999 * c.x), (int)(255.999 * c.y), (int)(255.999 * c.z));
}

void image_ppm_close() {
    fclose(image);
}
