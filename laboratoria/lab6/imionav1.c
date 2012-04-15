#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
  if(argc == 1){
    fprintf(stderr,"Error. Źle wywołany program\n");
    exit(1);
  }
  else{
    char *tablica =(char*) malloc(atoi(argv[1])*sizeof(char*));
    printf("%i - %s\n",atoi(argv[1]),argv[2]);
    char temp[20];
    
    int i = 0;
    while(scanf("%s",temp) == 1){
      tablica[i] = (char)malloc(20*sizeof(char));
      strcpy(tablica[i],temp);
      i++;
    }

    for(i = 0 ; i < atoi(argv[1]); i++){
	if (!strncmp (tablica[i], argv[2], strlen (argv[2])))
	  printf ("%s\n", tablica);
      }

  }

  return 0;
}
