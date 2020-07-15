#include "print_macros.h" //for testing

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
	int x;
	int y;
};

/* makepoint: take two integers and return a point struct */
struct point makepoint(int x, int y)
{
	struct point temp;
	
	temp.x = x;
	temp.y = y;
	return temp;
}

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}



struct rect { /* rectangle struct. Defining a rectangle via the points of its diagonally opposite corners */
	struct point pt1;
	struct point pt2;
};

/* canonrect: "canonicalize" coordinates of rectangle. I.e. reorder and redefine them such that the smaller coordinates are the first point, the larger coordinates the second point. */
struct rect canonrect(struct rect r)
{
	/* If the initial points were (2, 7) and (7, 3), this would return (2, 3) and (7, 7). Those points as diagonally opposite corners define the same rectangle as the original. */

	struct rect temp;
	
	temp.pt1.x = min(r.pt1.x, r.pt2.x); /* point1 becomes (smallest x, smallest y) */
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}

void mutate_canonrect(struct rect *r) /* It needs to take a pointer to the rectangle in order to mutate the rectangle itself. If the arg is "struct rect r" as original canonrect has, then the calling code passes a copy of the rectangle, not (pointers to) the rectangle itself. */
{
	/* Attempt to mutate the original rect in place, without returning a new one. */

	struct rect temp = *r; /* This is still creating a copy of the entire rectangle in memory */
		
	int *x1 = &(*r).pt1.x;
	int *y1 = &(*r).pt1.y;
	int *x2 = &(*r).pt2.x;
	int *y2 = &(*r).pt2.y;
	
	*x1 = min(temp.pt1.x, temp.pt2.x);
	//printf("Printing the new x1 after mutate attempt:\n\t");
	//ptprint(*r.pt1);
	*y1 = min(temp.pt1.y, temp.pt2.y);
	//printf("printing the new point 1 after mutate attempt:\n\t");
	//ptprint(*r.pt1);
	*x2 = max(temp.pt1.x, temp.pt2.x);
	*y2 = max(temp.pt1.y, temp.pt2.y);
	
	//printf("print of original rectangle struct rect r from mutate_canonrect:\n\t");
	//rectprint(*r);
}

/* ptinrect: Tests whether a point is inside a rectangle (assuming convention that rectangle includes its left and bottom sides but not its top and right) */
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x
		&& p.y >= r.pt1.y && p.y < r.pt2.y;
} /* Also assumes a rectangle is represented in a standard form where the pt1 coords are less than the pt2 coords */

