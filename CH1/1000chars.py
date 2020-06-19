"""Save a 1000-character string and a 1001-character string to a textfile, each on a single line."""

import random

outfile = open('longlines.txt', 'w', encoding = 'utf-8')

characters = [chr(i) for i in range(ord('a'), ord('z'))]

string = ''
while len(string) < 1000:
	string += random.choice(characters)

outfile.write(string)
outfile.write('\n\n')

string = ''
while len(string) < 1001:
	string += random.choice(characters)
outfile.write(string)

outfile.close()

