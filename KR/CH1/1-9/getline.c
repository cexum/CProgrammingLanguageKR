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

int getline(char line[], int maxline);
void copy (char to[], char from[]);

int main(int argc, char **argv)
{
	int len; 
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {		
		if (len > max) {
			max = len;			
			copy(longest, line);
			}
		printf("len = %d\n", len);
		}
	if (max > 0)
		printf("%s", longest);
	else
		printf("there was no input buffer\n");
	return 0;
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

