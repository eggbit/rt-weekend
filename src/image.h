#pragma once

#include <stdio.h>
#include "vec3.h"

void image_ppm_create(const char *filename, int width, int height);
void image_ppm_write(Color c);
void image_ppm_close();
