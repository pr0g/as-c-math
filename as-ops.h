#ifndef AS_OPS_MATH_H
#define AS_OPS_MATH_H

#include "as-types.h"

// constants
extern const float as_k_pi;
extern const float as_k_half_pi;
extern const float as_k_two_pi;
extern const float as_k_tau;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// vec2f
as_vec2f as_vec2f_from_point2f(as_point2f point);
as_vec2f as_vec2f_from_vec2i(as_vec2i vec);
as_vec2f as_vec2f_add_vec2f(as_vec2f lhs, as_vec2f rhs);
as_vec2f as_vec2f_sub_vec2f(as_vec2f lhs, as_vec2f rhs);
as_vec2f as_vec2f_mul_scalar(as_vec2f vec, float scale);
as_vec2f as_vec2f_div_scalar(as_vec2f vec, float scale);
float as_vec2f_length(as_vec2f vec);
float as_vec2f_wedge_vec2f(as_vec2f lhs, as_vec2f rhs);
float as_vec2f_dot_vec2f(as_vec2f lhs, as_vec2f rhs);
as_vec2f as_vec2f_normalized(as_vec2f vec);

// vec2i
as_vec2i as_vec2i_from_vec2f(as_vec2f vec);
as_vec2i as_vec2i_add_vec2i(as_vec2i lhs, as_vec2i rhs);
as_vec2i as_vec2i_sub_vec2i(as_vec2i lhs, as_vec2i rhs);
as_vec2f as_vec2i_mul_scalar(as_vec2i vec, float scale);
as_vec2f as_vec2i_div_scalar(as_vec2i vec, float scale);
float as_vec2i_length(as_vec2i vec);

// vec3f
as_vec3f as_vec3f_from_point3f(as_point3f point);
as_vec3f as_vec3f_from_vec3i(as_vec3i vec);
as_vec3f as_vec3f_from_mat34f(const as_mat34f* mat);
as_vec3f as_vec3f_add_vec3f(as_vec3f lhs, as_vec3f rhs);
as_vec3f as_vec3f_sub_vec3f(as_vec3f lhs, as_vec3f rhs);
as_vec3f as_vec3f_mul_scalar(as_vec3f vec, float scale);
as_vec3f as_vec3f_div_scalar(as_vec3f vec, float scale);
float as_vec3f_length(as_vec3f vec);
as_vec3f as_vec3f_rotate_x(as_vec3f vec, float angle);
as_vec3f as_vec3f_rotate_y(as_vec3f vec, float angle);
as_vec3f as_vec3f_rotate_z(as_vec3f vec, float angle);
as_vec3f as_vec3f_cross_vec3f(as_vec3f lhs, as_vec3f rhs);
float as_vec3f_dot_vec3f(as_vec3f lhs, as_vec3f rhs);
as_vec3f as_vec3f_normalized(as_vec3f vec);
as_vec3f as_vec3f_x_axis(void);
as_vec3f as_vec3f_y_axis(void);
as_vec3f as_vec3f_z_axis(void);
as_vec3f as_vec3f_mix(as_vec3f begin, as_vec3f end, float t);

// vec3i
as_vec3i as_vec3i_from_vec3f(as_vec3f vec);
as_vec3i as_vec3i_add_vec3i(as_vec3i lhs, as_vec3i rhs);
as_vec3i as_vec3i_sub_vec3i(as_vec3i lhs, as_vec3i rhs);
as_vec3f as_vec3i_mul_scalar(as_vec3i vec, float scale);
as_vec3f as_vec3i_div_scalar(as_vec3i vec, float scale);
float as_vec3i_length(as_vec3i vec);

// point2f
as_point2f as_point2f_from_vec2f(as_vec2f vec);
as_point2f as_point2f_from_point4f(as_point4f point);
as_point2f as_point2f_from_point2i(as_point2i point);
as_point2f as_point2f_add_vec2f(as_point2f point, as_vec2f vec);
as_vec2f as_point2f_sub_point2f(as_point2f lhs, as_point2f rhs);
float as_point2f_distance_point2f(as_point2f lhs, as_point2f rhs);

// point2i
as_point2i as_point2i_from_point2f(as_point2f point);
as_point2i as_point2i_add_vec2i(as_point2i point, as_vec2i vec);
as_vec2i as_point2i_sub_point2i(as_point2i lhs, as_point2i rhs);
float as_point2i_distance_point2i(as_point2i lhs, as_point2i rhs);

