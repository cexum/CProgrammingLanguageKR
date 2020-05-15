/*
 * squeeze.c
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
#include <stdlib.h>
void squeeze(char s[], int c);
void squeeze2(char s[], char rem[]);
int any(char s1[], char s2[]);

int main(int argc, char **argv)
{
	
	char test[5] = { 'a', 'a', 'a', 'b', '\0' };
	char s1[10] = { 'z', 'b', 'q', 'd', 'f', '\0' };
	char s2[10] = { 'a', 'b', 'z', 'd', '\0' };	
	
	/*
	int me = 'a';
	squeeze(test, me);
	puts(test);
	*/
	
	/*
	squeeze2(s1, s2);
	puts(s1);
	*/
	
	char s3[10] = { 'q', 'r', 'm', 'n', 'a', '\0' };
	char s4[10] = { 'a', 'b', 'c', 'd', '\0' };
	printf("match found at index: %d\n", (any(s3, s4)));
	
	return 0;
}

int any(char s1[], char s2[]) 
{
	int id = -1;
	int i, c;
	for (i = 0; s2[i] != 0; i++) 
		for (c = 0; s1[c] != 0; c++) 
			if (s1[c] == s2[i]) 				
				return id = c;	
	return id;
}


void squeeze2(char s1[], char s2[])
{
	/* through the work comes learning
	 * the struggle is worth your time
	 * even if it takes a long time.
	 * 
	 * in fact, the time it takes does
	 * not matter. */
	int i, c, j;	
	
	for (i = 0; s2[i] != '\0'; i++) {
		for (c = j = 0; s1[c] != '\0'; c++) 
			if (s1[c] != s2[i])
				s1[j++] = s1[c];
		s1[j] = '\0';		
	}
			
}

void squeeze(char s[], int c) 
{
	/* counters */
	int i, j;
	/* double assign counters to 0
	 * while s[i] is not c
	 * 	s[j] is 	*/
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
	
}

