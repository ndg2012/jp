#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} pt;

typedef struct {
  pt ld; // lewy dolny 
  pt pg; // prawy górny
} rect;

int area(rect a){
  return (a.pg.x - a.ld.x)*(a.pg.y - a.ld.y);
}

int main(void){
  rect a, b;
  int da;
  int db;

  while(scanf("%d %d %d %d", &a.ld.x, &a.ld.y, &a.pg.x, &a.pg.y) == 4){
    scanf("%d %d %d %d", &b.ld.x, &b.ld.y, &b.pg.x, &b.pg.y);

    da = abs(a.pg.x - b.ld.x);
    db = abs(b.pg.y - a.ld.y);
    
  
    if(a.pg.x < b.ld.x || b.pg.x < a.ld.x)
      printf("%d\n",area(a)+area(b));
    else if((a.ld.x <= b.ld.x && b.pg.x <= a.pg.x) || (b.ld.x <= a.ld.x && a.pg.x <= b.pg.x))
      printf("%d\n",area(a) > area(b) ? area(a) : area(b));
    else
      printf("%d\n",area(a)+area(b)-da*db);

  }

  return 0;
}

