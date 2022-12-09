#include "as-ops.h"

#include <math.h>

const float as_k_pi = 3.14159265358979323846f;
const float as_k_half_pi = 1.57079632679489661923f;
const float as_k_two_pi = 6.28318530717958647692f;
const float as_k_tau = 6.28318530717958647692f;

as_vec2f as_vec2f_from_point2f(const as_point2f point) {
  return (as_vec2f){point.x, point.y};
}

as_vec2f as_vec2f_from_vec2i(const as_vec2i vec) {
  return (as_vec2f){(float)vec.x, (float)vec.y};
}

as_vec2f as_vec2f_from_float(const float value) {
  return (as_vec2f){value, value};
}

as_vec2f as_vec2f_add_vec2f(const as_vec2f lhs, const as_vec2f rhs) {
  return (as_vec2f){.x = lhs.x + rhs.x, .y = lhs.y + rhs.y};
}

as_vec2f as_vec2f_sub_vec2f(const as_vec2f lhs, const as_vec2f rhs) {
  return (as_vec2f){.x = lhs.x - rhs.x, .y = lhs.y - rhs.y};
}

as_vec2f as_vec2f_mul_float(const as_vec2f vec, const float scalar) {
  return (as_vec2f){.x = vec.x * scalar, .y = vec.y * scalar};
}

as_vec2f as_vec2f_div_float(const as_vec2f vec, const float scalar) {
  return as_vec2f_mul_float(vec, 1.0f / scalar);
}

float as_vec2f_length(const as_vec2f vec) {
  return sqrtf(as_vec2f_length_sq(vec));
}

float as_vec2f_length_sq(const as_vec2f vec) {
  return as_vec2f_dot_vec2f(vec, vec);
}

float as_vec2f_wedge_vec2f(const as_vec2f lhs, const as_vec2f rhs) {
  return lhs.x * rhs.y - lhs.y * rhs.x;
}

float as_vec2f_dot_vec2f(const as_vec2f lhs, const as_vec2f rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}

as_vec2f as_vec2f_normalized(const as_vec2f vec) {
  return as_vec2f_mul_float(vec, 1.0f / as_vec2f_length(vec));
}

as_vec2i as_vec2i_from_vec2f(const as_vec2f vec) {
  return (as_vec2i){(int)roundf(vec.x), (int)roundf(vec.y)};
}

as_vec2i as_vec2i_from_int(const int value) {
  return (as_vec2i){(int)value, (int)value};
}

as_vec2i as_vec2i_add_vec2i(const as_vec2i lhs, const as_vec2i rhs) {
  return (as_vec2i){.x = lhs.x + rhs.x, .y = lhs.y + rhs.y};
}

as_vec2i as_vec2i_sub_vec2i(const as_vec2i lhs, const as_vec2i rhs) {
  return (as_vec2i){.x = lhs.x - rhs.x, .y = lhs.y - rhs.y};
}

as_vec2f as_vec2i_mul_float(const as_vec2i vec, const float scalar) {
  return (as_vec2f){.x = (float)vec.x * scalar, .y = (float)vec.y * scalar};
}

as_vec2f as_vec2i_div_float(const as_vec2i vec, const float scalar) {
  return as_vec2i_mul_float(vec, 1.0f / scalar);
}

float as_vec2i_length(const as_vec2i vec) {
  return sqrtf((float)as_vec2i_length_sq(vec));
}

int as_vec2i_length_sq(const as_vec2i vec) {
  return vec.x * vec.x + vec.y * vec.y;
}

as_vec3f as_vec3f_from_point3f(const as_point3f point) {
  return (as_vec3f){point.x, point.y, point.z};
}

as_vec3f as_vec3f_from_vec3i(const as_vec3i vec) {
  return (as_vec3f){(float)vec.x, (float)vec.y, (float)vec.z};
}

as_vec3f as_vec3f_from_mat34f(const as_mat34f* const mat, const int col) {
  return (as_vec3f){mat->elem[col], mat->elem[col + 4], mat->elem[col + 8]};
}

as_vec3f as_vec3f_from_float(const float value) {
  return (as_vec3f){value, value, value};
}

as_vec3f as_vec3f_add_vec3f(const as_vec3f lhs, const as_vec3f rhs) {
  return (as_vec3f){.x = lhs.x + rhs.x, .y = lhs.y + rhs.y, .z = lhs.z + rhs.z};
}

as_vec3f as_vec3f_sub_vec3f(const as_vec3f lhs, const as_vec3f rhs) {
  return (as_vec3f){.x = lhs.x - rhs.x, .y = lhs.y - rhs.y, .z = lhs.z - rhs.z};
}

as_vec3f as_vec3f_mul_float(const as_vec3f vec, const float scalar) {
  return (as_vec3f){
    .x = vec.x * scalar, .y = vec.y * scalar, .z = vec.z * scalar};
}

as_vec3f as_vec3f_div_float(const as_vec3f vec, const float scalar) {
  return as_vec3f_mul_float(vec, 1.0f / scalar);
}

float as_vec3f_length(const as_vec3f vec) {
  return sqrtf(as_vec3f_length_sq(vec));
}

float as_vec3f_length_sq(const as_vec3f vec) {
  return as_vec3f_dot_vec3f(vec, vec);
}

as_vec3f as_vec3f_rotate_x_axis(const as_vec3f vec, const float radians) {
  const float cos_angle = cosf(radians);
  const float sin_angle = sinf(radians);
  return (as_vec3f){
    .x = vec.x,
    .y = vec.y * cos_angle - vec.z * sin_angle,
    .z = vec.y * sin_angle + vec.z * cos_angle};
}

as_vec3f as_vec3f_rotate_y_axis(const as_vec3f vec, const float radians) {
  const float cos_angle = cosf(radians);
  const float sin_angle = sinf(radians);
  return (as_vec3f){
    .x = vec.x * cos_angle + vec.z * sin_angle,
    .y = vec.y,
    .z = -vec.x * sin_angle + vec.z * cos_angle};
}

