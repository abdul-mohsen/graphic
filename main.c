#include "Graphic.h"

#define WIDTH 600
#define HEIGHT 800

static uint32_t pixels[HEIGHT * WIDTH];

int main()
{
  char * filePath = "output.ppm";
  fill(pixels, WIDTH, HEIGHT, 0xFF202020);
  fillRect(pixels, WIDTH, HEIGHT, 0xFFFF00FF, 234, -23, 100, 1000);
  int result = saveImage(pixels, WIDTH, HEIGHT, filePath);
  if (result == EXIT_FAILURE) {
    fprintf(stderr, "ERROR: could not save file %s: %i\n", filePath, result);
    printf("Couldn't save %s ", filePath);
  }
  return EXIT_SUCCESS;
}
