#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void fill(uint32_t *pixels, size_t width, size_t height, uint32_t color);
void fillRect(uint32_t *pixels, size_t width, size_t height, uint32_t color, int x, int y, size_t w, size_t h);
void fillCircle(uint32_t *pixels, size_t width, size_t height, uint32_t color, int cx, int cy, size_t r);
int saveImage(uint32_t *pixels, size_t width, size_t height, const char *filePath);
