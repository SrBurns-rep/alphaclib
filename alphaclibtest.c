#include "alphaclib.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	char strnum[15] = {0};

	srand(time(0));
	uint64_t bignum = integer_pow(36, 3);

	for (int i = 0; i < 10; i++) {
		print_to_alpha(bignum, strnum); //just prints
		printf(" %u", bignum);
		printf(" %s\n", to_alpha(bignum, strnum));
		bignum += rand();

	}

	return 0;
}
