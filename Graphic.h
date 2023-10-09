#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void fill(uint32_t *pixels, size_t width, size_t height, uint32_t color);
void fillRect(uint32_t *pixels, size_t width, size_t height, uint32_t color, int x, int y, size_t w, size_t h);
void fillCircle(uint32_t *pixels, size_t width, size_t height, uint32_t color, int cx, int cy, size_t r);
void drawLine(uint32_t *pixels, size_t width, size_t height, uint32_t color, int x0, int y0, int x1, int y1, size_t thic);
void drawTriangle(uint32_t *pixels, size_t width, size_t height, uint32_t color, int x0, int y0, int x1, int y1, int x2, int y2);
int saveImage(uint32_t *pixels, size_t width, size_t height, const char *filePath);
