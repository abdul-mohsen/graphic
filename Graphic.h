#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void fill(uint32_t *pixels, size_t width, size_t height, uint32_t color);
int saveImage(uint32_t *pixels, size_t width, size_t height, const char *filePath);
void fillRect(uint32_t *pixels, size_t width, size_t height, uint32_t color, int x, int y, size_t w, size_t h);
