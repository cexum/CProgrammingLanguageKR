/*
 * 3-3.c
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

void shellsort(int v[], int n);
void expand(char *s1, char * s2);

int main(int argc, char **argv)
{
	char s1[16] = {0};
	s1[0] = ' ';
	s1[1] = 'a';
	s1[2] = '-';
	s1[3] = 'g';
	s1[4] = 'k';
	s1[5] = '-';
	s1[6] = 'y';
	
	
	char s2[1024] = {0};
	expand(s1, s2);
	printf("expanded string:\n%s\n", s2);
	int c;
	for (c = 0; s2[c] > 0; c++) {
		printf("index[%d] = %d\n", c, s2[c]);
	}
	return 0;
}

void expand(char *s1, char *s2) 
{
	int hasstart, hasend, founddash;
	hasstart = hasend = founddash = 0;	
	int c = 0;
	int i = 0;
	int in = 0;
	int range;
	int sign = 1;
	int start = 0;
	int end = 0;
	char ch = 0;
	
	/* skip white space */
	while (s1[c] == ' ')
		c++;
	
	/* loops needs to...
	 * ** assuming the script is correctly formatted **
	 * 1) determine the sign and value of start
	 * 2) determine sign and value of end
	 * 3) expand into s2
	 * 4) goto 1
	 *  */	
	
	while (s1[c] != '\0') {		 
		/* determine start */
		/* check sign */
		if (s1[c] == '-') {
			sign = -1;
			c++;
		}
		else
			sign = 1;			
		start = s1[c++] * sign;
		/* make sure bounds are separated by dash
		 * exit if this is not the case
		 * */
		if (s1[c++] != '-') {
			printf("malformed script...\n");
			break;
		}
		/* determine end */
		/* check sign */
		if (s1[c] == '-') {
			sign = -1;
			c++;
		}
		else
			sign = 1;
		end = s1[c++] * sign;
		/* we have a start and a finish
		 * populate s2
		 * */
		range = (end - start);
		printf("start is: %d\nend is: %d\n", start, end);
		printf("range is: %d\n", range);
		
		if (range < 0) {
			for (i = 0; i >= range; i--) {
				s2[in++] = start - i;
			}
		}
		else {
			for (i = 0; i <= range; i++) {
				s2[in++] = start + i;
			}
		}				
	}		
}

void shellsort(int v[], int n) 
{
	int gap, i, j, temp;
	
	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}
