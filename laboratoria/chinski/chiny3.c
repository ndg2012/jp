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
    if(strlen(argv[1]) > 512){
      fprintf(stderr,"Error. Za długi łańcuch.\n");
      exit(2);
    } else {
      zdanie = strdup(argv[1]);
      /*
	bez strdup, czyli gdy zdanie = argv[1] oraz przy korzystaniu
	z realloc powstaje bład
      */
      pobierz_slownik(slownik, &size);
    }
  }

  usun_spacje(zdanie);    /* testowanie */
  wypisz_zdanie(zdanie);  /* testowanie */
  
  //  printf("przed tz - %p\n",zdanie);
  
  tlumacz_zdanie(zdanie, slownik, size);

  // printf("za tz - %p\n",zdanie);

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
  int max = 0;
  int rozmiar;
  char tablica[512] = { '\0' };
  void *testowy;
  int pozycja = 0;
   
  while (strlen(chinskie) > 1) {
    char wskaznik = chinskie[0];
    for (i = 0; i < size; i++) {
      if (slownik[i][0] == wskaznik) {
        rozmiar = strlen(slownik[i]);
        if (!strncmp(chinskie, slownik[i], rozmiar)) {
	  if( rozmiar > max ) {
	    max = rozmiar;
	    pozycja = i;
	  }
        }
      } else {
        continue;
      }
    }
    strcat(tablica, slownik[pozycja]);
    strcat(tablica, " ");
    skroc_lancuch(chinskie, max);
    max = 0;
    pozycja = 0;
  }
  tablica[strlen(tablica) - 1] = '\0';

  /*
  fprintf(stdout,"w tz - %p\n",chinskie);

  chinskie = strdup(tablica);

  if(chinskie == NULL){
    fprintf(stderr,"strdup\n");
  }
  fprintf(stdout,"w tz, po strdup - %p\n",chinskie);
  */

  
  testowy = (char*)realloc(chinskie,strlen(tablica)*sizeof(char));
  
  if(testowy == NULL){
    fprintf(stderr,"Reallokacja nieudana\n");
  } else {
    chinskie = testowy;
  }

  free(testowy);
  
  strcpy(chinskie, tablica);
 
}
