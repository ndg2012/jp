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

int rectinrect(rect r1, rect r2);
int ptinrect(point p, rect r);


int main(void){
  rect r1, r2;

  scanf("%d %d %d %d",&r1.ll.x, &r1.ll.y, &r1.ur.x, &r1.ur.y); 
  scanf("%d %d %d %d",&r2.ll.x, &r2.ll.y, &r2.ur.x, &r2.ur.y);
  
  if(rectinrect(r1, r2) == 1)
    printf("Pierwszy prostokąt zawiera się w drugim\n");
  else
    printf("Niestety, spróbuj ponownie\n");
  
  return EXIT_SUCCESS;
}

int rectinrect(rect r1, rect r2){
  return ptinrect(r1.ur, r2) && ptinrect(r1.ur, r2);
}

int ptinrect(point p, rect r) {
  return p.x >= r.ll.x && p.x < r.ur.x
      && p.y >= r.ll.y && p.y < r.ur.y;
}
