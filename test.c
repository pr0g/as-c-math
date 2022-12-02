#include <unity.h>

#include "as-ops.h"

#include <float.h>
#include <math.h>

void setUp(void) {
}

void tearDown(void) {
}

void test_vec2f_expected_values(void) {
  const as_vec2f vec2f = {.x = 1.0f, .y = 2.0f};
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec2f.x);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec2f.y);
}

void test_vec2f_from_point2f(void) {
  const as_point2f point2f = {.x = 10.0f, .y = 20.0f};
  const as_vec2f vec2f = as_vec2f_from_point2f(point2f);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, vec2f.x);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 20.0f, vec2f.y);
}

void test_vec2f_from_vec2i(void) {
  const as_vec2i vec2i = {.x = 12, .y = 24};
  const as_vec2f vec2f = as_vec2f_from_vec2i(vec2i);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, vec2f.x);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 24.0f, vec2f.y);
}

void test_vec2f_from_float(void) {
  {
    const as_vec2f vec2f = as_vec2f_from_float(5.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, vec2f.y);
  }
  {
    const as_vec2f vec2f = as_vec2f_from_float(3.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, vec2f.y);
  }
}

void test_vec2f_add_vec2f(void) {
  {
    const as_vec2f vec2f = as_vec2f_add_vec2f(
      (as_vec2f){.x = 12.0f, .y = 24.0f}, (as_vec2f){.x = 24.0f, .y = 12.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 36.0f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 36.0f, vec2f.y);
  }

  {
    const as_vec2f vec2f = as_vec2f_add_vec2f(
      (as_vec2f){.x = -6.0f, .y = -3.0f}, (as_vec2f){.x = 3.0f, .y = 6.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -3.0f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, vec2f.y);
  }
}

void test_vec2f_sub_vec2f(void) {
  const as_vec2f vec2f = as_vec2f_sub_vec2f(
    (as_vec2f){.x = 12.0f, .y = 24.0f}, (as_vec2f){.x = 24.0f, .y = 12.0f});
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -12.0f, vec2f.x);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, vec2f.y);
}

void test_vec2f_mul_float(void) {
  const as_vec2f vec2f =
    as_vec2f_mul_float((as_vec2f){.x = 5.0f, .y = 2.5f}, 2.0f);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, vec2f.x);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, vec2f.y);
}

void test_vec2f_div_float(void) {
  {
    const as_vec2f vec2f =
      as_vec2f_div_float((as_vec2f){.x = 5.0f, .y = 2.5f}, 2.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.5f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.25f, vec2f.y);
  }
  {
    const as_vec2f vec2f =
      as_vec2f_div_float((as_vec2f){.x = 10.0f, .y = 20.0f}, 5.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, vec2f.y);
  }
}

