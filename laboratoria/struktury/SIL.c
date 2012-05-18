#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
  pt ld;
  pt pg;
} rect;

int area(rect a)
{
  return (a.pg.x - a.ld.x) * (a.pg.y - a.ld.y);
}

int dis(rect a, rect b)
{
    if ((a.pg.x <= b.ld.x && a.ld.y <= b.pg.y)
	|| (b.pg.x <= a.ld.x && b.ld.y <= a.pg.y))
	return 1;
    else if ((a.pg.y <= b.ld.y && a.pg.x >= b.ld.x)
	     || (b.pg.y <= a.ld.y && b.pg.x >= a.ld.x))
	return 1;
    else
	return 0;
}

int in(rect a, rect b)
{
    if ((a.ld.x <= b.ld.x && b.pg.x <= a.pg.x && a.ld.y <= b.ld.y
	 && b.pg.y <= a.pg.y)
	|| (b.ld.x <= a.ld.x && a.pg.x <= b.pg.x && b.ld.y <= a.ld.y
	    && a.pg.y <= b.pg.y))
	return 1;
    else
	return 0;
}



int main(void)
{
    rect a, b;
    int da = 0;
    int db = 0;

    scanf("%d %d %d %d", &a.ld.x, &a.ld.y, &a.pg.x, &a.pg.y);
    scanf("%d %d %d %d", &b.ld.x, &b.ld.y, &b.pg.x, &b.pg.y);


    if (dis(a, b) == 1)
	printf("%d\n", area(a) + area(b));
    else {
	if (in(a, b) == 1)
	    printf("%d\n", area(a) > area(b) ? area(a) : area(b));
	else {
	    if (a.pg.x <= b.pg.x && a.pg.y <= b.pg.y) {
		if (a.ld.x <= b.ld.x && b.pg.x >= a.pg.x
		    && a.pg.y == b.pg.y) {
		    da = a.pg.x - b.ld.x;
		    db = a.pg.y - a.ld.y;
		    printf("%d\n", area(a) + area(b) - da * db);
		} else {
		    da = a.pg.x - b.ld.x;
		    db = a.pg.y - b.ld.y;
		    printf("%d\n", area(a) + area(b) - da * db);
		}
	    } else if (a.ld.y == b.ld.y) {
		if (b.pg.x <= a.pg.x && b.pg.y <= a.pg.y) {
		    da = b.pg.x - a.ld.x;
		    db = b.pg.y - b.ld.y;
		    printf("%d\n", area(a) + area(b) - da * db);
		} else {
		    da = a.pg.x - a.ld.x;
		    db = b.pg.y - b.ld.y;
		    printf("%d\n", area(a) + area(b) - da * db);
		}
	    } else if (a.pg.y == b.pg.y) {
		da = b.pg.x - a.ld.x;
		db = a.pg.y - a.ld.y;
		printf("%d\n", area(a) + area(b) - da * db);
	    } else if (a.ld.x == b.ld.x) {
		if (b.pg.x <= a.pg.x && b.pg.y <= a.pg.y) {
		    da = b.pg.x - b.ld.x;
		    db = b.pg.y - a.ld.y;
		    printf("%d\n", area(a) + area(b) - da * db);
		}
		else if(b.pg.x <= a.pg.x && b.pg.y >= a.pg.y){
		  da = b.pg.x - b.ld.x;
		  db = a.pg.y - a.ld.y;
	          printf("%d\n", area(a) + area(b) - da * db);
		} else {
		    da = a.pg.x - a.ld.x;
		    db = b.pg.y - b.ld.y;
		    printf("%d\n", area(a) + area(b) - da * db);
		}
	    } else if (a.pg.x >= b.pg.x && a.pg.y <= b.pg.y
		       && b.ld.y >= a.ld.y) {
		if (a.ld.x <= b.ld.x && b.pg.x <= a.pg.x) {
		    da = b.pg.x - b.ld.x;
		    db = a.pg.y - b.ld.y;
		    printf("%d\n", area(a) + area(b) - da * db);
		} else {
		    da = b.pg.x - a.ld.x;
		    db = a.pg.y - b.ld.y;
		    printf("%d\n", area(a) + area(b) - da * db);
		}
	    } else if (a.ld.x <= b.ld.x && a.pg.x <= b.pg.x) {
		if (a.ld.y <= b.ld.y && b.pg.y <= a.pg.y) {
		    da = a.pg.x - b.ld.x;
		    db = b.pg.y - b.ld.y;
		    printf("%d\n", area(a) + area(b) - da * db);
		} else if (a.ld.y >= b.ld.y && a.pg.y >= b.pg.y) {
		    da = a.pg.x - b.ld.x;
		    db = b.pg.y - a.ld.y;
		    printf("%d\n", area(a) + area(b) - da * db);
		} else
		    fprintf(stderr, "Error2. Nieznany przypadek.\n");
	    } else if (b.ld.x <= a.ld.x && b.pg.x <= a.pg.x) {
		da = b.pg.x - a.ld.x;
		db = b.pg.y - a.ld.y;
		printf("%d\n", area(a) + area(b) - da * db);
	    } else if (a.ld.x <= b.ld.x && b.pg.x <= a.pg.x) {
		da = b.pg.x - b.ld.x;
		db = b.pg.y - a.ld.y;
		printf("%d\n", area(a) + area(b) - da * db);
	    } else
		fprintf(stderr, "Error. Nieznany przypadek.\n");
	}
    }

    return 0;
}
