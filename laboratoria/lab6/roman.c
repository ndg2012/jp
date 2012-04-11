#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char imie[50];
  //int i, tr=0;
  char* znaki;
  char c;
  znaki = argv[1];

  // użyc funkcji strncmp
  printf("Imiona zaczynajace sie od: %s\n", znaki);
  while (c != EOF) {
    scanf("%s", imie);
    
    if(!strncmp(imie,znaki,strlen(znaki)))
       printf("%s\n", imie);
    
    c = getchar();
  }

  return 0;
}
