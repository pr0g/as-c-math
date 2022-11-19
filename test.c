#include <unity.h>

#include "th-ops.h"

#include <float.h>
#include <math.h>

void setUp(void) {
}

void tearDown(void) {
}

void test_vec2f_expected_values(void) {
  vec2f_t vec2f = {.x = 1.0f, .y = 2.0f};
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 1.0f, vec2f.x);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 2.0f, vec2f.y);
}

void test_vec2f_from_point2f(void) {
  point2f_t point2f = {.x = 10.0f, .y = 20.0f};
  vec2f_t vec2f = vec2f_from_point2f(point2f);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 10.0f, vec2f.x);
  TEST_ASSERT_FLOAT_WITHIN(FLT_EPSILON, 20.0f, vec2f.y);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_vec2f_expected_values);
  RUN_TEST(test_vec2f_from_point2f);
  return UNITY_END();
}
