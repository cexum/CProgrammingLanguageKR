/*
 * 3-2.c
 * 
 * Copyright 2019 graf <g@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>

void escape(char *s, char *t);
void escape2(char *s, char *t);

int main(int argc, char **argv)
{
	char in[128] = {0};
	char out[128] = {0};
	int c = 0;
	int i = 0;
	
	/* does not prevent buffer overflow!! */
	while ((c = getchar()) != EOF) {
		in[i] = c;
		++i;
	}
	/* new line + null terminus */
	in[i] = '\0';	
	
	escape2(out, in);
	
	return 0;
}

/* converts visible escape sequences into their int value as it copies
 * string t to s */
void escape2(char *s, char *t) 
{
	printf("my input is:\n\n****\n%s\n****\n", t);
	int c, i;
	
	for (c = i = 0; *(t + c) != '\0'; ++c) {
		switch (*(t + c)) {
		case '\\':
			puts("found \\; determine type");
			switch (*(t + (c + 1)))	{
			case 'n':
				*(s + c - i) = '\n';
				++i;
				++c;
				break;
			case 't':
				*(s + c - i) = '\t';
				++i;
				++c;				
				break;
			default:
				break;
			}
		break;
		default:
			*(s + c - i) = *(t + c );
			break;
		}
	}
	printf("my output is:\n\n****\n%s\n****\n", s);	
}

/* converts characters newline and tab chars into \n and \t as it copies
 * string t to s */
void escape(char *s, char *t) 
{
	printf("my input is:\n\n****\n%s\n****\n", t);
	int c, i;
	
	for (c = i = 0; *(t + c) != '\0'; ++c) {
		switch (*(t + c)) {
		case '\n':
			puts("found new line!");
			*(s + c + i) = '\\';
			++i;
			*(s + c + i) = 'n';			
			break;
		case '\t':
			puts("found tab!");
			*(s + c + i) = '\\';
			++i;
			*(s + c + i) = 't';			
			break;
		default:
			*(s + c + i) = *(t + c);
			break;
		}
		printf("iteration number: %d\n", c);
	}
	printf("my output is:\n\n****\n%s\n****\n", s);
	puts("exit escape");	
}

