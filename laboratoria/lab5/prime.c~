#include <stdio.h>
#include <stdbool.h>

#define MAX 123

int
main (void)
{
  bool sito[MAX];
  int i, j, k;
 
  sito[0] = false;
  sito[1] = false;
  
  for(i = 2; i < MAX; i++){
    sito[i] = true;
  }

  puts("druga");

  for (i = 2; i < MAX; i++){
    if( sito[i] = true){
      for(k = i; k*k < MAX; k += i)
	sito[k] = false;
    }
    
  }

  for(i = 0; i < MAX; i++)
    printf("(%d,%d)\n",i,sito[i]);


    return 0;
}
