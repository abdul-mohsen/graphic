#include "Graphic.h"
#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a > b) ? a : b)
#define min(a,b) ((a < b) ? a : b)
void swapInt(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void swapLong(size_t *a, size_t *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

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
  size_t yStart = max(0, y);
  size_t yEnd = min(cy + r, height);
  size_t r2 = r * r;
  for (size_t sy = yStart; sy < yEnd; sy++) {
    size_t y2 = (sy - cy) * (sy - cy);
    double_t x2 = r2 - y2;
    int xr = (int) sqrt(x2);
    size_t xStart = max(0, cx - xr);
    assert(cx + xr > 0);
    size_t xEnd = min((size_t) cx + xr, width);
    for (size_t sx = xStart; sx < xEnd; sx++) {
      pixels[sy * width + sx] = color;
    }
  }
}

void drawLine(uint32_t *pixels, size_t width, size_t height, uint32_t color, int x0, int y0, int x1, int y1, size_t thic) {
  if (y0 > y1) {
    swapInt(&y0, &y1);
    swapInt(&x0, &x1);
  }
  size_t yStart = max(0, y0);
  size_t yEnd = min(max(y0 + 1, y1), (int) height);
  int dy = y0 - y1;
  int dx = x0 - x1;
  int line = 0;
  double b = 0;
  if (dy == 0) {
    yStart -= thic;
    yEnd += thic;
    line = abs(dx);
  } else {
    b = (double) dx/dy ;
  }
  for (size_t sy = yStart; sy < yEnd; sy++) {
    int x = sy * b + x0;
    int xStart = max(0, (int) (x - thic));
    int xEnd = min(max(x, xStart + 1) + thic + line, width);
    for (int sx = xStart; sx < xEnd; sx++) {
      pixels[sy * width + sx] = color;
    }
  }
}

void drawTriangle(uint32_t *pixels, size_t width, size_t height, uint32_t color, int x0, int y0, int x1, int y1, int x2, int y2) {
  if (y0 > y1) {
    swapInt(&y0, &y1);
    swapInt(&x0, &x1);
  }
  if (y1 > y2) {
    swapInt(&y2, &y1);
    swapInt(&x2, &x1);
  }
  if (y0 > y1) {
    swapInt(&y0, &y1);
    swapInt(&x0, &x1);
  }
  size_t yStart = max(0, y0);
  size_t yEnd = min((size_t)max(0, y2), height);
  double m0 = (double) (x0 - x1) / (y0 - y1);
  double m1 = (double) (x0 - x2) / (y0 - y2);
  double m2 = (double) (x1 - x2) / (y1 - y2);
  for (size_t sy = yStart; sy < yEnd; sy++) {
    int si = (int) sy;
    size_t z = (si > y0) + (si > y1) + (si > y2);
    size_t xStart = max((sy - y0) * m1 + x0, 0) ;
    int tmp;
    if (z > 1) {
      tmp = (sy - y1) * m2 + x1;
    } else {
      tmp = (sy - y0) * m0 + x0;
    }
    size_t xEnd = (size_t)max(0, tmp);

    if (xStart>xEnd) {
      swapLong(&xStart, &xEnd);
    }
    xStart = max(0, xStart);
    xEnd = min((size_t) max(0, xEnd), width);
    for (size_t sx = xStart; sx <= xEnd; sx++) {
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
