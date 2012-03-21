/*
Napisz program, który wczyta liczbę rzeczywistą i wypisze jej pierwiastek kwadratowy. W wypadku podania liczby ujemnej, program powinien wypisać komunikat o błędzie oraz zakończyć działanie.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void){
  double a;

  fprintf(stdout,"Podaj liczbe rzeczywistą nieujemną ");
  scanf("%lf",&a);
  // printf("\n");

  if(a < 0){
    fprintf(stderr,"Błąd. Liczba %.2lf jest ujemna\n",a);
    exit(1);
  }
  else{
    printf("Kwadrat liczby %.2lf wynosi %.2lf\n",a,a*a);
  }
    

  return 0;
}
