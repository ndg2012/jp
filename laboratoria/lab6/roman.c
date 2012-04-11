#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char imie[50];
  int i, tr=0;
  char* znaki;
  char c;
  znaki = argv[1];

  // użyc funkcji strncmp
  printf("Imiona zaczynajace sie od: %s\n\n", znaki);
  while (c != EOF) {
    scanf("%s", imie);
    for (i=0; i<strlen(znaki); i++) {
      if (znaki[i] == imie[i]) {
        tr++;
      }
    }
    if (tr == strlen(znaki))
      printf("%s\n", imie);
    tr=0;
    c = getchar();
  }

  return 0;
}
