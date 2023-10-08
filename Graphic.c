#include "Graphic.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a > b) ? a : b)
#define min(a,b) ((a < b) ? a : b)

void fill(uint32_t *pixels, size_t width, size_t height, uint32_t color) {
  for (size_t i = 0; i < height * width; ++i) {
    pixels[i] = color;
  }
}  

void fillRect(uint32_t *pixels, size_t width, size_t height, uint32_t color, int x, int y, size_t w, size_t h) {
  size_t yStart = max(0, y);
  size_t yEnd = min(y + h, height);
  size_t xStart = max(0, x);
  size_t xEnd = min(x + w, width);
  for (size_t sy = yStart; sy < yEnd; sy++) {
    for (size_t sx = xStart; sx < xEnd; sx++) {
      pixels[sy * width + sx] = color;
    }
  }
}

void fillCircle(uint32_t *pixels, size_t width, size_t height, uint32_t color, int cx, int cy, size_t r) {
  int y = cy - r;
  int x = cx - r;
  size_t yStart = max(0, y);
  size_t yEnd = min(cy + r, height);
  size_t r2 = r * r;
  for (size_t sy = yStart; sy < yEnd; sy++) {
    size_t y2 = (sy - cy) * (sy - cy);
    double_t x2 = r2 - y2;
    int xr = (int) sqrt(x2);
    size_t xStart = max(0, cx - xr);
    size_t xEnd = min(cx + xr, width);
    for (size_t sx = xStart; sx < xEnd; sx++) {
      pixels[sy * width + sx] = color;
    }
  }
}

int saveImage(uint32_t *pixels, size_t width, size_t height, const char *filePath) {
  FILE *f = fopen(filePath, "wb");
  if (f == NULL) {
    return EXIT_FAILURE;
  }

  fprintf(f, "P6\n%zu %zu 255\n", width, height);
  if (ferror(f)) {
    fclose(f);
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < width * height; ++i) {
    uint32_t pixel = pixels[i];
    uint8_t bytes[3] = {
      (pixel>>(8 * 0))&0xFF,
      (pixel>>(8 * 1))&0xFF,
      (pixel>>(8 * 2))&0xFF,
    };

    fwrite(bytes, sizeof(bytes), 1, f);
    if (ferror(f)) {
      fclose(f);
      return EXIT_FAILURE;
    }
  }
   
  fclose(f);
  return EXIT_SUCCESS;
}
