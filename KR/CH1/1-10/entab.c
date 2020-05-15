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
#define SIZE 128	

int getline(char line[], int maxline);
void setemptyline(char line[], int maxline);
void copy(char to[], char from[]);
void detab(char in[], int len);
void entab(char in[], int len);


void test(char in[], int len) 
{	
	char temp[len] = {0};
	int tab, space, c, i;
		
	tab = (SIZE - 2) / TABSTOP;
	space = (SIZE - 2) % TABSTOP;	
	setemptyline(in, SIZE);
	printf("tab = %d\nspace = %d\n", tab, space);
	puts("empty line below..."); 
	printf("%s", buf);
	for (c = 0, i = 0; c < tab; ++c, ++i) 
		temp[i] = '\t';
	for (c = 0; c < space; ++c, ++i)
		temp[i] = ' ';
	printf("i = %d\n", i);	
	
	temp[i] = '\n';
	++i;
	temp[i] = '\0';	 
	printf("%s\n", temp);	
	for (c = 0; c <= i; ++c)
		buf[c] = temp[c];	
}

int main(int argc, char **argv)
{	
	test();
	return 0;
}

void entab(char in[], int len)
{
	char temp[MAXLINE] = {0};
	int tab, space, c, i;
		
	tab = (SIZE - 2) / TABSTOP;
	space = (SIZE - 2) % TABSTOP;	
	setemptyline(in, len);
	printf("tab = %d\nspace = %d\n", tab, space);
	puts("empty line below..."); 
	printf("%s", buf);
	for (c = 0, i = 0; c < tab; ++c, ++i) 
		temp[i] = '\t';
	for (c = 0; c < space; ++c, ++i)
		temp[i] = ' ';
	printf("i = %d\n", i);	
	
	temp[i] = '\n';
	++i;
	temp[i] = '\0';	 
	printf("%s\n", temp);	
	for (c = 0; c <= i; ++c)
		buf[c] = temp[c];	
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

void setemptyline(char s[], int lim)
{
	int i;
	
	for (i = 0; i < lim - 2; i++) 
		s[i] = '*';	
	s[lim - 2] = '\n';
	s[lim - 1] = '\0';	
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

