#include<stdio.h>

short int swap_endianness(short int x) {
	short int y;
	
	y = (x << 8) | (x >> 8 & 0x00FF);
	return y;
}

int main() {
	short int in1 = 1;
	short int in2 = 550;
	short int in3 = 1775;	
	
	printf("%d\n", swap_endianness(in1));
	printf("%d\n", swap_endianness(in2));
	printf("%d\n", swap_endianness(in3));
	return 0;
}
