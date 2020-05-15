/*
 * temperaturefunction.c
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

float tempconversion(float temp, int format) {
	float t;
	float f, c;
	/* determine desired output format
	 * calculate temperature */
	if (format == 0) {
		f = temp;
		c = (5.0 / 9.0) * (f - 32);
		t = c;
		}
	else if (format == 1) {
		c = temp;
		f = (c / (5.0 / 9.0)) + 32;
		t = f;
		}
	else {
		puts ("unrecognisable format");
		
		}
	
	printf("%1.3f\n", t);
	return t;
	}

int main(int argc, char **argv)
{
	tempconversion(32, 0);
	return 0;
}

