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
as_vec2f as_vec2f_from_float(float value);
as_vec2f as_vec2f_add_vec2f(as_vec2f lhs, as_vec2f rhs);
as_vec2f as_vec2f_sub_vec2f(as_vec2f lhs, as_vec2f rhs);
as_vec2f as_vec2f_mul_float(as_vec2f vec, float scalar);
as_vec2f as_vec2f_div_float(as_vec2f vec, float scalar);
float as_vec2f_length(as_vec2f vec);
float as_vec2f_length_sq(as_vec2f vec);
float as_vec2f_wedge_vec2f(as_vec2f lhs, as_vec2f rhs);
float as_vec2f_dot_vec2f(as_vec2f lhs, as_vec2f rhs);
as_vec2f as_vec2f_normalize(as_vec2f vec);
as_vec2f as_vec2f_mix(as_vec2f begin, as_vec2f end, float t);
as_vec2f as_vec2f_negate(as_vec2f vec);

// vec2i
as_vec2i as_vec2i_from_vec2f(as_vec2f vec);
as_vec2i as_vec2i_from_int(int value);
as_vec2i as_vec2i_add_vec2i(as_vec2i lhs, as_vec2i rhs);
as_vec2i as_vec2i_sub_vec2i(as_vec2i lhs, as_vec2i rhs);
as_vec2f as_vec2i_mul_float(as_vec2i vec, float scalar);
as_vec2f as_vec2i_div_float(as_vec2i vec, float scalar);
float as_vec2i_length(as_vec2i vec);
int as_vec2i_length_sq(as_vec2i vec);
as_vec2i as_vec2i_negate(as_vec2i vec);

// vec3f
as_vec3f as_vec3f_from_point3f(as_point3f point);
as_vec3f as_vec3f_from_vec3i(as_vec3i vec);
as_vec3f as_vec3f_from_mat34f(const as_mat34f* mat, int col);
as_vec3f as_vec3f_from_mat34f_v(as_mat34f mat, int col);
as_vec3f as_vec3f_from_float(float value);
as_vec3f as_vec3f_add_vec3f(as_vec3f lhs, as_vec3f rhs);
as_vec3f as_vec3f_sub_vec3f(as_vec3f lhs, as_vec3f rhs);
as_vec3f as_vec3f_mul_float(as_vec3f vec, float scalar);
as_vec3f as_vec3f_div_float(as_vec3f vec, float scalar);
float as_vec3f_length(as_vec3f vec);
float as_vec3f_length_sq(as_vec3f vec);
as_vec3f as_vec3f_rotate_x_axis(as_vec3f vec, float radians);
as_vec3f as_vec3f_rotate_y_axis(as_vec3f vec, float radians);
as_vec3f as_vec3f_rotate_z_axis(as_vec3f vec, float radians);
as_vec3f as_vec3f_cross_vec3f(as_vec3f lhs, as_vec3f rhs);
float as_vec3f_dot_vec3f(as_vec3f lhs, as_vec3f rhs);
as_vec3f as_vec3f_normalize(as_vec3f vec);
as_vec3f as_vec3f_x_axis(void);
as_vec3f as_vec3f_y_axis(void);
as_vec3f as_vec3f_z_axis(void);
as_vec3f as_vec3f_mix(as_vec3f begin, as_vec3f end, float t);
as_vec3f as_vec3f_negate(as_vec3f vec);

// vec3i
as_vec3i as_vec3i_from_vec3f(as_vec3f vec);
as_vec3i as_vec3i_add_vec3i(as_vec3i lhs, as_vec3i rhs);
as_vec3i as_vec3i_sub_vec3i(as_vec3i lhs, as_vec3i rhs);
as_vec3f as_vec3i_mul_float(as_vec3i vec, float scalar);
as_vec3f as_vec3i_div_float(as_vec3i vec, float scalar);
float as_vec3i_length(as_vec3i vec);
int as_vec3i_length_sq(as_vec3i vec);
as_vec3i as_vec3i_negate(as_vec3i vec);

// point2f
as_point2f as_point2f_from_vec2f(as_vec2f vec);
as_point2f as_point2f_from_point4f(as_point4f point);
as_point2f as_point2f_from_point2i(as_point2i point);
as_point2f as_point2f_from_float(float value);
as_point2f as_point2f_add_vec2f(as_point2f point, as_vec2f vec);
as_vec2f as_point2f_sub_point2f(as_point2f lhs, as_point2f rhs);
float as_point2f_distance_point2f(as_point2f lhs, as_point2f rhs);
as_point2f as_point2f_negate(as_point2f point);

