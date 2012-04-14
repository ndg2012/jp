/*
 * TODO: napis obsługe sytuacji gdy nie ma danego slowa w słowniku ...
 *       dynamiczna alokacja pamieci ... :]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 9;			// ilosc slow w slowniku

void usun_spacje(char *zdanie);
void skroc_lancuch(char *zdanie, int rozmiar);
void tlumacz_zdanie(char *chinskie, char *slownik[]);

void pobierz_slownik(char *slownik[])
{
  int i = 0;
  char temp[15];
  extern int size;
  
  while(scanf("%s",temp) == 1){
    slownik[i] = (char *)malloc(15*sizeof(char));
    strcpy(slownik[i],temp);
    i++;
    if(i == size)
      break;
  }
    
}

void wypisz_zdanie(char *zdanie)
{
    printf("%s\n", zdanie);
}

int main(int argc, char *argv[])
{
    char* slownik[9];
    char string[100] = { '\0' };
    
    if (argc == 1) {
	fprintf(stderr,"usage: cat slownik.txt | %s \"what jesus blatantly fails to  appreciate is that it is the meek who are the problem\" \n",argv[0]);
	exit(1);
    } else {
        pobierz_slownik(slownik);
	strcpy(string, argv[1]);
	usun_spacje(string);
	wypisz_zdanie(string);
	tlumacz_zdanie(string, slownik);
	wypisz_zdanie(string);
    }

    return 0;
}

void skroc_lancuch(char *zdanie, int rozmiar)
{
    int i, j;
    char temp[100] = { '\0' };

    for (i = rozmiar, j = 0; zdanie[i] != '\0'; i++, j++)
	temp[j] = zdanie[i];
    temp[j] = '\0';
    strcpy(zdanie, temp);
}

void usun_spacje(char *zdanie)
{
    int length = strlen(zdanie);
    int j = 0, i = 0;
    char temp[100] = { '\0' };

    j = i;
    for (i = 0; i < length; i++)
	if (zdanie[i] != ' ') {
	    temp[j] = zdanie[i];
	    j++;
	}
    temp[j] = '\0';
    strcpy(zdanie, temp);
}

void tlumacz_zdanie(char *chinskie, char *slownik[])
{
    extern int size;
    int i;
    int numer;
    int rozmiar;
    char tablica[100] = { '\0' };

    while ((int) strlen(chinskie) > 1) {
	char wskaznik = chinskie[0];
	for (i = 0; i < size; i++) {
	    if (slownik[i][0] == wskaznik) {
		numer = i;
		rozmiar = (int) strlen(slownik[numer]);
		if (!strncmp(chinskie, slownik[numer], rozmiar)) {
		    strcat(tablica, slownik[numer]);
		    strcat(tablica, " ");
		    skroc_lancuch(chinskie, rozmiar);
		}
	    } else
		continue;
	}
    }
    tablica[strlen(tablica) - 1] = '\0';
    strcpy(chinskie, tablica);
}
