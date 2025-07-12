#include "as-ops.h"

#include <math.h>

const float as_k_pi = 3.14159265358979323846f;
const float as_k_half_pi = 1.57079632679489661923f;
const float as_k_quarter_pi = 0.78539816339744827900f;
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

as_vec2f as_vec2f_normalize(const as_vec2f vec) {
  return as_vec2f_mul_float(vec, 1.0f / as_vec2f_length(vec));
}

as_vec2f as_vec2f_mix(const as_vec2f begin, const as_vec2f end, const float t) {
  return (as_vec2f){
    .x = as_float_mix(begin.x, end.x, t), .y = as_float_mix(begin.y, end.y, t)};
}

as_vec2f as_vec2f_negate(const as_vec2f vec) {
  return (as_vec2f){.x = -vec.x, .y = -vec.y};
}

bool as_vec2f_near(
  const as_vec2f lhs,
  const as_vec2f rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_float_near(lhs.x, rhs.x, max_diff, max_rel_diff)
      && as_float_near(lhs.y, rhs.y, max_diff, max_rel_diff);
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

as_vec2i as_vec2i_negate(const as_vec2i vec) {
  return (as_vec2i){.x = -vec.x, .y = -vec.y};
}

bool as_vec2i_equal(const as_vec2i lhs, const as_vec2i rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
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

as_vec3f as_vec3f_from_mat34f_v(const as_mat34f mat, const int col) {
  return as_vec3f_from_mat34f(&mat, col);
}

as_vec3f as_vec3f_from_float(const float value) {
  return (as_vec3f){value, value, value};
}

as_vec3f as_vec3f_from_floats(const float x, const float y, const float z) {
  return (as_vec3f){x, y, z};
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

as_vec3f as_vec3f_normalize(const as_vec3f vec) {
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
    .x = as_float_mix(begin.x, end.x, t),
    .y = as_float_mix(begin.y, end.y, t),
    .z = as_float_mix(begin.z, end.z, t)};
}

as_vec3f as_vec3f_negate(const as_vec3f vec) {
  return (as_vec3f){-vec.x, -vec.y, -vec.z};
}

bool as_vec3f_near(
  const as_vec3f lhs,
  const as_vec3f rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_float_near(lhs.x, rhs.x, max_diff, max_rel_diff)
      && as_float_near(lhs.y, rhs.y, max_diff, max_rel_diff)
      && as_float_near(lhs.z, rhs.z, max_diff, max_rel_diff);
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

as_vec3i as_vec3i_negate(const as_vec3i vec) {
  return (as_vec3i){.x = -vec.x, .y = -vec.y, .z = -vec.z};
}

bool as_vec3i_equal(const as_vec3i lhs, const as_vec3i rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
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

as_point2f as_point2f_negate(const as_point2f point) {
  return (as_point2f){.x = -point.x, .y = -point.y};
}

bool as_point2f_near(
  const as_point2f lhs,
  const as_point2f rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_float_near(lhs.x, rhs.x, max_diff, max_rel_diff)
      && as_float_near(lhs.y, rhs.y, max_diff, max_rel_diff);
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

as_point2i as_point2i_negate(const as_point2i point) {
  return (as_point2i){.x = -point.x, .y = -point.y};
}

bool as_point2i_equal(const as_point2i lhs, const as_point2i rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
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
    .x = as_float_mix(begin.x, end.x, t),
    .y = as_float_mix(begin.y, end.y, t),
    .z = as_float_mix(begin.z, end.z, t)};
}

as_point3f as_point3f_negate(const as_point3f point) {
  return (as_point3f){.x = -point.x, .y = -point.y, .z = -point.z};
}

bool as_point3f_near(
  const as_point3f lhs,
  const as_point3f rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_float_near(lhs.x, rhs.x, max_diff, max_rel_diff)
      && as_float_near(lhs.y, rhs.y, max_diff, max_rel_diff)
      && as_float_near(lhs.z, rhs.z, max_diff, max_rel_diff);
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

as_point2f as_mat22f_mul_point2f_v(
  const as_mat22f mat, const as_point2f point) {
  return as_mat22f_mul_point2f(&mat, point);
}

as_vec2f as_mat22f_mul_vec2f(const as_mat22f* mat, const as_vec2f vec) {
  return (as_vec2f){.x = mat->elem[0] * vec.x + mat->elem[1] * vec.y,
                    .y = mat->elem[2] * vec.x + mat->elem[3] * vec.y};
}

as_vec2f as_mat22f_mul_vec2f_v(as_mat22f mat, const as_vec2f vec) {
  return as_mat22f_mul_vec2f(&mat, vec);
}

float as_mat22f_determinant(const as_mat22f* mat) {
  return mat->elem[0] * mat->elem[3] - mat->elem[1] * mat->elem[2];
}

float as_mat22f_determinant_v(const as_mat22f mat) {
  return as_mat22f_determinant(&mat);
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

as_mat22f as_mat22f_inverse_v(const as_mat22f mat) {
  return as_mat22f_inverse(&mat);
}

static bool as_mat_near(
  const float* lhs_elems,
  const float* rhs_elems,
  const float count,
  const float max_diff,
  const float max_rel_diff) {
  for (int i = 0; i < count; ++i) {
    if (!as_float_near(lhs_elems[i], rhs_elems[i], max_diff, max_rel_diff)) {
      return false;
    }
  }
  return true;
}

bool as_mat22f_near(
  const as_mat22f* lhs,
  const as_mat22f* rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_mat_near(lhs->elem, rhs->elem, 4, max_diff, max_rel_diff);
}

bool as_mat22f_near_v(
  const as_mat22f lhs,
  const as_mat22f rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_mat22f_near(&lhs, &rhs, max_diff, max_rel_diff);
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

as_mat33f as_mat33f_from_mat34f_v(const as_mat34f mat) {
  return as_mat33f_from_mat34f(&mat);
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

as_mat33f as_mat33f_transpose_v(const as_mat33f mat) {
  return as_mat33f_transpose(&mat);
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

as_point3f as_mat33f_mul_point3f_v(
  const as_mat33f mat, const as_point3f point) {
  return as_mat33f_mul_point3f(&mat, point);
}

as_vec3f as_mat33f_mul_vec3f(const as_mat33f* const mat, const as_vec3f vec) {
  return (as_vec3f){
    .x = mat->elem[0] * vec.x + mat->elem[1] * vec.y + mat->elem[2] * vec.z,
    .y = mat->elem[3] * vec.x + mat->elem[4] * vec.y + mat->elem[5] * vec.z,
    .z = mat->elem[6] * vec.x + mat->elem[7] * vec.y + mat->elem[8] * vec.z};
}

as_vec3f as_mat33f_mul_vec3f_v(const as_mat33f mat, const as_vec3f vec) {
  return as_mat33f_mul_vec3f(&mat, vec);
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

as_mat33f as_mat33f_mul_mat33f_v(const as_mat33f lhs, const as_mat33f rhs) {
  return as_mat33f_mul_mat33f(&lhs, &rhs);
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

as_mat34f as_mat33f_mul_mat34f_v(const as_mat33f lhs, const as_mat34f rhs) {
  return as_mat33f_mul_mat34f(&lhs, &rhs);
}

float as_mat33f_determinant(const as_mat33f* const mat) {
  return mat->elem[0]
         * (mat->elem[4] * mat->elem[8] - mat->elem[5] * mat->elem[7])
       + mat->elem[1]
           * (mat->elem[5] * mat->elem[6] - mat->elem[3] * mat->elem[8])
       + mat->elem[2]
           * (mat->elem[3] * mat->elem[7] - mat->elem[4] * mat->elem[6]);
}

float as_mat33f_determinant_v(const as_mat33f mat) {
  return as_mat33f_determinant(&mat);
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

as_mat33f as_mat33f_inverse_v(const as_mat33f mat) {
  return as_mat33f_inverse(&mat);
}

bool as_mat33f_near(
  const as_mat33f* lhs,
  const as_mat33f* rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_mat_near(lhs->elem, rhs->elem, 9, max_diff, max_rel_diff);
}

bool as_mat33f_near_v(
  const as_mat33f lhs,
  const as_mat33f rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_mat33f_near(&lhs, &rhs, max_diff, max_rel_diff);
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

as_mat34f as_mat34f_from_mat33f_and_vec3f_v(
  const as_mat33f rotation, const as_vec3f translation) {
  return as_mat34f_from_mat33f_and_vec3f(&rotation, translation);
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

as_point3f as_mat34f_mul_point3f_v(
  const as_mat34f mat, const as_point3f point) {
  return as_mat34f_mul_point3f(&mat, point);
}

as_vec3f as_mat34f_mul_vec3f(const as_mat34f* const mat, const as_vec3f vec) {
  return (as_vec3f){
    .x = mat->elem[0] * vec.x + mat->elem[1] * vec.y + mat->elem[2] * vec.z,
    .y = mat->elem[4] * vec.x + mat->elem[5] * vec.y + mat->elem[6] * vec.z,
    .z = mat->elem[8] * vec.x + mat->elem[9] * vec.y + mat->elem[10] * vec.z};
}

as_vec3f as_mat34f_mul_vec3f_v(const as_mat34f mat, const as_vec3f vec) {
  return as_mat34f_mul_vec3f(&mat, vec);
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

as_mat34f as_mat34f_mul_mat34f_v(const as_mat34f lhs, const as_mat34f rhs) {
  return as_mat34f_mul_mat34f(&lhs, &rhs);
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

as_mat34f as_mat34f_mul_mat33f_v(const as_mat34f lhs, const as_mat33f rhs) {
  return as_mat34f_mul_mat33f(&lhs, &rhs);
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

as_mat34f as_mat34f_inverse_v(const as_mat34f mat) {
  return as_mat34f_inverse(&mat);
}

bool as_mat34f_near(
  const as_mat34f* lhs,
  const as_mat34f* rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_mat_near(lhs->elem, rhs->elem, 12, max_diff, max_rel_diff);
}

bool as_mat34f_near_v(
  const as_mat34f lhs,
  const as_mat34f rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_mat34f_near(&lhs, &rhs, max_diff, max_rel_diff);
}

int as_mat44_rc(const int r, const int c) {
  return mat_rc(r, c, 4);
}

as_mat44f as_mat44f_identity(void) {
  return (as_mat44f){
    .elem = {[0] = 1.0f, [5] = 1.0f, [10] = 1.0f, [15] = 1.0f}};
}

as_mat44f as_mat44f_translation_from_floats(
  const float translation_x,
  const float translation_y,
  const float translation_z) {
  return (as_mat44f){
    .elem = {
      [0] = 1.0f,
      [5] = 1.0f,
      [10] = 1.0f,
      [15] = 1.0f,
      [3] = translation_x,
      [7] = translation_y,
      [11] = translation_z}};
}

as_mat44f as_mat44f_translation_from_vec3f(const as_vec3f translation) {
  return as_mat44f_translation_from_floats(
    translation.x, translation.y, translation.z);
}

as_mat44f as_mat44f_translation_from_point3f(const as_point3f position) {
  return as_mat44f_translation_from_floats(position.x, position.y, position.z);
}

as_mat44f as_mat44f_from_mat33f_and_vec3f(
  const as_mat33f* mat33, const as_vec3f translation) {
  return (as_mat44f){
    .elem = {
      [0] = mat33->elem[0],
      [1] = mat33->elem[1],
      [2] = mat33->elem[2],
      [4] = mat33->elem[3],
      [5] = mat33->elem[4],
      [6] = mat33->elem[5],
      [8] = mat33->elem[6],
      [9] = mat33->elem[7],
      [10] = mat33->elem[8],
      [3] = translation.x,
      [7] = translation.y,
      [11] = translation.z,
      [15] = 1.0f}};
}

as_mat44f as_mat44f_from_mat33f_and_vec3f_v(
  const as_mat33f mat33, const as_vec3f translation) {
  return as_mat44f_from_mat33f_and_vec3f(&mat33, translation);
}

as_mat44f as_mat44f_from_mat34f(const as_mat34f* mat34) {
  return (as_mat44f){
    .elem = {
      [0] = mat34->elem[0],
      [1] = mat34->elem[1],
      [2] = mat34->elem[2],
      [3] = mat34->elem[3],
      [4] = mat34->elem[4],
      [5] = mat34->elem[5],
      [6] = mat34->elem[6],
      [7] = mat34->elem[7],
      [8] = mat34->elem[8],
      [9] = mat34->elem[9],
      [10] = mat34->elem[10],
      [11] = mat34->elem[11],
      [15] = 1.0f}};
}

as_mat44f as_mat44f_from_mat34f_v(const as_mat34f mat34) {
  return as_mat44f_from_mat34f(&mat34);
}

as_mat44f as_mat44f_transpose(const as_mat44f* mat) {
  return (as_mat44f){
    .elem = {
      [0] = mat->elem[0],
      [1] = mat->elem[4],
      [2] = mat->elem[8],
      [3] = mat->elem[12],
      [4] = mat->elem[1],
      [5] = mat->elem[5],
      [6] = mat->elem[9],
      [7] = mat->elem[13],
      [8] = mat->elem[2],
      [9] = mat->elem[6],
      [10] = mat->elem[10],
      [11] = mat->elem[14],
      [12] = mat->elem[3],
      [13] = mat->elem[7],
      [14] = mat->elem[11],
      [15] = mat->elem[15],
    }};
}

as_mat44f as_mat44f_transpose_v(const as_mat44f mat) {
  return as_mat44f_transpose(&mat);
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

as_mat44f as_mat44f_mul_mat44f_v(const as_mat44f lhs, const as_mat44f rhs) {
  return as_mat44f_mul_mat44f(&lhs, &rhs);
}

static as_mat44f as_mat44f_perspective_projection_depth_zero_to_one_handed(
  const float aspect_ratio,
  const float vertical_fov_radians,
  const float near,
  const float far,
  const float handed) {
  const float e = 1.0f / tanf(vertical_fov_radians * 0.5f);
  return (as_mat44f){
    .elem = {
      [0] = e / aspect_ratio,
      [5] = e,
      [10] = far / ((far - near) * handed),
      [11] = (far * near) / (near - far),
      [14] = handed}};
}

as_mat44f as_mat44f_perspective_projection_depth_zero_to_one_lh(
  const float aspect_ratio,
  const float vertical_fov_radians,
  const float near,
  const float far) {
  return as_mat44f_perspective_projection_depth_zero_to_one_handed(
    aspect_ratio, vertical_fov_radians, near, far, 1.0f);
}

as_mat44f as_mat44f_perspective_projection_depth_zero_to_one_rh(
  const float aspect_ratio,
  const float vertical_fov_radians,
  const float near,
  const float far) {
  return as_mat44f_perspective_projection_depth_zero_to_one_handed(
    aspect_ratio, vertical_fov_radians, near, far, -1.0f);
}

static as_mat44f as_mat44f_perspective_projection_depth_minus_one_to_one_handed(
  const float aspect_ratio,
  const float vertical_fov_radians,
  const float near,
  const float far,
  const float handed) {
  const float e = 1.0f / tanf(vertical_fov_radians * 0.5f);
  return (as_mat44f){
    .elem = {
      [0] = e / aspect_ratio,
      [5] = e,
      [10] = (far + near) / ((far - near) * handed),
      [11] = (2.0f * far * near) / (near - far),
      [14] = handed}};
}

as_mat44f as_mat44f_perspective_projection_depth_minus_one_to_one_lh(
  const float aspect_ratio,
  const float vertical_fov_radians,
  const float near,
  const float far) {
  return as_mat44f_perspective_projection_depth_minus_one_to_one_handed(
    aspect_ratio, vertical_fov_radians, near, far, 1.0f);
}

as_mat44f as_mat44f_perspective_projection_depth_minus_one_to_one_rh(
  const float aspect_ratio,
  const float vertical_fov_radians,
  const float near,
  const float far) {
  return as_mat44f_perspective_projection_depth_minus_one_to_one_handed(
    aspect_ratio, vertical_fov_radians, near, far, -1.0f);
}

static as_mat44f as_mat44f_orthographic_projection_depth_zero_to_one_handed(
  const float left,
  const float right,
  const float bottom,
  const float top,
  const float near,
  const float far,
  const float handed) {
  const float x = 1.0f / (right - left);
  const float y = 1.0f / (top - bottom);
  const float z = 1.0f / (far - near);
  return (as_mat44f){
    .elem = {
      [0] = 2.0f * x,
      [5] = 2.0f * y,
      [10] = z * handed,
      [3] = -(left + right) * x,
      [7] = -(bottom + top) * y,
      [11] = -near * z,
      [15] = 1.0f}};
}

as_mat44f as_mat44f_orthographic_projection_depth_zero_to_one_lh(
  const float left,
  const float right,
  const float bottom,
  const float top,
  const float near,
  const float far) {
  return as_mat44f_orthographic_projection_depth_zero_to_one_handed(
    left, right, bottom, top, near, far, 1.0f);
}

as_mat44f as_mat44f_orthographic_projection_depth_zero_to_one_rh(
  const float left,
  const float right,
  const float bottom,
  const float top,
  const float near,
  const float far) {
  return as_mat44f_orthographic_projection_depth_zero_to_one_handed(
    left, right, bottom, top, near, far, -1.0f);
}

static as_mat44f as_mat44f_orthographic_projection_depth_minus_one_to_one_handed(
  const float left,
  const float right,
  const float bottom,
  const float top,
  const float near,
  const float far,
  const float handed) {
  const float x = 1.0f / (right - left);
  const float y = 1.0f / (top - bottom);
  const float z = 1.0f / (far - near);
  return (as_mat44f){
    .elem = {
      [0] = 2.0f * x,
      [5] = 2.0f * y,
      [10] = 2.0f * z * handed,
      [3] = -(left + right) * x,
      [7] = -(bottom + top) * y,
      [11] = -(near + far) * z,
      [15] = 1.0f}};
}

as_mat44f as_mat44f_orthographic_projection_depth_minus_one_to_one_lh(
  const float left,
  const float right,
  const float bottom,
  const float top,
  const float near,
  const float far) {
  return as_mat44f_orthographic_projection_depth_minus_one_to_one_handed(
    left, right, bottom, top, near, far, 1.0f);
}

as_mat44f as_mat44f_orthographic_projection_depth_minus_one_to_one_rh(
  const float left,
  const float right,
  const float bottom,
  const float top,
  const float near,
  const float far) {
  return as_mat44f_orthographic_projection_depth_minus_one_to_one_handed(
    left, right, bottom, top, near, far, -1.0f);
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

as_point4f as_mat44f_mul_point4f_v(
  const as_mat44f mat, const as_point4f point) {
  return as_mat44f_mul_point4f(&mat, point);
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

as_point4f as_mat44f_project_point3f_v(
  const as_mat44f projection, const as_point3f point) {
  return as_mat44f_project_point3f(&projection, point);
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

float as_mat44f_determinant_v(const as_mat44f mat) {
  return as_mat44f_determinant(&mat);
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

as_mat44f as_mat44f_inverse_v(const as_mat44f mat) {
  return as_mat44f_inverse(&mat);
}

bool as_mat44f_near(
  const as_mat44f* lhs,
  const as_mat44f* rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_mat_near(lhs->elem, rhs->elem, 16, max_diff, max_rel_diff);
}

bool as_mat44f_near_v(
  const as_mat44f lhs,
  const as_mat44f rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_mat44f_near(&lhs, &rhs, max_diff, max_rel_diff);
}

as_quat as_quat_identity(void) {
  return (as_quat){.w = 1.0f, .x = 0.0f, .y = 0.0f, .z = 0.0f};
}

as_quat as_quat_mul_quat(const as_quat lhs, const as_quat rhs) {
  return (as_quat){
    .w = lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z,
    .x = lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
    .y = lhs.w * rhs.y + lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z,
    .z = lhs.w * rhs.z + lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x};
}

as_quat as_quat_add_quat(const as_quat lhs, const as_quat rhs) {
  return (as_quat){
    .w = lhs.w + rhs.w,
    .x = lhs.x + rhs.x,
    .y = lhs.y + rhs.y,
    .z = lhs.z + rhs.z};
}

as_quat as_quat_sub_quat(const as_quat lhs, const as_quat rhs) {
  return (as_quat){
    .w = lhs.w - rhs.w,
    .x = lhs.x - rhs.x,
    .y = lhs.y - rhs.y,
    .z = lhs.z - rhs.z};
}

as_quat as_quat_mul_float(const as_quat quat, const float scalar) {
  return (as_quat){
    .w = quat.w * scalar,
    .x = quat.x * scalar,
    .y = quat.y * scalar,
    .z = quat.z * scalar};
}

as_quat as_quat_div_float(const as_quat quat, const float scalar) {
  const float recip = 1.0f / scalar;
  return as_quat_mul_float(quat, recip);
}

as_quat as_quat_negate(const as_quat quat) {
  return (as_quat){.w = -quat.w, .x = -quat.x, .y = -quat.y, .z = -quat.z};
}

float as_quat_dot(const as_quat lhs, const as_quat rhs) {
  return lhs.w * rhs.w + lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

float as_quat_length_sq(const as_quat quat) {
  return as_quat_dot(quat, quat);
}

float as_quat_length(const as_quat quat) {
  return sqrtf(as_quat_length_sq(quat));
}

as_quat as_quat_normalize(const as_quat quat) {
  return as_quat_div_float(quat, as_quat_length(quat));
}

as_quat as_quat_conjugate(const as_quat quat) {
  return (as_quat){.w = quat.w, .x = -quat.x, .y = -quat.y, .z = -quat.z};
}

as_quat as_quat_inverse(const as_quat quat) {
  return as_quat_div_float(as_quat_conjugate(quat), as_quat_length_sq(quat));
}

as_vec3f as_quat_rotate_vec3f(const as_quat quat, const as_vec3f vec) {
  const as_quat result = as_quat_mul_quat(
    quat,
    as_quat_mul_quat(
      (as_quat){.w = 0.0f, .x = vec.x, .y = vec.y, .z = vec.z},
      as_quat_conjugate(quat)));
  return (as_vec3f){result.x, result.y, result.z};
}

as_quat as_quat_axis_rotation(const as_vec3f axis, const float radians) {
  const as_vec3f quat_axis = as_vec3f_mul_float(axis, sinf(0.5f * radians));
  return as_quat_normalize((as_quat){
    .w = cosf(0.5f * radians),
    .x = quat_axis.x,
    .y = quat_axis.y,
    .z = quat_axis.z});
}

as_quat as_quat_x_axis_rotation(const float radians) {
  return as_quat_axis_rotation(as_vec3f_x_axis(), radians);
}

as_quat as_quat_y_axis_rotation(const float radians) {
  return as_quat_axis_rotation(as_vec3f_y_axis(), radians);
}

as_quat as_quat_z_axis_rotation(const float radians) {
  return as_quat_axis_rotation(as_vec3f_z_axis(), radians);
}

static as_quat as_quat_mix(
  const as_quat begin, const as_quat end, const float t) {
  return (as_quat){
    .w = as_float_mix(begin.w, end.w, t),
    .x = as_float_mix(begin.x, end.x, t),
    .y = as_float_mix(begin.y, end.y, t),
    .z = as_float_mix(begin.z, end.z, t)};
}

as_quat as_quat_nlerp(const as_quat begin, const as_quat end, const float t) {
  const as_quat end_s =
    as_quat_dot(begin, end) < 0.0f ? as_quat_negate(end) : end;
  return as_quat_normalize(as_quat_mix(begin, end_s, t));
}

as_quat as_quat_slerp(const as_quat begin, const as_quat end, const float t) {
  const float dot = as_float_clamp(as_quat_dot(begin, end), -1.0f, 1.0f);
  const float abs_dot = fabsf(dot);
  const as_quat end_s = dot < 0.0f ? as_quat_negate(end) : end;
  if (abs_dot > 0.9995f) {
    return as_quat_normalize(as_quat_mix(begin, end_s, t));
  }
  const float theta = acosf(abs_dot);
  return as_quat_div_float(
    as_quat_add_quat(
      as_quat_mul_float(begin, sinf((1.0f - t) * theta)),
      as_quat_mul_float(end_s, sinf(t * theta))),
    sinf(theta));
}

bool as_quat_near(
  const as_quat lhs,
  const as_quat rhs,
  const float max_diff,
  const float max_rel_diff) {
  return as_float_near(lhs.w, rhs.w, max_diff, max_rel_diff)
      && as_float_near(lhs.x, rhs.x, max_diff, max_rel_diff)
      && as_float_near(lhs.y, rhs.y, max_diff, max_rel_diff)
      && as_float_near(lhs.z, rhs.z, max_diff, max_rel_diff);
}

void as_float_swap(float* lhs, float* rhs) {
  const float temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

void as_int_swap(int* lhs, int* rhs) {
  const int temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

float as_float_clamp(const float value, const float min, const float max) {
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

int as_int_clamp(const int value, const int min, const int max) {
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}

float as_float_max(const float lhs, const float rhs) {
  if (lhs > rhs) {
    return lhs;
  }
  return rhs;
}

int as_int_max(const int lhs, const int rhs) {
  if (lhs > rhs) {
    return lhs;
  }
  return rhs;
}

int as_float_min(const float lhs, const float rhs) {
  if (lhs < rhs) {
    return lhs;
  }
  return rhs;
}

int as_int_min(const int lhs, const int rhs) {
  if (lhs < rhs) {
    return lhs;
  }
  return rhs;
}

float as_float_mix(const float begin, const float end, const float t) {
  return (1.0f - t) * begin + t * end;
}

// floating point comparison by Bruce Dawson
// https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
bool as_float_near(
  const float a,
  const float b,
  const float max_diff,
  const float max_rel_diff) {
  // check if the numbers are really close
  // needed when comparing numbers near zero
  const float diff = fabsf(a - b);
  if (diff <= max_diff) {
    return true;
  }
  const float largest = fmaxf(fabsf(a), fabsf(b));
  // find relative difference
  return diff <= largest * max_rel_diff;
}

float as_radians_from_degrees(const float degrees) {
  return degrees * (as_k_pi / 180.0f);
}

float as_degrees_from_radians(const float radians) {
  return radians * (180.0f / as_k_pi);
}
