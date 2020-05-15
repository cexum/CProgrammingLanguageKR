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

void squeeze(char s[], int c);
void squeeze2(char s[], char rem[]);

int main(int argc, char **argv)
{
	
	char test[5] = { 'a', 'a', 'a', 'b', '\0' };
	char s1[10] = { 'a', 'b', 'c', 'e', 'f', '\0' };
	char s2[10] = { 'a', 'b', 'c', 'd', '\0' };
	int me = 'a';
	squeeze(test, me);
	puts(test);
	
	squeeze2(s1, s2);
	puts(s1);
	return 0;
}

void squeeze2(char s1[], char s2[])
{
	/* through the work comes learning
	 * the struggle is worth your time
	 * even if it takes a long time */
	int i, c, j;
	
	for (i = 0; s2[i] != 0; i++) {
		for (c = j = 0; s1[c] != 0; c++) 
			if (s1[c] != s2[c])
				s1[j++] = s1[c];
		s1[j] = '\0';		
	}		
}

void squeeze(char s[], int c) 
{
	int i, c, j;	
	
	for (i = 0; s2[i] != '\0'; i++) {
		for (c = j = 0; s1[c] != '\0'; c++) 
			if (s1[c] != s2[i])
				s1[j++] = s1[c];
		s1[j] = '\0';		
	}
	
}

