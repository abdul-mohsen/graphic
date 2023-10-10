#!/bin/bash
set -ex
clear
rm -rf build
mkdir build

clang -O3 -Wall -Wextra -o build/main main.c Graphic.c -ggdb
# clang -O3 -Wall -Wextra -o wasm.wasm  wasm.c Graphic.c  -ggdb --sysroot /tmp/wasi-libc --target=wasm32-wasi

echo done
./build/main 
