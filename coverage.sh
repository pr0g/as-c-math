#!/bin/bash

cmake -B build -G Ninja -DAS_MATH_ENABLE_TEST=ON \
  -DAS_MATH_ENABLE_COVERAGE=ON \
  -DCMAKE_C_COMPILER=gcc-12
cmake --build build
./build/as-c-math-test
cd build/CMakeFiles/as-c-math.dir
gcov-12 as-ops.c.o
cd ../../..
lcov --directory build/CMakeFiles/as-c-math.dir/ --capture \
  --output-file build/as-ops-coverage.info --gcov-tool=gcov-12
genhtml build/as-ops-coverage.info --output-directory build/coverage-output
# open build/coverage-output/index.html
