#include <stdio.h>
#include "point_rectangle_screen.h"
#include "print_macros.h"

int main()
{
	int x = 1;
	int y = 3;
	struct point point1 = makepoint(x, y);
	struct point point2 = makepoint(8, 6); /* can declare it this way if you declared an initializer function for the struct*/
	struct point point3 = addpoint(point1, point2);
	
	struct rect my_rectangle;
	
	my_rectangle.pt1 = point2; /* Can initialize a struct this way even without having written an initializer 											function. Would also work for a point, by declaring a blank struct point, then 											assigning that_point.x = some int, etc. */
	my_rectangle.pt2 = point1;
	
	//intprint(x);
	
	//ptprint(makepoint(x, y));
	//ptprint(point2);
	//ptprint(point3);
	rectprint(my_rectangle);
	
	//struct rect *pointer_to_the_rectangle = &my_rectangle;
	
	//mutate_canonrect(pointer_to_the_rectangle);
	mutate_canonrect(&my_rectangle); /* This works. "&" plus name of pointed-to thing is sufficient, compiler already knows the type ("struct rect *r", a pointer to a struct rect), and "&my_rectangle" matches that type. */
	
	printf("After calling canonrect on my_rectangle:\n");
	rectprint(my_rectangle);
	//rectprint(canonrect(my_rectangle)); /* K&R's canonrect returns a new rectangle rather than mutating-in-place the one that was passed in */

		
	
}
