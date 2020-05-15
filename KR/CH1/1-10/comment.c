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

#define MAXDOC 100000 
#define MAXLINE 1000
#define TABSTOP	8
#define LINESTOP 24

#define INCOMMENT 2
#define OUTCOMMENT 3

int getdoc(char doc[], int maxdoc);
void remcomments(char doc[], int len);
int getline(char line[], int maxline);
void copy(char to[], char from[]);
void detab(char in[], int len);
void fold(char buf[], int len);

void test(char in[], int len) 
{
	char buf[MAXLINE] = {0};
	int lines;
	if (len < LINESTOP)
		lines = 1;
	else
		lines  = len / LINESTOP;
	int shift = 0;
	int c1, c2;
	/* populate buf
	 * 1) copy up to each line break;
	 * 2) insert '\n'
	 * 3) increment shift
	 * 4) copy buf back into in[] */ 	
	printf("number of lines: %d\n", lines);
	c1 = 0;
	while (c1 <= lines) {
		printf("first iteration\nc2 = (LINESTOP * c1) = %d\n(LINESTOP * (c1 + 1)) = %d\n", (LINESTOP * c1), (LINESTOP * (c1 + 1)));
		for (c2 = (LINESTOP * c1); c2 <= (LINESTOP * (c1 + 1)); ++c2) {
			if (c2 == (LINESTOP * (c1 + 1))) {
				puts("add new line");
				buf[c2 + shift] = '\n';
				++shift;
				break;				
			}
			buf[c2 + shift] = in[c2];
		}
		++c1; 
	}
	 
	puts("this is your buf:");
	puts(buf);	 
}

int main(int argc, char **argv)
{	
	int len, i, c; 	
	char doc[MAXDOC] = {0};
	
	len = getdoc(doc, MAXDOC);
		
	printf("%s", doc);	
	
	remcomments(doc, len);
	
	return 0;
}

void fold(char in[], int len) 
{
	char buf[MAXLINE] = {0};
	int lines;
	if (len < LINESTOP)
		lines = 1;
	else
		lines  = len / LINESTOP;
	int shift = 0;
	int c1, c2;
	/* populate buf
	 * 1) copy up to each line break;
	 * 2) insert '\n'
	 * 3) increment shift
	 * 4) copy buf back into in[] */ 	
	
	c1 = 0;
	while (c1 <= lines) {		
		for (c2 = (LINESTOP * c1); c2 <= (LINESTOP * (c1 + 1)); ++c2) {
			if (c2 == (LINESTOP * (c1 + 1))) {				
				buf[c2 + shift] = '\n';
				++shift;
				break;				
			}
			buf[c2 + shift] = in[c2];
						
		}
		
		++c1; 
	}
	c1 = 0;
	while (c1 <= len) {
		in[c1] = buf[c1];
		if (buf[c1] == '\0')
			break;
		++c1;
	}	 
}

void fold2(char in[], int len) 
{
	int c1, c2;
	int lines = len / LINESTOP;
	int fold;
	char buf[MAXLINE] = {0};
	
	for (c1 = 0; c1 < lines; ++c1) {
		for (c2 = (LINESTOP * (c1 + 1)); c2 > 0; --c2) {
			if (in[c2] == ' ' || in[c2] == '\t') {
				in[c2] = '\n';
				break;
			}
			if (c2 == 1) {
				puts (" special sauce ");
			}
		}	
	}	 
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

int getdoc(char doc[], int lim) 
{		
	int i, c; 	
	
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
		doc[i] = c;
	printf("the length of the document is: %d\n", i);
	printf("the last char is: %d\n", (doc[i]));
	return i;
}

void remcomments(char doc[], int len) 
{
	int c, state;
	int comment = 0;
	int offset = 0;
	char buf[MAXDOC] = {0};
	state = OUTCOMMENT;
	c = 0;
	puts ("pre loop");
	 
	for (c = 0; c <= len; ++c) {
		
		if (doc[c] == '\"')
			comment = !comment;
				
		if (doc[c] == '/' && doc[c + 1] == '*' && comment == 0) {	
			offset += 2;		
			state = INCOMMENT;
			++c;			
			puts("found /*");
			continue;
		}
		
		if (doc[c] == '*' && doc[c + 1] == '/' && comment == 0) {
			offset += 2;
			state = OUTCOMMENT;
			++c;			
			puts("found */");
			continue;
		}
			
		
		
		if (state == INCOMMENT)
			++offset;
		
		if (state == OUTCOMMENT) 
			buf[c - offset] = doc[c];
			
		if (doc[c] == '\0') {
			puts ("found terminus");
			break;
		}
	}
	puts("post loop");	
	puts ("original document");
	puts (doc);
	
	puts ("copied buffer");
	puts (buf);
}
 
int getline(char s[], int lim) 
{	
	int c, i;
	
	for (i = 0; i < lim - 1; ++i)
		s[i] = 0;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
		
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int getline2(char s[], int lim) 
{	
	int c, i;
	
	for (i = 0; i < lim - 1; ++i)
		s[i] = 0;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
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