// point3f
as_point3f as_point3f_from_vec3f(as_vec3f vec);
as_point3f as_point3f_from_point3i(as_point3i point);
as_point3f as_point3f_add_vec3f(as_point3f point, as_vec3f vec);
as_point3f as_point3f_sub_vec3f(as_point3f point, as_vec3f vec);
as_vec3f as_point3f_sub_point3f(as_point3f lhs, as_point3f rhs);
as_point3f as_point3f_rotate_x(as_point3f point, float angle);
as_point3f as_point3f_rotate_y(as_point3f point, float angle);
as_point3f as_point3f_rotate_z(as_point3f point, float angle);
as_point3f as_point3f_mix(as_point3f begin, as_point3f end, float t);

// point3i
as_point3i as_point3i_from_point3f(as_point3f point);

// point4f
as_point4f as_point4f_from_point3f(as_point3f point);
as_point4f as_point4f_from_point2f(as_point2f point);

// mat22
int as_mat22_rc(int r, int c);
as_mat22f as_mat22f_identity(void);
as_mat22f as_mat22f_uniform_scale_from_float(float scale);
as_mat22f as_mat22f_scale_from_floats(float scale_x, float scale_y);
as_mat22f as_mat22f_scale_from_vec2f(as_vec2f scale_xy);
as_point2f as_mat22f_multiply_point2f(const as_mat22f* mat, as_point2f point);

// mat33
int as_mat33_rc(int r, int c);
as_mat33f as_mat33f_identity(void);
as_mat33f as_mat33f_uniform_scale_from_float(float scale);
as_mat33f as_mat33f_scale_from_floats(
  float scale_x, float scale_y, float scale_z);
as_mat33f as_mat33f_scale_from_vec3f(as_vec3f scale_xyz);
as_mat33f as_mat33f_transpose(const as_mat33f* mat);
as_mat33f as_mat33f_x_rotation_from_float(float rotation_radians);
as_mat33f as_mat33f_y_rotation_from_float(float rotation_radians);
as_mat33f as_mat33f_z_rotation_from_float(float rotation_radians);
as_mat33f as_mat33f_from_mat34f(const as_mat34f* mat);
as_point3f as_mat33f_multiply_point3f(const as_mat33f* mat, as_point3f point);
as_vec3f as_mat33f_multiply_vec3f(const as_mat33f* mat, as_vec3f vec);
as_mat33f as_mat33f_multiply_mat33f(const as_mat33f* lhs, const as_mat33f* rhs);
as_mat34f as_mat33f_multiply_mat34f(const as_mat33f* lhs, const as_mat34f* rhs);

// mat34
int as_mat34_rc(int r, int c);
as_mat34f as_mat34f_identity(void);
as_mat34f as_mat34f_translation_from_floats(
  float translation_x, float translation_y, float translation_z);
as_mat34f as_mat34f_translation_from_vec3f(as_vec3f translation);
as_mat34f as_mat34f_translation_from_point3f(as_point3f position);
as_mat34f as_mat34f_from_mat33f_and_vec3f(
  const as_mat33f* rotation, as_vec3f translation);
as_point3f as_mat34f_multiply_point3f(const as_mat34f* mat, as_point3f point);
as_vec3f as_mat34f_multiply_vec3f(const as_mat34f* mat, as_vec3f vec);
as_mat34f as_mat34f_multiply_mat34f(const as_mat34f* lhs, const as_mat34f* rhs);
as_mat34f as_mat34f_multiply_mat33f(const as_mat34f* lhs, const as_mat33f* rhs);
as_mat34f as_mat34f_inverse(const as_mat34f* mat);

// mat44
int as_mat44_rc(int r, int c);
as_mat44f as_mat44f_identity(void);
as_mat44f as_mat44f_multiply_mat44f(const as_mat44f* lhs, const as_mat44f* rhs);
as_mat44f as_mat44f_perspective_projection(
  float aspect_ratio, float fov, float near, float far);
as_point4f as_mat44f_multiply_point4f(const as_mat44f* mat, as_point4f point);
as_point4f as_mat44f_project_point3f(
  const as_mat44f* projection, as_point3f point);

// utils
void as_swapf(float* lhs, float* rhs);
void as_swapi(int* lhs, int* rhs);
int as_clampi(int value, int min, int max);
float as_clampf(float value, float min, float max);
int as_maxi(int lhs, int rhs);
float as_maxf(float lhs, float rhs);
int as_mini(int lhs, int rhs);
int as_minf(float lhs, float rhs);
float as_mixf(float begin, float end, float t);

float as_radians_from_degrees(float degrees);
float as_degrees_from_radians(float radians);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // AS_OPS_MATH_H