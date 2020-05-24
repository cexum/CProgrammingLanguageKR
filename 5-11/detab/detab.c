#include <u.h>
#include <libc.h>
#include <bio.h>
#define MAX 1000

int	getline(uchar*, int);
void	detab(uchar*);

Biobuf		out;
Biobufhdr 	in;
int		tstop;

int
main(void)
{
	uchar line[MAX] = {0};
	int len;
	        
	tstop = 8;
	Binits(&in, 0, OREAD, line, MAX);
	Binit(&out, 1, OWRITE);
	while ((len = getline(line, MAX)) > 0) {
		detab(line);
	}
	return 0;
}

void
detab(uchar *line)
{
	uchar temp[MAX] = {1};
	int c, t, i;
	
	c = t = 0;
	while (line[c] != '\0') {
		print("incoming char: %d\n", *(line + c));
		if (line[c] == '\t') {
			print("found a tab!\n");
			
			for (i = 0; i < tstop; i++) {
				temp[c + t] = '*';
				t++;
				print("append *: %s\n", temp);
			}
			
			//temp[c] = '*';
			c++;
			continue;
		}
		else {
		temp[c + t] = line[c];
		print("temp[%d] = %d\n", c + t, temp[c]);
		c++;
		}
	}

	print("test: %s\n", temp);
	Bprint(&out, "unmodified line: %s", line);
	Bprint(&out, "modified line: %s", temp);
}

int
getline(uchar line[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = Bgetc(&in)) != Beof && c != '\n'; i++)
		*(line + i) = c;
	if (c == '\n') 
		*(line + i++) = '\n';
	*(line + i) = '\0';
	return i;
}