void test_vec2f_length(void) {
  {
    const float length = as_vec2f_length((as_vec2f){.x = 3.0f, .y = 4.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, length);
  }
  {
    const float length = as_vec2f_length((as_vec2f){.x = 6.0f, .y = 8.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, length);
  }
}

void test_vec2f_length_sq(void) {
  {
    const float length = as_vec2f_length_sq((as_vec2f){.x = 3.0f, .y = 4.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 25.0f, length);
  }
  {
    const float length = as_vec2f_length_sq((as_vec2f){.x = 6.0f, .y = 8.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 100.0f, length);
  }
}

void test_vec2f_dot_vec2f(void) {
  {
    const float dot = as_vec2f_dot_vec2f(
      (as_vec2f){.x = 0.0f, .y = 1.0f}, (as_vec2f){.x = 0.0f, .y = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, dot);
  }
  {
    const float dot = as_vec2f_dot_vec2f(
      (as_vec2f){.x = 1.0f, .y = 0.0f}, (as_vec2f){.x = 0.0f, .y = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, dot);
  }
  {
    const float dot = as_vec2f_dot_vec2f(
      (as_vec2f){.x = -1.0f, .y = 0.0f}, (as_vec2f){.x = 1.0f, .y = 0.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.0f, dot);
  }
  {
    const float dot = as_vec2f_dot_vec2f(
      (as_vec2f){.x = 3.0f, .y = 5.0f}, (as_vec2f){.x = -1.0f, .y = 0.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -3.0f, dot);
  }
}

void test_vec2f_wedge_vec2f(void) {
  {
    const float wedge = as_vec2f_wedge_vec2f(
      (as_vec2f){.x = 0.0f, .y = 1.0f}, (as_vec2f){.x = 0.0f, .y = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, wedge);
  }
  {
    const float wedge = as_vec2f_wedge_vec2f(
      (as_vec2f){.x = 1.0f, .y = 0.0f}, (as_vec2f){.x = 0.0f, .y = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, wedge);
  }
  {
    const float wedge = as_vec2f_wedge_vec2f(
      (as_vec2f){.x = 5.0f, .y = 0.0f}, (as_vec2f){.x = 0.0f, .y = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 25.0f, wedge);
  }
}

void test_vec2f_normalized(void) {
  {
    const as_vec2f normalized =
      as_vec2f_normalized((as_vec2f){.x = 1.0f, .y = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.7071068f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.7071068f, normalized.y);
  }
  {
    const as_vec2f normalized =
      as_vec2f_normalized((as_vec2f){.x = 10.0f, .y = 0.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.y);
  }
  {
    const as_vec2f normalized =
      as_vec2f_normalized((as_vec2f){.x = 0.0f, .y = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, normalized.y);
  }
}

void test_vec2i_from_vec2f(void) {
  {
    const as_vec2i vec2i =
      as_vec2i_from_vec2f((as_vec2f){.x = 0.2f, .y = 0.8f});
    TEST_ASSERT_EQUAL_INT32(0, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(1, vec2i.y);
  }
  {
    const as_vec2i vec2i =
      as_vec2i_from_vec2f((as_vec2f){.x = 0.5f, .y = 1.5f});
    TEST_ASSERT_EQUAL_INT32(1, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(2, vec2i.y);
  }
  {
    const as_vec2i vec2i =
      as_vec2i_from_vec2f((as_vec2f){.x = 4.99f, .y = 10.49f});
    TEST_ASSERT_EQUAL_INT32(5, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(10, vec2i.y);
  }
}

void test_vec2i_from_int(void) {
  {
    const as_vec2i vec2i = as_vec2i_from_int(2);
    TEST_ASSERT_EQUAL_INT32(2, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(2, vec2i.y);
  }
  {
    const as_vec2i vec2i = as_vec2i_from_int(5);
    TEST_ASSERT_EQUAL_INT32(5, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(5, vec2i.y);
  }
}

void test_vec2i_add_vec2i(void) {
  {
    const as_vec2i vec2i = as_vec2i_add_vec2i(
      (as_vec2i){.x = 1, .y = 4}, (as_vec2i){.x = 3, .y = 2});
    TEST_ASSERT_EQUAL_INT32(4, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(6, vec2i.y);
  }

  {
    const as_vec2i vec2i = as_vec2i_add_vec2i(
      (as_vec2i){.x = 10, .y = 5}, (as_vec2i){.x = 5, .y = 7});
    TEST_ASSERT_EQUAL_INT32(15, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(12, vec2i.y);
  }
}

void test_vec2i_sub_vec2i(void) {
  {
    const as_vec2i vec2i = as_vec2i_sub_vec2i(
      (as_vec2i){.x = 5, .y = 4}, (as_vec2i){.x = 2, .y = 5});
    TEST_ASSERT_EQUAL_INT32(3, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(-1, vec2i.y);
  }
  {
    const as_vec2i vec2i = as_vec2i_sub_vec2i(
      (as_vec2i){.x = 2, .y = 15}, (as_vec2i){.x = 5, .y = 11});
    TEST_ASSERT_EQUAL_INT32(-3, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(4, vec2i.y);
  }
}

void test_vec2i_mul_float(void) {
  {
    const as_vec2f vec2f = as_vec2i_mul_float((as_vec2i){.x = 2, .y = 4}, 2.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, vec2f.y);
  }
  {
    const as_vec2f vec2f = as_vec2i_mul_float((as_vec2i){.x = 1, .y = 2}, 0.5f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.5f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec2f.y);
  }
}

void test_vec2i_div_float(void) {
  {
    const as_vec2f vec2f = as_vec2i_div_float((as_vec2i){.x = 2, .y = 4}, 2.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec2f.y);
  }
  {
    const as_vec2f vec2f = as_vec2i_div_float((as_vec2i){.x = 1, .y = 2}, 0.5f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, vec2f.y);
  }
}

void test_vec2i_length(void) {
  {
    const float length = as_vec2i_length((as_vec2i){.x = 3, .y = 4});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, length);
  }
  {
    const float length = as_vec2i_length((as_vec2i){.x = 6, .y = 8});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, length);
  }
}

void test_vec2i_length_sq(void) {
  {
    const int length = as_vec2i_length_sq((as_vec2i){.x = 3, .y = 4});
    TEST_ASSERT_EQUAL_INT32(25.0f, length);
  }
  {
    const int length = as_vec2i_length_sq((as_vec2i){.x = 6, .y = 8});
    TEST_ASSERT_EQUAL_INT32(100.0f, length);
  }
}

void test_vec3f_from_point3f(void) {
  {
    const as_vec3f vec3f =
      as_vec3f_from_point3f((as_point3f){.x = 3.0f, .y = 2.0f, .z = 11.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3f_from_point3f((as_point3f){.x = 9.0f, .y = 1.0f, .z = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, vec3f.z);
  }
}

void test_vec3f_from_vec3i(void) {
  {
    const as_vec3f vec3f =
      as_vec3f_from_vec3i((as_vec3i){.x = 4, .y = 1, .z = 15});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 15.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3f_from_vec3i((as_vec3i){.x = 3, .y = 2, .z = 8});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, vec3f.z);
  }
}

void test_vec3f_from_mat34f(void) {
  // clang-format off
  const as_mat34f mat34f = (as_mat34f){.elem = {
        1.0f, 2.0f,  3.0f,  4.0f,
        5.0f, 6.0f,  7.0f,  8.0f,
        9.0f, 10.0f, 11.0f, 12.0f}};
  // clang-format on
  {
    const as_vec3f vec3f = as_vec3f_from_mat34f(&mat34f, 0);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f = as_vec3f_from_mat34f(&mat34f, 1);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 6.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f = as_vec3f_from_mat34f(&mat34f, 2);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 7.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f = as_vec3f_from_mat34f(&mat34f, 3);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, vec3f.z);
  }
}

void test_vec3f_from_float(void) {
  {
    const as_vec3f vec3f = as_vec3f_from_float(5.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f = as_vec3f_from_float(2.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.z);
  }
}

void test_vec3f_add_vec3f(void) {
  {
    const as_vec3f vec3f = as_vec3f_add_vec3f(
      (as_vec3f){.x = 12.0f, .y = 24.0f, .z = 9.0f},
      (as_vec3f){.x = 24.0f, .y = 12.0f, .z = 27.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 36.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 36.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 36.0f, vec3f.z);
  }

  {
    const as_vec3f vec3f = as_vec3f_add_vec3f(
      (as_vec3f){.x = -6.0f, .y = -3.0f, .z = 2.0f},
      (as_vec3f){.x = 3.0f, .y = 6.0f, .z = 9.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -3.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, vec3f.z);
  }
}

void test_vec3f_sub_vec3f(void) {
  {
    const as_vec3f vec3f = as_vec3f_sub_vec3f(
      (as_vec3f){.x = 12.0f, .y = 24.0f, .z = 9.0f},
      (as_vec3f){.x = 8.0f, .y = 12.0f, .z = 27.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -18.0f, vec3f.z);
  }

  {
    const as_vec3f vec3f = as_vec3f_sub_vec3f(
      (as_vec3f){.x = 20.0f, .y = 10.0f, .z = 1.0f},
      (as_vec3f){.x = 5.0f, .y = 15.0f, .z = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 15.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -5.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -4.0f, vec3f.z);
  }
}

void test_vec3f_mul_float(void) {
  {
    const as_vec3f vec3f =
      as_vec3f_mul_float((as_vec3f){.x = 2.0f, .y = 4.0f, .z = 6.0f}, 2.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3f_mul_float((as_vec3f){.x = 5.0f, .y = 4.0f, .z = 7.0f}, 5.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 25.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 20.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 35.0f, vec3f.z);
  }
}

void test_vec3f_div_float(void) {
  {
    const as_vec3f vec3f =
      as_vec3f_div_float((as_vec3f){.x = 2.0f, .y = 4.0f, .z = 6.0f}, 2.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3f_div_float((as_vec3f){.x = 5.0f, .y = 10.0f, .z = 25.0f}, 5.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, vec3f.z);
  }
}

void test_vec3f_length(void) {
  {
    const float length =
      as_vec3f_length((as_vec3f){.x = 3.0f, .y = 4.0f, .z = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 7.0710678f, length);
  }
  {
    const float length =
      as_vec3f_length((as_vec3f){.x = 6.0f, .y = 8.0f, .z = 10.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 14.1421356f, length);
  }
}

void test_vec3f_rotate_x_axis(void) {
  {
    const as_vec3f vec3f =
      as_vec3f_rotate_x_axis((as_vec3f){.y = 1.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3f_rotate_x_axis((as_vec3f){.z = 1.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.z);
  }
}

void test_vec3f_rotate_y_axis(void) {
  {
    const as_vec3f vec3f =
      as_vec3f_rotate_y_axis((as_vec3f){.x = 1.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3f_rotate_y_axis((as_vec3f){.z = 1.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.z);
  }
}

void test_vec3f_rotate_z_axis(void) {
  {
    const as_vec3f vec3f =
      as_vec3f_rotate_z_axis((as_vec3f){.x = 1.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3f_rotate_z_axis((as_vec3f){.y = 1.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.z);
  }
}

void test_vec3f_cross_vec3f(void) {
  {
    const as_vec3f vec3f =
      as_vec3f_cross_vec3f((as_vec3f){.x = 1.0f}, (as_vec3f){.z = -1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3f_cross_vec3f((as_vec3f){.z = 1.0f}, (as_vec3f){.x = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3f_cross_vec3f((as_vec3f){.z = 1.0f}, (as_vec3f){.y = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3f_cross_vec3f((as_vec3f){.y = 1.0f}, (as_vec3f){.z = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f.z);
  }
}

void test_vec3f_dot_vec3f(void) {
  {
    const float dot = as_vec3f_dot_vec3f(
      (as_vec3f){.x = 0.0f, .y = 1.0f, .z = 0.0f},
      (as_vec3f){.x = 0.0f, .y = 1.0f, .z = 0.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, dot);
  }
  {
    const float dot = as_vec3f_dot_vec3f(
      (as_vec3f){.x = 0.0f, .y = 0.0f, .z = 1.0f},
      (as_vec3f){.x = 0.0f, .y = 1.0f, .z = 0.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, dot);
  }
  {
    const float dot = as_vec3f_dot_vec3f(
      (as_vec3f){.x = 0.0f, .y = 0.0f, .z = 1.0f},
      (as_vec3f){.x = 0.0f, .y = 0.0f, .z = -1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.0f, dot);
  }
  {
    const float dot = as_vec3f_dot_vec3f(
      (as_vec3f){.x = 3.0f, .y = 5.0f, .z = 10.0f},
      (as_vec3f){.x = 0.0f, .y = 0.0f, .z = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, dot);
  }
}

void test_vec3f_normalized(void) {
  {
    const as_vec3f normalized =
      as_vec3f_normalized((as_vec3f){.x = 1.0f, .y = 1.0f, .z = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.577350269f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.577350269f, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.577350269f, normalized.z);
  }
  {
    const as_vec3f normalized = as_vec3f_normalized((as_vec3f){.x = 10.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.z);
  }
  {
    const as_vec3f normalized = as_vec3f_normalized((as_vec3f){.y = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.z);
  }
  {
    const as_vec3f normalized = as_vec3f_normalized((as_vec3f){.z = 12.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, normalized.z);
  }
}

void test_vec3f_axes(void) {
  {
    const as_vec3f vec3f_axis = as_vec3f_x_axis();
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f_axis.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f_axis.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f_axis.z);
  }
  {
    const as_vec3f vec3f_axis = as_vec3f_y_axis();
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f_axis.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f_axis.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f_axis.z);
  }
  {
    const as_vec3f vec3f_axis = as_vec3f_z_axis();
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f_axis.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, vec3f_axis.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f_axis.z);
  }
}

void test_vec3f_mix(void) {
  {
    const as_vec3f begin = (as_vec3f){};
    const as_vec3f end = as_vec3f_from_float(10.0f);
    const as_vec3f mixed = as_vec3f_mix(begin, end, 0.5f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mixed.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mixed.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mixed.z);
  }
  {
    const as_vec3f begin = as_vec3f_from_float(10.0f);
    const as_vec3f end = as_vec3f_from_float(20.0f);
    const as_vec3f mixed = as_vec3f_mix(begin, end, 0.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mixed.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mixed.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mixed.z);
  }
  {
    const as_vec3f begin = as_vec3f_from_float(50.0f);
    const as_vec3f end = as_vec3f_from_float(100.0f);
    const as_vec3f mixed = as_vec3f_mix(begin, end, 1.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 100.0f, mixed.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 100.0f, mixed.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 100.0f, mixed.z);
  }
  {
    const as_vec3f begin = as_vec3f_from_float(0.0f);
    const as_vec3f end = as_vec3f_from_float(100.0f);
    const as_vec3f mixed = as_vec3f_mix(begin, end, 1.5f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 150.0f, mixed.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 150.0f, mixed.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 150.0f, mixed.z);
  }
}

void test_vec3i_from_vec3f(void) {
  {
    const as_vec3i vec3i =
      as_vec3i_from_vec3f((as_vec3f){.x = 0.2f, .y = 0.8f, .z = 1.2f});
    TEST_ASSERT_EQUAL_INT32(0, vec3i.x);
    TEST_ASSERT_EQUAL_INT32(1, vec3i.y);
    TEST_ASSERT_EQUAL_INT32(1, vec3i.z);
  }
  {
    const as_vec3i vec3i =
      as_vec3i_from_vec3f((as_vec3f){.x = 0.5f, .y = 1.5f, .z = 2.5f});
    TEST_ASSERT_EQUAL_INT32(1, vec3i.x);
    TEST_ASSERT_EQUAL_INT32(2, vec3i.y);
    TEST_ASSERT_EQUAL_INT32(3, vec3i.z);
  }
  {
    const as_vec3i vec3i =
      as_vec3i_from_vec3f((as_vec3f){.x = 4.99f, .y = 10.49f, .z = 15.49f});
    TEST_ASSERT_EQUAL_INT32(5, vec3i.x);
    TEST_ASSERT_EQUAL_INT32(10, vec3i.y);
    TEST_ASSERT_EQUAL_INT32(15, vec3i.z);
  }
}

void test_vec3i_add_vec3i(void) {
  {
    const as_vec3i vec3i = as_vec3i_add_vec3i(
      (as_vec3i){.x = 1, .y = 4, .z = 2}, (as_vec3i){.x = 3, .y = 2, .z = 6});
    TEST_ASSERT_EQUAL_INT32(4, vec3i.x);
    TEST_ASSERT_EQUAL_INT32(6, vec3i.y);
    TEST_ASSERT_EQUAL_INT32(8, vec3i.z);
  }

  {
    const as_vec3i vec3i = as_vec3i_add_vec3i(
      (as_vec3i){.x = 10, .y = 5, .z = 100},
      (as_vec3i){.x = 5, .y = 7, .z = 23});
    TEST_ASSERT_EQUAL_INT32(15, vec3i.x);
    TEST_ASSERT_EQUAL_INT32(12, vec3i.y);
    TEST_ASSERT_EQUAL_INT32(123, vec3i.z);
  }
}

void test_vec3i_sub_vec3i(void) {
  {
    const as_vec3i vec3i = as_vec3i_sub_vec3i(
      (as_vec3i){.x = 1, .y = 4, .z = 2}, (as_vec3i){.x = 3, .y = 2, .z = 6});
    TEST_ASSERT_EQUAL_INT32(-2, vec3i.x);
    TEST_ASSERT_EQUAL_INT32(2, vec3i.y);
    TEST_ASSERT_EQUAL_INT32(-4, vec3i.z);
  }

  {
    const as_vec3i vec3i = as_vec3i_sub_vec3i(
      (as_vec3i){.x = 10, .y = 5, .z = 100},
      (as_vec3i){.x = 5, .y = 7, .z = 23});
    TEST_ASSERT_EQUAL_INT32(5, vec3i.x);
    TEST_ASSERT_EQUAL_INT32(-2, vec3i.y);
    TEST_ASSERT_EQUAL_INT32(77, vec3i.z);
  }
}

void test_vec3i_mul_float(void) {
  {
    const as_vec3f vec3f =
      as_vec3i_mul_float((as_vec3i){.x = 2, .y = 4, .z = 8}, 2.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 16.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3i_mul_float((as_vec3i){.x = 1, .y = 2, .z = 4}, 0.5f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.5f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.z);
  }
}

void test_vec3i_div_float(void) {
  {
    const as_vec3f vec3f =
      as_vec3i_div_float((as_vec3i){.x = 10, .y = 20, .z = 50}, 5.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, vec3f.z);
  }
  {
    const as_vec3f vec3f =
      as_vec3i_div_float((as_vec3i){.x = 5, .y = 20, .z = 1}, 10.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.5f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.1f, vec3f.z);
  }
}

void test_vec3i_length(void) {
  {
    const float length = as_vec3i_length((as_vec3i){.x = 3, .y = 6, .z = 9});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.22497216f, length);
  }
  {
    const float length = as_vec3i_length((as_vec3i){.x = 6, .y = 8, .z = 2});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.1980390f, length);
  }
}

void test_point2f_from_vec2f(void) {
  {
    const as_point2f point2f =
      as_point2f_from_vec2f((as_vec2f){.x = 10.0f, .y = 20.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 20.0f, point2f.y);
  }
  {
    const as_point2f point2f =
      as_point2f_from_vec2f((as_vec2f){.x = 5.0f, .y = 10.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, point2f.y);
  }
}

void test_point2f_from_point4f(void) {
  {
    const as_point2f point2f = as_point2f_from_point4f(
      (as_point4f){.x = 10.0f, .y = 20.0f, .z = 30.0f, .w = 40.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 20.0f, point2f.y);
  }
  {
    const as_point2f point2f = as_point2f_from_point4f(
      (as_point4f){.x = 5.0f, .y = 10.0f, .z = 2.0f, .w = 15.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, point2f.y);
  }
}

void test_mat22f_determinant(void) {
  {
    const as_mat22f mat44f = (as_mat22f){.elem = {1.0f, 3.0f, 6.0f, 7.0f}};
    const float determinant = as_mat22f_determinant(&mat44f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -11.0f, determinant);
  }
  {
    const as_mat22f mat44f = (as_mat22f){.elem = {10.0f, 20.0f, 25.0f, 35.0f}};
    const float determinant = as_mat22f_determinant(&mat44f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -150.0f, determinant);
  }
}

void test_mat22f_inverse(void) {
  {
    const as_mat22f mat22f = (as_mat22f){.elem = {5.0f, 12.0f, 11.0f, 16.0f}};
    const float expected[] = {
      -4.0f / 13.0f, 3.0f / 13.0f, 11.0f / 52.0f, -5.0f / 52.0f};
    const as_mat22f inverse = as_mat22f_inverse(&mat22f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[0], inverse.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[1], inverse.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[2], inverse.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[3], inverse.elem[3]);
  }
  {
    const as_mat22f mat22f = (as_mat22f){.elem = {1.0f, 5.0f, 2.0f, 1.0f}};
    const float expected[] = {
      -1.0f / 9.0f, 5.0f / 9.0f, 2.0f / 9.0f, -1.0f / 9.0f};
    const as_mat22f inverse = as_mat22f_inverse(&mat22f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[0], inverse.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[1], inverse.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[2], inverse.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[3], inverse.elem[3]);
  }
}

void test_mat33f_determinant(void) {
  {
    // clang-format off
    const as_mat33f mat33f = (as_mat33f){.elem = {
      1.0f, 3.0f, 5.0f,
      1.0f, 3.0f, 1.0f,
      4.0f, 3.0f, 9.0f}};
    // clang-format on
    const float determinant = as_mat33f_determinant(&mat33f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -36.0f, determinant);
  }
  {
    // clang-format off
    const as_mat33f mat33f = (as_mat33f){.elem = {
      2.0f, 24.0f, 9.0f,
      3.0f, 11.0f, 15.0f,
      1.0f, 3.0f, 2.0f}};
    // clang-format on
    const float determinant = as_mat33f_determinant(&mat33f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 152.0f, determinant);
  }
}

void test_mat33f_inverse(void) {
  {
    // clang-format off
    const as_mat33f mat33f = (as_mat33f){.elem = {
      1.0f, 3.0f, 5.0f,
      1.0f, 3.0f, 1.0f,
      4.0f, 3.0f, 9.0f}};
    const float expected[] = {
      -2.0f/3.0f, 1.0f/3.0f, 1.0f/3.0f,
      5.0f/36.0f, 11.0f/36.0f, -1.0f/9.0f,
      1.0f/4.0f, -1.0f/4.0f, 0.0f};
    // clang-format on
    const as_mat33f inverse = as_mat33f_inverse(&mat33f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[0], inverse.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[1], inverse.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[2], inverse.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[3], inverse.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[4], inverse.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[5], inverse.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[6], inverse.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[7], inverse.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[8], inverse.elem[8]);
  }
  {
    // clang-format off
    const as_mat33f mat33f = (as_mat33f){.elem = {
      1.0f, 2.0f, 3.0f,
      4.0f, 5.0f, 6.0f,
      7.0f, 2.0f, 9.0f}};
    const float expected[] = {
      -11.0f/12.0f, 1.0f/3.0f, 1.0f/12.0f,
      -1.0f/6.0f, 1.0f/3.0f, -1.0f/6.0f,
      3.0f/4.0f, -1.0f/3.0f, 1.0f/12.0f};
    // clang-format on
    const as_mat33f inverse = as_mat33f_inverse(&mat33f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[0], inverse.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[1], inverse.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[2], inverse.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[3], inverse.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[4], inverse.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[5], inverse.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[6], inverse.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[7], inverse.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[8], inverse.elem[8]);
  }
}

void test_mat44f_determinant(void) {
  {
    // clang-format off
    const as_mat44f mat44f = (as_mat44f){.elem = {
      1.0f, 3.0f, 5.0f, 9.0f,
      1.0f, 3.0f, 1.0f, 7.0f,
      4.0f, 3.0f, 9.0f, 7.0f,
      5.0f, 2.0f, 0.0f, 9.0f}};
    // clang-format on
    const float determinant = as_mat44f_determinant(&mat44f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -376.0f, determinant);
  }
  {
    // clang-format off
    const as_mat44f mat44f = (as_mat44f){.elem = {
      1.0f, 2.0f, 3.0f, 4.0f,
      4.0f, 6.0f, 7.0f, 8.0f,
      9.0f, 6.0f, 11.0f, 3.0f,
      13.0f, 14.0f, 3.0f, 4.0f}};
    // clang-format on
    const float determinant = as_mat44f_determinant(&mat44f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -180.0f, determinant);
  }
  {
    // clang-format off
    const as_mat44f mat44f = (as_mat44f){.elem = {
      2.0f, 5.0f, 1.0f, 8.0f,
      2.0f, 1.0f, 4.0f, 3.0f,
      2.0f, 4.0f, 7.0f, 3.0f,
      1.0f, 3.0f, 4.0f, 5.0f}};
    // clang-format on
    const float determinant = as_mat44f_determinant(&mat44f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -132.0f, determinant);
  }
}

void test_mat44f_inverse(void) {
  {
    // clang-format off
    const as_mat44f mat44f = (as_mat44f){.elem = {
        1.0f, 3.0f, 5.0f, 9.0f,
        1.0f, 3.0f, 1.0f, 7.0f,
        4.0f, 3.0f, 9.0f, 7.0f,
        5.0f, 2.0f, 0.0f, 9.0f}};
    const float expected[] = {
      -13.0f/47.0f, 2.0f/47.0f, 7.0f/47.0f, 6.0f/47.0f,
      -5.0f/8.0f, 7.0f/8.0f, 1.0f/4.0f, -1.0f/4.0f,
       39.0f/376.0f, -53.0f/376.0f, 13.0f/188.0f, -9.0f/188.0f,
       55.0f/188.0f, -41.0f/188.0f, -13.0f/94.0f, 9.0f/94.0f};
    // clang-format on
    const as_mat44f inverse = as_mat44f_inverse(&mat44f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[0], inverse.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[1], inverse.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[2], inverse.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[3], inverse.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[4], inverse.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[5], inverse.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[6], inverse.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[7], inverse.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[8], inverse.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[9], inverse.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[10], inverse.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[11], inverse.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[12], inverse.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[13], inverse.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[14], inverse.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[15], inverse.elem[15]);
  }
  {
    // clang-format off
    const as_mat44f mat44f = (as_mat44f){.elem = {
      2.0f, 5.0f, 1.0f, 8.0f,
      2.0f, 1.0f, 4.0f, 3.0f,
      2.0f, 4.0f, 7.0f, 3.0f,
      1.0f, 3.0f, 4.0f, 5.0f}};
    const float expected[] = {
      3.0f/11.0f, 16.0f/33.0f, 5.0f/33.0f, -9.0f/11.0f,
      7.0f/44.0f, -47.0f/132.0f, 41.0f/132.0f, -5.0f/22.0f,
      -7.0f/44.0f, 1.0f/44.0f, 1.0f/44.0f, 5.0f/22.0f,
      -1.0f/44.0f, 13.0f/132.0f, -31.0f/132.0f, 7.0f/22.0f};
    // clang-format on
    const as_mat44f inverse = as_mat44f_inverse(&mat44f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[0], inverse.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[1], inverse.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[2], inverse.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[3], inverse.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[4], inverse.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[5], inverse.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[6], inverse.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[7], inverse.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[8], inverse.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[9], inverse.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[10], inverse.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[11], inverse.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[12], inverse.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[13], inverse.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[14], inverse.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, expected[15], inverse.elem[15]);
  }
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_vec2f_expected_values);
  RUN_TEST(test_vec2f_from_point2f);
  RUN_TEST(test_vec2f_from_vec2i);
  RUN_TEST(test_vec2f_from_float);
  RUN_TEST(test_vec2f_add_vec2f);
  RUN_TEST(test_vec2f_sub_vec2f);
  RUN_TEST(test_vec2f_mul_float);
  RUN_TEST(test_vec2f_div_float);
  RUN_TEST(test_vec2f_length);
  RUN_TEST(test_vec2f_length_sq);
  RUN_TEST(test_vec2f_dot_vec2f);
  RUN_TEST(test_vec2f_wedge_vec2f);
  RUN_TEST(test_vec2f_normalized);
  RUN_TEST(test_vec2i_from_vec2f);
  RUN_TEST(test_vec2i_from_int);
  RUN_TEST(test_vec2i_add_vec2i);
  RUN_TEST(test_vec2i_sub_vec2i);
  RUN_TEST(test_vec2i_mul_float);
  RUN_TEST(test_vec2i_div_float);
  RUN_TEST(test_vec2i_length);
  RUN_TEST(test_vec2i_length_sq);
  RUN_TEST(test_vec3f_from_point3f);
  RUN_TEST(test_vec3f_from_vec3i);
  RUN_TEST(test_vec3f_from_mat34f);
  RUN_TEST(test_vec3f_from_float);
  RUN_TEST(test_vec3f_add_vec3f);
  RUN_TEST(test_vec3f_sub_vec3f);
  RUN_TEST(test_vec3f_mul_float);
  RUN_TEST(test_vec3f_div_float);
  RUN_TEST(test_vec3f_length);
  RUN_TEST(test_vec3f_rotate_x_axis);
  RUN_TEST(test_vec3f_rotate_y_axis);
  RUN_TEST(test_vec3f_rotate_z_axis);
  RUN_TEST(test_vec3f_cross_vec3f);
  RUN_TEST(test_vec3f_dot_vec3f);
  RUN_TEST(test_vec3f_normalized);
  RUN_TEST(test_vec3f_axes);
  RUN_TEST(test_vec3f_mix);
  RUN_TEST(test_vec3i_from_vec3f);
  RUN_TEST(test_vec3i_add_vec3i);
  RUN_TEST(test_vec3i_sub_vec3i);
  RUN_TEST(test_vec3i_mul_float);
  RUN_TEST(test_vec3i_div_float);
  RUN_TEST(test_vec3i_length);
  RUN_TEST(test_point2f_from_vec2f);
  RUN_TEST(test_point2f_from_point4f);
  //
  RUN_TEST(test_mat22f_determinant);
  RUN_TEST(test_mat22f_inverse);
  RUN_TEST(test_mat33f_determinant);
  RUN_TEST(test_mat33f_inverse);
  RUN_TEST(test_mat44f_determinant);
  RUN_TEST(test_mat44f_inverse);
  return UNITY_END();
}