// point2i
as_point2i as_point2i_from_point2f(as_point2f point);
as_point2i as_point2i_from_vec2i(as_vec2i vec);
as_point2i as_point2i_from_int(int value);
as_point2i as_point2i_add_vec2i(as_point2i point, as_vec2i vec);
as_vec2i as_point2i_sub_point2i(as_point2i lhs, as_point2i rhs);
float as_point2i_distance_point2i(as_point2i lhs, as_point2i rhs);
as_point2i as_point2i_negate(as_point2i point);

// point3f
as_point3f as_point3f_from_vec3f(as_vec3f vec);
as_point3f as_point3f_from_float(float value);
as_point3f as_point3f_add_vec3f(as_point3f point, as_vec3f vec);
as_vec3f as_point3f_sub_point3f(as_point3f lhs, as_point3f rhs);
as_point3f as_point3f_rotate_x_axis(as_point3f point, float radians);
as_point3f as_point3f_rotate_y_axis(as_point3f point, float radians);
as_point3f as_point3f_rotate_z_axis(as_point3f point, float radians);
as_point3f as_point3f_mix(as_point3f begin, as_point3f end, float t);
as_point3f as_point3f_negate(as_point3f point);

// point4f
as_point4f as_point4f_from_point3f(as_point3f point);
as_point4f as_point4f_from_point2f(as_point2f point);

// mat22
int as_mat22_rc(int r, int c);
as_mat22f as_mat22f_identity(void);
as_mat22f as_mat22f_uniform_scale(float scale);
as_mat22f as_mat22f_scale_from_floats(float scale_x, float scale_y);
as_mat22f as_mat22f_scale_from_vec2f(as_vec2f scale_xy);
as_mat22f as_mat22f_rotation(float radians);
as_point2f as_mat22f_mul_point2f(const as_mat22f* mat, as_point2f point);
as_point2f as_mat22f_mul_point2f_v(as_mat22f mat, as_point2f point);
float as_mat22f_determinant(const as_mat22f* mat);
float as_mat22f_determinant_v(as_mat22f mat);
as_mat22f as_mat22f_inverse(const as_mat22f* mat);
as_mat22f as_mat22f_inverse_v(as_mat22f mat);

// mat33
int as_mat33_rc(int r, int c);
as_mat33f as_mat33f_identity(void);
as_mat33f as_mat33f_uniform_scale(float scale);
as_mat33f as_mat33f_scale_from_floats(
  float scale_x, float scale_y, float scale_z);
as_mat33f as_mat33f_scale_from_vec3f(as_vec3f scale_xyz);
as_mat33f as_mat33f_transpose(const as_mat33f* mat);
as_mat33f as_mat33f_transpose_v(as_mat33f mat);
as_mat33f as_mat33f_x_axis_rotation(float radians);
as_mat33f as_mat33f_y_axis_rotation(float radians);
as_mat33f as_mat33f_z_axis_rotation(float radians);
as_mat33f as_mat33f_from_mat34f(const as_mat34f* mat);
as_mat33f as_mat33f_from_mat34f_v(as_mat34f mat);
as_point3f as_mat33f_mul_point3f(const as_mat33f* mat, as_point3f point);
as_point3f as_mat33f_mul_point3f_v(as_mat33f mat, as_point3f point);
as_vec3f as_mat33f_mul_vec3f(const as_mat33f* mat, as_vec3f vec);
as_vec3f as_mat33f_mul_vec3f_v(as_mat33f mat, as_vec3f vec);
as_mat33f as_mat33f_mul_mat33f(const as_mat33f* lhs, const as_mat33f* rhs);
as_mat33f as_mat33f_mul_mat33f_v(as_mat33f lhs, as_mat33f rhs);
as_mat34f as_mat33f_mul_mat34f(const as_mat33f* lhs, const as_mat34f* rhs);
as_mat34f as_mat33f_mul_mat34f_v(as_mat33f lhs, as_mat34f rhs);
float as_mat33f_determinant(const as_mat33f* mat);
float as_mat33f_determinant_v(as_mat33f mat);
as_mat33f as_mat33f_inverse(const as_mat33f* mat);
as_mat33f as_mat33f_inverse_v(as_mat33f mat);

