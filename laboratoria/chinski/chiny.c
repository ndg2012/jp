#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;
int* ps = &size;


void usun_spacje(char *zdanie);
void skroc_lancuch(char *zdanie, int rozmiar);
void tlumacz_zdanie(char *chinskie, char **slownik);
void wypisz_zdanie(char *zdanie);

void pobierz_slownik(char **slownik)
{
    int i = 0;
    char temp[15];
    extern int size;

    while (scanf("%s", temp) == 1) {
	slownik[i] = (char *) malloc(15 * sizeof(char));
	strcpy(slownik[i], temp);
	i++;
	if (i == size)
	    break;
    }

}


int main(int argc, char *argv[])
{
    char string[100] = { '\0' };
    extern int size;
    if (argc < 3 ) {
	fprintf(stderr,
		"cat slownik.txt | %s \"jesli krowie dasz kakao nie wydoisz czekolady ani mleka\" \n",
		argv[0]);
	exit(1);
    } else {
      char* slownik = malloc(atoi(argv[1])*sizeof(char*));
	pobierz_slownik(&slownik);
	strcpy(string, argv[2]);
	usun_spacje(string);
	wypisz_zdanie(string);
	tlumacz_zdanie(string, &slownik);

	if (string[0] != '\0')
	    wypisz_zdanie(string);
	else
	    fprintf(stderr,
		    "Error. Nie znaleziono pierwszego slowa w słowniku.\n");
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

void tlumacz_zdanie(char *chinskie, char **slownik)
{
    extern int size;
    int i, j = 1;;
    int numer;
    int rozmiar;
    int dlugosc;
    char tablica[100] = { '\0' };

    while ((dlugosc = strlen(chinskie)) > 1) {
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
	    } else {
		j++;
		continue;
	    }

	}
	if ((j == size) || (j - 1 == size)) {
	    break;
	}
    }
    tablica[strlen(tablica) - 1] = '\0';
    strcpy(chinskie, tablica);
}

void wypisz_zdanie(char *zdanie)
{
    printf("%s\n", zdanie);
}
