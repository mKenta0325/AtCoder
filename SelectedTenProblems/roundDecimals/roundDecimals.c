#include <stdio.h>
int main() {
  float x ;
  scanf("%f", &x) ;
  int integerPartX = (int) x ;
  if (x - integerPartX < 0.5)
    printf("%d\n", integerPartX) ;
  else
    printf("%d\n", integerPartX + 1) ;
  return 0 ;
}
