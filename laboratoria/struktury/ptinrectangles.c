#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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
void ptinrectangles(char *fmt, ...);

int main(void){
  rect r1, r2, r3, r4, r5, r6; 

  scanf("%d %d %d %d",&r1.ll.x, &r1.ll.y, &r1.ur.x, &r1.ur.y); 
  scanf("%d %d %d %d",&r2.ll.x, &r2.ll.y, &r2.ur.x, &r2.ur.y);
  scanf("%d %d %d %d",&r3.ll.x, &r3.ll.y, &r3.ur.x, &r3.ur.y);
  scanf("%d %d %d %d",&r4.ll.x, &r4.ll.y, &r4.ur.x, &r4.ur.y);
  scanf("%d %d %d %d",&r5.ll.x, &r5.ll.y, &r5.ur.x, &r5.ur.y);
  scanf("%d %d %d %d",&r6.ll.x, &r6.ll.y, &r6.ur.x, &r6.ur.y);


  return 0;
}

int rectinrect(rect r1, rect r2){
  return ptinrect(r1.ur, r2) && ptinrect(r1.ur, r2);
}

int ptinrect(point p, rect r){
  return p.x >= r.ll.x && p.x < r.ur.x
      && p.y >= r.ll.y && p.y < r.ur.y;
}

int disjointrect(rect r1, rect r2){
  if(rectinrect(r1, r2) == 0)
    return 1;
  else
    return 0;
}

void ptinrectangles(char *fmt, ...){
  va_list ap;
  
  va_start(ap, fmt);

  while(*fmt){
  
  }
  
  va_end(ap);

}
