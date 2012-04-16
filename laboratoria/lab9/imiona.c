#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pobierz_imiona(char* slownik[]);
void podaj_prefiks(char* prefiks);
void wypisz_imiona(char* slownik[], char* prefiks, int ilosc_wczytanych);

int main(int argc, char* argv[]){
  char *slownik[4960];
  char prefiks[20];
  int size = 0;
  
  printf("Podaj imiona (aby zakonczyć ^D): \n");

  size = pobierz_imiona(slownik);

  printf("Wczytano %d imion\n",size);

  podaj_prefiks(prefiks);

  printf("Imiona zaczynające się na %s, to :\n",prefiks);

  wypisz_imiona(slownik,prefiks,size);
  
  return 0;
}

int pobierz_imiona(char *slownik[]){
  char temp[20];
  
  int i = 0;
  while(scanf("%s",temp) == 1){
    slownik[i] = (char* )malloc((int)strlen(temp)*sizeof(char));
    strcpy(slownik[i],temp);
    i++;
  }
  return i;

}
void podaj_prefiks(char *prefiks){
  printf("Podaj prefiks:  ");
  scanf("%s",prefiks);
}
void wypisz_imiona(char* slownik[], char* prefiks, int ilosc_wczytanych){
  int i;
  for(i = 0 ; i < ilosc_wczytanych; i++){
	if (!strncmp (slownik[i], prefiks, strlen (prefiks)))
	  printf("%s\n",slownik[i]);
  }

}
