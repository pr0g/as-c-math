#!/bin/bash

cmake -B build -G Ninja -DAS_MATH_ENABLE_TEST=ON \
  -DAS_MATH_ENABLE_COVERAGE=ON \
  -DCMAKE_C_COMPILER=gcc-14
cmake --build build
./build/as-c-math-test
# https://gcovr.com/en/stable/index.html
gcovr -r . --object-directory=./ --gcov-executable gcov-14 \
  --exclude test.c --html-details as-coverage-details.html 
