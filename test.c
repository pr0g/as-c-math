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

void test_vec2f_normalize(void) {
  {
    const as_vec2f normalized =
      as_vec2f_normalize((as_vec2f){.x = 1.0f, .y = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.7071068f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.7071068f, normalized.y);
  }
  {
    const as_vec2f normalized =
      as_vec2f_normalize((as_vec2f){.x = 10.0f, .y = 0.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.y);
  }
  {
    const as_vec2f normalized =
      as_vec2f_normalize((as_vec2f){.x = 0.0f, .y = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, normalized.y);
  }
}

void test_vec2f_mix(void) {
  {
    const as_vec2f begin = (as_vec2f){};
    const as_vec2f end = as_vec2f_from_float(10.0f);
    const as_vec2f mixed = as_vec2f_mix(begin, end, 0.5f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mixed.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mixed.y);
  }
  {
    const as_vec2f begin = as_vec2f_from_float(10.0f);
    const as_vec2f end = as_vec2f_from_float(20.0f);
    const as_vec2f mixed = as_vec2f_mix(begin, end, 0.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mixed.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mixed.y);
  }
  {
    const as_vec2f begin = as_vec2f_from_float(50.0f);
    const as_vec2f end = as_vec2f_from_float(100.0f);
    const as_vec2f mixed = as_vec2f_mix(begin, end, 1.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 100.0f, mixed.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 100.0f, mixed.y);
  }
  {
    const as_vec2f begin = as_vec2f_from_float(0.0f);
    const as_vec2f end = as_vec2f_from_float(100.0f);
    const as_vec2f mixed = as_vec2f_mix(begin, end, 1.5f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 150.0f, mixed.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 150.0f, mixed.y);
  }
}

void test_vec2f_negate(void) {
  {
    const as_vec2f negated =
      as_vec2f_negate((as_vec2f){.x = 10.5f, .y = 20.2f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -10.5f, negated.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -20.2f, negated.y);
  }
  {
    const as_vec2f negated =
      as_vec2f_negate((as_vec2f){.x = -2.0f, .y = -4.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, negated.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, negated.y);
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

void test_vec2i_negate(void) {
  {
    const as_vec2i negated = as_vec2i_negate((as_vec2i){.x = 12, .y = 36});
    TEST_ASSERT_EQUAL_INT32(-12, negated.x);
    TEST_ASSERT_EQUAL_INT32(-36, negated.y);
  }
  {
    const as_vec2i negated = as_vec2i_negate((as_vec2i){.x = -5, .y = -10});
    TEST_ASSERT_EQUAL_INT32(5, negated.x);
    TEST_ASSERT_EQUAL_INT32(10, negated.y);
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

void test_vec3f_normalize(void) {
  {
    const as_vec3f normalized =
      as_vec3f_normalize((as_vec3f){.x = 1.0f, .y = 1.0f, .z = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.577350269f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.577350269f, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.577350269f, normalized.z);
  }
  {
    const as_vec3f normalized = as_vec3f_normalize((as_vec3f){.x = 10.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.z);
  }
  {
    const as_vec3f normalized = as_vec3f_normalize((as_vec3f){.y = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, normalized.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, normalized.z);
  }
  {
    const as_vec3f normalized = as_vec3f_normalize((as_vec3f){.z = 12.0f});
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

void test_vec3f_negate(void) {
  {
    const as_vec3f negated =
      as_vec3f_negate((as_vec3f){.x = 1.5f, .y = 25.2f, .z = 35.1f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.5f, negated.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -25.2f, negated.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -35.1f, negated.z);
  }
  {
    const as_vec3f negated =
      as_vec3f_negate((as_vec3f){.x = -1.0f, .y = -5.0f, .z = 6.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, negated.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, negated.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -6.0f, negated.z);
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

void test_vec3i_negate(void) {
  {
    const as_vec3i negated =
      as_vec3i_negate((as_vec3i){.x = 4, .y = 8, .z = 12});
    TEST_ASSERT_EQUAL_INT32(-4, negated.x);
    TEST_ASSERT_EQUAL_INT32(-8, negated.y);
    TEST_ASSERT_EQUAL_INT32(-12, negated.z);
  }
  {
    const as_vec3i negated =
      as_vec3i_negate((as_vec3i){.x = -1, .y = -5, .z = 6.0f});
    TEST_ASSERT_EQUAL_INT32(1, negated.x);
    TEST_ASSERT_EQUAL_INT32(5, negated.y);
    TEST_ASSERT_EQUAL_INT32(-6, negated.z);
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

void test_point2f_from_point2i(void) {
  {
    const as_point2f point2f =
      as_point2f_from_point2i((as_point2i){.x = 3, .y = 8});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, point2f.y);
  }
  {
    const as_point2f point2f =
      as_point2f_from_point2i((as_point2i){.x = 25, .y = 50});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 25.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 50.0f, point2f.y);
  }
}

void test_point2f_from_float(void) {
  {
    const as_point2f point2f = as_point2f_from_float(10.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, point2f.y);
  }
  {
    const as_point2f point2f = as_point2f_from_float(123.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 123.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 123.0f, point2f.y);
  }
}

void test_point2f_add_vec2f(void) {
  {
    as_point2f point2f =
      as_point2f_add_vec2f((as_point2f){2.0f, 5.0f}, (as_vec2f){7.0f, 11.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 16.0f, point2f.y);
  }
  {
    as_point2f point2f = as_point2f_add_vec2f(
      (as_point2f){37.0f, 123.0f}, (as_vec2f){13.0f, 27.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 50.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 150.0f, point2f.y);
  }
  {
    as_point2f point2f = as_point2f_add_vec2f(
      (as_point2f){37.0f, 123.0f}, (as_vec2f){-4.0f, -20.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 33.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 103.0f, point2f.y);
  }
}

void test_point2f_sub_point2f(void) {
  {
    as_vec2f vec2f = as_point2f_sub_point2f(
      (as_point2f){100.0f, 50.0f}, (as_point2f){20.0f, 30.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 80.0f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 20.0f, vec2f.y);
  }
  {
    as_vec2f vec2f = as_point2f_sub_point2f(
      (as_point2f){200.0f, 150.0f}, (as_point2f){100.0f, -20.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 100.0f, vec2f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 170.0f, vec2f.y);
  }
}

void test_point2f_negate(void) {
  {
    const as_point2f negated =
      as_point2f_negate((as_point2f){.x = 10.5f, .y = 20.2f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -10.5f, negated.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -20.2f, negated.y);
  }
  {
    const as_point2f negated =
      as_point2f_negate((as_point2f){.x = -2.0f, .y = -4.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, negated.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, negated.y);
  }
}

void test_point2f_distance_point2f(void) {
  {
    const float distance = as_point2f_distance_point2f(
      (as_point2f){0.0f, 0.0f}, (as_point2f){3.0f, 4.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, distance);
  }

  {
    const float distance = as_point2f_distance_point2f(
      (as_point2f){3.0f, 4.0f}, (as_point2f){-3.0f, -4.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, distance);
  }
}

void test_point2i_from_point2f(void) {
  {
    const as_point2i point2i =
      as_point2i_from_point2f((as_point2f){.x = 3.8f, .y = 7.2f});
    TEST_ASSERT_EQUAL_INT32(4, point2i.x);
    TEST_ASSERT_EQUAL_INT32(7, point2i.y);
  }
  {
    const as_point2i point2i =
      as_point2i_from_point2f((as_point2f){.x = 0.1f, .y = -0.1f});
    TEST_ASSERT_EQUAL_INT32(0, point2i.x);
    TEST_ASSERT_EQUAL_INT32(0, point2i.y);
  }
  {
    const as_point2i point2i =
      as_point2i_from_point2f((as_point2f){.x = 55.99f, .y = 6.49f});
    TEST_ASSERT_EQUAL_INT32(56, point2i.x);
    TEST_ASSERT_EQUAL_INT32(6, point2i.y);
  }
}

void test_point2i_from_vec2i(void) {
  {
    const as_point2i point2i =
      as_point2i_from_vec2i((as_vec2i){.x = 13, .y = 18});
    TEST_ASSERT_EQUAL_INT32(13, point2i.x);
    TEST_ASSERT_EQUAL_INT32(18, point2i.y);
  }
  {
    const as_point2i point2i =
      as_point2i_from_vec2i((as_vec2i){.x = 3, .y = 2});
    TEST_ASSERT_EQUAL_INT32(3, point2i.x);
    TEST_ASSERT_EQUAL_INT32(2, point2i.y);
  }
}

void test_point2i_from_int(void) {
  {
    const as_point2i point2i = as_point2i_from_int(2);
    TEST_ASSERT_EQUAL_INT32(2, point2i.x);
    TEST_ASSERT_EQUAL_INT32(2, point2i.y);
  }
  {
    const as_point2i point2i = as_point2i_from_int(10);
    TEST_ASSERT_EQUAL_INT32(10, point2i.x);
    TEST_ASSERT_EQUAL_INT32(10, point2i.y);
  }
}

void test_point2i_add_vec2i(void) {
  {
    const as_point2i point2i =
      as_point2i_add_vec2i((as_point2i){2, 5}, (as_vec2i){7, 11});
    TEST_ASSERT_EQUAL_INT32(9, point2i.x);
    TEST_ASSERT_EQUAL_INT32(16, point2i.y);
  }
  {
    const as_point2i point2i =
      as_point2i_add_vec2i((as_point2i){37, 123}, (as_vec2i){13, 27});
    TEST_ASSERT_EQUAL_INT32(50, point2i.x);
    TEST_ASSERT_EQUAL_INT32(150, point2i.y);
  }
  {
    const as_point2i point2i =
      as_point2i_add_vec2i((as_point2i){37, 123}, (as_vec2i){-4, -20});
    TEST_ASSERT_EQUAL_INT32(33, point2i.x);
    TEST_ASSERT_EQUAL_INT32(103, point2i.y);
  }
}

void test_point2i_sub_point2i(void) {
  {
    const as_vec2i vec2i =
      as_point2i_sub_point2i((as_point2i){2, 5}, (as_point2i){7, 11});
    TEST_ASSERT_EQUAL_INT32(-5, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(-6, vec2i.y);
  }
  {
    const as_vec2i vec2i =
      as_point2i_sub_point2i((as_point2i){37, 123}, (as_point2i){13, 27});
    TEST_ASSERT_EQUAL_INT32(24, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(96, vec2i.y);
  }
  {
    const as_vec2i vec2i =
      as_point2i_sub_point2i((as_point2i){37, 123}, (as_point2i){-4, -20});
    TEST_ASSERT_EQUAL_INT32(41, vec2i.x);
    TEST_ASSERT_EQUAL_INT32(143, vec2i.y);
  }
}

void test_point2i_distance_point2i(void) {
  {
    const float distance =
      as_point2i_distance_point2i((as_point2i){9, 12}, (as_point2i){142, 213});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 241.0186714f, distance);
  }
  {
    const float distance =
      as_point2i_distance_point2i((as_point2i){15, 10}, (as_point2i){250, 12});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 235.0085104f, distance);
  }
  {
    const float distance =
      as_point2i_distance_point2i((as_point2i){12, 24}, (as_point2i){16, 2});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 22.3606797f, distance);
  }
}

void test_point2i_negate(void) {
  {
    const as_point2i negated =
      as_point2i_negate((as_point2i){.x = 12, .y = 36});
    TEST_ASSERT_EQUAL_INT32(-12, negated.x);
    TEST_ASSERT_EQUAL_INT32(-36, negated.y);
  }
  {
    const as_point2i negated =
      as_point2i_negate((as_point2i){.x = -5, .y = -10});
    TEST_ASSERT_EQUAL_INT32(5, negated.x);
    TEST_ASSERT_EQUAL_INT32(10, negated.y);
  }
}

void test_point3f_from_vec3f(void) {
  {
    const as_point3f point3f =
      as_point3f_from_vec3f((as_vec3f){.x = 3.0f, .y = 2.0f, .z = 11.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, point3f.z);
  }
  {
    const as_point3f point3f =
      as_point3f_from_vec3f((as_vec3f){.x = 9.0f, .y = 1.0f, .z = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, point3f.z);
  }
}

void test_point3f_add_vec3f(void) {
  {
    const as_point3f point3f = as_point3f_add_vec3f(
      (as_point3f){.x = 12.0f, .y = 24.0f, .z = 9.0f},
      (as_vec3f){.x = 24.0f, .y = 12.0f, .z = 27.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 36.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 36.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 36.0f, point3f.z);
  }

  {
    const as_point3f point3f = as_point3f_add_vec3f(
      (as_point3f){.x = -6.0f, .y = -3.0f, .z = 2.0f},
      (as_vec3f){.x = 3.0f, .y = 6.0f, .z = 9.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -3.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, point3f.z);
  }
}

void test_point3f_sub_point3f(void) {
  {
    as_vec3f vec3f = as_point3f_sub_point3f(
      (as_point3f){100.0f, 50.0f, 40.0f}, (as_point3f){25.0f, 32.0f, 11.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 75.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 18.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 29.0f, vec3f.z);
  }
  {
    as_vec3f vec3f = as_point3f_sub_point3f(
      (as_point3f){202.0f, 150.0f, 1000.0f},
      (as_point3f){100.0f, -40.0f, 200.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 102.0f, vec3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 190.0f, vec3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 800.0f, vec3f.z);
  }
}

void test_point3f_rotate_x_axis(void) {
  const float epsilon = 0.0001f;
  {
    const as_point3f point3f = as_point3f_rotate_x_axis(
      (as_point3f){.x = 10.0f, .y = 2.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 10.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 2.0f, point3f.z);
  }
  {
    const as_point3f point3f = as_point3f_rotate_x_axis(
      (as_point3f){.x = 20.0f, .z = 5.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 20.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -5.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.z);
  }
}

void test_point3f_rotate_y_axis(void) {
  const float epsilon = 0.0001f;
  {
    const as_point3f point3f = as_point3f_rotate_y_axis(
      (as_point3f){.y = 50.0f, .x = 10.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 50.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -10.0f, point3f.z);
  }
  {
    const as_point3f point3f = as_point3f_rotate_y_axis(
      (as_point3f){.y = 10.0f, .z = 12.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 12.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 10.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.z);
  }
}

void test_point3f_rotate_z_axis(void) {
  const float epsilon = 0.0001f;
  {
    const as_point3f point3f = as_point3f_rotate_z_axis(
      (as_point3f){.z = 5.0f, .x = 2.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 2.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 5.0f, point3f.z);
  }
  {
    const as_point3f point3f = as_point3f_rotate_z_axis(
      (as_point3f){.z = 16.0f, .y = 4.0f}, as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -4.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 16.0f, point3f.z);
  }
}

void test_point3f_mix(void) {
  {
    const as_point3f begin = (as_point3f){};
    const as_point3f end = as_point3f_from_float(10.0f);
    const as_point3f mixed = as_point3f_mix(begin, end, 0.5f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mixed.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mixed.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mixed.z);
  }
  {
    const as_point3f begin = as_point3f_from_float(10.0f);
    const as_point3f end = as_point3f_from_float(20.0f);
    const as_point3f mixed = as_point3f_mix(begin, end, 0.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mixed.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mixed.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mixed.z);
  }
}

void test_point3f_negate(void) {
  {
    const as_point3f negated =
      as_point3f_negate((as_point3f){.x = 1.5f, .y = 25.2f, .z = 35.1f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.5f, negated.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -25.2f, negated.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -35.1f, negated.z);
  }
  {
    const as_point3f negated =
      as_point3f_negate((as_point3f){.x = -1.0f, .y = -5.0f, .z = 6.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, negated.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, negated.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -6.0f, negated.z);
  }
}

void test_point4f_from_point3f(void) {
  {
    const as_point4f point4f =
      as_point4f_from_point3f((as_point3f){.x = 3.0f, .y = 2.0f, .z = 11.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, point4f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, point4f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, point4f.z);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, point4f.w);
  }
  {
    const as_point4f point4f =
      as_point4f_from_point3f((as_point3f){.x = 9.0f, .y = 1.0f, .z = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, point4f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, point4f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, point4f.z);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, point4f.w);
  }
}

void test_point4f_from_point2f(void) {
  {
    const as_point4f point4f =
      as_point4f_from_point2f((as_point2f){.x = 3.0f, .y = 2.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, point4f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, point4f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, point4f.z);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, point4f.w);
  }
  {
    const as_point4f point4f =
      as_point4f_from_point2f((as_point2f){.x = 9.0f, .y = 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, point4f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, point4f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, point4f.z);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, point4f.w);
  }
}

void test_mat22_rc(void) {
  const int m00 = as_mat22_rc(0, 0);
  const int m01 = as_mat22_rc(0, 1);
  const int m10 = as_mat22_rc(1, 0);
  const int m11 = as_mat22_rc(1, 1);
  TEST_ASSERT_EQUAL_INT32(0, m00);
  TEST_ASSERT_EQUAL_INT32(1, m01);
  TEST_ASSERT_EQUAL_INT32(2, m10);
  TEST_ASSERT_EQUAL_INT32(3, m11);
}

void test_mat22f_identity(void) {
  const as_mat22f mat22f = as_mat22f_identity();
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat22f.elem[0]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[1]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[2]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat22f.elem[3]);
}

void test_mat22f_uniform_scale(void) {
  {
    const as_mat22f mat22f = as_mat22f_uniform_scale(2.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat22f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat22f.elem[3]);
  }
  {
    const as_mat22f mat22f = as_mat22f_uniform_scale(10.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mat22f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mat22f.elem[3]);
  }
}

void test_mat22f_scale_from_floats(void) {
  {
    const as_mat22f mat22f = as_mat22f_scale_from_floats(2.0f, 4.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat22f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, mat22f.elem[3]);
  }
  {
    const as_mat22f mat22f = as_mat22f_scale_from_floats(11.0f, 12.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, mat22f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, mat22f.elem[3]);
  }
}

void test_mat22f_scale_from_vec2f(void) {
  {
    const as_mat22f mat22f = as_mat22f_scale_from_vec2f((as_vec2f){2.0f, 4.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat22f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, mat22f.elem[3]);
  }
  {
    const as_mat22f mat22f =
      as_mat22f_scale_from_vec2f((as_vec2f){11.0f, 12.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, mat22f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, mat22f.elem[3]);
  }
}

void test_mat22f_rotation(void) {
  {
    const as_mat22f mat22f = as_mat22f_rotation(as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.0f, mat22f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat22f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[3]);
  }
  {
    const as_mat22f mat22f = as_mat22f_rotation(-as_k_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.0f, mat22f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat22f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -1.0f, mat22f.elem[3]);
  }
}

void test_mat22f_mul_point2f(void) {
  const float epsilon = 0.0001f;
  {
    const as_mat22f mat22f = as_mat22f_rotation(as_k_half_pi);
    const as_point2f point2f =
      as_mat22f_mul_point2f(&mat22f, (as_point2f){2.0f, 2.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -2.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 2.0f, point2f.y);
  }
  {
    const as_mat22f mat22f = as_mat22f_rotation(as_k_pi);
    const as_point2f point2f =
      as_mat22f_mul_point2f(&mat22f, (as_point2f){5.0f, 0.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -5.0f, point2f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point2f.y);
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

void test_mat33_rc(void) {
  const int m00 = as_mat33_rc(0, 0);
  const int m01 = as_mat33_rc(0, 1);
  const int m02 = as_mat33_rc(0, 2);
  const int m10 = as_mat33_rc(1, 0);
  const int m11 = as_mat33_rc(1, 1);
  const int m12 = as_mat33_rc(1, 2);
  const int m20 = as_mat33_rc(2, 0);
  const int m21 = as_mat33_rc(2, 1);
  const int m22 = as_mat33_rc(2, 2);
  TEST_ASSERT_EQUAL_INT32(0, m00);
  TEST_ASSERT_EQUAL_INT32(1, m01);
  TEST_ASSERT_EQUAL_INT32(2, m02);
  TEST_ASSERT_EQUAL_INT32(3, m10);
  TEST_ASSERT_EQUAL_INT32(4, m11);
  TEST_ASSERT_EQUAL_INT32(5, m12);
  TEST_ASSERT_EQUAL_INT32(6, m20);
  TEST_ASSERT_EQUAL_INT32(7, m21);
  TEST_ASSERT_EQUAL_INT32(8, m22);
}

void test_mat33f_identity(void) {
  const as_mat33f mat33f = as_mat33f_identity();
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat33f.elem[0]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[1]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[2]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[3]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat33f.elem[4]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[5]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[6]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[7]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat33f.elem[8]);
}

void test_mat33f_uniform_scale(void) {
  {
    const as_mat33f mat33f = as_mat33f_uniform_scale(2.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat33f.elem[8]);
  }
  {
    const as_mat33f mat33f = as_mat33f_uniform_scale(10.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mat33f.elem[8]);
  }
}

void test_mat33f_scale_from_floats(void) {
  {
    const as_mat33f mat33f = as_mat33f_scale_from_floats(1.0f, 2.0f, 3.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, mat33f.elem[8]);
  }
  {
    const as_mat33f mat33f = as_mat33f_scale_from_floats(15.0f, 30.0f, 45.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 15.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 30.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 45.0f, mat33f.elem[8]);
  }
}

void test_mat33f_scale_from_vec3f(void) {
  {
    const as_mat33f mat33f =
      as_mat33f_scale_from_vec3f((as_vec3f){.x = 1.0f, .y = 2.0f, .z = 3.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, mat33f.elem[8]);
  }

  {
    const as_mat33f mat33f =
      as_mat33f_scale_from_vec3f((as_vec3f){.x = 2.0f, .y = 4.0f, .z = 8.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, mat33f.elem[8]);
  }
}

void test_mat33f_from_mat34f(void) {
  {
    // clang-format off
    const as_mat33f mat33f = as_mat33f_from_mat34f(
      &(as_mat34f){ .elem = {
        1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 10.0f, 11.0f, 12.0f}});
    // clang-format on
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 6.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 7.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, mat33f.elem[8]);
  }
  {
    // clang-format off
    const as_mat33f mat33f = as_mat33f_from_mat34f(
      &(as_mat34f){ .elem = {
        23.0f, 14.0f, 97.0f, 11.0f,
        16.0f, 22.0f, 14.0f, 64.0f,
        75.0f, 27.0f, 18.0f, 33.0f}});
    // clang-format on
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 23.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 14.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 97.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 16.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 22.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 14.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 75.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 27.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 18.0f, mat33f.elem[8]);
  }
}

void test_mat33f_transpose(void) {
  {
    // clang-format off
    const as_mat33f mat33f = as_mat33f_transpose(
      &(as_mat33f){.elem = {
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f}});
    // clang-format on
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 7.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 6.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, mat33f.elem[8]);
  }
  {
    // clang-format off
    const as_mat33f mat33f = as_mat33f_transpose(
      &(as_mat33f){.elem = {
        11.0f, 22.0f, 33.0f,
        44.0f, 55.0f, 66.0f,
        77.0f, 88.0f, 99.0f}});
    // clang-format on
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 44.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 77.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 22.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 55.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 88.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 33.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 66.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 99.0f, mat33f.elem[8]);
  }
}

void test_mat33f_x_axis_rotation(void) {
  const float epsilon = 0.0001f;
  {
    const as_mat33f mat33f = as_mat33f_x_axis_rotation(as_k_half_pi);
    const as_point3f point3f =
      as_mat33f_mul_point3f(&mat33f, (as_point3f){.x = 10.0f, .y = 2.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 10.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 2.0f, point3f.z);
  }
  {
    const as_mat33f mat33f = as_mat33f_x_axis_rotation(as_k_half_pi);
    const as_point3f point3f =
      as_mat33f_mul_point3f(&mat33f, (as_point3f){.x = 20.0f, .z = 5.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 20.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -5.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.z);
  }
}

void test_mat33f_y_axis_rotation(void) {
  const float epsilon = 0.0001f;
  {
    const as_mat33f mat33f = as_mat33f_y_axis_rotation(as_k_half_pi);
    const as_point3f point3f =
      as_mat33f_mul_point3f(&mat33f, (as_point3f){.y = 50.0f, .x = 10.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 50.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -10.0f, point3f.z);
  }
  {
    const as_mat33f mat33f = as_mat33f_y_axis_rotation(as_k_half_pi);
    const as_point3f point3f =
      as_mat33f_mul_point3f(&mat33f, (as_point3f){.y = 10.0f, .z = 12.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 12.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 10.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.z);
  }
}

void test_mat33f_z_axis_rotation(void) {
  const float epsilon = 0.0001f;
  {
    const as_mat33f mat33f = as_mat33f_z_axis_rotation(as_k_half_pi);
    const as_point3f point3f =
      as_mat33f_mul_point3f(&mat33f, (as_point3f){.z = 5.0f, .x = 2.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 2.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 5.0f, point3f.z);
  }
  {
    const as_mat33f mat33f = as_mat33f_z_axis_rotation(as_k_half_pi);
    const as_point3f point3f =
      as_mat33f_mul_point3f(&mat33f, (as_point3f){.z = 16.0f, .y = 4.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -4.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 16.0f, point3f.z);
  }
}

void test_mat33f_mul_point3f(void) {
  const float epsilon = 0.0001f;
  {
    const as_mat33f mat33f = as_mat33f_scale_from_floats(10.0f, 5.0f, 2.0f);
    const as_point3f point3f = as_mat33f_mul_point3f(
      &mat33f, (as_point3f){.x = 2.0f, .y = 4.0f, .z = 8.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 20.0f, point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 20.0f, point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 16.0f, point3f.z);
  }
}

void test_mat33f_mul_mat33f(void) {
  {
    const as_mat33f mat33f = as_mat33f_mul_mat33f(
      &(as_mat33f){
        .elem = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f}},
      &(as_mat33f){
        .elem = {
          2.0f, 4.0f, 8.0f, 16.0f, 32.0f, 64.0f, 128.0f, 256.0f, 512.0f}});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 418.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 836.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1672.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 856.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1712.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3424.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1294.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2588.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5176.0f, mat33f.elem[8]);
  }
  {
    const as_mat33f mat33f = as_mat33f_mul_mat33f(
      &(as_mat33f){
        .elem = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f}},
      &(as_mat33f){
        .elem = {2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f}});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 36.0f, mat33f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 42.0f, mat33f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 48.0f, mat33f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 81.0f, mat33f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 96.0f, mat33f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 111.0f, mat33f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 126.0f, mat33f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 150.0f, mat33f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 174.0f, mat33f.elem[8]);
  }
}

void test_mat33f_mul_mat34f(void) {
  const float epsilon = 0.0001f;
  {
    const as_mat33f mat33f = as_mat33f_z_axis_rotation(as_k_half_pi);
    const as_mat34f mat34f =
      as_mat34f_translation_from_vec3f((as_vec3f){.x = 10.0f});
    const as_mat34f result = as_mat33f_mul_mat34f(&mat33f, &mat34f);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -1.0f, result.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 1.0f, result.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 10.0f, result.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 1.0f, result.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[11]);
  }
  {
    const as_mat33f mat33f = as_mat33f_z_axis_rotation(as_k_half_pi);
    const as_mat33f opp_mat33f = as_mat33f_z_axis_rotation(-as_k_half_pi);
    const as_mat34f mat34f =
      as_mat34f_from_mat33f_and_vec3f(&opp_mat33f, (as_vec3f){.x = 10.0f});
    const as_mat34f result = as_mat33f_mul_mat34f(&mat33f, &mat34f);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 1.0f, result.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 1.0f, result.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 10.0f, result.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 1.0f, result.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.elem[11]);
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

void test_mat34_rc(void) {
  const int m00 = as_mat34_rc(0, 0);
  const int m01 = as_mat34_rc(0, 1);
  const int m02 = as_mat34_rc(0, 2);
  const int m03 = as_mat34_rc(0, 3);
  const int m10 = as_mat34_rc(1, 0);
  const int m11 = as_mat34_rc(1, 1);
  const int m12 = as_mat34_rc(1, 2);
  const int m13 = as_mat34_rc(1, 3);
  const int m20 = as_mat34_rc(2, 0);
  const int m21 = as_mat34_rc(2, 1);
  const int m22 = as_mat34_rc(2, 2);
  const int m23 = as_mat34_rc(2, 3);
  TEST_ASSERT_EQUAL_INT32(0, m00);
  TEST_ASSERT_EQUAL_INT32(1, m01);
  TEST_ASSERT_EQUAL_INT32(2, m02);
  TEST_ASSERT_EQUAL_INT32(3, m03);
  TEST_ASSERT_EQUAL_INT32(4, m10);
  TEST_ASSERT_EQUAL_INT32(5, m11);
  TEST_ASSERT_EQUAL_INT32(6, m12);
  TEST_ASSERT_EQUAL_INT32(7, m13);
  TEST_ASSERT_EQUAL_INT32(8, m20);
  TEST_ASSERT_EQUAL_INT32(9, m21);
  TEST_ASSERT_EQUAL_INT32(10, m22);
  TEST_ASSERT_EQUAL_INT32(11, m23);
}

void test_mat34f_identity(void) {
  const as_mat34f mat34f = as_mat34f_identity();
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[0]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[1]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[2]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[3]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[4]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[5]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[6]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[7]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[8]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[9]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[10]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[11]);
}

void test_mat34f_translation_from_floats(void) {
  {
    const as_mat34f mat34f =
      as_mat34f_translation_from_floats(1.0f, 2.0f, 3.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat34f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, mat34f.elem[11]);
  }
  {
    const as_mat34f mat34f =
      as_mat34f_translation_from_floats(2.0f, 4.0f, 8.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat34f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, mat34f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, mat34f.elem[11]);
  }
}

void test_mat34f_translation_from_vec3f(void) {
  {
    const as_mat34f mat34f =
      as_mat34f_translation_from_vec3f((as_vec3f){1.0f, 2.0f, 3.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat34f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, mat34f.elem[11]);
  }
  {
    const as_mat34f mat34f =
      as_mat34f_translation_from_vec3f((as_vec3f){2.0f, 4.0f, 8.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat34f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, mat34f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, mat34f.elem[11]);
  }
}

void test_mat34f_translation_from_point3f(void) {
  {
    const as_mat34f mat34f =
      as_mat34f_translation_from_point3f((as_point3f){10.0f, 20.0f, 30.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mat34f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 20.0f, mat34f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 30.0f, mat34f.elem[11]);
  }
  {
    const as_mat34f mat34f =
      as_mat34f_translation_from_point3f((as_point3f){11.0f, 22.0f, 33.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, mat34f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 22.0f, mat34f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat34f.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat34f.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 33.0f, mat34f.elem[11]);
  }
}

void test_mat34f_from_mat33f_and_vec3f(void) {
  const as_mat34f mat34f = as_mat34f_from_mat33f_and_vec3f(
    &(as_mat33f){
      .elem = {2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f, 18.0f}},
    (as_vec3f){123.0f, 456.0f, 789.0f});
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat34f.elem[0]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, mat34f.elem[1]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 6.0f, mat34f.elem[2]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 123.0f, mat34f.elem[3]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, mat34f.elem[4]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mat34f.elem[5]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, mat34f.elem[6]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 456.0f, mat34f.elem[7]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 14.0f, mat34f.elem[8]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 16.0f, mat34f.elem[9]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 18.0f, mat34f.elem[10]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 789.0f, mat34f.elem[11]);
}

void test_mat34f_mul_point3f(void) {
  const float epsilon = 0.0001f;
  {
    const as_mat33f mat33f = as_mat33f_z_axis_rotation(as_k_half_pi);
    const as_mat34f mat34f =
      as_mat34f_from_mat33f_and_vec3f(&mat33f, (as_vec3f){.x = 10.0f});
    const as_point3f result =
      as_mat34f_mul_point3f(&mat34f, (as_point3f){.y = 50.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -40.0f, result.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.z);
  }
  {
    const as_mat33f mat33f = as_mat33f_y_axis_rotation(-as_k_half_pi);
    const as_mat34f mat34f =
      as_mat34f_from_mat33f_and_vec3f(&mat33f, (as_vec3f){.x = 2.0f});
    const as_point3f result =
      as_mat34f_mul_point3f(&mat34f, (as_point3f){.z = -5.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 7.0f, result.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.z);
  }
  {
    const as_mat33f mat33f = as_mat33f_x_axis_rotation(as_k_pi);
    const as_mat34f mat34f =
      as_mat34f_from_mat33f_and_vec3f(&mat33f, (as_vec3f){.z = -2.0f});
    const as_point3f result =
      as_mat34f_mul_point3f(&mat34f, (as_point3f){.y = 10.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -10.0f, result.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -2.0f, result.z);
  }
}

void test_mat34f_mul_vec3f(void) {
  const float epsilon = 0.0001f;
  {
    const as_mat33f mat33f = as_mat33f_z_axis_rotation(as_k_half_pi);
    const as_mat34f mat34f =
      as_mat34f_from_mat33f_and_vec3f(&mat33f, (as_vec3f){.x = 10.0f});
    const as_vec3f result =
      as_mat34f_mul_vec3f(&mat34f, (as_vec3f){.y = 50.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -50.0f, result.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.z);
  }
  {
    const as_mat33f mat33f = as_mat33f_y_axis_rotation(-as_k_half_pi);
    const as_mat34f mat34f =
      as_mat34f_from_mat33f_and_vec3f(&mat33f, (as_vec3f){.x = 2.0f});
    const as_vec3f result =
      as_mat34f_mul_vec3f(&mat34f, (as_vec3f){.z = -5.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 5.0f, result.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.z);
  }
  {
    const as_mat33f mat33f = as_mat33f_x_axis_rotation(as_k_pi);
    const as_mat34f mat34f =
      as_mat34f_from_mat33f_and_vec3f(&mat33f, (as_vec3f){.z = -2.0f});
    const as_vec3f result =
      as_mat34f_mul_vec3f(&mat34f, (as_vec3f){.y = 10.0f});
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.x);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -10.0f, result.y);
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 0.0f, result.z);
  }
}

void test_mat34f_mul_mat34f(void) {
  {
    // clang-format off
    const as_mat34f lhs = (as_mat34f) { .elem = {
      1.0f, 2.0f, 3.0f, 4.0f,
      5.0f, 6.0f, 7.0f, 8.0f,
      9.0f, 10.0f, 11.0f, 12.0f}};
    const as_mat34f rhs = (as_mat34f) { .elem = {
      2.0f, 4.0f, 6.0f, 8.0f,
      10.0f, 12.0f, 14.0f, 16.0f,
      18.0f, 20.0f, 22.0f, 24.0f}};
    // clang-format on
    const as_mat34f result = as_mat34f_mul_mat34f(&lhs, &rhs);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 76.0f, result.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 88.0f, result.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 100.0f, result.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 116.0f, result.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 196.0f, result.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 232.0f, result.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 268.0f, result.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 312.0f, result.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 316.0f, result.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 376.0f, result.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 436.0f, result.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 508.0f, result.elem[11]);
  }
  {
    // clang-format off
    const as_mat34f lhs = (as_mat34f) { .elem = {
      1.0f, 0.0f, 0.0f, 4.0f,
      0.0f, 1.0f, 0.0f, 20.0f,
      0.0f, 0.0f, 1.0f, 44.0f}};
    const as_mat34f rhs = (as_mat34f) { .elem = {
      1.0f, 0.0f, 0.0f, 6.0f,
      0.0f, 1.0f, 0.0f, 32.0f,
      0.0f, 0.0f, 1.0f, 24.0f}};
    // clang-format on
    const as_mat34f result = as_mat34f_mul_mat34f(&lhs, &rhs);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, result.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, result.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, result.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 52.0f, result.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, result.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 68.0f, result.elem[11]);
  }
}

void test_mat34f_mul_mat33f(void) {
  {
    // clang-format off
    const as_mat34f lhs = (as_mat34f) { .elem = {
      1.0f, 2.0f, 3.0f, 4.0f,
      5.0f, 6.0f, 7.0f, 8.0f,
      9.0f, 10.0f, 11.0f, 12.0f}};
    const as_mat33f rhs = (as_mat33f) { .elem = {
      2.0f, 4.0f, 6.0f,
      10.0f, 12.0f, 14.0f,
      18.0f, 20.0f, 22.0f}};
    // clang-format on
    const as_mat34f result = as_mat34f_mul_mat33f(&lhs, &rhs);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 76.0f, result.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 88.0f, result.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 100.0f, result.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, result.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 196.0f, result.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 232.0f, result.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 268.0f, result.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, result.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 316.0f, result.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 376.0f, result.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 436.0f, result.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, result.elem[11]);
  }
  {
    // clang-format off
    const as_mat34f lhs = (as_mat34f) { .elem = {
      5.0f, 7.0f, 2.0f, 3.0f,
      4.0f, 8.0f, 1.0f, 9.0f,
      12.0f, 6.0f, 10.0f, 2.0f}};
    const as_mat33f rhs = (as_mat33f) { .elem = {
      4.0f, 1.0f, 9.0f,
      2.0f, 8.0f, 7.0f,
      6.0f, 3.0f, 5.0f}};
    // clang-format on
    const as_mat34f result = as_mat34f_mul_mat33f(&lhs, &rhs);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 46.0f, result.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 67.0f, result.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 104.0f, result.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, result.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 38.0f, result.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 71.0f, result.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 97.0f, result.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, result.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 120.0f, result.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 90.0f, result.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 200.0f, result.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, result.elem[11]);
  }
}

void test_mat34f_inverse(void) {
  // ensure inverse restores original point (scale)
  {
    const as_mat33f scale = as_mat33f_scale_from_floats(2.0f, 4.0f, 8.0f);
    const as_mat34f scale_and_translation = as_mat34f_from_mat33f_and_vec3f(
      &scale, (as_vec3f){.x = 1.0f, .y = 1.0f, .z = 1.0f});
    const as_point3f transformed_point3f = as_mat34f_mul_point3f(
      &scale_and_translation, (as_point3f){.x = 5.0f, .y = 5.0f, .z = 5.0f});
    const as_mat34f scale_and_translation_inv =
      as_mat34f_inverse(&scale_and_translation);
    const as_point3f inverse_point3f =
      as_mat34f_mul_point3f(&scale_and_translation_inv, transformed_point3f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, inverse_point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, inverse_point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, inverse_point3f.z);
  }
  // ensure inverse restores original point (rotation)
  {
    const as_mat33f rotation = as_mat33f_x_axis_rotation(as_k_half_pi);
    const as_mat34f rotation_and_translation = as_mat34f_from_mat33f_and_vec3f(
      &rotation, (as_vec3f){.x = 1.0f, .y = 1.0f, .z = 1.0f});
    const as_point3f transformed_point3f = as_mat34f_mul_point3f(
      &rotation_and_translation,
      (as_point3f){.x = 15.0f, .y = 30.0f, .z = 45.0f});
    const as_mat34f scale_and_translation_inv =
      as_mat34f_inverse(&rotation_and_translation);
    const as_point3f inverse_point3f =
      as_mat34f_mul_point3f(&scale_and_translation_inv, transformed_point3f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 15.0f, inverse_point3f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 30.0f, inverse_point3f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 45.0f, inverse_point3f.z);
  }
}

void test_mat44_rc(void) {
  const int m00 = as_mat34_rc(0, 0);
  const int m01 = as_mat34_rc(0, 1);
  const int m02 = as_mat34_rc(0, 2);
  const int m03 = as_mat34_rc(0, 3);
  const int m10 = as_mat34_rc(1, 0);
  const int m11 = as_mat34_rc(1, 1);
  const int m12 = as_mat34_rc(1, 2);
  const int m13 = as_mat34_rc(1, 3);
  const int m20 = as_mat34_rc(2, 0);
  const int m21 = as_mat34_rc(2, 1);
  const int m22 = as_mat34_rc(2, 2);
  const int m23 = as_mat34_rc(2, 3);
  const int m30 = as_mat34_rc(3, 0);
  const int m31 = as_mat34_rc(3, 1);
  const int m32 = as_mat34_rc(3, 2);
  const int m33 = as_mat34_rc(3, 3);
  TEST_ASSERT_EQUAL_INT32(0, m00);
  TEST_ASSERT_EQUAL_INT32(1, m01);
  TEST_ASSERT_EQUAL_INT32(2, m02);
  TEST_ASSERT_EQUAL_INT32(3, m03);
  TEST_ASSERT_EQUAL_INT32(4, m10);
  TEST_ASSERT_EQUAL_INT32(5, m11);
  TEST_ASSERT_EQUAL_INT32(6, m12);
  TEST_ASSERT_EQUAL_INT32(7, m13);
  TEST_ASSERT_EQUAL_INT32(8, m20);
  TEST_ASSERT_EQUAL_INT32(9, m21);
  TEST_ASSERT_EQUAL_INT32(10, m22);
  TEST_ASSERT_EQUAL_INT32(11, m23);
  TEST_ASSERT_EQUAL_INT32(12, m30);
  TEST_ASSERT_EQUAL_INT32(13, m31);
  TEST_ASSERT_EQUAL_INT32(14, m32);
  TEST_ASSERT_EQUAL_INT32(15, m33);
}

void test_mat44f_identity(void) {
  const as_mat44f mat44f = as_mat44f_identity();
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[0]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[1]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[2]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[3]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[4]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[5]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[6]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[7]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[8]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[9]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[10]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[11]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[12]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[13]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[14]);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[15]);
}

void test_mat44f_translation_from_floats(void) {
  {
    const as_mat44f mat44f =
      as_mat44f_translation_from_floats(2.0f, 3.0f, 4.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat44f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, mat44f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, mat44f.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[15]);
  }
}

void test_mat44f_translation_from_vec3f(void) {
  {
    const as_mat44f mat44f =
      as_mat44f_translation_from_vec3f((as_vec3f){10.0f, 20.0f, 30.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, mat44f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 20.0f, mat44f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 30.0f, mat44f.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[15]);
  }
}

void test_mat44f_translation_from_point3f(void) {
  {
    const as_mat44f mat44f =
      as_mat44f_translation_from_point3f((as_point3f){99.0f, 98.0f, 97.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 99.0f, mat44f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 98.0f, mat44f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 97.0f, mat44f.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[15]);
  }
}

void test_mat44f_from_mat33f_and_vec3f(void) {
  {
    const as_mat33f mat33f = (as_mat33f){
      .elem = {4.0f, 1.0f, 9.0f, 2.0f, 8.0f, 7.0f, 6.0f, 3.0f, 5.0f}};
    const as_mat44f mat44f =
      as_mat44f_from_mat33f_and_vec3f(&mat33f, (as_vec3f){22.0f, 33.0f, 97.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, mat44f.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, mat44f.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 22.0f, mat44f.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, mat44f.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, mat44f.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 7.0f, mat44f.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 33.0f, mat44f.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 6.0f, mat44f.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, mat44f.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, mat44f.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 97.0f, mat44f.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, mat44f.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, mat44f.elem[15]);
  }
}

void test_mat44f_transpose(void) {
  {
    // clang-format off
    const as_mat44f mat44f = (as_mat44f) { .elem = {
      1.0f, 2.0f, 3.0f, 4.0f,
      5.0f, 6.0f, 7.0f, 8.0f,
      9.0f, 10.0f, 11.0f, 12.0f,
      13.0f, 14.0f, 15.0f, 16.0f
    }};
    // clang-format on
    const as_mat44f transpose = as_mat44f_transpose(&mat44f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, transpose.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, transpose.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f, transpose.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 13.0f, transpose.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, transpose.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 6.0f, transpose.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, transpose.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 14.0f, transpose.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, transpose.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 7.0f, transpose.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, transpose.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 15.0f, transpose.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4.0f, transpose.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8.0f, transpose.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, transpose.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 16.0f, transpose.elem[15]);
  }
  {
    // clang-format off
    const as_mat44f mat44f = (as_mat44f) { .elem = {
      11.0f, 22.0f, 33.0f, 44.0f,
      55.0f, 66.0f, 77.0f, 88.0f,
      99.0f, 100.0f, 110.0f, 120.0f,
      130.0f, 140.0f, 150.0f, 160.0f
    }};
    // clang-format on
    const as_mat44f transpose = as_mat44f_transpose(&mat44f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11.0f, transpose.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 55.0f, transpose.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 99.0f, transpose.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 130.0f, transpose.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 22.0f, transpose.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 66.0f, transpose.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 100.0f, transpose.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 140.0f, transpose.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 33.0f, transpose.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 77.0f, transpose.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 110.0f, transpose.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 150.0f, transpose.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 44.0f, transpose.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 88.0f, transpose.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 120.0f, transpose.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 160.0f, transpose.elem[15]);
  }
}

void test_mat44f_mul_mat44f(void) {
  {
    // clang-format off
    const as_mat44f lhs = (as_mat44f){.elem = {
      1.0f, 2.0f, 3.0f, 4.0f,
      5.0f, 6.0f, 7.0f, 8.0f,
      9.0f, 10.0f, 11.0f, 12.0f,
      13.0f, 14.0f, 15.0f, 16.0f
    }};
    const as_mat44f rhs = (as_mat44f){.elem = {
      16.0f, 15.0f, 14.0f, 13.0f,
      12.0f, 11.0f, 10.0f, 9.0f,
      8.0f, 7.0f, 6.0f, 5.0f,
      4.0f, 3.0f, 2.0f, 1.0f
    }};
    // clang-format on
    const as_mat44f result = as_mat44f_mul_mat44f(&lhs, &rhs);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 80.0f, result.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 70.0f, result.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 60.0f, result.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 50.0f, result.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 240.0f, result.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 214.0f, result.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 188.0f, result.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 162.0f, result.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 400.0f, result.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 358.0f, result.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 316.0f, result.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 274.0f, result.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 560.0f, result.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 502.0f, result.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 444.0f, result.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 386.0f, result.elem[15]);
  }
  {
    // clang-format off
    const as_mat44f lhs = (as_mat44f){.elem = {
      6.0f, 1.0f, 8.0f, 2.0f,
      7.0f, 9.0f, 4.0f, 3.0f,
      5.0f, 14.0f, 20.0f, 17.0f,
      21.0f, 33.0f, 97.0f, 42.0f
    }};
    const as_mat44f rhs = (as_mat44f){.elem = {
      3.0f, 2.0f, 1.0f, 4.0f,
      36.0f, 88.0f, 34.0f, 8.0f,
      64.0f, 72.0f, 12.0f, 91.0f,
      22.0f, 35.0f, 42.0f, 18.0f
    }};
    // clang-format on
    const as_mat44f result = as_mat44f_mul_mat44f(&lhs, &rhs);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 610.0f, result.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 746.0f, result.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 220.0f, result.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 796.0f, result.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 667.0f, result.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1199.0f, result.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 487.0f, result.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 518.0f, result.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2173.0f, result.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3277.0f, result.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1435.0f, result.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2258.0f, result.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 8383.0f, result.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 11400.0f, result.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 4071.0f, result.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9931.0f, result.elem[15]);
  }
}

void test_mat44f_perspective_projection_lh(void) {
  {
    const float fov = as_k_half_pi;
    const float aspect = 16.0f / 9.0f;
    const as_mat44f result =
      as_mat44f_perspective_projection_lh(aspect, fov, 0.01f, 1000.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.562500f, result.elem[0]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[1]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[2]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[3]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[4]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, result.elem[5]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[6]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[7]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[8]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[9]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.000010f, result.elem[10]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -0.01f, result.elem[11]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[12]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[13]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, result.elem[14]);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 0.0f, result.elem[15]);
  }
}

void test_mat44f_mul_point4f(void) {
  {
    const as_mat44f translation =
      as_mat44f_translation_from_floats(20.0f, 40.0f, 60.0f);
    const as_point4f point4f = as_mat44f_mul_point4f(
      &translation, (as_point4f){5.0f, 10.0f, 15.0f, 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 25.0f, point4f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 50.0f, point4f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 75.0f, point4f.z);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, point4f.w);
  }
  {
    const float fov = as_k_half_pi;
    const float aspect = 16.0f / 9.0f;
    const as_mat44f projection =
      as_mat44f_perspective_projection_lh(aspect, fov, 0.01f, 1000.0f);
    const as_point4f point4f = as_mat44f_mul_point4f(
      &projection, (as_point4f){67.0f, 12.0f, 34.0f, 1.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 37.6875f, point4f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, point4f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 33.99034f, point4f.z);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 34.0f, point4f.w);
  }
}

void test_mat44f_project_point3f(void) {
  {
    const float fov = as_k_half_pi;
    const float aspect = 16.0f / 9.0f;
    const as_mat44f projection =
      as_mat44f_perspective_projection_lh(aspect, fov, 0.01f, 1000.0f);
    const as_point4f point4f =
      as_mat44f_project_point3f(&projection, (as_point3f){16.0f, 17.0f, 18.0f});
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 9.0f / 18.0f, point4f.x);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 17.0 / 18.0f, point4f.y);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 17.99018f / 18.0f, point4f.z);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 18.0f, point4f.w);
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

void test_swap_float(void) {
  {
    float a = 3.0f;
    float b = 5.0f;
    as_swap_float(&a, &b);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, a);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 3.0f, b);
  }
  {
    float a = 12.0f;
    float b = 25.0f;
    as_swap_float(&a, &b);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 25.0f, a);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 12.0f, b);
  }
}

void test_swap_int(void) {
  {
    int a = 7;
    int b = 2;
    as_swap_int(&a, &b);
    TEST_ASSERT_EQUAL_INT32(2, a);
    TEST_ASSERT_EQUAL_INT32(7, b);
  }
  {
    int a = 15;
    int b = 30;
    as_swap_int(&a, &b);
    TEST_ASSERT_EQUAL_INT32(30, a);
    TEST_ASSERT_EQUAL_INT32(15, b);
  }
}

void test_clamp_float(void) {
  {
    const float clamped = as_clamp_float(2.0f, 5.0f, 10.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 5.0f, clamped);
  }
  {
    const float clamped = as_clamp_float(30.0f, 10.0f, 20.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 20.0f, clamped);
  }
  {
    const float clamped = as_clamp_float(18.0f, 15.0f, 20.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 18.0f, clamped);
  }
}

void test_clamp_int(void) {
  {
    const int clamped = as_clamp_int(2, 5, 10);
    TEST_ASSERT_EQUAL_INT32(5, clamped);
  }
  {
    const int clamped = as_clamp_int(30, 10, 20);
    TEST_ASSERT_EQUAL_INT32(20, clamped);
  }
  {
    const int clamped = as_clamp_int(18, 15, 20);
    TEST_ASSERT_EQUAL_INT32(18, clamped);
  }
}

void test_max_float(void) {
  {
    const float max = as_max_float(5.0f, 10.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, max);
  }
  {
    const float max = as_max_float(25.0f, 8.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 25.0f, max);
  }
}

void test_max_int(void) {
  {
    const int max = as_max_int(5, 10);
    TEST_ASSERT_EQUAL_INT32(10, max);
  }
  {
    const int max = as_max_int(25.0f, 8.0f);
    TEST_ASSERT_EQUAL_INT32(25, max);
  }
}

void test_min_float(void) {
  {
    const float min = as_min_float(2.0f, 21.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, min);
  }
  {
    const float min = as_min_float(36.0f, 14.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 14.0f, min);
  }
}

void test_min_int(void) {
  {
    const int min = as_min_int(57, 63);
    TEST_ASSERT_EQUAL_INT32(57, min);
  }
  {
    const int min = as_min_int(102.0f, 45.0f);
    TEST_ASSERT_EQUAL_INT32(45, min);
  }
}

void test_radians_from_degrees(void) {
  {
    const float radians = as_radians_from_degrees(45.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, as_k_half_pi * 0.5f, radians);
  }
  {
    const float radians = as_radians_from_degrees(90.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, as_k_half_pi, radians);
  }
  {
    const float radians = as_radians_from_degrees(180.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, as_k_pi, radians);
  }
  {
    const float radians = as_radians_from_degrees(-360.0f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -as_k_two_pi, radians);
  }
}

void test_degrees_from_radians(void) {
  {
    const float degrees = as_degrees_from_radians(as_k_half_pi * 0.5f);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 45.0f, degrees);
  }
  {
    const float degrees = as_degrees_from_radians(as_k_half_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 90.0f, degrees);
  }
  {
    const float degrees = as_degrees_from_radians(as_k_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 180.0f, degrees);
  }
  {
    const float degrees = as_degrees_from_radians(-as_k_two_pi);
    TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, -360.0f, degrees);
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
  RUN_TEST(test_vec2f_normalize);
  RUN_TEST(test_vec2f_mix);
  RUN_TEST(test_vec2f_negate);
  RUN_TEST(test_vec2i_from_vec2f);
  RUN_TEST(test_vec2i_from_int);
  RUN_TEST(test_vec2i_add_vec2i);
  RUN_TEST(test_vec2i_sub_vec2i);
  RUN_TEST(test_vec2i_mul_float);
  RUN_TEST(test_vec2i_div_float);
  RUN_TEST(test_vec2i_length);
  RUN_TEST(test_vec2i_length_sq);
  RUN_TEST(test_vec2i_negate);
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
  RUN_TEST(test_vec3f_normalize);
  RUN_TEST(test_vec3f_axes);
  RUN_TEST(test_vec3f_mix);
  RUN_TEST(test_vec3f_negate);
  RUN_TEST(test_vec3i_from_vec3f);
  RUN_TEST(test_vec3i_add_vec3i);
  RUN_TEST(test_vec3i_sub_vec3i);
  RUN_TEST(test_vec3i_mul_float);
  RUN_TEST(test_vec3i_div_float);
  RUN_TEST(test_vec3i_length);
  RUN_TEST(test_vec3i_negate);
  RUN_TEST(test_point2f_from_vec2f);
  RUN_TEST(test_point2f_from_point4f);
  RUN_TEST(test_point2f_from_point2i);
  RUN_TEST(test_point2f_from_float);
  RUN_TEST(test_point2f_add_vec2f);
  RUN_TEST(test_point2f_sub_point2f);
  RUN_TEST(test_point2f_negate);
  RUN_TEST(test_point2f_distance_point2f);
  RUN_TEST(test_point2i_from_point2f);
  RUN_TEST(test_point2i_from_vec2i);
  RUN_TEST(test_point2i_from_int);
  RUN_TEST(test_point2i_add_vec2i);
  RUN_TEST(test_point2i_sub_point2i);
  RUN_TEST(test_point2i_distance_point2i);
  RUN_TEST(test_point2i_negate);
  RUN_TEST(test_point3f_from_vec3f);
  RUN_TEST(test_point3f_add_vec3f);
  RUN_TEST(test_point3f_sub_point3f);
  RUN_TEST(test_point3f_rotate_x_axis);
  RUN_TEST(test_point3f_rotate_y_axis);
  RUN_TEST(test_point3f_rotate_z_axis);
  RUN_TEST(test_point3f_mix);
  RUN_TEST(test_point3f_negate);
  RUN_TEST(test_point4f_from_point3f);
  RUN_TEST(test_point4f_from_point2f);
  RUN_TEST(test_mat22_rc);
  RUN_TEST(test_mat22f_identity);
  RUN_TEST(test_mat22f_uniform_scale);
  RUN_TEST(test_mat22f_scale_from_floats);
  RUN_TEST(test_mat22f_scale_from_vec2f);
  RUN_TEST(test_mat22f_rotation);
  RUN_TEST(test_mat22f_mul_point2f);
  RUN_TEST(test_mat22f_determinant);
  RUN_TEST(test_mat22f_inverse);
  RUN_TEST(test_mat33_rc);
  RUN_TEST(test_mat33f_identity);
  RUN_TEST(test_mat33f_uniform_scale);
  RUN_TEST(test_mat33f_scale_from_floats);
  RUN_TEST(test_mat33f_scale_from_vec3f);
  RUN_TEST(test_mat33f_from_mat34f);
  RUN_TEST(test_mat33f_transpose);
  RUN_TEST(test_mat33f_x_axis_rotation);
  RUN_TEST(test_mat33f_y_axis_rotation);
  RUN_TEST(test_mat33f_z_axis_rotation);
  RUN_TEST(test_mat33f_mul_point3f);
  RUN_TEST(test_mat33f_mul_mat33f);
  RUN_TEST(test_mat33f_mul_mat34f);
  RUN_TEST(test_mat33f_determinant);
  RUN_TEST(test_mat33f_inverse);
  RUN_TEST(test_mat34_rc);
  RUN_TEST(test_mat34f_identity);
  RUN_TEST(test_mat34f_translation_from_floats);
  RUN_TEST(test_mat34f_translation_from_vec3f);
  RUN_TEST(test_mat34f_translation_from_point3f);
  RUN_TEST(test_mat34f_from_mat33f_and_vec3f);
  RUN_TEST(test_mat34f_mul_point3f);
  RUN_TEST(test_mat34f_mul_vec3f);
  RUN_TEST(test_mat34f_mul_mat34f);
  RUN_TEST(test_mat34f_mul_mat33f);
  RUN_TEST(test_mat34f_inverse);
  RUN_TEST(test_mat44_rc);
  RUN_TEST(test_mat44f_identity);
  RUN_TEST(test_mat44f_translation_from_floats);
  RUN_TEST(test_mat44f_translation_from_vec3f);
  RUN_TEST(test_mat44f_translation_from_point3f);
  RUN_TEST(test_mat44f_from_mat33f_and_vec3f);
  RUN_TEST(test_mat44f_transpose);
  RUN_TEST(test_mat44f_mul_mat44f);
  RUN_TEST(test_mat44f_perspective_projection_lh);
  RUN_TEST(test_mat44f_mul_point4f);
  RUN_TEST(test_mat44f_project_point3f);
  RUN_TEST(test_mat44f_determinant);
  RUN_TEST(test_mat44f_inverse);
  RUN_TEST(test_swap_float);
  RUN_TEST(test_swap_int);
  RUN_TEST(test_clamp_float);
  RUN_TEST(test_clamp_int);
  RUN_TEST(test_max_float);
  RUN_TEST(test_max_int);
  RUN_TEST(test_min_float);
  RUN_TEST(test_min_int);
  RUN_TEST(test_radians_from_degrees);
  RUN_TEST(test_degrees_from_radians);
  return UNITY_END();
}