as_vec3f as_vec3f_rotate_z_axis(const as_vec3f vec, const float radians) {
  const float cos_angle = cosf(radians);
  const float sin_angle = sinf(radians);
  return (as_vec3f){
    .x = vec.x * cos_angle - vec.y * sin_angle,
    .y = vec.x * sin_angle + vec.y * cos_angle,
    .z = vec.z};
}

as_vec3f as_vec3f_cross_vec3f(const as_vec3f lhs, const as_vec3f rhs) {
  return (as_vec3f){
    lhs.y * rhs.z - lhs.z * rhs.y,
    lhs.z * rhs.x - lhs.x * rhs.z,
    lhs.x * rhs.y - lhs.y * rhs.x};
}

float as_vec3f_dot_vec3f(const as_vec3f lhs, const as_vec3f rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

as_vec3f as_vec3f_normalized(const as_vec3f vec) {
  return as_vec3f_div_float(vec, as_vec3f_length(vec));
}

as_vec3f as_vec3f_x_axis(void) {
  return (as_vec3f){.x = 1.0f};
}

as_vec3f as_vec3f_y_axis(void) {
  return (as_vec3f){.y = 1.0f};
}

as_vec3f as_vec3f_z_axis(void) {
  return (as_vec3f){.z = 1.0f};
}

as_vec3f as_vec3f_mix(const as_vec3f begin, const as_vec3f end, const float t) {
  return (as_vec3f){
    .x = as_mix_float(begin.x, end.x, t),
    .y = as_mix_float(begin.y, end.y, t),
    .z = as_mix_float(begin.z, end.z, t)};
}

as_vec3i as_vec3i_from_vec3f(const as_vec3f vec) {
  return (as_vec3i){(int)roundf(vec.x), (int)roundf(vec.y), (int)roundf(vec.z)};
}

as_vec3i as_vec3i_add_vec3i(const as_vec3i lhs, const as_vec3i rhs) {
  return (as_vec3i){.x = lhs.x + rhs.x, .y = lhs.y + rhs.y, .z = lhs.z + rhs.z};
}

as_vec3i as_vec3i_sub_vec3i(const as_vec3i lhs, const as_vec3i rhs) {
  return (as_vec3i){.x = lhs.x - rhs.x, .y = lhs.y - rhs.y, .z = lhs.z - rhs.z};
}

as_vec3f as_vec3i_mul_float(const as_vec3i vec, const float scalar) {
  return (as_vec3f){
    .x = (float)vec.x * scalar,
    .y = (float)vec.y * scalar,
    .z = (float)vec.z * scalar};
}

as_vec3f as_vec3i_div_float(const as_vec3i vec, const float scalar) {
  return as_vec3i_mul_float(vec, 1.0f / scalar);
}

float as_vec3i_length(const as_vec3i vec) {
  return sqrtf((float)as_vec3i_length_sq(vec));
}

int as_vec3i_length_sq(const as_vec3i vec) {
  return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
}

as_point2f as_point2f_from_vec2f(const as_vec2f vec) {
  return (as_point2f){vec.x, vec.y};
}

as_point2f as_point2f_from_point4f(const as_point4f point) {
  return (as_point2f){point.x, point.y};
}

as_point2f as_point2f_from_point2i(const as_point2i point) {
  return (as_point2f){(float)point.x, (float)point.y};
}

as_point2f as_point2f_from_float(const float value) {
  return (as_point2f){value, value};
}

as_point2f as_point2f_add_vec2f(const as_point2f point, const as_vec2f vec) {
  return (as_point2f){point.x + vec.x, point.y + vec.y};
}

as_vec2f as_point2f_sub_point2f(const as_point2f lhs, const as_point2f rhs) {
  return (as_vec2f){lhs.x - rhs.x, lhs.y - rhs.y};
}

float as_point2f_distance_point2f(const as_point2f lhs, const as_point2f rhs) {
  return as_vec2f_length(as_point2f_sub_point2f(lhs, rhs));
}

as_point2i as_point2i_from_point2f(const as_point2f point) {
  return (as_point2i){(int)roundf(point.x), (int)roundf(point.y)};
}

as_point2i as_point2i_from_vec2i(const as_vec2i vec) {
  return (as_point2i){vec.x, vec.y};
}

as_point2i as_point2i_from_int(const int value) {
  return (as_point2i){value, value};
}

as_point2i as_point2i_add_vec2i(const as_point2i point, const as_vec2i vec) {
  return (as_point2i){point.x + vec.x, point.y + vec.y};
}

as_vec2i as_point2i_sub_point2i(const as_point2i lhs, const as_point2i rhs) {
  return (as_vec2i){lhs.x - rhs.x, lhs.y - rhs.y};
}

float as_point2i_distance_point2i(const as_point2i lhs, const as_point2i rhs) {
  return as_vec2i_length(as_point2i_sub_point2i(lhs, rhs));
}

as_point3f as_point3f_from_vec3f(const as_vec3f vec) {
  return (as_point3f){vec.x, vec.y, vec.z};
}

as_point3f as_point3f_from_float(const float value) {
  return (as_point3f){value, value, value};
}

as_point3f as_point3f_add_vec3f(const as_point3f point, const as_vec3f vec) {
  return (as_point3f){
    .x = point.x + vec.x, .y = point.y + vec.y, .z = point.z + vec.z};
}

as_vec3f as_point3f_sub_point3f(const as_point3f lhs, const as_point3f rhs) {
  return (as_vec3f){.x = lhs.x - rhs.x, .y = lhs.y - rhs.y, .z = lhs.z - rhs.z};
}

as_point3f as_point3f_rotate_x_axis(
  const as_point3f point, const float radians) {
  return as_point3f_from_vec3f(
    as_vec3f_rotate_x_axis(as_vec3f_from_point3f(point), radians));
}

as_point3f as_point3f_rotate_y_axis(
  const as_point3f point, const float radians) {
  return as_point3f_from_vec3f(
    as_vec3f_rotate_y_axis(as_vec3f_from_point3f(point), radians));
}

as_point3f as_point3f_rotate_z_axis(
  const as_point3f point, const float radians) {
  return as_point3f_from_vec3f(
    as_vec3f_rotate_z_axis(as_vec3f_from_point3f(point), radians));
}

as_point3f as_point3f_mix(
  const as_point3f begin, const as_point3f end, const float t) {
  return (as_point3f){
    .x = as_mix_float(begin.x, end.x, t),
    .y = as_mix_float(begin.y, end.y, t),
    .z = as_mix_float(begin.z, end.z, t)};
}

as_point4f as_point4f_from_point3f(const as_point3f point) {
  return (as_point4f){point.x, point.y, point.z, 1.0f};
}

as_point4f as_point4f_from_point2f(const as_point2f point) {
  return (as_point4f){point.x, point.y, 0.0f, 1.0f};
}

static int mat_rc(const int r, const int c, const int d) {
  return r * d + c;
}

int as_mat22_rc(const int r, const int c) {
  return mat_rc(r, c, 2);
}

as_mat22f as_mat22f_identity(void) {
  return as_mat22f_uniform_scale(1.0f);
}

as_mat22f as_mat22f_uniform_scale(const float scale) {
  return as_mat22f_scale_from_floats(scale, scale);
}

as_mat22f as_mat22f_scale_from_floats(
  const float scale_x, const float scale_y) {
  return (as_mat22f){.elem = {[0] = scale_x, [3] = scale_y}};
}

as_mat22f as_mat22f_scale_from_vec2f(const as_vec2f scale_xy) {
  return as_mat22f_scale_from_floats(scale_xy.x, scale_xy.y);
}

as_mat22f as_mat22f_rotation(const float radians) {
  const float cos_angle = cosf(radians);
  const float sin_angle = sinf(radians);
  return (as_mat22f){
    .elem = {
      [0] = cos_angle, [1] = -sin_angle, [2] = sin_angle, [3] = cos_angle}};
}

as_point2f as_mat22f_mul_point2f(
  const as_mat22f* const mat, const as_point2f point) {
  return (as_point2f){
    .x = mat->elem[0] * point.x + mat->elem[1] * point.y,
    .y = mat->elem[2] * point.x + mat->elem[3] * point.y};
}

float as_mat22f_determinant(const as_mat22f* mat) {
  return mat->elem[0] * mat->elem[3] - mat->elem[1] * mat->elem[2];
}

as_mat22f as_mat22f_inverse(const as_mat22f* mat) {
  const float det_recip = 1.0f / as_mat22f_determinant(mat);
  return (as_mat22f){
    .elem = {
      [0] = mat->elem[3] * det_recip,
      [1] = -mat->elem[1] * det_recip,
      [2] = -mat->elem[2] * det_recip,
      [3] = mat->elem[0] * det_recip}};
}

int as_mat33_rc(const int r, const int c) {
  return mat_rc(r, c, 3);
}

as_mat33f as_mat33f_identity(void) {
  return as_mat33f_uniform_scale(1.0f);
}

as_mat33f as_mat33f_uniform_scale(const float scale) {
  return as_mat33f_scale_from_floats(scale, scale, scale);
}

as_mat33f as_mat33f_scale_from_floats(
  const float scale_x, const float scale_y, const float scale_z) {
  return (as_mat33f){.elem = {[0] = scale_x, [4] = scale_y, [8] = scale_z}};
}

as_mat33f as_mat33f_scale_from_vec3f(const as_vec3f scale_xyz) {
  return as_mat33f_scale_from_floats(scale_xyz.x, scale_xyz.y, scale_xyz.z);
}

as_mat33f as_mat33f_from_mat34f(const as_mat34f* const mat) {
  return (as_mat33f){
    .elem = {
      [0] = mat->elem[0],
      [1] = mat->elem[1],
      [2] = mat->elem[2],
      [3] = mat->elem[4],
      [4] = mat->elem[5],
      [5] = mat->elem[6],
      [6] = mat->elem[8],
      [7] = mat->elem[9],
      [8] = mat->elem[10],
    }};
}

as_mat33f as_mat33f_transpose(const as_mat33f* const mat) {
  return (as_mat33f){
    .elem = {
      [0] = mat->elem[0],
      [1] = mat->elem[3],
      [2] = mat->elem[6],
      [3] = mat->elem[1],
      [4] = mat->elem[4],
      [5] = mat->elem[7],
      [6] = mat->elem[2],
      [7] = mat->elem[5],
      [8] = mat->elem[8],
    }};
}

as_mat33f as_mat33f_x_axis_rotation(const float radians) {
  const float cos_angle = cosf(radians);
  const float sin_angle = sinf(radians);
  return (as_mat33f){
    .elem = {
      [0] = 1.0f,
      [4] = cos_angle,
      [5] = -sin_angle,
      [7] = sin_angle,
      [8] = cos_angle}};
}

as_mat33f as_mat33f_y_axis_rotation(const float radians) {
  const float cos_angle = cosf(radians);
  const float sin_angle = sinf(radians);
  return (as_mat33f){
    .elem = {
      [0] = cos_angle,
      [2] = sin_angle,
      [4] = 1.0f,
      [6] = -sin_angle,
      [8] = cos_angle}};
}

as_mat33f as_mat33f_z_axis_rotation(const float radians) {
  const float cos_angle = cosf(radians);
  const float sin_angle = sinf(radians);
  return (as_mat33f){
    .elem = {
      [0] = cos_angle,
      [1] = -sin_angle,
      [3] = sin_angle,
      [4] = cos_angle,
      [8] = 1.0f}};
}

as_point3f as_mat33f_mul_point3f(
  const as_mat33f* const mat, const as_point3f point) {
  return as_point3f_from_vec3f(
    as_mat33f_mul_vec3f(mat, as_vec3f_from_point3f(point)));
}

as_vec3f as_mat33f_mul_vec3f(const as_mat33f* const mat, const as_vec3f vec) {
  return (as_vec3f){
    .x = mat->elem[0] * vec.x + mat->elem[1] * vec.y + mat->elem[2] * vec.z,
    .y = mat->elem[3] * vec.x + mat->elem[4] * vec.y + mat->elem[5] * vec.z,
    .z = mat->elem[6] * vec.x + mat->elem[7] * vec.y + mat->elem[8] * vec.z};
}

as_mat33f as_mat33f_mul_mat33f(
  const as_mat33f* const lhs, const as_mat33f* const rhs) {
  return (as_mat33f){
    .elem = {
      [0] = lhs->elem[0] * rhs->elem[0] + lhs->elem[1] * rhs->elem[3]
          + lhs->elem[2] * rhs->elem[6],
      [1] = lhs->elem[0] * rhs->elem[1] + lhs->elem[1] * rhs->elem[4]
          + lhs->elem[2] * rhs->elem[7],
      [2] = lhs->elem[0] * rhs->elem[2] + lhs->elem[1] * rhs->elem[5]
          + lhs->elem[2] * rhs->elem[8],
      [3] = lhs->elem[3] * rhs->elem[0] + lhs->elem[4] * rhs->elem[3]
          + lhs->elem[5] * rhs->elem[6],
      [4] = lhs->elem[3] * rhs->elem[1] + lhs->elem[4] * rhs->elem[4]
          + lhs->elem[5] * rhs->elem[7],
      [5] = lhs->elem[3] * rhs->elem[2] + lhs->elem[4] * rhs->elem[5]
          + lhs->elem[5] * rhs->elem[8],
      [6] = lhs->elem[6] * rhs->elem[0] + lhs->elem[7] * rhs->elem[3]
          + lhs->elem[8] * rhs->elem[6],
      [7] = lhs->elem[6] * rhs->elem[1] + lhs->elem[7] * rhs->elem[4]
          + lhs->elem[8] * rhs->elem[7],
      [8] = lhs->elem[6] * rhs->elem[2] + lhs->elem[7] * rhs->elem[5]
          + lhs->elem[8] * rhs->elem[8]}};
}

as_mat34f as_mat33f_mul_mat34f(
  const as_mat33f* const lhs, const as_mat34f* const rhs) {
  return (as_mat34f){
    .elem = {
      [0] = lhs->elem[0] * rhs->elem[0] + lhs->elem[1] * rhs->elem[4]
          + lhs->elem[2] * rhs->elem[8],
      [1] = lhs->elem[0] * rhs->elem[1] + lhs->elem[1] * rhs->elem[5]
          + lhs->elem[2] * rhs->elem[9],
      [2] = lhs->elem[0] * rhs->elem[2] + lhs->elem[1] * rhs->elem[6]
          + lhs->elem[2] * rhs->elem[10],
      [3] = lhs->elem[0] * rhs->elem[3] + lhs->elem[1] * rhs->elem[7]
          + lhs->elem[2] * rhs->elem[11],
      [4] = lhs->elem[3] * rhs->elem[0] + lhs->elem[4] * rhs->elem[4]
          + lhs->elem[5] * rhs->elem[8],
      [5] = lhs->elem[3] * rhs->elem[1] + lhs->elem[4] * rhs->elem[5]
          + lhs->elem[5] * rhs->elem[9],
      [6] = lhs->elem[3] * rhs->elem[2] + lhs->elem[4] * rhs->elem[6]
          + lhs->elem[5] * rhs->elem[10],
      [7] = lhs->elem[3] * rhs->elem[3] + lhs->elem[4] * rhs->elem[7]
          + lhs->elem[5] * rhs->elem[11],
      [8] = lhs->elem[6] * rhs->elem[0] + lhs->elem[7] * rhs->elem[4]
          + lhs->elem[8] * rhs->elem[8],
      [9] = lhs->elem[6] * rhs->elem[1] + lhs->elem[7] * rhs->elem[5]
          + lhs->elem[8] * rhs->elem[9],
      [10] = lhs->elem[6] * rhs->elem[2] + lhs->elem[7] * rhs->elem[6]
           + lhs->elem[8] * rhs->elem[10],
      [11] = lhs->elem[6] * rhs->elem[3] + lhs->elem[7] * rhs->elem[7]
           + lhs->elem[8] * rhs->elem[11]}};
}

float as_mat33f_determinant(const as_mat33f* const mat) {
  return mat->elem[0]
         * (mat->elem[4] * mat->elem[8] - mat->elem[5] * mat->elem[7])
       + mat->elem[1]
           * (mat->elem[5] * mat->elem[6] - mat->elem[3] * mat->elem[8])
       + mat->elem[2]
           * (mat->elem[3] * mat->elem[7] - mat->elem[4] * mat->elem[6]);
}

as_mat33f as_mat33f_inverse(const as_mat33f* const mat) {
  const float m_11 = mat->elem[4] * mat->elem[8] - mat->elem[5] * mat->elem[7];
  const float m_12 = mat->elem[3] * mat->elem[8] - mat->elem[5] * mat->elem[6];
  const float m_13 = mat->elem[3] * mat->elem[7] - mat->elem[4] * mat->elem[6];
  const float m_21 = mat->elem[1] * mat->elem[8] - mat->elem[2] * mat->elem[7];
  const float m_22 = mat->elem[0] * mat->elem[8] - mat->elem[2] * mat->elem[6];
  const float m_23 = mat->elem[0] * mat->elem[7] - mat->elem[1] * mat->elem[6];
  const float m_31 = mat->elem[1] * mat->elem[5] - mat->elem[2] * mat->elem[4];
  const float m_32 = mat->elem[0] * mat->elem[5] - mat->elem[2] * mat->elem[3];
  const float m_33 = mat->elem[0] * mat->elem[4] - mat->elem[1] * mat->elem[3];
  const float det_recip =
    1.0f / (mat->elem[0] * m_11 - mat->elem[1] * m_12 + mat->elem[2] * m_13);
  return (as_mat33f){
    .elem = {
      [0] = m_11 * det_recip,
      [1] = -m_21 * det_recip,
      [2] = m_31 * det_recip,
      [3] = -m_12 * det_recip,
      [4] = m_22 * det_recip,
      [5] = -m_32 * det_recip,
      [6] = m_13 * det_recip,
      [7] = -m_23 * det_recip,
      [8] = m_33 * det_recip,
    }};
}

int as_mat34_rc(const int r, const int c) {
  return as_mat44_rc(r, c);
}

as_mat34f as_mat34f_identity(void) {
  return (as_mat34f){.elem = {[0] = 1.0f, [5] = 1.0f, [10] = 1.0f}};
}

as_mat34f as_mat34f_translation_from_floats(
  const float translation_x,
  const float translation_y,
  const float translation_z) {
  return (as_mat34f){
    .elem = {
      [0] = 1.0f,
      [5] = 1.0f,
      [10] = 1.0f,
      [3] = translation_x,
      [7] = translation_y,
      [11] = translation_z}};
}

as_mat34f as_mat34f_translation_from_vec3f(const as_vec3f translation) {
  return as_mat34f_translation_from_floats(
    translation.x, translation.y, translation.z);
}

as_mat34f as_mat34f_translation_from_point3f(const as_point3f position) {
  return as_mat34f_translation_from_floats(position.x, position.y, position.z);
}

as_mat34f as_mat34f_from_mat33f_and_vec3f(
  const as_mat33f* const rotation, const as_vec3f translation) {
  return (as_mat34f){
    .elem = {
      [0] = rotation->elem[0],
      [1] = rotation->elem[1],
      [2] = rotation->elem[2],
      [4] = rotation->elem[3],
      [5] = rotation->elem[4],
      [6] = rotation->elem[5],
      [8] = rotation->elem[6],
      [9] = rotation->elem[7],
      [10] = rotation->elem[8],
      [3] = translation.x,
      [7] = translation.y,
      [11] = translation.z}};
}

as_point3f as_mat34f_mul_point3f(
  const as_mat34f* const mat, const as_point3f point) {
  return (as_point3f){
    .x = mat->elem[0] * point.x + mat->elem[1] * point.y
       + mat->elem[2] * point.z + mat->elem[3],
    .y = mat->elem[4] * point.x + mat->elem[5] * point.y
       + mat->elem[6] * point.z + mat->elem[7],
    .z = mat->elem[8] * point.x + mat->elem[9] * point.y
       + mat->elem[10] * point.z + mat->elem[11]};
}

as_vec3f as_mat34f_mul_vec3f(const as_mat34f* const mat, const as_vec3f vec) {
  return (as_vec3f){
    .x = mat->elem[0] * vec.x + mat->elem[1] * vec.y + mat->elem[2] * vec.z,
    .y = mat->elem[4] * vec.x + mat->elem[5] * vec.y + mat->elem[6] * vec.z,
    .z = mat->elem[8] * vec.x + mat->elem[9] * vec.y + mat->elem[10] * vec.z};
}

as_mat34f as_mat34f_mul_mat34f(
  const as_mat34f* const lhs, const as_mat34f* const rhs) {
  return (as_mat34f){
    .elem = {
      [0] = lhs->elem[0] * rhs->elem[0] + lhs->elem[1] * rhs->elem[4]
          + lhs->elem[2] * rhs->elem[8],
      [1] = lhs->elem[0] * rhs->elem[1] + lhs->elem[1] * rhs->elem[5]
          + lhs->elem[2] * rhs->elem[9],
      [2] = lhs->elem[0] * rhs->elem[2] + lhs->elem[1] * rhs->elem[6]
          + lhs->elem[2] * rhs->elem[10],
      [3] = lhs->elem[0] * rhs->elem[3] + lhs->elem[1] * rhs->elem[7]
          + lhs->elem[2] * rhs->elem[11] + lhs->elem[3],
      [4] = lhs->elem[4] * rhs->elem[0] + lhs->elem[5] * rhs->elem[4]
          + lhs->elem[6] * rhs->elem[8],
      [5] = lhs->elem[4] * rhs->elem[1] + lhs->elem[5] * rhs->elem[5]
          + lhs->elem[6] * rhs->elem[9],
      [6] = lhs->elem[4] * rhs->elem[2] + lhs->elem[5] * rhs->elem[6]
          + lhs->elem[6] * rhs->elem[10],
      [7] = lhs->elem[4] * rhs->elem[3] + lhs->elem[5] * rhs->elem[7]
          + lhs->elem[6] * rhs->elem[11] + lhs->elem[7],
      [8] = lhs->elem[8] * rhs->elem[0] + lhs->elem[9] * rhs->elem[4]
          + lhs->elem[10] * rhs->elem[8],
      [9] = lhs->elem[8] * rhs->elem[1] + lhs->elem[9] * rhs->elem[5]
          + lhs->elem[10] * rhs->elem[9],
      [10] = lhs->elem[8] * rhs->elem[2] + lhs->elem[9] * rhs->elem[6]
           + lhs->elem[10] * rhs->elem[10],
      [11] = lhs->elem[8] * rhs->elem[3] + lhs->elem[9] * rhs->elem[7]
           + lhs->elem[10] * rhs->elem[11] + lhs->elem[11]}};
}

as_mat34f as_mat34f_mul_mat33f(
  const as_mat34f* const lhs, const as_mat33f* const rhs) {
  return (as_mat34f){
    .elem = {
      [0] = lhs->elem[0] * rhs->elem[0] + lhs->elem[1] * rhs->elem[3]
          + lhs->elem[2] * rhs->elem[6],
      [1] = lhs->elem[0] * rhs->elem[1] + lhs->elem[1] * rhs->elem[4]
          + lhs->elem[2] * rhs->elem[7],
      [2] = lhs->elem[0] * rhs->elem[2] + lhs->elem[1] * rhs->elem[5]
          + lhs->elem[2] * rhs->elem[8],
      [3] = lhs->elem[3],
      [4] = lhs->elem[4] * rhs->elem[0] + lhs->elem[5] * rhs->elem[3]
          + lhs->elem[6] * rhs->elem[6],
      [5] = lhs->elem[4] * rhs->elem[1] + lhs->elem[5] * rhs->elem[4]
          + lhs->elem[6] * rhs->elem[7],
      [6] = lhs->elem[4] * rhs->elem[2] + lhs->elem[5] * rhs->elem[5]
          + lhs->elem[6] * rhs->elem[8],
      [7] = lhs->elem[7],
      [8] = lhs->elem[8] * rhs->elem[0] + lhs->elem[9] * rhs->elem[3]
          + lhs->elem[10] * rhs->elem[6],
      [9] = lhs->elem[8] * rhs->elem[1] + lhs->elem[9] * rhs->elem[4]
          + lhs->elem[10] * rhs->elem[7],
      [10] = lhs->elem[8] * rhs->elem[2] + lhs->elem[9] * rhs->elem[5]
           + lhs->elem[10] * rhs->elem[8],
      [11] = lhs->elem[11]}};
}

as_mat34f as_mat34f_inverse(const as_mat34f* const mat) {
  const as_mat33f rotation_scale = as_mat33f_from_mat34f(mat);
  const as_mat33f inverse_rotation_scale = as_mat33f_inverse(&rotation_scale);
  const as_point3f inverse_translation = as_mat33f_mul_point3f(
    &inverse_rotation_scale,
    (as_point3f){.x = -mat->elem[3], .y = -mat->elem[7], .z = -mat->elem[11]});
  return as_mat34f_from_mat33f_and_vec3f(
    &inverse_rotation_scale, as_vec3f_from_point3f(inverse_translation));
}

int as_mat44_rc(const int r, const int c) {
  return mat_rc(r, c, 4);
}

as_mat44f as_mat44f_identity(void) {
  return (as_mat44f){
    .elem = {[0] = 1.0f, [5] = 1.0f, [10] = 1.0f, [15] = 1.0f}};
}

as_mat44f as_mat44f_mul_mat44f(
  const as_mat44f* const lhs, const as_mat44f* const rhs) {
  return (as_mat44f){
    .elem = {
      [0] = lhs->elem[0] * rhs->elem[0] + lhs->elem[1] * rhs->elem[4]
          + lhs->elem[2] * rhs->elem[8] + lhs->elem[3] * rhs->elem[12],
      [1] = lhs->elem[0] * rhs->elem[1] + lhs->elem[1] * rhs->elem[5]
          + lhs->elem[2] * rhs->elem[9] + lhs->elem[3] * rhs->elem[13],
      [2] = lhs->elem[0] * rhs->elem[2] + lhs->elem[1] * rhs->elem[6]
          + lhs->elem[2] * rhs->elem[10] + lhs->elem[3] * rhs->elem[14],
      [3] = lhs->elem[0] * rhs->elem[3] + lhs->elem[1] * rhs->elem[7]
          + lhs->elem[2] * rhs->elem[11] + lhs->elem[3] * rhs->elem[15],
      [4] = lhs->elem[4] * rhs->elem[0] + lhs->elem[5] * rhs->elem[4]
          + lhs->elem[6] * rhs->elem[8] + lhs->elem[7] * rhs->elem[12],
      [5] = lhs->elem[4] * rhs->elem[1] + lhs->elem[5] * rhs->elem[5]
          + lhs->elem[6] * rhs->elem[9] + lhs->elem[7] * rhs->elem[13],
      [6] = lhs->elem[4] * rhs->elem[2] + lhs->elem[5] * rhs->elem[6]
          + lhs->elem[6] * rhs->elem[10] + lhs->elem[7] * rhs->elem[14],
      [7] = lhs->elem[4] * rhs->elem[3] + lhs->elem[5] * rhs->elem[7]
          + lhs->elem[6] * rhs->elem[11] + lhs->elem[7] * rhs->elem[15],
      [8] = lhs->elem[8] * rhs->elem[0] + lhs->elem[9] * rhs->elem[4]
          + lhs->elem[10] * rhs->elem[8] + lhs->elem[11] * rhs->elem[12],
      [9] = lhs->elem[8] * rhs->elem[1] + lhs->elem[9] * rhs->elem[5]
          + lhs->elem[10] * rhs->elem[9] + lhs->elem[11] * rhs->elem[13],
      [10] = lhs->elem[8] * rhs->elem[2] + lhs->elem[9] * rhs->elem[6]
           + lhs->elem[10] * rhs->elem[10] + lhs->elem[11] * rhs->elem[14],
      [11] = lhs->elem[8] * rhs->elem[3] + lhs->elem[9] * rhs->elem[7]
           + lhs->elem[10] * rhs->elem[11] + lhs->elem[11] * rhs->elem[15],
      [12] = lhs->elem[12] * rhs->elem[0] + lhs->elem[13] * rhs->elem[4]
           + lhs->elem[14] * rhs->elem[8] + lhs->elem[15] * rhs->elem[12],
      [13] = lhs->elem[12] * rhs->elem[1] + lhs->elem[13] * rhs->elem[5]
           + lhs->elem[14] * rhs->elem[9] + lhs->elem[15] * rhs->elem[13],
      [14] = lhs->elem[12] * rhs->elem[2] + lhs->elem[13] * rhs->elem[6]
           + lhs->elem[14] * rhs->elem[10] + lhs->elem[15] * rhs->elem[14],
      [15] = lhs->elem[12] * rhs->elem[3] + lhs->elem[13] * rhs->elem[7]
           + lhs->elem[14] * rhs->elem[11] + lhs->elem[15] * rhs->elem[15]}};
}

as_mat44f as_mat44f_perspective_projection_lh(
  const float aspect_ratio,
  const float vertical_fov,
  const float near,
  const float far) {
  const float e = 1.0f / tanf(vertical_fov * 0.5f);
  return (as_mat44f){
    .elem = {
      [0] = e / aspect_ratio,
      [5] = e,
      [10] = far / (far - near),
      [11] = (far * near) / (near - far),
      [14] = 1.0f}};
}

as_point4f as_mat44f_mul_point4f(
  const as_mat44f* const mat, const as_point4f point) {
  return (as_point4f){
    .x = mat->elem[0] * point.x + mat->elem[1] * point.y
       + mat->elem[2] * point.z + mat->elem[3] * point.w,
    .y = mat->elem[4] * point.x + mat->elem[5] * point.y
       + mat->elem[6] * point.z + mat->elem[7] * point.w,
    .z = mat->elem[8] * point.x + mat->elem[9] * point.y
       + mat->elem[10] * point.z + mat->elem[11] * point.w,
    .w = mat->elem[12] * point.x + mat->elem[13] * point.y
       + mat->elem[14] * point.z + mat->elem[15] * point.w};
}

static as_point4f perspective_divide(const as_point4f point) {
  return (as_point4f){
    .x = point.x / point.w,
    .y = point.y / point.w,
    .z = point.z / point.w,
    .w = point.w};
}

as_point4f as_mat44f_project_point3f(
  const as_mat44f* const projection, const as_point3f point) {
  return perspective_divide(
    as_mat44f_mul_point4f(projection, as_point4f_from_point3f(point)));
}

float as_mat44f_determinant(const as_mat44f* const mat) {
  return
    (mat->elem[0]
    * (mat->elem[5] * mat->elem[10] * mat->elem[15] + mat->elem[6] * mat->elem[11] * mat->elem[13] + mat->elem[7] * mat->elem[9] * mat->elem[14]
     - mat->elem[7] * mat->elem[10] * mat->elem[13] - mat->elem[6] * mat->elem[9] * mat->elem[15] - mat->elem[5] * mat->elem[11] * mat->elem[14]))
    - (mat->elem[4]
    * (mat->elem[1] * mat->elem[10] * mat->elem[15] + mat->elem[2] * mat->elem[11] * mat->elem[13] + mat->elem[3] * mat->elem[9] * mat->elem[14]
    - mat->elem[3] * mat->elem[10] * mat->elem[13] - mat->elem[2] * mat->elem[9] * mat->elem[15] - mat->elem[1] * mat->elem[11] * mat->elem[14]))
    + (mat->elem[8]
    * (mat->elem[1] * mat->elem[6] * mat->elem[15] + mat->elem[2] * mat->elem[7] * mat->elem[13] + mat->elem[3] * mat->elem[5] * mat->elem[14]
    - mat->elem[3] * mat->elem[6] * mat->elem[13] - mat->elem[2] * mat->elem[5] * mat->elem[15] - mat->elem[1] * mat->elem[7] * mat->elem[14]))
    - (mat->elem[12]
    * (mat->elem[1] * mat->elem[6] * mat->elem[11] + mat->elem[2] * mat->elem[7] * mat->elem[9] + mat->elem[3] * mat->elem[5] * mat->elem[10]
    - mat->elem[3] * mat->elem[6] * mat->elem[9] - mat->elem[2] * mat->elem[5] * mat->elem[11] - mat->elem[1] * mat->elem[7] * mat->elem[10]));
}

as_mat44f as_mat44f_inverse(const as_mat44f* const mat) {
  const float m_11 = mat->elem[5] * mat->elem[10] * mat->elem[15]
                   + mat->elem[6] * mat->elem[11] * mat->elem[13]
                   + mat->elem[7] * mat->elem[9] * mat->elem[14]
                   - mat->elem[7] * mat->elem[10] * mat->elem[13]
                   - mat->elem[6] * mat->elem[9] * mat->elem[15]
                   - mat->elem[5] * mat->elem[11] * mat->elem[14];
  const float m_12 = mat->elem[4] * mat->elem[10] * mat->elem[15]
                   + mat->elem[6] * mat->elem[11] * mat->elem[12]
                   + mat->elem[7] * mat->elem[8] * mat->elem[14]
                   - mat->elem[7] * mat->elem[10] * mat->elem[12]
                   - mat->elem[6] * mat->elem[8] * mat->elem[15]
                   - mat->elem[4] * mat->elem[11] * mat->elem[14];
  const float m_13 = mat->elem[4] * mat->elem[9] * mat->elem[15]
                   + mat->elem[5] * mat->elem[11] * mat->elem[12]
                   + mat->elem[7] * mat->elem[8] * mat->elem[13]
                   - mat->elem[7] * mat->elem[9] * mat->elem[12]
                   - mat->elem[5] * mat->elem[8] * mat->elem[15]
                   - mat->elem[4] * mat->elem[11] * mat->elem[13];
  const float m_14 = mat->elem[4] * mat->elem[9] * mat->elem[14]
                   + mat->elem[5] * mat->elem[10] * mat->elem[12]
                   + mat->elem[6] * mat->elem[8] * mat->elem[13]
                   - mat->elem[6] * mat->elem[9] * mat->elem[12]
                   - mat->elem[5] * mat->elem[8] * mat->elem[14]
                   - mat->elem[4] * mat->elem[10] * mat->elem[13];
  const float m_21 = mat->elem[1] * mat->elem[10] * mat->elem[15]
                   + mat->elem[2] * mat->elem[11] * mat->elem[13]
                   + mat->elem[3] * mat->elem[9] * mat->elem[14]
                   - mat->elem[3] * mat->elem[10] * mat->elem[13]
                   - mat->elem[2] * mat->elem[9] * mat->elem[15]
                   - mat->elem[1] * mat->elem[11] * mat->elem[14];
  const float m_22 = mat->elem[0] * mat->elem[10] * mat->elem[15]
                   + mat->elem[2] * mat->elem[11] * mat->elem[12]
                   + mat->elem[3] * mat->elem[8] * mat->elem[14]
                   - mat->elem[3] * mat->elem[10] * mat->elem[12]
                   - mat->elem[2] * mat->elem[8] * mat->elem[15]
                   - mat->elem[0] * mat->elem[11] * mat->elem[14];
  const float m_23 = mat->elem[0] * mat->elem[9] * mat->elem[15]
                   + mat->elem[1] * mat->elem[11] * mat->elem[12]
                   + mat->elem[3] * mat->elem[8] * mat->elem[13]
                   - mat->elem[3] * mat->elem[9] * mat->elem[12]
                   - mat->elem[1] * mat->elem[8] * mat->elem[15]
                   - mat->elem[0] * mat->elem[11] * mat->elem[13];
  const float m_24 = mat->elem[0] * mat->elem[9] * mat->elem[14]
                   + mat->elem[1] * mat->elem[10] * mat->elem[12]
                   + mat->elem[2] * mat->elem[8] * mat->elem[13]
                   - mat->elem[2] * mat->elem[9] * mat->elem[12]
                   - mat->elem[1] * mat->elem[8] * mat->elem[14]
                   - mat->elem[0] * mat->elem[10] * mat->elem[13];
  const float m_31 = mat->elem[1] * mat->elem[6] * mat->elem[15]
                   + mat->elem[2] * mat->elem[7] * mat->elem[13]
                   + mat->elem[3] * mat->elem[5] * mat->elem[14]
                   - mat->elem[3] * mat->elem[6] * mat->elem[13]
                   - mat->elem[2] * mat->elem[5] * mat->elem[15]
                   - mat->elem[1] * mat->elem[7] * mat->elem[14];
  const float m_32 = mat->elem[0] * mat->elem[6] * mat->elem[15]
                   + mat->elem[2] * mat->elem[7] * mat->elem[12]
                   + mat->elem[3] * mat->elem[4] * mat->elem[14]
                   - mat->elem[3] * mat->elem[6] * mat->elem[12]
                   - mat->elem[2] * mat->elem[4] * mat->elem[15]
                   - mat->elem[0] * mat->elem[7] * mat->elem[14];
  const float m_33 = mat->elem[0] * mat->elem[5] * mat->elem[15]
                   + mat->elem[1] * mat->elem[7] * mat->elem[12]
                   + mat->elem[3] * mat->elem[4] * mat->elem[13]
                   - mat->elem[3] * mat->elem[5] * mat->elem[12]
                   - mat->elem[1] * mat->elem[4] * mat->elem[15]
                   - mat->elem[0] * mat->elem[7] * mat->elem[13];
  const float m_34 = mat->elem[0] * mat->elem[5] * mat->elem[14]
                   + mat->elem[1] * mat->elem[6] * mat->elem[12]
                   + mat->elem[2] * mat->elem[4] * mat->elem[13]
                   - mat->elem[2] * mat->elem[5] * mat->elem[12]
                   - mat->elem[1] * mat->elem[4] * mat->elem[14]
                   - mat->elem[0] * mat->elem[6] * mat->elem[13];
  const float m_41 = mat->elem[1] * mat->elem[6] * mat->elem[11]
                   + mat->elem[2] * mat->elem[7] * mat->elem[9]
                   + mat->elem[3] * mat->elem[5] * mat->elem[10]
                   - mat->elem[3] * mat->elem[6] * mat->elem[9]
                   - mat->elem[2] * mat->elem[5] * mat->elem[11]
                   - mat->elem[1] * mat->elem[7] * mat->elem[10];
  const float m_42 = mat->elem[0] * mat->elem[6] * mat->elem[11]
                   + mat->elem[2] * mat->elem[7] * mat->elem[8]
                   + mat->elem[3] * mat->elem[4] * mat->elem[10]
                   - mat->elem[3] * mat->elem[6] * mat->elem[8]
                   - mat->elem[2] * mat->elem[4] * mat->elem[11]
                   - mat->elem[0] * mat->elem[7] * mat->elem[10];
  const float m_43 = mat->elem[0] * mat->elem[5] * mat->elem[11]
                   + mat->elem[1] * mat->elem[7] * mat->elem[8]
                   + mat->elem[3] * mat->elem[4] * mat->elem[9]
                   - mat->elem[3] * mat->elem[5] * mat->elem[8]
                   - mat->elem[1] * mat->elem[4] * mat->elem[11]
                   - mat->elem[0] * mat->elem[7] * mat->elem[9];
  const float m_44 = mat->elem[0] * mat->elem[5] * mat->elem[10]
                   + mat->elem[1] * mat->elem[6] * mat->elem[8]
                   + mat->elem[2] * mat->elem[4] * mat->elem[9]
                   - mat->elem[2] * mat->elem[5] * mat->elem[8]
                   - mat->elem[1] * mat->elem[4] * mat->elem[10]
                   - mat->elem[0] * mat->elem[6] * mat->elem[9];
  const float det_recip = 1.0f
                        / (m_11 * mat->elem[0] - m_21 * mat->elem[4]
                           + m_31 * mat->elem[8] - m_41 * mat->elem[12]);
  return (as_mat44f){
    .elem = {
      [0] = m_11 * det_recip,
      [1] = -m_21 * det_recip,
      [2] = m_31 * det_recip,
      [3] = -m_41 * det_recip,
      [4] = -m_12 * det_recip,
      [5] = m_22 * det_recip,
      [6] = -m_32 * det_recip,
      [7] = m_42 * det_recip,
      [8] = m_13 * det_recip,
      [9] = -m_23 * det_recip,
      [10] = m_33 * det_recip,
      [11] = -m_43 * det_recip,
      [12] = -m_14 * det_recip,
      [13] = m_24 * det_recip,
      [14] = -m_34 * det_recip,
      [15] = m_44 * det_recip}};
}

void as_swap_float(float* lhs, float* rhs) {
  const float temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

void as_swap_int(int* lhs, int* rhs) {
  const int temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

int as_clamp_int(const int value, const int min, const int max) {
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

float as_clamp_float(const float value, const float min, const float max) {
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

int as_max_int(const int lhs, const int rhs) {
  if (lhs > rhs) {
    return lhs;
  }
  return rhs;
}

float as_max_float(const float lhs, const float rhs) {
  if (lhs > rhs) {
    return lhs;
  }
  return rhs;
}

int as_min_int(const int lhs, const int rhs) {
  if (lhs < rhs) {
    return lhs;
  }
  return rhs;
}

int as_min_float(const float lhs, const float rhs) {
  if (lhs < rhs) {
    return lhs;
  }
  return rhs;
}

float as_mix_float(const float begin, const float end, const float t) {
  return (1.0f - t) * begin + t * end;
}

float as_radians_from_degrees(const float degrees) {
  return degrees * (as_k_pi / 180.0f);
}

float as_degrees_from_radians(const float radians) {
  return radians * (180.0f / as_k_pi);
}
