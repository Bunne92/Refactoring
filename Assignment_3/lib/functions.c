double calculate(char operator, double first, double second){
  if(operator == '+') return first + second;
  else if(operator == '-') return first - second;
  else if(operator == '*') return first * second;
  else if(operator == '/') return first / second;
  else printf("Error! operator is not correct");
}
