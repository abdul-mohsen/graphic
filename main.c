#include "Graphic.h"
#include <stdio.h>

#define WIDTH 600
#define HEIGHT 800

static uint32_t pixels[HEIGHT * WIDTH];

int main()
{
  printf(" ------ Program Start ------\n");
  char * filePath = "output.ppm";
  fill(pixels, WIDTH, HEIGHT, 0xFF202020);
  fillRect(pixels, WIDTH, HEIGHT, 0xFFFF00FF, 200, 200, 100, 100);
  fillCircle(pixels, WIDTH, HEIGHT, 0xFF335400, WIDTH, HEIGHT, WIDTH);
  drawLine(pixels, WIDTH, HEIGHT, 0xFFFFFFFF, 0, 0, WIDTH/16, HEIGHT, 1); 
  drawLine(pixels, WIDTH, HEIGHT, 0xFFFFFFFF, WIDTH/2, 0, WIDTH/2, HEIGHT, 1); 
  drawLine(pixels, WIDTH, HEIGHT, 0xFFFFFFFF, 0, HEIGHT/2, WIDTH, HEIGHT/2, 1); 

  drawLine(pixels, WIDTH, HEIGHT, 0xFFFFFFFF, 0, HEIGHT, WIDTH, 0, 1); 

  int result = saveImage(pixels, WIDTH, HEIGHT, filePath);
  if (result == EXIT_FAILURE) {
    fprintf(stderr, "ERROR: could not save file %s: %i\n", filePath, result);
    printf("Couldn't save %s ", filePath);
  }
  printf(" ------ Program End ------ \n");
  return EXIT_SUCCESS;
}
