#include "unity/src/unity.h"
#include "lib/functions.h"

void AdditionTest(void){
  TEST_ASSERT_EQUAL_FLOAT(8.0, calculate('+', 4.0, 4.0));
}

void SubtractionTest(void){
  TEST_ASSERT_EQUAL_FLOAT(3.0, calculate('-', 8.0, 5.0));
}

void MultiplicationTest(void){
  TEST_ASSERT_EQUAL_FLOAT(12.0, calculate('*', 3.0, 4.0));
}

void DivisionTest(void){
  TEST_ASSERT_EQUAL_FLOAT(3.0, calculate('/', 9.0, 3.0));
}



int main(){
  RUN_TEST(AdditionTest);
  RUN_TEST(SubtractionTest);
  RUN_TEST(MultiplicationTest);
  RUN_TEST(DivisionTest);
}
