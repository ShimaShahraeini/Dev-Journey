/*C programming
dev journey: simple code for turning binary variable into decimal*/
#include <stdio.h>

int main() {
  
  int num2 = 10101001; 
  int num10=0, i=1;

  for (int i=1; num2 > 0; )
  {
    num10 += (num2%10)*i; 
    i*=2;
    num2 /=10;
  }
  printf("%d", num10); 

  return 0;
} 