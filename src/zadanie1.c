#include<stdio.h>
#include<string.h>

short int swap_endianness(short int x) {
	int temp = (int) x;
	
	temp = (x << 8) | (x >> 8);
	return (short int) temp;
}

short int swap_endianness2(short int x) {
	short int y;
	
	y = (x << 8) | (x >> 8 & 0x00FF);
	return y;
}

short int swap_endianness3(short int x) {
	unsigned char res[2];
	memcpy(&res, &x, 2);
	unsigned char tmp = res[0];
	res[0] = res[1];
	res[1] = tmp;
	memcpy(&x, &res, 2);
	return x;
}

int main() {
	int i;
	for (i = -32767; i< 32768; i++) {
		if (swap_endianness2(i) != swap_endianness3(i)) {
			printf("%d\n", i);
		}
	}
	return 0;
}
