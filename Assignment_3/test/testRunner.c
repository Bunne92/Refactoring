#include "../unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP_RUNNER(Calc){
  RUN_TEST_CASE(Calc, AdditionTest);
  RUN_TEST_CASE(Calc, SubtractionTest);
  RUNT_TEST_CASE(Calc, MultiplicationTest);
  RUN_TEST_CASE(Calc, DivisionTest);
}
