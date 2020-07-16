

struct key {
	char *word;
	int count;
} keytab[] = { /* size of this array won't change--constant set of keywords */
	"auto", 0, /* a "char *" type followed by an int */
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	/* ... */
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};
