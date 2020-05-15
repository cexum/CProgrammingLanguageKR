/*
 * maxvalues.c
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(int argc, char **argv)
{
	int c;
	/* signed 8 bit integers */
	printf("max value of 8 bit signed int -- header: %d\n", SCHAR_MAX);
	printf("min value of 8 bit signed int -- header: %d\n", SCHAR_MIN);
	
	signed char byte;		
	
	byte = pow(2, 7) - 1;	
	printf("max value of 8 bit signed int -- calculated: %d\n", byte);
	byte = pow(2, 7) * -1;
	printf("min value of 8 bit signed int -- calculated: %d\n", (byte) );
	
	/* unsigned 8 bit integers */
	
	printf("max value of 8 bit unsigned int -- header: %u\n", CHAR_MAX);
	printf("min value of 8 bit unsigned int -- header: %u\n", CHAR_MIN);	
	
	/* chars are by default unsigned, so the unsigned modifier
	 *  is redundant in this case */	
	unsigned char ubyte; 
	ubyte = (pow(2, 8) - 1) ;
	printf ("max value of a 8 bit unsigned int: %u\n", ubyte);
	ubyte *= 0;
	printf ("min value of a 8 bit unsigned int: %u\n", ubyte);
	
	/* signed 16 bit integers */
	printf("max value of 16 bit signed int -- header: %d\n", SHRT_MAX);
	printf("min value of 16 bit signed int -- header: %d\n", SHRT_MIN);
	signed short int ssint; /* signed and int are redundant in this case */ 
	ssint = (pow(2, 15) - 1);	
	printf("max value of 16 bit signed int -- calculated: %d\n", ssint);
	ssint = pow(2, 15) * -1;
	printf("min value of 16 bit signed int -- calculated: %d\n", ssint);
	
	/* unsigned 16 bit integers */
	printf("max value of 16 bit unsigned int -- header: %u\n", USHRT_MAX);
	printf("min value of 16 bit unsigned int -- header: %u\n", 0);
	unsigned short int usint; 
	usint = (pow(2, 15) - 1) ;
	printf ("max value of a 16 bit unsigned int: %u\n", usint);
	usint *= 0;
	printf ("min value of a 16 bit unsigned int: %u\n", usint);
	
	/* signed 32 bit integers */
	printf("max value of 32 bit signed int -- header: %d\n", INT_MAX);
	printf("min value of 32 bit signed int -- header: %d\n", INT_MIN);
	signed int sint; /* signed is redundant in this case */
	sint = (pow(2, 31) - 1);
	printf("max value of 32 bit signed int -- calculated: %d\n", sint);
	sint = pow(2, 31) * -1;
	printf("min value of 32 bit signed int -- calculated: %d\n", sint);
	/* unsigned 32 bit integers */
	printf("ULONG_MAX to prove that int and long int are the same here: %lu\n", ULONG_MAX);
	printf("max value of 32 bit unsigned int -- header: %lu\n", UINT_MAX);
	printf("min value of 32 bit unsigned int -- header: %lu\n", 0);
	unsigned int unint;
	unint = (pow(2, 32) - 1);
	printf("max value of 32 bit unsigned int -- calculated: %lu\n", unint);
	unint *= 0;
	printf("min value of 32 bit unsigned int -- calculated: %lu\n", unint);
	/* signed 64 bit integers */	
	printf("max value of 64 bit signed int -- header: %lld\n", LLONG_MAX);
	printf("min value of 64 bit signed int -- header: %lld\n", LLONG_MIN);
	signed long long int sllint;
	 /*sllint = (pow(2, 63) - 1); */
	sllint = 0;
	sllint = ~sllint;
	printf("max value of 64 bit signed int -- calculated: %lld\n", sllint);
	sllint = pow(2, 63) * -1;
	printf("min value of 64 bit signed int -- calculated: %lld\n", sllint);
	/* unsigned 64 bit integers */
	printf("max value of 64 bit unsigned int -- header: %llu\n", ULLONG_MAX);
	printf("min value of 64 bit unsigned int -- header: %llu\n", ULLONG_MAX - ULLONG_MAX);
	unsigned long long int ullint;
	ullint = 0;
	ullint = ~ullint;
	printf("max value of 64 bit signed int -- calculated: %llu\n", ullint);
	ullint *= 0;
	printf("min value of 64 bit signed int -- calculated: %llu\n", ullint);
	
	/* floating point types
	 * too lazy to do the "hard mode" 
	 * where one calculates this */
	printf("max float -- header: %f\n", FLT_MAX);
	printf("min float -- header: %f\n", FLT_MIN);
	printf("max dbl -- header: %f\n", DBL_MAX);
	printf("min dbl -- header: %f\n", DBL_MIN);
	printf("max ldbl -- header: %f\n", LDBL_MAX);
	printf("min ldbl -- header: %f\n", LDBL_MIN);
	
	return 0;
}

