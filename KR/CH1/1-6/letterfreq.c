/*
 * letterfreq.c
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
	int c = 0;;
	int arr[36] = {0};
	
	while ((c = getchar()) != EOF) {
		if (c == 'a' || c == 'A')
			++arr[0];
		else if (c == 'b' || c == 'B')
			++arr[1];
		else if (c == 'c' || c == 'C')
			++arr[2];
		else if (c == 'd' || c == 'D')
			++arr[3];
		else if (c == 'e' || c == 'E')
			++arr[4];
		else if (c == 'f' || c == 'F')
			++arr[5];
		else if (c == 'g' || c == 'G')
			++arr[6];
		else if (c == 'h' || c == 'H')
			++arr[7];
		else if (c == 'i' || c == 'I')
			++arr[8];
		else if (c == 'j' || c == 'J')
			++arr[9];
		else if (c == 'k' || c == 'K')
			++arr[10];
		else if (c == 'l' || c == 'L')
			++arr[11];
		else if (c == 'm' || c == 'M')
			++arr[12];
		else if (c == 'n' || c == 'N')
			++arr[13];
		else if (c == 'o' || c == 'O')
			++arr[14];
		else if (c == 'p' || c == 'P')
			++arr[15];
		else if (c == 'q' || c == 'Q')
			++arr[16];
		else if (c == 'r' || c == 'R')
			++arr[17];
		else if (c == 's' || c == 'S')
			++arr[18];
		else if (c == 't' || c == 'T')
			++arr[19];
		else if (c == 'u' || c == 'U')
			++arr[20];
		else if (c == 'v' || c == 'V')
			++arr[21];
		else if (c == 'w' || c == 'W')
			++arr[22];
		else if (c == 'x' || c == 'X')
			++arr[23];
		else if (c == 'y' || c == 'Y')
			++arr[24];
		else if (c == 'z' || c == 'Z')
			++arr[25];		
		else if (c == '0')
			++arr[26];
		else if (c == '1')
			++arr[27];
		else if (c == '2')
			++arr[28];
		else if (c == '3')
			++arr[29];
		else if (c == '4')
			++arr[30];
		else if (c == '5')
			++arr[31];
		else if (c == '6')
			++arr[32];
		else if (c == '7')
			++arr[33];
		else if (c == '8')
			++arr[34];
		else if (c == '9')
			++arr[35];
		else 
			continue;
		}	
			
	int s = 0;
	for (int n = 0; n < 36; n++) {
		if (arr[n] > s)
			s = arr[n];
		}
	/* print the header
	 * this could have been done in the loop above
	 * but I did it separatly to improve read-ability */
	for (int n = 0; n < 38; n++) {
		printf("#");
		} 
	printf("\n");	
	
	while (s > 0) {
		printf("#", s);
		for (int n = 0; n < 36; n++) {
			if (s <= arr[n]) {
				printf("|");
				}
			else 
				printf(" ");
			}
			printf("#%d\n", s);
			--s;
			
		}
	
	for (int n = 0; n < 38; n++) {
		printf("#");
		} 
	printf("\n");
	
	printf(" abcdefghijklmnopqrstuvwxyz0123456789\n");	
	
	return 0;
		
		
			
			
		
}

