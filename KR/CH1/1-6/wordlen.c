/*
 * wordlen.c
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

int main(int argc, char **argv)
{
	int c = 0;
	int i = 0;
	int wordlen[13] = {0};
	int longword = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (c == ' ')
			// increment index for length 0
			++wordlen[0];
			if (c == '\n')
				++wordlen[11];
			if (c == '\t')
				++wordlen[12];
			// increment word len index
			if (i > 9)
				++wordlen[10];
			if ((i > 0) && (i <= 9))
				++wordlen[i];
			i = 0;
			}
		else {
			++i;
			}
		}
	puts ("horizontal orientation");
	for (int n = 0; n < 13; n++) {
		if (n == 0)
			printf("w:");
		else if (n == 10)
			printf("*:");
		else if (n == 11)
			printf("n:");
		else if (n == 12)
			printf("t:");
		else
			printf("%d:", n);
		for (int in = 0; in < wordlen[n]; in++) {
			printf("-");
			}
		printf("\n");
		}
		
	puts("vertical orientation");
	/* for fun: do it vertically... */
	/* determine the biggest member, ie where to start printing the square at. */
	int s = 0;
	for (int n = 0; n < 13; n++) {
		if (wordlen[n] > s)
			s = wordlen[n];
		}
	/* print the header */
	for (int n = 0; n < 13; n++) {
		printf("_");
		} 
	printf("\n");
	while (s > 0) {
		for (int n = 0; n < 13; n++) {
			if (s <= wordlen[n]) {
				printf("|");
				}
			else 
				printf(" ");
			}
			--s;
			printf("\n");
		}
	/* print the legend */
	/*
	for (int n = 0; n < 13; n++)
		printf ("_");
	printf("\n");
	* */
	for (int n = 0; n < 13; n++) {
		if (n == 0)
			printf("w");
		else if (n == 10)
			printf("*");
		else if (n == 11)
			printf("n");
		else if (n == 12)
			printf("t");
		else
			printf("%d", n);
		}
	printf("\n");
	return 0;
}

