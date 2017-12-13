double calculate(char operatorr, double first, double second){
  if(operatorr == '+') return first + second;
  else if(operatorr == '-') return first - second;
  else if(operatorr == '*') return first * second;
  else if(operatorr == '/') return first / second;
  else printf("Error! operator is not correct");
}
