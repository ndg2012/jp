#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *word_pointer(char *tablica[], int i, char wskaznik);
int word_int(char *tablica[], int i, char wskaznik);
void usun_spacje(char *tekst, char *po);
void sstr(char *string, int rozmiar);


int size = 9; 

void token(char *chinskie, char *slownik[])
{
    extern int size;
    int i;
    int numer2;
    int rozmiar;
    
    while (strlen(chinskie) > 1) {
	char wskaznik = chinskie[0];
	for (i = 0; i < size; i++) {
	    numer2 = word_int(slownik, i, wskaznik);
	    rozmiar = strlen(slownik[numer2]);
	    if (!strncmp(chinskie, slownik[numer2], rozmiar)) {
	      printf("%s ", slownik[numer2]);
	      sstr(chinskie, rozmiar);
	    }
	}
    }
    puts("");
}


int main(int argc, char *argv[])
{

    char *slownik[] =
	{ "czekolady", "dasz", "jesli", "kakao", "krowie", "nie",
	  "wydoisz", "ani", "mleka"
    };
    char *przed = "jesli krowie dasz kakao nie wydoisz czekolady ani mleka";
    char po[100];


    usun_spacje(przed, po);

    printf("%s\n%s\n",przed,po);
    token(po, slownik);


    return 0;
}


void sstr(char *string, int rozmiar)
{
    int i, j;

    char *temp = malloc(strlen(string) * sizeof(char));

    for (i = rozmiar, j = 0; string[i] != '\0'; i++, j++) {
	temp[j] = string[i];

    }
    temp[++j] = '\0';

    strncpy(string,temp,strlen(temp)+1);

    /*
    free(temp);
    */
}



void usun_spacje(char *tekst, char *po)
{
    int length = strlen(tekst);
    int j;
    int i = 0;

    j = i;
    for (i = 0; i < length; i++)
	if (tekst[i] != ' ') {
	    po[j] = tekst[i];
	    j++;
	}
}

char *word_pointer(char *tablica[], int i, char wskaznik)
{
    if (tablica[i][0] == wskaznik)
	return tablica[i];
    else
	return NULL;
}

int word_int(char *tablica[], int i, char wskaznik)
{
    if (tablica[i][0] == wskaznik)
	return i;
    else
	return -1;
}
