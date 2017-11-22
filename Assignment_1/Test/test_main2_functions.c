#include "C:\Users\denni\Desktop\unity\src\unity.h"
#include "functions.h"

void test_MultiplyTwoNumbers(void){
  TEST_ASSERT_EQUAL_FLOAT(6.0, multipli_two_values(2.0, 3.0));
}
int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_MultiplyTwoNumbers);
return UNITY_END();
}
