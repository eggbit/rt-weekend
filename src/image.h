#pragma once

#include <stdio.h>

void image_ppm_create(const char *filename, int width, int height);
void image_ppm_write(int r, int g, int b);
void image_ppm_close();
