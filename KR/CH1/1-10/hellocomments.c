/*
 * hellocomments.c
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
	int arr[10] = {0};
	arr[0] = arr[1];
		
	char *comment = "/* i almost look like a comment */";
	/* the first comment */	
	/* ***************** */
	printf("i am an empty program with some comments in it...\n");
	printf("/* exception case just to mess with you */\n");		
	int i;
	int true = 1;
	if (true) 
		puts("truth be told...");
		
	for (;;) { }	
	
	for (i = 0; i < 4; ++i) {
		puts("i print 4 times :D if your syntax is correct");
		}
	/* the final comment */
	char *cheese = "char constant exception () () ( ";
	return 0;
}

