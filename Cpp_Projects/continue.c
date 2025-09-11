/*C programming
dev journey: heres practicing continiues for loops and usage of 'continue'
we learned:
The provided commented code below attempts to use continue in the inner for loop's declaration,
which is syntactically incorrect. 
Instead, continue should be used within the loop body to skip the current iteration and proceed to the next one.*/
#include <stdio.h>

int main() {
  
    for (int i = 0; i < 10; i++)
    {
        for(int j = 11; j<20; j++){
            
            if(j%2==0)
                continue;
            printf("i = %d, j=%d\n", i,j);
        }
        if(i==5)
                break;
    }
    
  return 0;
}
  /*
  int main() {
  
    for (int i = 0; i < 10; i++)
    {
        for(int j = 11; j<20; continue){
            
            if(j%2==0)
                continue;
            printf("i = %d, j=%d\n", i,j);
        }
        if(i==5)
                break;
    }
    
  return 0;
} */