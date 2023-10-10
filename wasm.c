#include "Graphic.h" 
#include <stdint.h>

#define WIDTH 600
#define HEIGHT 800

static uint32_t pixels[HEIGHT * WIDTH];

uint32_t *render(void) {

  fill(pixels, WIDTH, HEIGHT, 0xFF181818);
  fillRect(pixels, WIDTH, HEIGHT, 0xFFFF00FF, 200, 200, 100, 100);
  fillCircle(pixels, WIDTH, HEIGHT, 0xFF335400, WIDTH, HEIGHT, WIDTH);
  drawLine(pixels, WIDTH, HEIGHT, 0xFFFFFFFF, 0, 0, WIDTH/16, HEIGHT, 5); 
  drawLine(pixels, WIDTH, HEIGHT, 0xFFFFFFFF, WIDTH/2, 0, WIDTH/2, HEIGHT, 0); 
  drawLine(pixels, WIDTH, HEIGHT, 0xFFFFFFFF, 0, HEIGHT/2, WIDTH, HEIGHT/2, 0); 
  drawLine(pixels, WIDTH, HEIGHT, 0xFFFFFFFF, 0, HEIGHT, WIDTH, 0, 0); 
  drawTriangle(pixels, WIDTH, HEIGHT, 0xFF004FAA, WIDTH/4, HEIGHT/8, 0, HEIGHT/2, WIDTH/2, 0);
  drawTriangle(pixels, WIDTH, HEIGHT, 0xFF004FAA, WIDTH, HEIGHT, 200, HEIGHT, 200, HEIGHT/2);
  return  pixels;
}
