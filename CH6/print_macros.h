#define intprint(expr) printf(#expr " = %d\n", expr)
#define strprint(expr) printf(#expr " = %s\n", expr)
#define ptprint(expr) printf(#expr " = (%d, %d)\n", expr.x, expr.y)
#define rectprint(expr) printf(#expr " = Diagonally opposite corners\n\t(%d, %d) and (%d, %d)\n", expr.pt1.x, expr.pt1.y, expr.pt2.x, expr.pt2.y)
