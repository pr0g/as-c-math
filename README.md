# as-c-math

C linear algebra math library (initial version created during [pikuma-3d-graphics](https://github.com/pr0g/pikuma-3d-graphics)).

## Conventions/Storage

- **Convention**: Column major
- **Storage**: Column major

`as-c-math` uses column major convention (matrices are multiplied right to left - post-multiply) with vectors appearing on the right of a matrix multiply. The storage order is also column major (basis axes are interleaved) so matrices must be transposed to put them in row major storage before being passed to any graphics API.

## as C++ library

- [as](https://github.com/pr0g/as) - C++ linear algebra math library  (templated).

## Alternative linear algebra math libraries written in C

- [linmath.h](https://github.com/datenwolf/linmath.h)
- [Handmade-Math](https://github.com/HandmadeMath/Handmade-Math)
- [kazmath](https://github.com/Kazade/kazmath)

## WIP

- ~~negate~~
- near
- vec_min
- vec_max
- vec_min_elem
- vec_max_elem
- vec_abs
- vec_clamp
- vec_saturate
- vec_floor
- vec_ceil
- vec_round
- vec_orthogonal (cw/ccw)
- reflect
- orthogonal
- orthonormal_basis
- point/vec average
- ~~mat_determinant~~
- ~~mat_inverse~~
- mat shear
- quaternion
- basis
- add _v postfix for matrix functions to allow call by value
