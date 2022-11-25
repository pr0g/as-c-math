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
  const as_vec2f vec2f =
    as_vec2f_div_float((as_vec2f){.x = 5.0f, .y = 2.5f}, 2.0f);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.5f, vec2f.x);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.25f, vec2f.y);
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
  {}
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
  return UNITY_END();
}
