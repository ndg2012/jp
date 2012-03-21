#include <stdio.h>

int main(){
  int tab[10] = {1};
  int i;
  int age = 19;
  int height = 189;

  printf("I am %d years old.\n", age);
  printf("I am %d inches tall.\n",height);

  for(i = 0 ; i<= 9; i++){
    printf("%i\n",tab[i]);
    tab[i] = i;
  }

  return 0;
}
