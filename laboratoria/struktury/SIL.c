#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    pt ld;			// lewy dolny 
    pt pg;			// prawy górny
} rect;

int area(rect a)
{
    return (a.pg.x - a.ld.x) * (a.pg.y - a.ld.y);
}

int main(void)
{
    rect a, b;
    int da = 0;
    int db = 0;

    while (scanf("%d %d %d %d", &a.ld.x, &a.ld.y, &a.pg.x, &a.pg.y) == 4) {
	scanf("%d %d %d %d", &b.ld.x, &b.ld.y, &b.pg.x, &b.pg.y);




	if ((a.pg.x <= b.ld.x && a.ld.y <= b.pg.y) || (b.pg.x <= a.ld.x && b.ld.y <= a.pg.y)) // rozała
	  printf("%d\n", area(a) + area(b));
	else if ((a.pg.x <= b.ld.x && b.pg.y <= a.ld.y) || (b.pg.x <= a.ld.x && a.pg.y <= b.ld.y))
	  printf("%d\n", area(a) + area(b));
	else if ((a.ld.x <= b.ld.x && b.pg.x <= a.pg.x  && a.ld.y <= b.ld.y && b.pg.y <= a.pg.y) 
	  	 || (b.ld.x <= a.ld.x && a.pg.x <= b.pg.x  && b.ld.y <= a.ld.y && a.pg.y <= b.pg.y)) {
	    printf("%d\n", area(a) > area(b) ? area(a) : area(b));
	} else{
	   if(a.ld.x < b.ld.x && (a.ld.y <= b.ld.y && b.pg.y <= a.ld.y)){
	     da = abs(a.pg.x - b.ld.x);
	     db = abs(b.pg.y - b.ld.y);
	     printf("c.a = %d\n", area(a) + area(b) - da * db);
	   }
	   else {
	   da = abs(a.ld.x - b.pg.x);
	   db = abs(a.pg.y - b.ld.y);
	   printf("c.b = %d\n", area(a) + area(b) - da * db);
	   }
	}

    }

    return 0;
}
