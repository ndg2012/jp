#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void token(char *przed,char *po, char *slownik[]){
  char temp;
  int i;
  int max = 0;


  temp = przed[2];
  
  /* wyszukiwanie najdłuższego słowa zaczynającego się na 
   * podana litera, zmienna max zawiera ten element tablicy który jest najdłuższy
   */
  for(i = 0; i < 7; i++){
    if( temp == slownik[i][0])
      if( max < strlen(slownik[i]))
	max = i;
  }
  

  /*
   * printf sprawdza powyższa petlę jej mankamentem jest to ze jeżeli 
   * nie znajdzie najdłuższego słowa na podaną litere to zwraca 
   * pierwszy string z slownika
   */
  //printf("%s",slownik[max]);
}

void usun_spacje(char *tekst, char *po){
  int length = strlen(tekst);
  int j;
  int i = 0;

  j = i;
  for( i = 0 ; i < length; i++)
    if( tekst[i] != ' '){
      po[j] = tekst[i];      
      j++;
    } 
}

int main(int argc, char *argv[]){

  char *slownik[] = {"czekolady", "dasz", "jesli", "kakao", "krowie", "nie", "wydoisz"};
  char *przed = "jesli krowie dasz kakao nie wydoisz czekolady";
  char po[45];
  //char temp[45];

  //printf("%i",strlen(przed));

  usun_spacje(przed,po);
  printf("%i %s\n%i %s\n",(int)strlen(przed),przed,(int)strlen(po),po);
  token(przed,po,slownik);
  
  return 0;
}
