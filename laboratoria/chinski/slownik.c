#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000

void pobierz_slownik(char *slownik[], int *size);

int main(int argc, char *argv[]) {
  int size;
  char **slownik = malloc(MAX_WORDS * sizeof(char *));

  if (argc <= 1) {
    fprintf(stderr, "cat /usr/share/dict/words | %s \"zdanie\" \n", argv[0]);
    exit(1);
  } else {
    pobierz_slownik(slownik, &size);
  }

  printf("liczba słów w słowniku: %d\n", size);
  printf("slownik[0] = %s\n", slownik[0]);
  printf("slownik[%d] = %s\n", size-1, slownik[size-1]);

  return 0;
}

void pobierz_slownik (char *slownik[], int *size) {
  int i = 0;
  char temp[512];

  while (scanf("%s", temp) == 1 && i < MAX_WORDS) {
    slownik[i] = strdup(temp);
    i++;
  }
  *size = i;
}
