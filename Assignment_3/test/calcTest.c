#include "../unity/extras/fixture/src/unity_fixture.h"
#include "../lib/functions.h"

TEST_GROUP(Calc);

TEST_SETUP(Calc){
}

TEST_TEAR_DOWN(Calc){
}

TEST(Calc, AdditionTest){
  TEST_ASSERT_EQUAL_FLOAT(8.0, calculate('+', 4.0, 4.0));
}

TEST(Calc, SubtractionTest){
  TEST_ASSERT_EQUAL_FLOAT(3.0, calculate('-', 8.0, 5.0));
}

TEST(Calc, MultiplicationTest){
  TEST_ASSERT_EQUAL_FLOAT(12.0, calculate('*', 3.0, 4.0));
}

TEST(Calc, DivisionTest){
  TEST_ASSERT_EQUAL_FLOAT(3.0, calculate('/', 9.0, 3.0));
}
