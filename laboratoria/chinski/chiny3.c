#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000

void pobierz_slownik(char *slownik[], int *size);
void usun_spacje(char *zdanie);
void wypisz_zdanie(char *zdanie);

void tlumacz_zdanie(char *chinskie, char **slownik, int size);

int main(int argc, char *argv[]) {
  int size;
  char **slownik = malloc(MAX_WORDS * sizeof(char *));
  char *zdanie;

  if (argc <= 1) {
    fprintf(stderr, "cat slownik.txt | %s \"zdanie\" \n", argv[0]);
    exit(1);
  } else {
    zdanie = strdup(argv[1]);
    pobierz_slownik(slownik, &size);
  }

  usun_spacje(zdanie);    /* testowanie */
  wypisz_zdanie(zdanie);  /* testowanie */

  tlumacz_zdanie(zdanie, slownik, size);

  if (zdanie[0] != '\0')
    wypisz_zdanie(zdanie);
  else
    fprintf(stderr, "Error. Nie znaleziono pierwszego slowa w słowniku.\n");

  free(slownik);
  
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

void usun_spacje(char *zdanie) {
  int length = strlen(zdanie);
  int j = 0, i = 0;
  char temp[512] = { '\0' };

  j = i;
  for (i = 0; i < length; i++)
    if (zdanie[i] != ' ') {
      temp[j] = zdanie[i];
      j++;
    }
  temp[j] = '\0';
  strcpy(zdanie, temp);
}

void wypisz_zdanie(char *zdanie) {
  printf ("%s\n", zdanie);
}

void skroc_lancuch (char *zdanie, int rozmiar) {
  int i, j;
  char temp[512] = { '\0' };

  for (i = rozmiar, j = 0; zdanie[i] != '\0'; i++, j++)
    temp[j] = zdanie[i];
  temp[j] = '\0';
  strcpy(zdanie, temp);
}

void tlumacz_zdanie (char *chinskie, char **slownik, int size) {
  int i;
  int numer;
  int rozmiar;
  char tablica[512] = { '\0' };
  void *testowy;

  while (strlen(chinskie) > 1) {
    char wskaznik = chinskie[0];
    for (i = 0; i < size; i++) {
      if (slownik[i][0] == wskaznik) {
        numer = i;
        rozmiar = strlen(slownik[numer]);
        if (!strncmp(chinskie, slownik[numer], rozmiar)) {
          strcat(tablica, slownik[numer]);
          strcat(tablica, " ");
          skroc_lancuch(chinskie, rozmiar);
        }
      } else
        continue;
    }/*
    if (wskaznik == chinskie[0]) {
      fprintf(stderr, "Error. Wybacz ale nie znalazłem >= 1 slowa.\n");
      break;
      }*/
  }
  tablica[strlen(tablica) - 1] = '\0';
  
  testowy = realloc(chinskie,strlen(tablica)*sizeof(char));
  
  if(testowy == NULL){
    fprintf(stderr,"Reallokacja nieudana\n");
  } else {
    chinskie = testowy;
  }
  free(testowy);

  strcpy(chinskie, tablica);
}
