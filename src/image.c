#include "image.h"

static FILE *image;

void image_ppm_create(const char *filename, int width, int height) {
    image = fopen(filename, "wb");
    fprintf(image, "P3 %d %d 255\n", width, height);
}

void image_ppm_write(int r, int g, int b) {
    fprintf(image, "%d %d %d\n", r, g, b);
}

void image_ppm_close() {
    fclose(image);
}
