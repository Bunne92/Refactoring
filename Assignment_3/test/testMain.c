#include "..unity/extras/fixture/src/unity_fixture.h"

static void RunAllTests(void){
  RUN_TEST_GROUP(Calc);
}

int main(int ac, const char *av[]){
  return UnityMain(ac, av, RunAllTests);
}
