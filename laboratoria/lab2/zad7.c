/*
Napisz program, który wczyta liczbę rzeczywistą i wypisze jej odwrotność oraz jej pierwiastek kwadratowy. Program nie powinien obliczać odwrotności liczby 0 oraz pierwiastka z liczby ujemnej. W takiej sytuacji zamiast obliczeń program powinien wypisać odpowiedni komunikat.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  double liczba;

  fprintf(stdout,"Podaj liczbę rzeczywistą nieujemną ");
  scanf("%lf",&liczba);

  if(liczba < 0){
    fprintf(stderr,"Błąd. Podana liczba jest ujemna.\n");
    exit(1);
  }
  else {
    printf("Odwrotność liczby %.2lf wynosi %.13lf.\n",liczba,1/liczba);
    printf("Pierwiastek liczby %.2lf wynosi %.4f.\n",liczba, sqrt(liczba));
  }

  return 0;
}
