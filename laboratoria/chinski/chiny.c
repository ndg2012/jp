#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 9;

int word_int(char *tablica[], int i, char wskaznik);
void usun_spacje(char *tekst);
void sstr(char *string, int rozmiar);

void token(char *chinskie, char *slownik[])
{
    extern int size;
    int i;
    int numer;
    int rozmiar;
    char tablica[100] = {'\0'};

    while ((int)strlen(chinskie) > 1) {
	char wskaznik = chinskie[0];
	for (i = 0; i < size; i++) {
	    numer = word_int(slownik, i, wskaznik);
	    rozmiar =(int)strlen(slownik[numer]);
	    if (!strncmp(chinskie, slownik[numer], rozmiar)) {
		strcat(tablica, slownik[numer]);
		strcat(tablica, " ");
		sstr(chinskie, rozmiar);
	    }
	}
    }
    tablica[strlen(tablica) - 1] = '\0';
    strcpy(chinskie, tablica);
}

int main(int argc, char *argv[])
{
    char *slownik[] = { "ani", "czekolady", "dasz", "jesli", "kakao", "krowie", "nie","mleka","wydoisz"};
    char string[] = "jesli krowie dasz kakao nie wydoisz czekolady ani mleka";

    printf("%d %s\n", (int)strlen(string), string);
    usun_spacje(string);    
    printf("%d %s\n", (int)strlen(string), string);
    token(string, slownik);
    printf("%d %s\n", (int)strlen(string), string);

    return 0;
}

void sstr(char *string, int rozmiar)
{
    int i, j;
    char temp[100];

    for (i = rozmiar, j = 0; string[i] != '\0'; i++, j++)
	temp[j] = string[i];
    temp[j] = '\0';
    strcpy(string, temp);
}

void usun_spacje(char *tekst)
{
    int length = strlen(tekst);
    int j= 0, i = 0;
    char temp[100];

    j = i;
    for (i = 0; i < length; i++)
	if (tekst[i] != ' ') {
	    temp[j] = tekst[i];
	    j++;
	}
    temp[j] = '\0';
    strcpy(tekst,temp);
}

int word_int(char *tablica[], int i, char wskaznik)
{
    if (tablica[i][0] == wskaznik) return i;
    // else return -1;
}
