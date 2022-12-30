#ifndef AS_TYPES_MATH_H
#define AS_TYPES_MATH_H

typedef struct as_vec2f {
  union {
    struct {
      float x;
      float y;
    };
    float elem[2];
  };
} as_vec2f;

typedef struct as_vec3f {
  union {
    struct {
      float x;
      float y;
      float z;
    };
    float elem[3];
  };
} as_vec3f;

typedef struct as_vec2i {
  union {
    struct {
      int x;
      int y;
    };
    int elem[2];
  };
} as_vec2i;

typedef struct as_vec3i {
  union {
    struct {
      int x;
      int y;
      int z;
    };
    int elem[3];
  };
} as_vec3i;

typedef struct as_point2f {
  union {
    struct {
      float x;
      float y;
    };
    float elem[2];
  };
} as_point2f;

typedef struct as_point3f {
  union {
    struct {
      float x;
      float y;
      float z;
    };
    float elem[3];
  };
} as_point3f;

typedef struct as_point4f {
  union {
    struct {
      float x;
      float y;
      float z;
      float w;
    };
    float elem[4];
  };
} as_point4f;

typedef struct as_point2i {
  union {
    struct {
      int x;
      int y;
    };
    int elem[2];
  };
} as_point2i;

typedef struct as_size2i {
  union {
    struct {
      int width;
      int height;
    };
    int elem[2];
  };
} as_size2i;

typedef struct as_rect {
  as_point2i pos;
  as_size2i size;
} as_rect;

typedef struct as_mat22f {
  float elem[4];
} as_mat22f;

typedef struct as_mat33f {
  float elem[9];
} as_mat33f;

typedef struct as_mat44f {
  float elem[16];
} as_mat44f;

typedef struct as_mat34f {
  float elem[12];
} as_mat34f;

typedef struct as_plane {
  as_point3f point;
  as_vec3f normal;
} as_plane;

#endif // AS_TYPES_MATH_H
