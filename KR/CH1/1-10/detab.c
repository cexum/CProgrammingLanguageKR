/*
 * getline.c
 * 
 * Copyright 2018 graf <g@raspberrypi>
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
#define MAXLINE 1000
#define TABSTOP	8

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void detab(char in[], int len);

void test() 
{
	char tabs[6] = {0};
	tabs[0] = 't';
	tabs[1] = '\t';
	tabs[2] = 't';
	tabs[3] = '\t';
	tabs[4] = 't';
	tabs[5] = '\0';
	puts (tabs);		
}

void test2() 
{
	int tabstop = 8;
	char buf[32] = {0};
	buf[0] = '\t';
	buf[1] = '\t';
	buf[2] = 't';
	buf[3] = 't';
	buf[4] = '\t';
	char temp[32] = {0};
	int q;
	for (q = 0; q < 32; ++q)
		temp[q] = 'q';
	int t;
	printf ("rem = %d\n", (9 % 8));
	
	int i;
	int c; 
	for (c = 0, i = 0; c < 17; ++c, ++i) {
		if (buf[c] == '\t') {
			puts ("found a tab");			
			printf("t = %d\nc = %d\ni = %d\n", (i % tabstop), c, i);
			
			for (t = i % tabstop; t < tabstop; ++t, ++i) {
				puts ("inner loop");
				temp[i] = 's';
				
				if (t == tabstop - 1) {					
					break; 
				} 
			
			}
			/*continue; */
			
		}
		else {
			puts ("else...");
			printf ("c = %d\ni = %d\n", c, i);
			temp[i] = 'c';
		}
	}
	puts (temp);
	
}

int main(int argc, char **argv)
{
	
	/*test2();
	test();*/
	int len; 	
	char line[MAXLINE];	
	
	while ((len = getline(line, MAXLINE)) > 0) {		
		if (len > 0) {				
			detab(line, len);		
			printf("%s\n", line);
		}
		else
			printf("there was no input buffer\n");				
	}
	return 0;
}

void detab(char in[], int len) 
{	
	char buf[MAXLINE] = {0};	
	int t, i, c;
	/* build a working buffer that converts tabs to spaces */
	for (c = 0, i = 0; c < len; ++c, ++i) {		
		if (in[c] == '\t') {
			if (i >= MAXLINE - TABSTOP) {
			puts ("Unable to complete the action because stack overflow.");
			break;
			}			
			for (t = i % TABSTOP; t < TABSTOP; ++t, ++i) {				
				buf[i] = ' ';				
				if (t == TABSTOP - 1) 					
					break; 				 			
			}			
		}
		else 			
			buf[i] = in[c];		
	}
	/* copy the working buffer back over to input */
	c = 0;
	while (c != '\0') {
		in[c] = buf[c];
		++c;
	}	
}
 
int getline(char s[], int lim) 
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
		
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy (char to[], char from[]) 
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

