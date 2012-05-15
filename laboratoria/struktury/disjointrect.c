#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point ll;
    point ur;
} rect;

int ptinrect(point p, rect r);
int disjointrect(rect r1, rect r2);
int rectinrect(rect r1, rect r2);

int main(void){
  rect r1, r2; 

  scanf("%d %d %d %d",&r1.ll.x, &r1.ll.y, &r1.ur.x, &r1.ur.y); 
  scanf("%d %d %d %d",&r2.ll.x, &r2.ll.y, &r2.ur.x, &r2.ur.y);
  
  if(disjointrect(r1, r2) == 1)
    printf("Prostokąty są rozłączne.\n");
  else
    printf("Niestety, prostokąty nie są rozłączne.\n");

  return 0;
}

int rectinrect(rect r1, rect r2){
  return ptinrect(r1.ur, r2) && ptinrect(r1.ur, r2);
}

int ptinrect( point p, rect r){
  return p.x >= r.ll.x && p.x < r.ur.x
      && p.y >= r.ll.y && p.y < r.ur.y;
}

int disjointrect(rect r1, rect r2){
  if(rectinrect(r1, r2) == 0)
    return 1;
  else
    return 0;
}
