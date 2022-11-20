#ifndef TH_TYPES_MATH_H
#define TH_TYPES_MATH_H

typedef struct vec2f_t {
  float x;
  float y;
} vec2f_t;

typedef struct vec3f_t {
  float x;
  float y;
  float z;
} vec3f_t;

typedef struct vec2i_t {
  int x;
  int y;
} vec2i_t;

typedef struct vec3i_t {
  int x;
  int y;
  int z;
} vec3i_t;

typedef struct point2f_t {
  float x;
  float y;
} point2f_t;

typedef struct point3f_t {
  float x;
  float y;
  float z;
} point3f_t;

typedef struct point4f_t {
  float x;
  float y;
  float z;
  float w;
} point4f_t;

typedef struct point2i_t {
  int x;
  int y;
} point2i_t;

typedef struct point3i_t {
  int x;
  int y;
  int z;
} point3i_t;

typedef struct size2i_t {
  int width;
  int height;
} size2i_t;

typedef struct rect_t {
  point2i_t pos;
  size2i_t size;
} rect_t;

typedef struct mat22f_t {
  float elem[4];
} mat22f_t;

typedef struct mat33f_t {
  float elem[9];
} mat33f_t;

typedef struct mat44f_t {
  float elem[16];
} mat44f_t;

typedef struct mat34f_t {
  float elem[12];
} mat34f_t;

typedef struct plane_t {
  point3f_t point;
  vec3f_t normal;
} plane_t;

#endif // TH_TYPES_MATH_H