// mat34
int as_mat34_rc(int r, int c);
as_mat34f as_mat34f_identity(void);
as_mat34f as_mat34f_translation_from_floats(
  float translation_x, float translation_y, float translation_z);
as_mat34f as_mat34f_translation_from_vec3f(as_vec3f translation);
as_mat34f as_mat34f_translation_from_point3f(as_point3f position);
as_mat34f as_mat34f_from_mat33f_and_vec3f(
  const as_mat33f* rotation, as_vec3f translation);
as_mat34f as_mat34f_from_mat33f_and_vec3f_v(
  as_mat33f rotation, as_vec3f translation);
as_point3f as_mat34f_mul_point3f(const as_mat34f* mat, as_point3f point);
as_point3f as_mat34f_mul_point3f_v(as_mat34f mat, as_point3f point);
as_vec3f as_mat34f_mul_vec3f(const as_mat34f* mat, as_vec3f vec);
as_vec3f as_mat34f_mul_vec3f_v(as_mat34f mat, as_vec3f vec);
as_mat34f as_mat34f_mul_mat34f(const as_mat34f* lhs, const as_mat34f* rhs);
as_mat34f as_mat34f_mul_mat34f_v(as_mat34f lhs, as_mat34f rhs);
as_mat34f as_mat34f_mul_mat33f(const as_mat34f* lhs, const as_mat33f* rhs);
as_mat34f as_mat34f_mul_mat33f_v(as_mat34f lhs, as_mat33f rhs);
as_mat34f as_mat34f_inverse(const as_mat34f* mat);
as_mat34f as_mat34f_inverse_v(as_mat34f mat);

// mat44
int as_mat44_rc(int r, int c);
as_mat44f as_mat44f_identity(void);
as_mat44f as_mat44f_translation_from_floats(
  float translation_x, float translation_y, float translation_z);
as_mat44f as_mat44f_translation_from_vec3f(as_vec3f translation);
as_mat44f as_mat44f_translation_from_point3f(as_point3f position);
as_mat44f as_mat44f_from_mat33f_and_vec3f(
  const as_mat33f* mat33, as_vec3f translation);
as_mat44f as_mat44f_from_mat33f_and_vec3f_v(
  as_mat33f mat33, as_vec3f translation);
as_mat44f as_mat44f_transpose(const as_mat44f* mat);
as_mat44f as_mat44f_transpose_v(as_mat44f mat);
as_mat44f as_mat44f_mul_mat44f(const as_mat44f* lhs, const as_mat44f* rhs);
as_mat44f as_mat44f_mul_mat44f_v(as_mat44f lhs, as_mat44f rhs);
as_mat44f as_mat44f_perspective_projection_depth_zero_to_one_lh(
  float aspect_ratio, float vertical_fov_radians, float near, float far);
as_mat44f as_mat44f_perspective_projection_depth_zero_to_one_rh(
  float aspect_ratio, float vertical_fov_radians, float near, float far);
as_mat44f as_mat44f_perspective_projection_depth_minus_one_to_one_lh(
  float aspect_ratio, float vertical_fov_radians, float near, float far);
as_mat44f as_mat44f_perspective_projection_depth_minus_one_to_one_rh(
  float aspect_ratio, float vertical_fov_radians, float near, float far);
as_point4f as_mat44f_mul_point4f(const as_mat44f* mat, as_point4f point);
as_point4f as_mat44f_mul_point4f_v(as_mat44f mat, as_point4f point);
as_point4f as_mat44f_project_point3f(
  const as_mat44f* projection, as_point3f point);
as_point4f as_mat44f_project_point3f_v(
  as_mat44f projection, as_point3f point);
float as_mat44f_determinant(const as_mat44f* mat);
float as_mat44f_determinant_v(as_mat44f mat);
as_mat44f as_mat44f_inverse(const as_mat44f* mat);
as_mat44f as_mat44f_inverse_v(as_mat44f mat);

// utils
void as_swap_float(float* lhs, float* rhs);
void as_swap_int(int* lhs, int* rhs);
float as_clamp_float(float value, float min, float max);
int as_clamp_int(int value, int min, int max);
float as_max_float(float lhs, float rhs);
int as_max_int(int lhs, int rhs);
int as_min_float(float lhs, float rhs);
int as_min_int(int lhs, int rhs);
float as_mix_float(float begin, float end, float t);

float as_radians_from_degrees(float degrees);
float as_degrees_from_radians(float radians);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // AS_OPS_MATH_H
