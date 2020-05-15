/*
 * linetabblank.c
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
	int c, nl, b, t;
	nl = 0;
	b = 0;
	t = 0;
	puts ("input text; type [CTRL + d] to input EOF and break while loop");
	while ((c = getchar()) != EOF) {
		
		if (c == '\n') {
			puts ("found a new line");
			++nl;
			}
		if (c == '\t') {
			puts ("found a new tab");
			++t;
			}
		if (c == ' ') {		
			puts ("found a blank space");
			++b;
			}
		}
		
	printf("line count: %d\ntab count: %d\nblank count: %d\n", nl, t, b);
		
	
	return 0;
}

