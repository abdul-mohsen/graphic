#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>

#define WIDTH 600
#define HEIGHT 800

void fill(uint32_t *pixels, size_t width, size_t height, uint32_t color) {
  for (size_t i = 0; i < height * width; ++i) {
    pixels[i] = color;
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

static uint32_t pixels[HEIGHT * WIDTH];

int main()
{
  fill(pixels, WIDTH, HEIGHT, 0xFF0000FF);
  saveImage(pixels, WIDTH, HEIGHT, "output.ppm");
  return EXIT_SUCCESS;
}
